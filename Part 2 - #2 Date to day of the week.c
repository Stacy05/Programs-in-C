/* ------------------------------------------------------------------------------------
 Program file: sbaronep2.c
 Author: Stacy Barone
 Date: February 14, 2019
 Assignment: Program #2
 Objective: A program that prompts the user for a date (mm/dd/yyyy), determines if the
 is valid and informs the user of the day of the week that that date fell or falls on.

 ------------------------------------------------------------------------------------ */

#include <stdio.h>

/* Variable Declarations and initializations */

char *display_days_of_week[7] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"}; /*array containing days of the week*/

char leapYearFlag = 'T'; /* Flag used in checking for leap year */

struct date
{
    int month;
    int day;
    int year;
}; /* Struct to hold three integers for a date */

int x;                                                                   /* loop control */
int daysPerMonth[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /* the amount of days per month in a non leap year*/
int fYear;                                                               /* year determined in function for calculation in finding long number representing date entered */
int fMonth;                                                              /* month determined in function for calculation in finding long number representing date entered */
long int N;                                                              /*long number representing the dated entered */
int C;                                                                   /*int found after calculations of N, used in indexing array for days of week */

/* Functions */

/* calc_date_number function: takes a date as an argument and returns a number representing the date entered.*/
void calc_date_number(struct date enteredDate)
{
    /* check entered date and assign formula calculations*/
    if (enteredDate.month <= 2)
    {

        fYear = enteredDate.year - 1;
        fMonth = enteredDate.month + 13;
    }
    else
    {
        fYear = enteredDate.year;
        fMonth = enteredDate.month + 1;
    }

    /* apply formula calculations */
    N = (1461 * fYear) / 4 + (153 * fMonth) / 5 + enteredDate.day;

} /* End calc_date_number function */

/* Begin calc_day_number:  which takes as a parameter the number calculated in calc_date_number, and returns the number (0 - 6) representing the day of the week (Sunday - Saturday)*/
int calc_day_number(int N)
{
    C = (N - 621049) % 7;
    return C;
} /* End calc_day_number function */

/* Begin display_day_of_week: index number from above in display_days_of_week array to display the proper day */
void display_day_of_week(int C)
{

    printf("%s.\n", display_days_of_week[C]);
} /*End display_day_of_week */

/* Begin Main */
int main()
{
    printf("Welcome to the Date to Day-of-Week Program.\n\nThe program will give the day of the week for any date from 1/1/1900\n");

    struct date enteredDate;
    /* Begin main for loop use to capture, check and increment date input*/
    for (x = 1; x < 2; ++x)
    {
        /* Prompt user to enter date */
        printf("\nEnter date (mm/dd/yyyy): ");
        scanf("%d/%d/%d", &enteredDate.month, &enteredDate.day, &enteredDate.year);

        /* Check Month entered to ensure it is not over 12 or under 1 */
        if (enteredDate.month > 12 || enteredDate.month < 1)
        {
            printf("Invalid month. Please re-enter date. \n");
            --x;
            continue;
        } /* if month passes: Check day. Ensure not over 31 or under 1, ensure it is proper per days per  month or if month was 2 and day is 29 */
        else if (enteredDate.day > 31 || enteredDate.day < 1 || enteredDate.day > daysPerMonth[enteredDate.month - 1] || (enteredDate.day == 29 && enteredDate.month == 2))
        {
            /* If month enetred was 2 and day entered was 29, check to verify if it was a leap year */
            if (enteredDate.day == 29 && enteredDate.month == 2)
            {
                if ((enteredDate.year % 4 == 0 && enteredDate.year % 100 != 0) || enteredDate.year % 400 == 0)
                {
                    leapYearFlag = 'T';
                }
                else
                {
                    leapYearFlag = 'F';
                    printf("Invalid day. Please re-enter date. \n");
                    --x;
                    continue;
                }
            }
            else
            {
                printf("Invalid day. Please re-enter date. \n");
                --x;
                continue;
            }
        } /* if day passes, check year entered to ensure it is not less than 1900 */
        else if (enteredDate.year < 1900)
        {
            printf("Invalid year. Please re-enter date. Year must be greater than 1900. \n");
            --x;
            continue;
        }
        else
        {
            ++x;
        }
    } /*End main for loop */

    /* call funtions from above */
    calc_date_number(enteredDate);
    calc_day_number(N);

    /* printe date and index day of week fro array */
    printf(" \n%.2i/%.2i/%.2i falls on a ", enteredDate.month, enteredDate.day, enteredDate.year);
    display_day_of_week(C);

    /*Thank you message*/
    printf("\nThank you for using the Date to Day-of-Week program.\n");
} /* end main */
