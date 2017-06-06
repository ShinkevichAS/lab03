#include <sstream>
#include <cassert>
#include "temperature.h"
istream& operator>>(istream& stream, Temperature& temperature) {
    stream >> temperature.value >> temperature.scale;
}
Temperature convert(const Temperature &from, char to) {
    double K, converted;
    switch (from.scale) {
        case 'K':
            K = from.value;
            break;
        case 'F':
            K = 5*(from.value - 32)/9 + 273,15;
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
            converted = 9*(K - 273,15)/5 + 32;
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
bool isLess(Temperature temperature_1, Temperature temperature_2) {
    temperature_1 = convert(temp1, 'K');
    temperature_2 = convert(temp2, 'K');
    if (temp1.value < temp2.value) {
        flag = true;
    }
    else {
        flag = false;
    }
    return flag;
}
void test_temperature_input() {
    Temperature temperature;
    istringstream heh("10K");
    heh >> temperature;
    assert (temperature.value == 10);
    assert (temperature.scale == 'K');
    istringstream kek("10F");
    kek >> temperature;
    assert (temperature.value == 10);
    assert (temperature.scale == 'F');
    istringstream lol("10C");
    lol >> temperature;
    assert (temperature.value == 10);
    assert (temperature.scale == 'C');
}
bool test (Temperature input) {
    bool check = true;
    if ((input.scale != 'K') && (input.scale != 'F') && (input.scale != 'C')) {
        check= false;
    }
    convert (input, 'K');
    if (input.value < (-273,15)) {
        check = false;
    }
    return check;
}