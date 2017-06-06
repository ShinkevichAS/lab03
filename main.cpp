#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include <cmath>
#include "temperature.h"
using namespace std;
int main() {
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    vector <Temperature> numbers[number_count];
    cerr << "\nEnter an array of temperatures:";
    for (size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
        if (test == false) {
            cout << "\nIncorrect temperature!\n";
            break;
        }
    }
    size_t column_count;
    cerr << "Enter basket count: ";
    cin >> column_count;
    if (column_count == 0) {
        column_count = sqrt(number_count);
        if (column_count > 25) {
            column_count = 1 + log2(number_count);
            cout << "\nSturges rule\n";
        } else {
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
    for (size_t i = 0; i < number_count; i++) {
        if (numbers[i].scale != 'K') {
            (numbers[i], 'K');
        }
    }
    vector <size_t> counts(column_count);
    for (double x : numbers) {
        if (x != max) {
            size_t column = (size_t)((x - min) / (max - min) * (column_count));
            counter[column]++;
        } else {
            size_t column = (size_t)((x - min) / (max - min) * (column_count)) - 1;
        }
        counts[column]++;
    }
    for (size_t count : counts) {
        if (count < 1000) {
            cout << ' ';
        }
        if (count < 100) { cout << ' ';
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

