#include "football.h"
#include <stdio.h>

int main() {
    int points;

    //loop to continuously prompt user
    while (1) { //while true
        printf("Enter the NFL score: ");
        scanf("%d", &points);

        // if invalid number (0 or 1)
        if (points <= 1) {
            prinf("Invalid Score.\n");
            break;
        }
        //call print_comb from football.c
        print_combinations(points);
        //call count_comb and print from football.c
        printf("Total combinations: %d\n", count_combinations(points));
    }
    
    return 0;
}