/* 
 Assinment 3        p3.c            Due: August 19, 2017
 login #: cs5vam
 
 This program reads in the users input of a whole number from 1 through 39. Then, the program displays the whole number in French text using the if-else statement and in Spanish using the switch statement. These calculations repeat until the user enters 'N' or 'n'.
 
 Type char is used for single character answer of 'y' or 'n' to repeat the program. Type integer is used for type number, ones, and tens.
 
 Symbolic constant "MIN" is used as the minimum input value. Symbolic constant "MAX" is used as the maximum input value. Symbolic constant "TEN" is used as a value of ten to calculate ones and tens place.
*/

#include <stdio.h>
#define MIN 1 //minimum input value
#define MAX 39 //maximum input value
#define TEN 10 //tens place

int main (void)
{
    char answer = 'y'; //later used when asking to repeat program
    int number; //input whole number
    int ones; //later used for ones place
    int tens; //later used for tens place
    
    printf ("This program converts cardinal numbers to French and Spanish.\n"); //output what the program does
    
    do
    {
        do
        {
            printf ("Enter a number (1-39) to display in French and Spanish text: "); //output asking for number between 1 and 39
            scanf ("%d", &number); //read type int input
            getchar(); //read <ENTER> key
        
            if (number < MIN || number > MAX) //makes sure the user inputs a number between 1 and 39
                printf ("ERROR: OUT of the RANGE of 1 through 39 \n"); //output error message
        }while (number < MIN || number > MAX); //repeats if number isn't between 1 and 39
        
        //if-else for french
        printf ("   In French  the number %d is ", number); //outputs language and number
        
        //printf for numbers that have differing names
        if (number == TEN)
            printf ("dix\n");
        else if (number == 11)
            printf ("onze\n");
        else if (number == 12)
            printf ("douze\n");
        else if (number == 13)
            printf ("treize\n");
        else if (number == 14)
            printf ("quatorze\n");
        else if (number == 15)
            printf ("quinze\n");
        else if (number == 16)
            printf ("seize\n");
        else if (number == 20)
            printf ("vingt\n");
        else if (number == 21)
            printf ("vingt-et-un\n");
        else if (number == 30)
            printf ("trente\n");
        else if (number == 31)
            printf ("trente-et-un\n");
        
        if ((number >= MIN && number <= 9) || (number >= 17 && number <= 19) || (number >= 22 && number <= 29) || (number >= 32 && number <= MAX)) //a condition that excludes numbers with differing names
        {
            tens = number / TEN; //calculates tens place
            //outputs for tens place
            if (tens == MIN)
                printf ("dix-"); //for numbers between 17-19
            else if (tens == 2)
                printf ("vingt-"); //for numbers between 22-29
            else if (tens == 3)
                printf ("trente-"); //for numbers between 32-39

            ones = number % TEN; //calculates ones place
            //outputs for ones place
            if (ones == MIN)
                printf ("un\n");
            else if (ones == 2)
                printf ("deux\n");
            else if (ones == 3)
                printf ("trois\n");
            else if (ones == 4)
                printf ("quatre\n");
            else if (ones == 5)
                printf ("cinq\n");
            else if (ones == 6)
                printf ("six\n");
            else if (ones == 7)
                printf ("sept\n");
            else if (ones == 8)
                printf ("huit\n");
            else if (ones == 9)
                printf ("neuf\n");
        }
        
        //switch statment for spanish
        printf ("   In Spanish the number %d is ", number); //outputs language and number
        
        //printf for numbers that have differing names
        if ((number >= TEN && number <= 15) || number == 20 || number == 30)
        {
            switch (number)
            {
                case 10:
                    printf ("diez\n");
                    break;
                case 11:
                    printf ("once\n");
                    break;
                case 12:
                    printf ("doce\n");
                    break;
                case 13:
                    printf ("trece\n");
                    break;
                case 14:
                    printf ("catorce\n");
                    break;
                case 15:
                    printf ("quince\n");
                    break;
                case 20:
                    printf ("veinte\n");
                    break;
                case 30:
                    printf ("treinta\n");
                    break;
            }
        }
        else
        {
            tens = number / TEN; //calculates tens place
            //outputs for tens place
            if (tens == MIN)
                printf ("dieci"); //for numbers between 16-19
            else if (tens == 2)
                printf ("veinti"); //for numbers between 21-29
            else if (tens == 3)
                printf ("treinta y "); //for numbers between 31-39
            
            ones = number % TEN; //calculates ones place
            //outputs for ones place
            switch (ones)
            {
                case 1:
                    printf ("uno\n");
                    break;
                case 2:
                    printf ("dos\n");
                    break;
                case 3:
                    printf ("tres\n");
                    break;
                case 4:
                    printf ("cuatro\n");
                    break;
                case 5:
                    printf ("cinco\n");
                    break;
                case 6:
                    printf ("seis\n");
                    break;
                case 7:
                    printf ("siete\n");
                    break;
                case 8:
                    printf ("ocho\n");
                    break;
                case 9:
                    printf ("nueve\n");
                    break;
            }
        }
        
        printf ("Want to convert another number (y/n)? "); //output asking if user wishes to convert another number
        answer = getchar(); //user input 'y' or 'n'
        printf ("\n");
    }while (answer != 'N' && answer != 'n'); //loop stops when user inputs 'n' or 'N'
    
    return 0;
}
