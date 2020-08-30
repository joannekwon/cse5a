/*
 Assignment 2        p2.c        Due August 16, 2017
 login #: cs5vam
 
 This program reads in the users input of kilograms and step factor. Then, the program converts kilograms at each step to pound and stone using a while, for, and do loop.
 
 Type char is used for dingle character answer of 'y' or 'n' to repeat the program. Type integer is used for the count. Type double is used to store the users input of kilogram, step, kilogram, pound, and stone.
 
 Symbolic constant "KG_TO_LBS" is used for conversion from kilogram to pounds. Symbolic constant "LB_TO_STONE" is used for conversion from pound to stone.

 Uses the formulas of "pounds = kilograms * 2.2" and "stones = pounds * 14)" to convert kilogram to pound and stone.
*/

#include <stdio.h>
#define KG_TO_LBS 2.2 //symbolic constant for conversion factor
#define LB_TO_STONE 14 //symbolic constant for conversion factor

int main (void)
{
    char answer = 'n'; //later used when asking to repeat program
    int count; //later used to reinitialize starting "count"
    double input_kg; //input weight in kilogram
    double step; //step factor to next weight
    double kg; //weight in kilogram
    double lb; //weight in pound
    double stone; //weight in stone
    
    printf ("This program prints a table of weights in kg, lbs, and stones.\n"); //output what the program does
    printf ("\n");
    
    do
    {
        do
        {
            printf ("Enter a positive real number in kilograms: "); //output asking for a positive real number in kg
            scanf ("%lf", &input_kg); //read type double input
            getchar(); //read <ENTER> key
        }while (input_kg < 0); //loop occurs when the input kg is a negative number
    
        do
        {
            printf ("Enter a positive real number step factor: "); //output asking for a positive real number for step factor
            scanf ("%lf", &step); //read type double input
            getchar(); //read <ENTER> key
        }while (step < 0); //loop occurs when the input step is a negative number
         printf ("\n");
        
        //WHILE LOOP
        count = 0; //reinitialize starting count
        kg = input_kg;
        printf (" KILOGRAMS     POUNDS         STONES\n"); //outputs labels for kg, lb, and stone
        printf (" =========     =======       ========\n"); //outputs equal signs used for organization
        
        while (count < 5)
        {
            lb = kg * KG_TO_LBS; //calculates pounds
            stone = lb * LB_TO_STONE; //calculates stones
            printf ("%7.2lf %14.2lf %14.2lf\n", kg, lb, stone); //creates spacing/organization of kg, lb, and stone
            kg+= step; //kilogram equals kilogram plus step
            ++count; //add one to count
        }
        printf ("\n");
        
        //FOR LOOP
        count = 0; //reinitialize starting count
        kg = input_kg;
        printf (" KILOGRAMS     POUNDS         STONES\n"); //outputs labels for kg, lb, and stone
        printf (" =========     =======       ========\n"); //outputs equal signs used for organization
    
        for (count = 0; count <5; ++count)
        {
            lb = kg * KG_TO_LBS; //calculates pounds
            stone = lb * LB_TO_STONE; //calculates stones
            printf ("%7.2lf %14.2lf %14.2lf\n", kg, lb, stone); //creates spacing/organization of kg, lb, and stone
            kg+= step; //kilogram equals kilogram plus step
        }
         printf ("\n");
        
        //DO LOOP
        count = 0; //reinitialize starting count
        kg = input_kg;
        printf (" KILOGRAMS     POUNDS         STONES\n"); //outputs labels for kg, lb, and stone
        printf (" =========     =======       ========\n"); //outputs equal signs used for organization
        
        do
        {
            lb = kg * KG_TO_LBS; //calculates pounds
            stone = lb * LB_TO_STONE; //calculates stones
            printf ("%7.2lf %14.2lf %14.2lf\n", kg, lb, stone); //creates spacing/organization of kg, lb, and stone
            kg+= step; //kilogram equals kilogram plus step
            ++count; //add one to count
        }while (count < 5); //loop occurs when count is less than five and stops once count is greater than or equal to five
    
        printf ("Want to convert more Kilograms (y/n)? "); //output asking if user wishes to convert more kg
        answer = getchar(); //user input 'y' or 'n'
        printf ("\n");
    }while (answer == 'y'); //loop occurs when user input 'y' and ends when user input 'n'
    
    return 0;
}
