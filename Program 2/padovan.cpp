// Reed Hartman
// CMPS 2433
// Catherine Stringfellow
// Program 2 Assignment

// libraries, input/output file reader/writer, console formating
#include <iostream> // console input/output
#include <iomanip> // text formatting
#include <fstream> // open input/output files
using namespace std;

#define BASE 1;

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
int padovanSum(int n);

int main ()
{
    for (int n = 0; n <= 50; n++)
    {
        cout << padovanSequence(n) << ", ";
    }
    cout << endl;
    for (int n = 0; n <= 50; n++)
    {
        cout << iterPadovanSequence(n) << ", ";
    }
    cout << endl << "sum: " << padovanSum(50) << endl;
    return 0;
}

int padovanSequence(int n){
    if (n <= 2)
        return BASE; // value of P(0), P(1), & P(3)
    return padovanSequence(n - 2) + padovanSequence(n - 3); // recursive computation
    // P(n) = P(n-2) + P(n-3)
}

int iterPadovanSequence(int n){

    if (n <= 2) // base cases
        return BASE;

    // hardcoded base cases
    int p0 = 1, p1 = 1, p2 = 1;
    int result = 0; // iterative output
    
    // calculate padovan sequence iteratively
    for (int i = 3; i <= n; ++i)
    {
        result = p0 + p1; // P(n) = P(n-2) + P(n-3)
        p0 = p1;
        p1 = p2;
        p2 = result;
    }
    return result;
}

int padovanSum(int n){
    int sum = 0;
    for (int a = 0; a <= n; a++)
    {
        sum += padovanSequence(a);
    }
    return sum;
}