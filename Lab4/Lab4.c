#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

//Function that determines if the user inputs are valid
bool validateInput(double leftBoundary, double rightBoundary, int numOfRectangles) {
    
    //uses condition to print a statement to exit the program
    if (leftBoundary == 0 && rightBoundary == 0 && numOfRectangles == 0) {
        printf("Invalid inputs...\n\nTerminating main!\n");
        exit (0);
    }
    
    //uses condition to print a statement if the inputs are invalid
    else if (leftBoundary <- 10 || rightBoundary > 10 || leftBoundary >= rightBoundary || numOfRectangles<=0) {
        printf("Invalid Inputs ...\n\n");
        return false;
    }
    
    //returns true if the inputs are valid so proceed with the code in the main function
    else {
        return true;
    }
}

//Function containing the function that will be integrated
double evalFunc(double x) {
    return (2 * pow(x,2) - 7 * x - 2);
}

int main() {
    
    //Decalares variables to be used in the code
    double leftBoundary, rightBoundary, deltaX, leftArea, xLeft, rightArea, xRight, midArea, xMid;
    int numOfRectangles, rectangleNumber;
    
    //Prints a statement directing user to input values and assigns the inputs to the respective variables
    printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\nTo exit enter 0 0 0\n");
    scanf("%lf %lf %d", &leftBoundary, &rightBoundary, &numOfRectangles);
    
    //This loop asks the user to input values until valid inputs are inputted
    while (validateInput (leftBoundary, rightBoundary, numOfRectangles)==false) {
        printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\nTo exit enter 0 0 0\n");
        scanf("%lf %lf %d", &leftBoundary, &rightBoundary, &numOfRectangles);
    }
    
    //Calculates delta x based off the bounds and number of rectangles inputted. Delta x is the width of each rectangle of the Riemann Sum
    deltaX = (rightBoundary - leftBoundary)/numOfRectangles;
    
    //initializes the area of the three methods of riemann sums to be 0
    leftArea = 0;
    rightArea = 0;
    midArea = 0;
    
    //Sets the left boundary as the intial x value for the left point evaluation
    xLeft = leftBoundary;
    //Loop to evaluate the rectangles of the riemann sums at all left points necessary using the rectangle number as a counter progressing from left to right
    for (rectangleNumber = 1; rectangleNumber <= numOfRectangles; rectangleNumber++) {
        leftArea = leftArea + deltaX * evalFunc(xLeft);
        xLeft = leftBoundary + rectangleNumber * deltaX;
    }
    
    //Sets the left boundary plus delta X as the intial x value for the right point evaluation
    xRight = leftBoundary + deltaX;
    //Loop to evaluate the rectangles of the riemann sums at all right points necessary using the rectangle number as a counter progressing from left to right
    for (rectangleNumber = 1; rectangleNumber <= numOfRectangles; rectangleNumber++) {
        rightArea = rightArea + deltaX * evalFunc(xRight);
        xRight = leftBoundary + deltaX + rectangleNumber * deltaX;
    }
    
    //Sets the left boundary plus half of delta X as the intial x value for the midpoint evaluation
    xMid = leftBoundary + 0.5 * deltaX;
    //Loop to evaluate the rectangles of the riemann sums at all midpoints necessary using the rectangle number as a counter progressing from left to right
    for (rectangleNumber = 1; rectangleNumber <= numOfRectangles; rectangleNumber++) {
        midArea = midArea + deltaX * evalFunc(xMid);
        xMid = leftBoundary + 0.5 * deltaX + rectangleNumber * deltaX;
    }
    
    //Series of print statements to output the step size of the Riemann Sum and the evalutations using the three different methods
    printf("With Step Size: %0.4lf\n", deltaX);
    printf("The approximate integral of the f(x) = 2(x^2)-7x-2\n");
    printf("Bound between %0.2lf and %0.2lf, using %d rectangles is as follows\n\n", leftBoundary, rightBoundary, numOfRectangles);
    printf("Mid point evaluation approximate: %0.4lf\n", midArea);
    printf("Left point evaluation approximate: %0.4lf\n", leftArea);
    printf("Right point evaluation approximate: %0.4lf\n", rightArea);
    
    return 0;
}