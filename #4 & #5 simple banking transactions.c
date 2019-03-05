/* ------------------------------------------------------------------------------------
 Program file: sbaronep5.c
 Author: Stacy Barone
 Date: July 29, 2018
 Assignment: Program #5
 Objective: Add at least 2 non-trivial functions to Program #4. 
            Program #4 Objective: Write a C program that allows the user to make 
            some simple banking transactions. User will enter their starting balance follwed by the
            number of deposits and withdrawls. Then the user will be proted to enter
            the amount of each transaction. The program wil then print the new balance
            as well a related message followed by a bank statement.
 ------------------------------------------------------------------------------------ */

#include <stdio.h>
/* declare function prototypes */

int numOfD(int);            /*prototype for function to capture number of deposits */
int numOfW(int);            /*prototype for function to capture number of withdrawls */
void balanceMessage(float); /*prototype for function to capture number of deposits */

/* function to capture number of deposits */
int numOfD(int numD)
{
    char c; /* Variable to clear buffer */

    printf("\nEnter the number of deposits (0 - 5): ");
    scanf("%i", &numD);
    while ((c = getchar() != '\n') && c != EOF); /* clear input buffer */

    numD = numD;
    return numD;
}

/* function to capture number of withdrawls */
int numOfW(int numw)
{
    char c; /* Variable to clear buffer */

    printf("\nEnter the number of deposits (0 - 5): ");
    scanf("%i", &numw);
    while ((c = getchar() != '\n') && c != EOF); /* clear input buffer */

    numw = numw;
    return numw;
}

void balanceMessage(float newBalance)
{

    if (newBalance >= 50000.00)
        printf("*** It is time to invest some money! ***\n");
    else if (newBalance >= 15000.00)
        printf("*** Maybe you should consider a CD. ***\n");
    else if (newBalance >= 1000.00)
        printf("*** Keep up the good work! ***\n");
    else
        printf("*** Your balance is getting low! ***\n");
}

