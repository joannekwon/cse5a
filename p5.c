/*
 Assignment 5        p5.c        August 30, 2017
 login #: cs5vam
 
 This program uses a function to display the users input of 3 numbers from 1 to 100. This program reads in the users input and displays the 3 numbers in the order it was inputted, ascending order, and decending order. The code continues until the user enters 'N' or 'n'.
 
 Type char is used  for single character answer of 'y' or 'n' to repeat the program. Type integer is used for score1, score2, score3, tmp, *s1, and *s2.
 
 Symbolic constant "MIN" is used as the minimum input value. Symbolic constant "MAX" is used as the maximum input value.
 */

#include <stdio.h>
#define MIN 0 //minimum value
#define MAX 100 //maximum value

/*
 The swap function switches the values of runner scores using pointers. The parameters include *s1 and *s2. First, the function places the value of *s1 into the tmp. Then it is set to equal the value of *s2. Lastly, *s2 is then set to equal tmp, which was the previous value of *s1. In the end, the valu of *s1 becomes *s2 and the value of *s2 becomes *s1.
 */
void swap (int *s1, int *s2)
{
    int tmp; //temporary placement
    
    tmp = *s1; //tmp holds value of *s1
    *s1 = *s2; //*s1 is set to the value of *s2
    *s2 = tmp; //*s2 is set to the value of tmp
}


int main (void)
{
    char answer = 'y'; //later used when asking to repeat program
    int score1; //user input first score
    int score2; //user input second score
    int score3; //user input third score
    
    do
    {
        do
        {
            printf ("   Enter 3 runner scores to sort (%d-%d): ", MIN, MAX);
            scanf ("%d %d %d", &score1, &score2, &score3); //user input
            getchar(); //read <ENTER> key
            
            if (score1 < MIN || score1 > MAX || score2 < MIN || score2 > MAX || score3 < MIN || score3 > MAX) //makes sure user inputs number between 0 and 100
                printf ("   ERR: Runner scores out of range (%d-%d)!\n\n", MIN, MAX); //output error
        }while (score1 < MIN || score1 > MAX || score2 < MIN || score2 > MAX || score3 < MIN || score3 > MAX); //repeats if input isn't between 0 and 100
        
        
        printf ("   Input Runner scores:     %d  %d  %d\n", score1, score2, score3); //outputs numbers in original order
        
        if(score1 > score2 || score1 > score3) //swap if score1 is greater than score2 or score3
            swap (&score1, &score2); //calls swap function (swap score1 and score2)
        if (score3 < score1) //swap if score3 is less than score1
            swap (&score3, &score1); //calls swap function (swap score3 and score1)
        if(score2 > score3) //swap if score2 is greater than score3
            swap (&score2, &score3); //calls swap function (swap score2 and score3)
        printf ("   ASCENDING ORDER:         %d  %d  %d\n", score1, score2, score3); //outputs numbers in ascending order
        
        
        if (score1 < score2 || score1 < score3) //swap if score1 is less than score2 or score3
            swap (&score1, &score2); //calls swap function (swap score1 and score2)
        if (score3 > score1) //swap if score3 is greater than score1
            swap (&score3, &score1); //calls swap function (swap score3 and score1)
        if (score2 < score3) //swap if score2 is less than score3
            swap (&score2, &score3); //calls swap function (swap score2 and score3)
        printf ("   DESCENDING ORDER:        %d  %d  %d\n", score1, score2, score3); //outputs numbers in descending order
        
        
        printf ("   Want to sort more Runner scores? ");
        answer = getchar(); //userinput 'y' or 'n'
        printf ("\n");
    }while (answer != 'N' && answer != 'n'); //loop stops when user inputs 'n' or 'N'*/
    return 0;
}

//layout messed up when multiple place digets
//do we need header comments for int main?
