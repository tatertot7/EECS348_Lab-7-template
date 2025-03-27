#include "temperature.h"
#include <stdio.h>

//converting celsius to fahreheit
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

//convert fahreheit to celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

//convert celsius to kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

//convert kelvin to celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

//convert fahrenheit to kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

//convert kelvin to fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float temp_in_celsius) {
    //temperature categorizations, converted all temp to celsius to make it easy.
    if (temp_in_celsius < 0) {
        printf("Category: Freezing - Advisory: Stay warm, it's freezing outside!\n");
    } else if (temp_in_celsius < 10) {
        printf("Category: Cold - Advisory: Wear a jacket, it's chilly.\n");
    } else if (temp_in_celsius < 25) {
        printf("Category: Comfortable - Advisory: Enjoy the nice weather!\n");
    } else if (temp_in_celsius < 35) {
        printf("Category: Hot - Advisory: Stay hydrated, it's getting warm.\n");
    } else {
        printf("Category: Extreme Heat - Advisory: Stay indoors and avoid the heat!\n");
    }
}

