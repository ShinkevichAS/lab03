#include <iostream>
#include <vector>
#include <sstream>
#include "temperature.h"
using namespace std;
int main() {
    size_t temperature_count;
    cerr << "Enter temperature count: ";
    cin >> temperature_count;
    vector <Temperature> temperatures[temperature_count];
    cerr << "\nEnter an array of temperatures:";
    for (size_t i = 0; i < temperature_count; i++) {
        cin >> temperatures[i];
        if (test(temperature[i]) == false) {
            cout << "\nIncorrect temperature!\n";
            return 0;
        }
    }
    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;
    double min = convert(temperatures[0], 'K').value;
    double max = convert(temperatures[0], 'K').value;
    for (Temperature number : temperatures) {
        double current_number = convert(number, 'K').value;
        if (current_number < min) {
            min = current_number;
        }
        if (current_number > max) {
            max = current_number;
        }
    }
    vector <size_t> counts(column_count);
    for (Temperature number : temperatures) {
        double current_number = convert(number, 'K').value;
        size_t column = (size_t)((current_number - min)/(max - min)*column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }
    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;
    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }

    const bool scaling_needed = max_count > chart_width;
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
        size_t height = count;
        if (scaling_needed) {
            const double scaling_factor = (double) chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }
        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}

