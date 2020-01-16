#include <stdio.h>

#define LOWER_BOUND 0
#define UPPER_BOUND 300
#define STEP        20
#define FAHRENHEIT  "Fahrenheit"
#define CELSIUS     "Celcius"

float to_celcius_calculation(float);
float to_fahrenheit_calculation(float);
void temperature_converter(char*, char*, float converter_calculation(float));

int main() {
    temperature_converter(FAHRENHEIT, CELSIUS, to_celcius_calculation);
    temperature_converter(CELSIUS, FAHRENHEIT, to_fahrenheit_calculation);
}

float to_celcius_calculation(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

float to_fahrenheit_calculation(float celcius) {
    return ((9.0 / 5.0) * celcius) + 32.0;
}

void temperature_converter(char* source_temp_title, char* converted_temp_title, float converter_calculation(float)) {
    printf("%12s\t%7s\n", source_temp_title, converted_temp_title);
    for(float source_temp = LOWER_BOUND; source_temp <= UPPER_BOUND; source_temp += STEP)
        printf("%12.0f\t%7.1f\n", source_temp, converter_calculation(source_temp));
}