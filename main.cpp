#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include <cmath>
#include "temperature.h"
using namespace std;
istream& operator>>(istream& stream, Temperature& temperature) {
    stream >> temperature.value >> temperature.scale;
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
int main() {
    Temperature temperature;
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    vector<Temperature> numbers[number_count];
    cerr<<"\nEnter an array of temperatures:";
    for(size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
        if (test == false) {
            cout << "\nIncorrect temperature!\n";
            break; //или return 0?
        }
    }
    size_t column_count;
    cerr << "Enter basket count: ";
    cin >> column_count;
    if (column_count == 0) { //доп.задание для второго варианта
        column_count = sqrt(number_count);
        if (column_count > 25) {
            column_count = 1 + log2(number_count);
            cout << "\nSturges rule\n";
        }
        else {
            cout << "\nEmperical formula\n";
        }
        cout << "Bins: " << column_count << '\n';
    }
    double min = numbers[0];
    double max = numbers[0];
    for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }
    for(size_t i = 0; i < number_count; i++) {
        if (numbers[i].scale != 'K') {
            convert(numbers[i], 'K');
        }
    }
    vector<size_t> counts(column_count);
    for (double x : numbers) {
        if (x != max) {
            size_t column = (size_t)((x - min) / (max - min) * (column_count));
            counter[column]++; }
        else {
            size_t column = (size_t)((x - min) / (max - min) * (column_count)) - 1;
        }
        counts[column]++;
    }
    for (size_t count : counts) {
        if (count < 1000) {
            cout << ' ';
        }
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";
        for (size_t i = 0; i < number_count; i++) {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}