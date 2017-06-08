#ifndef TEMPERATURE
#define TEMPERATURE
struct Temperature {
    double value;
    char scale;
};
istream & operator>>(istream & stream, Temperature & temperature);
Temperature convert(const Temperature & from, char to);
bool isLess(Temperature temperature_1, Temperature temperature_2);
void test_temperature_input();
bool test (Temperature input);
#endif
