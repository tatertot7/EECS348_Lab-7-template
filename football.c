#include <stdio.h>
#include "football.h"

void print_combinations(int points) {
    //printing all score combinations
    if (points <= 1) {      //if an invalid score is given
        printf("Invalid score. Enter a value greater than 1.\n");
        return;
    }

    printf("Possible cominations of scoring plays for %d points:\n", points);
    //listing all combinations as for loops. I'm sure there's a simpler way, but this should work
    for (int td2 = 0; td2 * 8 <= points; td2++) {                               // td2 = touchdown with 2pt conversion
        for (int td1 = 0; td1 * 7 + td2 * 8 <= points; td1++) {                 // td1 = touchdown with 1pt field goal
            for (int td = 0; td * 6 +td1 * 7 + td2 * 8 <= points; td++) {       // td = touchdown with no extra points
                for (int fg = 0; fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= points; fg++) {                                 // number of field goald
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= points; safety++) {        // number of safeties
                        if (safety * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 == points) {                               //check if combinations matches points
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Saftey\n", td2, td1, td, fg, safety);     //print results
                        }
                    }
                }
            }
        }
    }
}

int count_combinations(int points) {
    //count combinations and return total
    int count = 0;     //start with empty count
    //for loops to iterate over all possible numbers of each type of scoring play
    for (int td2 = 0; td2 * 8 <= points; td2++) { 
        for (int td1 = 0; td1 * 7 + td2 * 8 <= points; td1++) {
            for (int td = 0; td * 6 + td1 * 7 + td2 * 8 <= points; td++) {
                for (int fg = 0; fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= points; fg++) {
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= points; safety++) {
                        if (safety * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 == points) { //check to see if combination matches the amount of points entered
                            count++; //if comb matches score, count is incremented
                        }
                    }
                }
            }
        }
    }
    return count; //returns count value
}