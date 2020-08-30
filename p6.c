/* 
Assignment 6        p6.c        September 2, 2017
login #: cs5vam

 This program uses one-dimensional arrays and functions. The program uses the functions getScores, prtScores, average, bubbleSort, and swap to calculate and display the average of a set of midterm scores, the highest score, and arrange the midterm scores in descending order using array and pointer notation. The code continues until the user enters 'N' or 'n'.
 
 Type char is used for single character answer of 'y' or 'n' to repeat the program. Type integer is used for i, tmp, sum, a[], *p, *q, and j. Type short was used for i. 
 
 Symbolic constant "NUM_SCORE" is used to represent the 5 elements. The symbolic constant "MIN_SCORE" is used as the minimum input value. "MAX_SCORE" is used as the maximum input value. Symbolic constant "ONE" is used as the numerical value of 1.
*/


#include <stdio.h>
#define NUM_SCORE 5 //5 elements
#define MIN_SCORE 0 //minimum input value
#define MAX_SCORE 103 //maximum input value
#define ONE 1 //numerical value of one


/*
 The fuction getScoresreads input into the 1-dimensional array. The parameters include a[]. This function displays an error message if the integer input value isn't between 0-103. A loop repeats the prompt until all five input numbers are valid. The function also reads input into a temporary variable to test and see if the input values are valid.
 */
void getScores (int a[])
{
    int i, tmp;
    
    do
    {
        tmp = 1; //later used to see if do loop needs to loop again
        printf ("\n");
        printf ("Enter %d midterm scores (%d-%d): ", NUM_SCORE, MIN_SCORE, MAX_SCORE);
        for(i=MIN_SCORE; i<NUM_SCORE; ++i) //for loop used to store each value
        {
            scanf ("%d", &a[i]); //stores values
            if (a[i] < MIN_SCORE || a[i] > MAX_SCORE) //checks to see if input values are between 0 and 103
            {
                tmp++; //adds to tmp
                printf ("ERROR! Enter valid scores in the range (%d-%d)\n", MIN_SCORE, MAX_SCORE);
            }
        }
        getchar();
    }while(tmp != 1); //loops if for loop adds 1 to tmp, therefore, making tmp not equal 1
}


/*
 The function prtScores uses pointer notation to display the values of the 1-dimensional array. The parameters include *p. This function uses a for loop. The loop says i is equal to 0 and if i is less than NUM_SCORE, then it prints the input. After each loop, 1 is added to i.
 */
void prtScores (int *p)
{
    short i;
    
    for (i=MIN_SCORE; i<NUM_SCORE;++i) //for loop used to display each value
        printf ("%d ", *(p+i)); //prints scores
    printf ("\n");
}


/*
 The function average uses array notation to calculate the average of all the scores. The paramter includes a[]. This function uses a for loop. The loop says i is equal to 0 and if i is less than the NUM_SCORE, the value is added to sum. After each loop, 1 is added to i. Once, the function finishes looping it takes the sum and divides it by NUM_SCORE. The result is then returned.
 */
double average (int a[])
{
    int i;
    double sum = MIN_SCORE;
    
    for (i=MIN_SCORE; i< NUM_SCORE; ++i) //for loop used to add values
        sum = sum +a[i]; //adds values for sum
    return (sum/NUM_SCORE); //returns the sum of values
}


/*
 The swap function switches the values of runner scores using pointers. The parameters include *p and *q. First, the function places the value of *p into the tmp. Then it is set to equal the value of *q. Lastly, *s2 is then set to equal tmp, which was the previous value of *p. In the end, the valu of *p becomes *q and the value of *q becomes *p.
 */
void swap (int *p, int *q)
{
    int tmp; //temporary placement
    
    tmp = *p; //tmp holds value of *p
    *p = *q; //*p is set to the value of *q
    *q = tmp; //*q is set to the value of tmp
}


/*
 The bubbleSort function uses the "bubble sort" algorithm to bubble up the largest value into the first element. The parameters include a[]. The function loops to check is one input number is larger than the other. If so, the function calls the swap function to switch the order of the number.
 */
void bubbleSort (int a[])
{
    int i,j;
    
    for (i=MIN_SCORE; i <NUM_SCORE-ONE; ++i) //for loop used to go through each value
        for(j=NUM_SCORE-1; i<j;--j)//for loop used to go through each value
            if(a[j-1]<a[j]) //if one values is less than another, then calls the swap function
                swap(&a[j-ONE], &a[j]); //calls swap function to switch values
}


/*
 The function main calls the functions bubbleSort, average, prtScores, and getScores to output the average of all five input scores, the order, and highest score. The function also uses an if statement to make sure that the initialized integer array only outputs once by incrementing the integer tmp.
 */
int main (void)
{
    char answer = 'y';
    int a[NUM_SCORE] = {72, 78, 82, 88, 99}; //initialized integer array
    int tmp = 1; //later used to see if do loop needs to loop again
    
    do
    {
            if(tmp == 1) //initialized integer array only outputs once because tmp is incremented
            {
                printf ("        Array:          ");
                prtScores(a); //calls function prtScores
                ++tmp; //adds to tmp
            }
            else
            {
                getScores(a); //calls function prtScores
            }
        printf ("        Average:        %0.2lf\n", average(a)); //output average of values
        bubbleSort(a); //calls function bubbleSort
        printf ("        Sorted:         ");
        prtScores(a); //calls function prtScores
        printf ("        Highest:        %d", a[MIN_SCORE]); //outputs first value in array
        printf ("\n");
        
        printf ("Want to calculate midterm score? ");
        answer = getchar(); //user input 'y' or 'n'
    }while(answer != 'N' && answer != 'n'); //loop repeats when input N or n
    return 0;
}
