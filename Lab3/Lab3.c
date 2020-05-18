#include <stdio.h>

int main()
{
    double coffeeCost,spendingMoney,totalCoffeeCost,remainingBalance,average;
    int numOfCoupons,numOfInitialCoffee,numOfFreeCoffee,totalCoffee,totalCoupons;
    
    
    //User inputs how much a coffee costs
    printf("How much does a coffee cost?\n");
    scanf("%lf",&coffeeCost);
    
    //Determines if the cost of coffee input is valid
    if (coffeeCost>=0.01) {
        
        //User inputs how many coupons are needed for a free coffee
        printf("How many coupons does it take to get a free coffee?\n");
        scanf("%d",&numOfCoupons);
        

        //Determines if number of coupons for a free coffee input is valid
        if (numOfCoupons>1 && numOfCoupons%1==0) {
            
            //User inputs the amount of money they have to spend on coffee for the month
            printf("How much money do you have to spend on coffee this month?\n");
            scanf("%lf",&spendingMoney);
            
            //Determines if the users monthly spending input is valid
            if (spendingMoney>0) {

                //Calculates how many coffees can be bought with the monthly money allocation
                numOfInitialCoffee=spendingMoney/coffeeCost;
    
                //Calculates total money spent on cofee
                totalCoffeeCost=numOfInitialCoffee*coffeeCost;
                remainingBalance=spendingMoney-totalCoffeeCost;
                
                totalCoupons=numOfInitialCoffee;
                numOfFreeCoffee=0;
                
                while(totalCoupons>=numOfCoupons) {
                    totalCoupons=totalCoupons-numOfCoupons;
                    numOfFreeCoffee+=1;
                    totalCoupons+=1;
                }
                
                //Total Coffee is calculated using the number of inital coffees bought, those from coupons and those after additional coupons are received
                totalCoffee=numOfInitialCoffee+numOfFreeCoffee;
                
                //Calculate average
                average=totalCoffeeCost/totalCoffee;
                
                printf("This month, you can purchase %d coffees at $%0.2lf each.\n",numOfInitialCoffee,coffeeCost);
                
                if (numOfFreeCoffee>0) {
                    printf("You will be able to redeem an additional %d coffee(s) from coupons.\n",numOfFreeCoffee);
                }
                else {
                    printf("You will not be able to redeem any additional coffees from coupons this month.\n");
                }
                printf("At the end of the month, you will have $%0.2lf and %d coupon(s) remaining.\n",remainingBalance,totalCoupons);
                printf("On average, you spent $%0.2lf on each cup of coffee this month.\n",average);
                
            }
            //prints a statement if the monthly spending input is invalid
            else {
                printf("Invalid Input.\n");
            }
        }
        //prints a statement if the number of coupons for a free coffee input is invalid
        else {
            printf("Invalid Input.\n");
        }
    }
    //prints a statement if the cost of coffee input is invalid
    else {
        printf("Invalid Input.\n");
    }
    return 0;
    
}
