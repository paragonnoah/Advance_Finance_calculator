/*A2_Functions.c
 * DO NOT RENAME THIS FILE
 * THIS FILE MUST BE NAMED A2_Functions.c
 * 
 * You need to complete this file.
 * This file contains all of your functions (except main) required for A2.
 * 
 * Two of the functions are started for you.
 * You must complete these, and create the others.
 * Make sure the function headers match the prototypes in A2_Functions.h exactly.
 * 
 * Note that we have added newline '\n' between prompts for the user.
 * 
 * Do not forget to create function header comments. 
 * Do not forget to create the file header comment.
 */

#include "A2_Functions.h"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

float getFloatInput(char prompt[]) {
    float value = 0;
    int validInput = 0;

    while (!validInput) {
        printf("\n%s", prompt);
        if (scanf("%f", &value) == 1) {
            // Check if the input is a valid float
            validInput = 1;
            while (getchar() != '\n');
        } else {
            // Invalid input, clear input buffer
            while (getchar() != '\n');
            printf("Invalid Input.\n");
        }
    }

    return value;
}

int getIntInput(char prompt[]) {
    int value = 0;
    int validInput = 0;

    while (!validInput) {
        printf("\n%s", prompt);
        if (scanf("%d", &value) == 1) {
            if (value >= 0) {
                validInput = 1;
            } else {
                printf("Invalid Input.\n");
            }
            while (getchar() != '\n');
        } else {
            // Invalid input, clear input buffer
            while (getchar() != '\n');
            printf("Invalid Input.\n");
        }
    }

    return value;
}

char getCharInput(char prompt[], char valid_inputs[], int num_valid) {
    char value = '\0';
    int validInput = 0;

    while (!validInput) {
        printf("\n%s", prompt);
        char input = getchar();
        while (getchar() != '\n');

        // Convert to uppercase for case-insensitivity
        input = toupper(input);

        for (int i = 0; i < num_valid; i++) {
            if (input == valid_inputs[i]) {
                validInput = 1;
                value = input;
                break;
            }
        }

        if (!validInput) {
            printf("Invalid Input.\n");
        }
    }

    return value;
}

float getWeeklyPay() {
    char valid_y_n[] = {'Y', 'N'};
    char hasPartTimeJob = getCharInput("Do you have a part-time job (Y/N)? ", valid_y_n, 2);

    if (hasPartTimeJob == 'N') {
        return 0.0;
    }

    float hourlyWage = getFloatInput("Enter your hourly wage: $ ");
    int hoursWorked = getIntInput("Enter the number of hours worked in a week: ");

    return hourlyWage * hoursWorked;
}

float getAnnualAllowance() {
    char valid_y_n[] = {'Y', 'N'};
    char receivesAllowance = getCharInput("Do you receive an allowance (Y/N)? ", valid_y_n, 2);

    if (receivesAllowance == 'N') {
        return 0.0;
    }

    float amount = getFloatInput("Enter the allowance amount: $ ");
    int frequency = getIntInput("Enter the frequency of allowance payments (e.g., 12 for monthly): ");

    return amount * frequency;
}

void getHousing(float *rent, float *utilities) {
    char valid_y_n[] = {'Y', 'N'};
    char paysForHousing = getCharInput("Do you pay for housing (Y/N)? ", valid_y_n, 2);

    if (paysForHousing == 'N') {
        *rent = 0.0;
        *utilities = 0.0;
    } else {
        *rent = getFloatInput("Enter your monthly rent cost: $ ");
        *utilities = getFloatInput("Enter your monthly utilities cost: $ ");
    }
}

void getExpenses(char expense_names[MAX_NUM_EXPENSES][MAX_STRING_LEN],
                 float expense_costs[MAX_NUM_EXPENSES],
                 int *num_expenses,
                 float *expenses_total) {
    *num_expenses = 0;
    *expenses_total = 0.0;

    printf("\nEnter a one-word name of an expense. If you are finished, enter \"finished\":\n");
    char input[MAX_STRING_LEN];

    while (*num_expenses < MAX_NUM_EXPENSES) {
        printf("What is the monthly cost of this expense? $ ");
        scanf("%s", input);

        if (strcmp(input, "finished") == 0) {
            break;
        }

        strncpy(expense_names[*num_expenses], input, MAX_STRING_LEN);
        expense_costs[*num_expenses] = getFloatInput("Enter the monthly cost of this expense: $ ");
        *expenses_total += expense_costs[*num_expenses];
        (*num_expenses)++;
    }

    if (*num_expenses >= MAX_NUM_EXPENSES) {
        printf("\nMaximum Expenses Reached\n");
    }
}

void printTable(float savings, 
                float grants, 
                float net_funds, 
                float monthly_funds,
                float monthly_income, 
                float monthly_budget,  
                float rent,
                float utilities,
                char expense_names[MAX_NUM_EXPENSES][MAX_STRING_LEN], 
                float expense_costs[MAX_NUM_EXPENSES], 
                int num_expenses,
                float essentials_total, 
                float monthly_essentials_avail,
                float expensesRemaining,
                float monthly_wants, 
                float monthly_savings) {

    printf("\nFinances Table:\n==========================================\t\t|\n");
    printf("Funds Available\t\t\t\t\t\t|\n");
    printf("------------------------------------------\t\t|\n");
    printf("\t%-32s | $ %-8.2f\t|\n", "Savings", savings);
    printf("\t%-32s | $ %-8.2f\t|\n", "Grants", grants);
    printf("\t%-32s | $ %-8.2f\t|\n", "Net Funds Available", net_funds);
    printf("\t%-32s | $ %-8.2f\t|\n", "Total Monthly Funds", monthly_funds);
    printf("\t%-32s | $ %-8.2f\t|\n", "Monthly Income", monthly_income);
    printf("\t%-32s | $ %-8.2f\t|\n", "Monthly Budget", monthly_budget);
    printf("\t%-32s | $ %-8.2f\t|\n", "Rent", rent);
    printf("\t%-32s | $ %-8.2f\t|\n", "Utilities", utilities);
    
    printf("Expenses Required (Per Month)\t\t\t\t|\n");
    
    for (int i = 0; i < num_expenses; i++) {
        printf("\t%-32s | $ %-8.2f\t|\n", expense_names[i], expense_costs[i]);
    }

    printf("\t%-32s | $ %-8.2f\t|\n", "Essentials Total", essentials_total);

    printf("==========================================\t\t|\n");
    printf("\nSummary:\n");
    printf("------------------------------------------\t\t|\n");
    
    if (expensesRemaining < 0) {
        printf("You need to earn an additional $ %.2f per month.\n", -expensesRemaining);
    } else {
        printf("You are following the 50/30/20 rule.\n");
    }
    
    if (monthly_savings < 0) {
        monthly_savings = 0;
    }
    
    if (monthly_wants < 0) {
        monthly_wants = 0;
    }

    printf("Amount Available for Savings: $ %.2f\n", monthly_savings);
    printf("Amount Available for Wants: $ %.2f\n", monthly_wants);
}

void printSummary(float expensesRemaining, float wantsAvailable, float savingsAvailable) {
    if (expensesRemaining < 0) {
        printf("You need to earn an additional $ %.2f per month.\n", -expensesRemaining);
    } else {
        printf("You are following the 50/30/20 rule.\n");
    }

    if (savingsAvailable < 0) {
        savingsAvailable = 0;
    }

    if (wantsAvailable < 0) {
        wantsAvailable = 0;
    }

    printf("Amount Available for Savings: $ %.2f\n", savingsAvailable);
    printf("Amount Available for Wants: $ %.2f\n", wantsAvailable);
}
