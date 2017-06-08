#include "temperature.h"
istream & operator>>(istream & stream, Temperature & temperature) {
    stream >> temperature.value >> temperature.scale;
}
Temperature convert(const Temperature &from, char to) {
    double K, converted;
    switch (from.scale) {
        case 'K':
            K = from.value;
            break;
        case 'F':
            K = 9*(from.value - 273,15)/5 + 32;
            break;
        case 'C':
            K = from.value + 273,15;
            break;
    }
    switch (to) {
        case 'K':
            converted = K;
            break;
        case 'F':
            converted = 5*(K - 32)/9 + 273,15;
            break;
        case 'C':
            converted = K - 273,15;
            break;
    }
    Temperature temperature;
    temperature.scale = to;
    temperature.value = converted;
    return temperature;
}
bool isLess(const Temperature & temperature_1, const Temperature & temperature_2) {
    temperature_1 = convert(temperature_1, 'K');
    temperature_2 = convert(temperature_2, 'K');
    if (temperature_1.value < temperature_2.value) {
        flag = true;
    }
    else {
        flag = false;
    }
    return flag;
}
bool test (Temperature input) {
    bool check = true;
    if ((input.scale != 'K') && (input.scale != 'F') && (input.scale != 'C')) {
        check = false;
    }
    convert (input, 'K');
    if (input.value < (-273,15)) {
        check = false;
    }
    return check;
}