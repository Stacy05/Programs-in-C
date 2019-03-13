/* ------------------------------------------------------------------------------------
 Program file: sbaronep1.c
 Author: Stacy Barone
 Date: January 23, 2019
 Assignment: Program #1
 Objective: A program that accepts a user-defined amount of grades from 0 - 10.
 Then determines the minimum grade, maximum grade, average of the entered grades and sorts
 and prints the entered grades in ascending order.
 ------------------------------------------------------------------------------------ */

#include <stdio.h>
int main(void)
{
    /* Variable Declarations and initializations */

    char c;                  /* variables to clear buffer */
    char changed = 'T';      /* flag to indicate if a swap was made */
    int grades[10];          /* variable to collect input grades as an array */
    int i;                   /* loop control variable */
    int x;                   /* loop control variable */
    int temp;                /* variable for sorting */
    int numberEnteredGrades; /* variable for total number of grades to be entered */
    float sum = 0;           /* accumulator variable for later calculation of average */
    float average = 0;       /* variable to store the average of the entered grades */

    /* Greeting message */

    printf("\nWelcome to the Grade Calculator\n");

    /*  Begin loop to test and collect number of grades to enter: numberEnteredGrades */

    for (x = 1; x < 2; ++x)
    {
        /* Prompt user for the number of total grades they would like to enter */

        printf("\nEnter the number of grades to process (0 - 10): ");
        scanf("%i", &numberEnteredGrades);
        while ((c = getchar() != '\n') && c != EOF); /* clear input buffer */

        /* Determine if the number of total grades entered is zero */

        if (numberEnteredGrades == 0)
        {
            /* Decrement the loop control variable to ensure proper average calculation  */
            x--;


        }/* End loop and go to printing of end message */

        /* Determine if the number of total grades entered is outside of the declared limits of greater than zero and less than 11 */

        else if (numberEnteredGrades < 0 || numberEnteredGrades > 10)
        {
            /* print error message for invalid grade entered */
            printf("\n*** Invalid number of grades entered. ***\n");

            /* Decrement the loop control variable to ensure proper average calculation  */
            x--;

            /* allow the loop to continue and go back to prompting the user to (re)enter the number of grades */
            continue;
        }

        /* If the number of total grades entered is within acceptable limits: Greater than 0 or less than 11, prompt user to enter each grade */

        else
        {
            printf("\n");

            /* loop to collect grades array values: (each grade) */

            for (x = 0; x < numberEnteredGrades; x++)
            {
                /* prompt user to enter the grade */

                printf("Enter grade for student #%i: ", x + 1);
                scanf("%i", &grades[x]);
                while ((c = getchar() != '\n') && c != EOF); /* clear input buffer */

                /* Determine if the grade entered is valid: (between 0 - 100) */

                if (grades[x] < 0 || grades[x] > 100)
                {
                    /* if grade entered is not between 0 and 100 print the invalid message */
                    printf("\n*** Invalid grade entered. Please enter 0 - 100. ***\n\n");

                    /* decrement the loop control variable to ensure proper average calculation */
                    x--;

                    /* allow the loop to continue and go back to prompting the user to enter the grade */
                    continue;
                }
                else
                {
                    /* if grade entered is between 0 and 100 run the accumulation variable */
                    sum = sum + grades[x];
                }
            } /* end check grade value and entering grades For loop */



            /* Use the "Bubble Sort" algorithm to sort array in ascending order. */

            while (changed == 'T')
            {
                /* Set swap flag to F */
                changed = 'F';

                /* For every element in the array starting at first, test if "this" */
                /* element is greater than the "next" element. If so, swap them. */

                for (x = 0; x < numberEnteredGrades - 1; x++)
                {
                    if (grades[x] > grades[x + 1])
                    {
                        /* Do Swap */
                        temp = grades[x];
                        grades[x] = grades[x + 1];
                        grades[x + 1] = temp;

                        /* Set flag indicating that a swap was made. This ensures that processing will continue, until nothing needs to be swapped. */
                        changed = 'T';

                    } /* end  swap if statement */
                } /* end swap for loop */
            } /* end swap while loop */


            /* Print the minimum grade entered  */

            printf("\n\nThe minimum grade is %i\n", grades[0]);

            /* Print the maximum grade entered  */

            printf("The maximum grade is %i\n", grades[x]);

            /* Do the average calculation and print the average of the grades entered */

            average = sum / numberEnteredGrades;
            printf("The class average is %.1f\n\n", average);

            /* Display the contents of the array, now in ascending sorted order. */

            printf("The %i grades entered are:\n\n", numberEnteredGrades);

            for (x = 0; x < numberEnteredGrades; x++)
                printf("%i, ", grades[x]);
                printf("\n");
        } /* end  number of entered grades if statement */

        /* End/Thank you message */

        printf("\nThank you for using the Grade Calculator\n");

        /* The following statement is used to pause output to ensure that we will see it. */
        getchar();
        return 0;

    } /* end containing for loop */

} /* end main */
