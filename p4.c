/* 
 Assignment 4          p4.c        August 23, 2017
 login #: cs5vam
 
 This program uses functions to display the users total price for a pizza order. The program displays a menu with the size and price. The program reads in the users input of the size and quantity of pizza wanted and then displays the dollar amount of their order. This program repeats until the user enters 'N' or 'n'.
 
 Type char is used for single character answer of 'y' or 'n' to repeat the program. Type integer is used to hold the size, quantity, choice and amount. Type double is used for price, subTotal and total, which is later used to calculate the total price.
 
 Symbolic constant "SMALL" is used as the price for a small pizza. Symbolic constant "MEDIUM" is used as the price for a medium pizza. Symbolic constant "LARGE" is used as the price for a large pizza. Symbolic constant "XLARGE" is used as the price for a x-large pizza. Symbolic constants "SM", "MD", "LG", "XLG" are used as options for size. Symbolic constants "MIN" and "MAX" are used for the quantity of pizzas.
 */

#include <stdio.h>
#define SMALL 14.29 //price for small
#define MEDIUM 19.09 //price for medium
#define LARGE 24.40 //price for large
#define XLARGE 39.70 //price for x-large
#define SM 1 //option for small
#define MD 2 //option for medium
#define LG 3 //option for large
#define XLG 4 //option for x-large
#define MIN 1 //minimum option for amount
#define MAX 10 //maximum option for amount


//function for menu
void menu (void)
{
    printf ("  **** PIZZA++  2 Toppings ****\n");
    printf ("     1) Small         $14.29   \n");
    printf ("     2) Medium        $19.09   \n");
    printf ("     3) Large         $24.40   \n");
    printf ("     4) X-Large       $39.70   \n");
    printf ("  *****************************\n");
    
}


//function for calculating price
double pay (int choice, int amount)
{
    double total; //price of single order
    
    if (choice == SM)
        total = SMALL * amount;
    else if (choice == MD)
        total = MEDIUM * amount;
    else if (choice == LG)
        total = LARGE * amount;
    else if (choice == XLG)
        total = XLARGE * amount;
    
    return total; //returns calculated price for single order
}


int main (void)
{
    char answer = 'y'; //later used when asking to repeat program
    int size, quantity; //user input of size, user input of quantity
    double price, subTotal; //total price, value from pay function
    
    do
    {
        menu(); //calls menu function
        do
        {
            printf ("  Enter your choice (1 2 3 4): ");
            scanf ("%d", &size); //user input
            getchar(); //read <ENTER> key
            
            if (size < SM || size > XLG) //makes sure user inputs number between 1 and 4
                printf ("ERROR: Choose ONLY (1-4)!\n"); //output error
        }while (size < SM || size > XLG); //repeats if input isn't between 1 and 4
    
        do
        {
            printf ("  Enter quantity (1-10):       ");
            scanf ("%d", &quantity); //user input
            getchar(); //read <ENTER> key
            
            if (quantity < MIN || quantity > MAX) //makes sure user inputs number between 1 and 10
                printf ("ERROR: Choose ONLY (1-10)!\n"); //output error
        }while (quantity < MIN || quantity > MAX); //repeats if input isnt between 1 and 10
    
        subTotal = pay(size, quantity); //assigns value from pay function to subTotal
        price += subTotal; //adds subTotal to overall price
        
        printf ("  Your TOTAL is:               $%0.2lf\n", price); //outputs total price of order
    
        printf ("  Want more pizza (y/n)?       "); // output asking if user wishes to order more
        answer = getchar(); //user input 'y' or 'n'
        printf ("\n");
    }while (answer != 'N' && answer != 'n'); //loop stops when user inputs 'n' or 'N'
    return 0;
}
