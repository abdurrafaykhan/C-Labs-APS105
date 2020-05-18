/* File: Lab0
 * Author: Abdurafay Khan
 * Date: January 16th, 2019
 * Description: Calculates and displays the product, difference and sum of roots of two positive numbers inputted 
 */

#include <stdio.h> //loads the library that contains general functions that are required for a C code
#include <Math.h>  //loads the library that contains various math functions that will be needed for the code

int main()  //Signifies what code is to be executed
{
    double inputNumber1, inputNumber2, product, difference, sumOfRoots;  //Creates a list of variables as doubles that represent the input numbers as well as the product, difference and the sum of roots of the numbers
    printf("Enter two positive numbers: "); //Prints a statement that directs the user to input two positive numbers
    scanf("%lf %lf",&inputNumber1, &inputNumber2);  //Assigns the two inputted numbers by the user to the two respective variables
    product=inputNumber1*inputNumber2;   //Calculates the product of the two inputted numbers
    difference=inputNumber1-inputNumber2;  //Calculates the difference between the two inputted numbers
    sumOfRoots=(sqrt(inputNumber1)+sqrt(inputNumber2));  //Calculates the sum of the roots of each inputted numbers
    printf("The product is: %0.2lf, the difference is: %0.2lf and the sum of roots is: %0.2lf.",product,difference,sumOfRoots);  //Prints a statement that displays the product, difference and sum of roots of the inputted numbers
    return 0; //exits the main function
}
