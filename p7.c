/*
Assignment 7        p7.c        September 6, 2017
login #: cs5vam

This program uses character strings, functions, and pointer notation to reverse the user's input string. This program uses the function strRev to reverse the input string by using pointer notation and a local temporary character string called tmpStrg. tmpStrg can hold the input sentence. The code loops until the user enters 'N' or 'n'.
 
 Type char is used for *pS, *s1, *s2, tmpStrg, inputStr, s, len, and a single character answer of 'y' or 'n' to repeat the program.Type integer is used for i, j, and len.
 
 Symbolic constant "MAX_STR" is used as the maximum value of 81 for the string. The symbolic constant "ZERO" is used as the numerical value of 0. The symbolic constant "ONE" is used as the numerical value of 1. The symbolic constant "TWO" is used as the numerical value of 2.
*/


#include <stdio.h>
#include <string.h>
#define MAX_STR 81 //maximum value of 81 for string
#define ZERO 0 //numerical value of 0
#define ONE 1 //numerical value of 1
#define TWO 2 //numerical value of 2


/*
 The function strRev is used to reverse the input string by using pointer notation and a local temporary character string called tmpStrg. The temporary character, tmpStrg, holds the input sentence. The function starts with a while loop that increments str until the value no longer equals null. Then len is set to str and s1 and s2 are set to pS. Then there is a for loop that increments s2 when i is less than length minus one. Then there is a for loop that switches values until
*/
void strRev (char *pS)
{
    int i, len; //used for loops, string length, length
    int str = strlen(pS);
    char *s1, *s2, tmpStrg; //beginning of string, end of string, temporary placement
     
    len = str; //len set to str
    s1 = pS; //s1 set to pS
    s2 = pS; //s2 set to pS
    
    for (i=ZERO; i<len-ONE; ++i) //increments s2 if i is less than len minus one; increments i each loop
        ++s2; //increment by 1
     
    for (i=ZERO; i<len/TWO; ++i) //switches values until reaches half of the loop; incrememtns i each loop
    {
        tmpStrg = *s2; //tmpStrg holds value of *s2
        *s2 = *s1; //*s2 is set to the value of *s1
        *s1 = tmpStrg; //*s1 is set to the value of tmpStrg
        ++s1; //increment by 1
        --s2; //decrement by 1
    }
}


/*
 The function main asks the user to input a sentence. fgets reads in an entire line of input while "MAX_STR" is used as a maximum space of 81. The function, then, prints the original string and then calls the function strRev. The function prints the reversed string. A character string is terminated with the end of string sentinel (null character) and the original string is modified. The function ends when the user inputs 'N' or 'n'.
 */
int main (void)
{
    char inputStr[MAX_STR]; //holds input string
    char s[MAX_STR]; //holds input stripped of newline
    char len, answer = 'y'; //used for newline, used when repeating program
    
    do
    {
        printf ("Enter a sentence: "); //read input line including newline
        fgets (inputStr, MAX_STR, stdin); //length of input string including newline
        len = strlen (inputStr);
        
        strncpy (s, inputStr, len-ONE); //stripped ending newline char
        s[len-ONE] = '\0'; //delimit with null char
        
        printf ("\"%s\"", s); //prints original string
        strRev(s); //calls the function strRev
        printf (" reversed is \"%s\"",s); //prints reversed string
    
        printf ("\nWant to reverse another sentence? ");
        answer = getchar(); //user input 'y' or 'n'
        getchar();
        printf ("\n");
    }while(answer != 'N' && answer != 'n'); //loop repeats when input N or n
    return 0;
}
