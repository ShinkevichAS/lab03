#include <sstream>
#include <cassert>
#include "temperature.h"
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
int main() {
    test_temperature_input();
    return 0;
}