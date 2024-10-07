#include <stdio.h>

//finding the combinations of different scores that sum to the number provided by user 
void find_combinations(int score, int results[][5], int *count) {
    *count = 0;

    //different combinations of the scoring plays 
    for (int td_2pt = 0; td_2pt <= score / 8; td_2pt++) {
        for (int td_fg = 0; td_fg <= score / 7; td_fg++) {
            for (int td = 0; td <= score / 6; td++) {
                for (int fg = 0; fg <= score / 3; fg++) {
                    for (int safety = 0; safety <= score / 2; safety++) {
                        if ((td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2) == score) {
                            results[*count][0] = td_2pt;
                            results[*count][1] = td_fg;
                            results[*count][2] = td;
                            results[*count][3] = fg;
                            results[*count][4] = safety;
                            (*count)++;
                        }
                    }
                }
            }
        }
    }
}

//all valid combinations found 
void display_combinations(int score, int results[][5], int count) {
    printf("\nPossible combinations of scoring plays if a team’s score is %d:\n", score);
    for (int i = 0; i < count; i++) { //looping through each combination to print 
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
               results[i][0], results[i][1], results[i][2], results[i][3], results[i][4]);
    }
}

int main() {
    int score; //storing user input
    int results[100][5]; // storing up to 100 combinations
    int count; //storing number of valid combinations

    while (1) { //creating an infinte loop for continued score count to be prompted to user 
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: "); //prompt user for score 
        if (scanf("%d", &score) != 1) { //checking if input is valid
            printf("Please enter a valid integer.\n");
            while(getchar() != '\n'); // clear input buffer if not valid
            continue; //continue until finding a final score
        }

        if (score <= 1) { //stop is score entered is 0 or 1
            break;
        }

        find_combinations(score, results, &count); //call function to find combinations
        if (count > 0) {
            display_combinations(score, results, count); //print the combinations 
        } else {
            printf("No possible combinations for score %d.\n", score); //no combinations 
        }
    }

    return 0; //program ended 
}
