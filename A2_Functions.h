
/*A2_Functions.h
 * DO NOT MODIFY THIS FILE
 * DO NOT SUBMIT THIS FILE
 * When testing we will supply our own .h file.
 * If you have modified this in any way, your code may not function 
 * correctly during grading.
 * 
 * This is the header file for the functions in CIS1500 F23 A2
 * You will need to copy the function prototypes below to create
 * your function definitions. 
 * Do not change the headers, or we will not be able to test them. 
 * */




#ifndef A2_FUNCTIONS_H_
#define A2_FUNCTIONS_H_

#define MAX_STRING_LEN 100 // use this for any string lengths
#define MAX_NUM_EXPENSES 100 // use this as the maximum array size for expense arrays

// Function Prototypes
int getIntInput(char prompt[]);
float getFloatInput(char prompt[]);
char getCharInput(char prompt[], char valid_inputs[], int num_valid);

float getWeeklyPay();
float getAnnualAllowance();
void getHousing(float *rent, float *utilities);
void getExpenses( char expense_names[MAX_NUM_EXPENSES][MAX_STRING_LEN],
    			float expense_costs[MAX_NUM_EXPENSES],
    			int *num_expenses,
    			float *expenses_total);

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
                float monthly_savings
                );
void printSummary(float expensesRemaining, float wantsAvailable, float savingsAvailable);

#endif
