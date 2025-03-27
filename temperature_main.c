#include "temperature.h"
#include <stdio.h>

int main() {
    float temp, converted_temp, temp_in_celsius; //set float value for input and output temp
    int input_unit, target_unit;    //int values for user selections
    
    //obtain user temp value
    printf("Enter the temperature value: ");
    if (scanf("%f", &temp) != 1) {              //!= 1 float check
        printf("Invalid input. Please enter a numeric value.\n");
        return 1;
    }
    
    //obtain user temperature unit
    printf("Select the input unit (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
    if (scanf("%d", &input_unit) != 1 || input_unit < 1 || input_unit > 3) { //input check
        printf("Invalid input unit.\n");
        return 1;
    }
    
    //obtain unit to convert to
    printf("Select the target unit (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
    if (scanf("%d", &target_unit) != 1 || target_unit < 1 || target_unit > 3) {
        printf("Invalid target unit.\n");
        return 1;
    }
    
    //if units are the same
    if (input_unit == target_unit) {
        printf("The input unit and target unit are the same. No conversion needed.\n");
        return 0;
    }
    
    //switch statement to call the conversion from user input
    switch (input_unit) {
        case 1: // celsius
            if (target_unit == 2)
                converted_temp = celsius_to_fahrenheit(temp); //call cel_to_fah
            else
                converted_temp = celsius_to_kelvin(temp);     //call cel_to_kel
            break;
        case 2: // fahrenheit
            if (target_unit == 1)
                converted_temp = fahrenheit_to_celsius(temp); //call fah_to_cel
            else
                converted_temp = celsius_to_kelvin(fahrenheit_to_celsius(temp)); //call fah_to_cel then cel_to_kel
            break;
        case 3: // kelvin
            if (temp < 0) {         //error check for negative kelvin
                printf("Invalid input: Temperature in Kelvin cannot be negative.\n");
                return 1;
            }
            if (target_unit == 1)
                converted_temp = kelvin_to_celsius(temp); //call kel_to_cel
            else
                converted_temp = celsius_to_fahrenheit(kelvin_to_celsius(temp)); //call kel_to_cel then cel_to_fah
            break;
    }
    
    //convert any input into celsius for categorization
    if (target_unit ==1) {
        temp_in_celsius = converted_temp;
    } else if (target_unit == 2) { //if unit is fahrenheit
        temp_in_celsius = fahrenheit_to_celsius(converted_temp);
    } else {
        temp_in_celsius = kelvin_to_celsius(converted_temp);
    }
    
    
    printf("Converted temperature: %.2f\n", converted_temp); //print converted temp
    categorize_temperature(temp_in_celsius);                 //call/print categorized temperature
    
    return 0;
}
