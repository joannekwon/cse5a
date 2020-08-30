/*
Assignment 1           p1.c            Due: August 12, 2017
login #: cs5vam
This program reads in student's information of: birth year, GPA, and leter grade using int, double, and char data types.
Age is calculated from birth year.

Type integer is used for the variables to hold the age and year values. Type double is used to store the GPA.
Type char is used for the isngle character letter grade.

Symbolic constant "THIS_YEAR" is used for current year.
*/

#include <stdio.h>
#define THIS_YEAR 2017

int main (void)
{
    char grade; //student's grade
    int birthyear; //student's year of birth
    int age; //student's age
    double gpa; //student's gpa
    
    printf ("Enter your grade in the class: ");
    grade = getchar(); //read single character input
    
    printf ("Enter your birthyear: ");
    scanf ("%d", &birthyear); //read integer input
    getchar(); //read <ENTER> key
    
    age = THIS_YEAR - birthyear; //calculates age
    
    printf ("Enter your GPA (Grade Point Average): ");
    scanf ("%lf", &gpa);
    getchar();
    
    printf("I am 20 years old with a GPA of %5.3lf and a class grade of %c.\n",gpa, grade);
    
    printf ("In %d I will be %d. ", THIS_YEAR+1, ++age );
    printf ("If I study hard, I will get an epic grade of %c++.\n", grade);
    getchar();
    
    return 0; //freeze output screen
}
