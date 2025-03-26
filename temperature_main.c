#include "temperature.h"

int main(int argc, char *argv[]) {
    float temp; //set temperature as a float value
    int choice; //user input number from menu

    //menu for user input
    printf("Temperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    scanf("%f", &choice);

    printf("Enter temperature value: ");
    scanf("%f", &temp);

    //call case that corresponds with user input value
    switch (choice) {   
        case 1:         //call celsius_to_fahrenheit
            printf("%.2f Celsius = %.2f Fahrenheit\n", temp, celsius_to_fahrenheit(temp)); //using "%.2f" to output the float to 2 decimal places
            break;
        case 2:         //call fahrenheit_to_celsius
            printf("%.2f Fahrenheit = %.2f Celsius\n", temp, fahrenheit_to_celsius(temp));
            break;
        case 3:         //call celsius_to_kelvin
            printf("%.2f Celsius = %.2f Kelvin\n", temp, celsius_to_kelvin(temp));
            break;
        case 4:         //call kelvin_to_celsius
            printf("%.2f Kelvin = %.2f Celsius\n", temp, kelvin_to_celsius(temp));
            break;
        default:        //error checking for invalid input
            printf("Invalid Choice.\n");
        
    }
    return 0;
}
