/* ------------------------------------------------------------------------------------
 Program file: sbaronep2.c
 Author: Stacy Barone
 Date: June 24, 2018
 Assignment: Program #2
 Objective: This program determines the miles per gallon for 3 tanks of gasoline
 The user inputs the gallons used and the miles driven for each tank.
 Then, the program will calculate the overall mileage.
 ------------------------------------------------------------------------------------ */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    /* Variable Declarations */

    int i;                  /* loop control variable */
    float gallons;          /* variables to capture gallons */
    float miles;            /* variables to capture miles */
    float mpg;              /* variables for miles per gallons */
    float totalGallons = 0; /* variables for total gallons */
    float totalMiles = 0;   /* variables for total gallons */
    float averageMpg = 0;   /* variables for Average overall MPG */
    char c;                 /* variables to clear buffer */

    /* Greeting message */

    printf("Welcome to the mileage calculator.\n\nThis program will calculate the miles per gallon for you for three tanks of gas after you have entered the gallons used and miles driven.\n\n");

    /* Begin for loop */

    for (i = 0; i < 3; ++i)
    {
        /* Prompt user for gallons used in each tank and display which tank info is being captured for */

        printf("Enter the number of gallons used for tank #%i: ", i + 1);
        scanf("%f", &gallons);
        while ((c = getchar() != '\n') && c != EOF)
            ; /* clear input buffer */

        /* Prompt user for miles driven in each tank */

        printf("Enter the number of miles driven: ");
        scanf("%f", &miles);
        while ((c = getchar() != '\n') && c != EOF)
            ;

        /* Determine & display mpg for tank */

        mpg = miles / gallons;

        printf("*** The miles per gallon for this tank is %.1f\n\n", mpg);

        /* determine total gallons and total miles */

        totalGallons = totalGallons + gallons;
        totalMiles = totalMiles + miles;

    } /* end for loop */

    /* Determine overall mpg */

    averageMpg = totalMiles / totalGallons;

    printf("Your overall average miles per gallon for three tanks is %.1f\n", averageMpg);

    /* Output the final greeting. */

    printf("\nThank you for using the program. Goodbye!\n");

    /* The following statement is used to pause output to ensure that we will see it.       */

    getchar();
    return 0;

} /* end main function */
