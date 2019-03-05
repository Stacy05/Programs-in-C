/* ------------------------------------------------------------------------------------
Program file: sbaronep1.c 
Author: Stacy Barone
Date: June 10, 2018
Assignment: Program #1 
Objective: This program calculates the sum, difference, product, quotient, 
and remainder of two integers.
The results of the calculations are then printed in the output. 
There is no user input required.
------------------------------------------------------------------------------------ */

#include <stdio.h>

int main(void)
{

    /* Variable Declarations                                                               */
    /* I decided that I would like to declare each variable on their own                   */
    /* line so that it would be easy to scan and update in the future if necessary.        */
    /* The calculations have been done and stored in their own variables as well as the    */
    /* two starting integers                                                               */
    /* ----------------------------------------------------------------------------------- */

    int num1 = 30;              /* integer number 1 */
    int num2 = 17;              /* integer number 2 */
    int sum = num1 + num2;      /* calculation to add the two integers */
    int diff = num1 - num2;     /* calculation to subtract the two integers */
    int product = num1 * num2;  /* calculation to multiple the two integers */
    int quotient = num1 / num2; /* calculation to divide the two integers */
    int remain = num1 % num2;   /* calculation to determine the remander of the division of the two integers */

    /* Output print declarations                                                            */
    /* Display a statement that delares the integers or which calcultions have been done    */
    /* along with the calculated result integers                                            */
    /* ------------------------------------------------------------------------------------ */

    printf("The two numbers used by this program are %i and %i.\n\n", num1, num2);
    printf("The sum is %i\n", sum);
    printf("The difference is %i\n", diff);
    printf("The product is %i\n", product);
    printf("The quotient is %i with a remainder of %i\n\n", quotient, remain);
    printf("Thank you for using the program.");

    /* The following statement is used to pause output to ensure that we will see it.       */
    /* ------------------------------------------------------------------------------------ */

    getchar();
    return 0;

} /* end main function */
