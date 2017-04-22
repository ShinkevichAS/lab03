#include <iostream>
#include <vector>
using namespace std;
struct Temperature {
    double value;
    char scale;
};
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
            converted = K - 273;
    }
    Temperature temperature;
    temperature.scale = to;
    temperature.value = converted;
    return temperature;
}
int main() {
    Temperature temperature;
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    vector<Temperature> Temp[number_count];
    cerr<<"\nEnter an array of temperatures:";
    for(size_t i = 0; i < number_count; i++) {
        cin >> Temp[i];
    }
    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;
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
    vector<size_t> counts(column_count);
    for (double number : numbers) {
        size_t column = (size_t)((number - min) / (max - min) * column_count);
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
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";
        size_t height = count;
        if (scaling_needed) {
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }
        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}