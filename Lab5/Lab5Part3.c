#include <stdio.h>

//function to obtain user input for date
void inputDate(int *day, int *month, int *year) {
    printf("Please enter a date: ");
    scanf("%d/%d/%d",day,month, year);
}
//function to calculate the day of the week that the day inputted occured in
void calculateDay(int day, int month, int year) {
    
    //declares integers
    int A, B, C, D, R, W ,X ,Y ,Z;
    B = day;
    C = year % 10;
    D = year/100;
    
    //Sets the numeric value for the months of March-December
    if (month>  2) {
        A = month - 2;
    }
    //Sets the numeric value for the months of January and February
    else {
        A = month + 10;
        C--;
        //When the year ends in "00", the year decreases by 1 and ends in "99" abd the century decreases by 1
        if (C < 0){
            C = C + 100;
            D = D - 1;
        }
    }
    
    //Calculations for the algorithms
    W = (13 * A - 1)/5;
    X = C / 4;
    Y = D / 4;
    Z = W + X + Y + B + C - 2 * D;
    R = Z % 7;
    
    if (R < 0) {
        R = R + 7;
    }
    
    //conditions for the different days of the week with print statements for the output
    if (R==0) {
        printf("The day %d/%d/%d is a Sunday.\n",day,month,year);
    }
    
    if (R==1) {
        printf("The day %d/%d/%d is a Monday.\n",day,month,year);
    }
    
    if (R==2) {
        printf("The day %d/%d/%d is a Tuesday.\n",day,month,year);
    }
    
    if (R==3) {
        printf("The day %d/%d/%d is a Wednesday.\n",day,month,year);
    }
    
    if (R==4) {
        printf("The day %d/%d/%d is a Thursday.\n",day,month,year);
    }
    
    if (R==5) {
        printf("The day %d/%d/%d is a Friday.\n",day,month,year);
    }
    
    if (R==6) {
        printf("The day %d/%d/%d is a Saturday.\n",day,month,year,R);
    }
}

int main() {
    
    int day,month,year;
    inputDate(&day,&month,&year);
    calculateDay(day,month,year);
    return 0;
    
}