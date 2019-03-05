/* ------------------------------------------------------------------------------------
 Program file: sbaronep3.c
 Author: Stacy Barone
 Date: July 1, 2018
 Assignment: Program #3
 Objective:This program first prompts the user to enter the number
 of grades they will want enter then determine the average of those
 grades and the associated letter grade.
 ------------------------------------------------------------------------------------ */

#include <stdio.h>

int main(void)
{
    /* Variable Declarations */
    
    int numberEnteredGrades; /* variable for total number of grades to be entered */
    int i; /* loop control variable */
    int grade; /* variable to capture entered grade */
    float sum = 0; /* accumulator variable for later calculation of average */
    float average = 0; /* variable to store the average of the entered grades */
    char c; /* variables to clear buffer */

    /* Greeting message */

    printf("This program calculates the average of as many grades you wish to enter.\n\nFirst, enter the number of grades to process: ");
    
    /* Prompt user for the number of total grades they would like to enter */
    
    scanf("%i", &numberEnteredGrades);
    while ( (c = getchar() != '\n') && c != EOF); /* clear input buffer */
    
    /* Determine if the number of total grades will be less than two as at least two are needed to average */
    
    if(numberEnteredGrades < 2)
        /* If the number of total grades to be entered is less than 2, print error message */
        
        printf("\nTwo grades must be enterd to be averaged. Please re-run the program. Goodbye.\n");
    else{
        
        /* If the number of total grades to be entered is more than 1, run the rest of the program */

        printf ("\nNow enter the %i grades to be averaged.\n\n", numberEnteredGrades);
        
        /* begin for loop to capture grades being enterd */
        
        for(i = 1;  i <= numberEnteredGrades; ++i)
        {
            /* prompt user to enter the grade */
            
            printf("Enter grade #%i: ", i);
            scanf("%i", &grade);
            while ( (c = getchar() != '\n') && c != EOF); /* clear input buffer */
            
            /* Begin if statement to determine if the grade entered is valid (between 0 - 100) */
            
            if (grade < 0 || grade > 100)
            {
                /* if grade entered is not between 0 and 100 print the invalid message */
                
                printf ("*** Invalid entry. Grade must be 0 to 100. ***\n");
                
                /* decrement the loop control variable to ensure proper average calculation */
                
                i--;
                
                /* allow the loop to continue and go back to prompting the user to enter the grade */
                
                continue;
            }
            else{
                /* if grade entered is between 0 and 100 run the accumulation variable */

                sum = sum + grade;
            }
        }
        
        /* Do the average calculation and print the averaged message */
        
        average = sum  / numberEnteredGrades ;
        printf ("\nThe averages of the %i grades entered is %.f\n\n", numberEnteredGrades, average  );

        /* Determine the letter grade of the calculated average and print the associated message */

        if (average >90)
            printf("You have a letter grade of A\n");
        else if (average > 80)
            printf("You have a letter grade of B\n");
        else if (average > 70)
            printf("You have a letter grade of C\n");
        else if  (average > 60)
            printf("You have a letter grade of D\n");
        else
            printf("You have a letter grade of F\n");
        /* end elseif statement which determined the letter grade */
    
    }/* end the intial determining (of number of grades to be entered) if statement's else */
    
    
    /* The following statement is used to pause output to ensure that we will see it.       */

    getchar();
    return 0;
    
    
}/* end main function */