int main(int argc, const char *argv[])
{
    /* Declare variables */

    int x = 0;                 /* Loop Control Varable */
    int i = 0;                 /* Loop Control Varable */
    int w = 0;                 /* Loop Control Varable */
    float deposits[5];         /* Array variable to store amount of each deposit made, entered by user */
    float withdrawls[5];       /* Array variable to store amount of each deposit made, entered by user. max: 5 */
    float startingBalance = 0; /* Array variable to store amount of each withdrawl made, entered by user. max: 5 */
    float depositsTotal = 0;   /* Variable to store calculated sum of the deposits made */
    float withdrawlsTotal = 0; /* Variable to store calculated sum of the withdrawls made */
    float balance = 0;         /* Variable to store calculated total of the deposits made minus the sum of the withdrawls made */
    float newBalance = 0;      /* Variable to store calculated starting balance plus the balance (transcational difference of deposits minus withdrawls) */
    char c;                    /* Variable to clear buffer */

    /* Greeting Message */

    printf("\nWelcome to the Computer Banking System\n");

    /* Begin loop to prompt user for their starting balance.  */

    for (x = 1; x < 2; x++)
    {
        /* Prompt user to enter their starting balance.  */

        printf("\nEnter your current balance in dollars and cents: ");
        scanf(" %f", &startingBalance);
        while ((c = getchar() != '\n') && c != EOF); /* clear input buffer */

        /* Determine if starting balance is valid */

        if (startingBalance < 0)
        {
            /* If starting balance is invalid, print error message and prompt the user to enter the starting balance again */

            printf("*** Beginning balance mst be at least zero, please re-enter.\n");
            x--;

            continue;
        }
        else
        {
            /* If starting balance is valid, continue running program and begin loop to prompt user for number of made deposits */

            for (x = 1; x < 2; x++)
            {
                /* Prompt user to enter number of deposits made */

                int numberOfDeposits = numOfD(1);

                /* Determine if number of deposits entered is valid (between 0-5) */
                if (numberOfDeposits < 0 || numberOfDeposits > 5)
                {
                    /* if number of deposits is invalid, above 5 or below 0, print error message */
                    /* ensure the increment is not added to the loop control variable and prompt the user to enter the number of deposits again  */

                    printf("*** Invalid number of deposits, please re-enter.\n");
                    x--;

                    continue;
                }
                else
                {
                    /* If number of deposits is valid, begin the loop for number of withdrawls */

                    for (x = 1; x < 2; x++)
                    {
                        /* Prompt user to enter number of withdrawls made */

                        int numberOfWithdrawls = numOfW(1);

                        /* Determine if number of withdrawls entered is valid (between 0-5) */

                        if (numberOfWithdrawls < 0 || numberOfWithdrawls > 5)
                        {
                            /* if number of withdrawls is invalid, above 5 or below 0, print error message */
                            /* ensure the increment is not added to the loop control variable and prompt the user to enter the number of withdrawls again  */

                            printf("*** Invalid number of withdrawls, please re-enter.\n");
                            x--;

                            continue;
                        }
                        else
                        {
                            printf("\n");

                            /* Begin loop to collect amount of each deposit based on number of deposits entered by user in previous step */

                            while (i < numberOfDeposits)
                            {

                                /* Prompt user to enter the amount of desposit */

                                printf("Enter the amount of deposit #%i: ", i + 1);
                                scanf("%f", &deposits[i]);
                                while ((c = getchar() != '\n') && c != EOF); /* clear input buffer */

                                /* If the amount of the deposit is invalid, less than or equal to zero, print error message and do not increment desposit array, prompt user to enter amount again */

                                if (deposits[i] <= 0)
                                {
                                    printf("** Deposit amount must be greater than zero, please re-enter.\n\n");
                                }
                                else
                                {
                                    /* If the amount of the deposit is valid, add amount to deposit total variable and increment to next deposit amount prompt */

                                    depositsTotal = depositsTotal + deposits[i];
                                    i++;
                                }
                            } /* end while loop */

                            printf("\n");

                            /* Begin loop to collect amount of each withdrawl based on number of withdrawls entered by user previously */

                            while (w < numberOfWithdrawls)
                            {

                                /* Prompt user to enter the amount of withdrawl */

                                printf("Enter the amount of withdrawal #%i: ", w + 1);
                                scanf("%f", &withdrawls[w]);
                                while ((c = getchar() != '\n') && c != EOF); /* clear input buffer */

                                /* If the amount of the withdrawl is invalid, less than the starting balance */
                                /* print error message and do not increment withdrawl array, prompt user to enter amount again */

                                if (withdrawlsTotal > startingBalance + depositsTotal)
                                {
                                    printf("*** Withdrawal amount exceeds current balance, please re-enter.\n\n");

                                    continue;
                                }
                                else
                                {

                                    /* If the amount of the withdrawl is valid, add amount to withdrawl total variable and increment to next withdrawl amount prompt */

                                    withdrawlsTotal = withdrawlsTotal + withdrawls[w];
                                    w++;
                                }

                            } /* end while loop*/

                            /* Calculate current balance and new balance */

                            balance = depositsTotal - withdrawlsTotal;
                            newBalance = startingBalance + balance;

                            /* print closing balance message and new balance */

                            printf("\n*** The closing balance is $%.2f ***\n", newBalance);
                            /* Print cooresponding bank message based on new balance */

                            balanceMessage(newBalance);

                            /* print bank record */

                            printf("\n\n\n *** Bank Record ***\n\n");
                            printf("Starting Balance: $ %.2f\n\n", startingBalance);
                            for (x = 0; x < numberOfDeposits; x++)
                                printf("Deposit #%i:         %.2f\n", x + 1, deposits[x]);

                            printf("\n");

                            for (x = 0; x < numberOfWithdrawls; x++)
                                printf("Withdrawl #%i:       %.2f\n", x + 1, withdrawls[x]);
                            printf("\n");

                            printf("Ending Balance:   $ %.2f\n", newBalance);
                        }
                    }
                }
            } /* End For Loop outside of Balance */
            getchar();
            return 0;
        } /* End if/Else Function for starting Balance */
    }     /* End containing For Loop */
} /* End Main Function */


