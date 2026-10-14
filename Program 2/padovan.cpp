// Reed Hartman
// CMPS 2433
// Catherine Stringfellow
// Program 2 Assignment

// libraries, input/output file reader/writer, console formating
#include <iostream> // console input/output
#include <iomanip> // text formatting
#include <fstream> // open input/output files
using namespace std;

// list of stuff 
/*
 - I probably do not need arrays for this assignment.
 - the Padovan sequence goes:
   1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 
   21, 28, 37, 49, 65, 86, 114, 151, 200, 265
*/

// recursive example of the sequence
int padovanSequence(int n);
int iterPadovanSequence(int n);

int main ()
{
    for (int n = 0; n <= 15; n++)
    {
        cout << padovanSequence(n) << ", ";
    }
    for (int n = 0; n <= 5; n++)
    {
        cout << iterPadovanSequence(n) << ", ";
    }
    return 0;
}

int padovanSequence(int n){
    if (n <= 2) {return 1;}
    else        {return padovanSequence(n - 2) + padovanSequence(n - 3);}
}

int iterPadovanSequence(int n){
    
}