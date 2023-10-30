/* skeleton.c
 * This file serves as a starting point for your A2 code. 
 * 
 * Compile this code with the gcc compiler and the flags -std=c99 -Wall -lm
 * ex if the file is named skeleton.c and you want to save the compiled program as a2
 * 
 * gcc -std=c99 -Wall -o a2 skeleton.c A2_Functions.c -lm
 * 
 * and run with the command 
 * ./a2
 * 
 * NOTE: sometimes when copying text a dash - turns into a long dash – or —. 
 * The compiler will not like that, so you may need to type it out. 
 * 
 * Remember to rename your file as the outline specifies, and place the correct file header here. 
 * Only submit the two .c files 
 * DO NOT CHANGE THE FUNCTION HEADERS OR PROTOTYPES!
*/

#include <stdio.h>
#include "A2_Functions.h"

int main() {
    // Declare and initialize variables
    float savings;
    float weeklyPay;
    float annualAllowance;
    float rent, utilities;
    char expenseNames[MAX_NUM_EXPENSES][MAX_STRING_LEN];
    float expenseCosts[MAX_NUM_EXPENSES];
    int numExpenses = 0;
    float expensesTotal;
    float grants;
    float netFunds;
    float monthlyFunds;
    float monthlyIncome;
    float monthlyBudget;
    float essentialsTotal;
    float monthlyEssentialsAvail;
    float expensesRemaining;
    float monthlyWants;
    float monthlySavings;

    printf("Welcome to the CIS1500 Student Finance Planner. We have a few questions for you:\n\n");

    // Get user input
    savings = getFloatInput("How much savings do you have set aside for the year? $ ");
    weeklyPay = getWeeklyPay();
    annualAllowance = getAnnualAllowance();
    getHousing(&rent, &utilities);
    getExpenses(expenseNames, expenseCosts, &numExpenses, &expensesTotal);
    
    // Calculate finances and essentials
    grants = 0; // You may need to implement logic to calculate grants
    netFunds = savings + weeklyPay + annualAllowance;
    monthlyFunds = netFunds / 12.0;
    monthlyIncome = monthlyFunds + grants;
    monthlyBudget = monthlyIncome;

    // Calculate essentials
    essentialsTotal = rent + utilities;
    monthlyEssentialsAvail = monthlyBudget - essentialsTotal;
    expensesRemaining = monthlyBudget - expensesTotal;
    monthlyWants = 0; // You may need to implement logic to calculate monthly wants
    monthlySavings = expensesRemaining - monthlyWants;

    // Print the financial table and summary
    printTable(savings, grants, netFunds, monthlyFunds, monthlyIncome, monthlyBudget, rent, utilities,
        expenseNames, expenseCosts, numExpenses, essentialsTotal, monthlyEssentialsAvail,
        expensesRemaining, monthlyWants, monthlySavings);

    printSummary(expensesRemaining, 0, monthlySavings); // You may need to add logic for wantsAvailable

    return 0;
}
