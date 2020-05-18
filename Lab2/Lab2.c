/* File: Lab2
 * Author: Abdurafay Khan
 * Date: January 23th, 2019
 * Description: Calculates and displays the monthly payments reqquired to pay off a loan with a given interest in a given period of time
 */
#include <stdio.h>
#include <math.h> //loads the library that contains various math functions that will be needed for the code
 
int main()
{
    double principle, interest, monthlyPayment, monthlyInterest, totalCost; 
    int numberOfMonths;
    
    printf("Enter the purchase price of the item: ");
    scanf("%lf", &principle);                                                                     //Takes in the principle value from the user
    
    printf("Enter the interest rate per year as a percentage: ");
    scanf("%lf", &interest);                                                                      //Takes in the interest rate from the user
    
    printf("Enter the number of months for repayment: ");
    scanf("%d", &numberOfMonths);                                                                 //Takes in the number of months value from the user
    
    monthlyInterest=interest/1200;                                                                //divide yearly interest in percentage by 1200 to get monthly interest in decimal
    monthlyPayment=((monthlyInterest)/(1-(pow(1+monthlyInterest,-numberOfMonths)))*principle);    //calculates monthlyPayment
    totalCost=monthlyPayment*numberOfMonths;                                                      //Calculates total cost using the monthly payment value and the number of months value
    
    printf("The monthly payment is: %0.2lf\n",monthlyPayment); 
    printf("The total cost of the purchase is: %0.2lf\n",totalCost);
    return 0;
}
