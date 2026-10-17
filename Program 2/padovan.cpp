// Reed Hartman
// CMPS 2433
// Catherine Stringfellow
// Program 2 Assignment

// libraries, input/output file reader/writer, console formating
#include <iostream> // console input/output
#include <iomanip> // text formatting
#include <fstream> // open input/output files
using namespace std;

// [Function prototypes]
void openFiles(ifstream& infile, ofstream& outfile);
/* Purpose: prompts which input/output files the program uses, doesn't close them.
   Recieves: infile, input file at direct address; outfile, output file at direct address.
   Returns: no return value
*/
 
void closeFiles(ifstream& infile, ofstream& outfile);
/* Purpose: closes input/output files. it closes files. the snoot drooped.
   Recieves: infile, input file at direct address; outfile, output file at direct address.
   Returns: no return value
*/

int padovanSequence(int n);
/* Purpose: recursively (with functions) calculates the n'th value in the padovan sequence.
   Recieves: integer n, the value of the n'th value in the padovan sequence.
   Returns: the n'th value in the padovan sequence, recursively.
*/

int iterPadovanSequence(int n);
/* Purpose: iteratively (with a loop) calculates the n'th value in the padovan sequence.
   Recieves: integer n, the value of the n'th value in the padovan sequence.
   Returns: the n'th value in the padovan sequence, iteratively.
*/

int padovanSum(int n);
/* Purpose: finds the sum of all integers leading up to and including the n'th value in the padovan sequence.
   Utilizes: the recusrive padovan sequence function, "int padovanSequence".
   Recieves: integer n, the value of the n'th value in the padovan sequence.
   Returns: the integer sum of all padovan numbers leading up the n'th number in the padovan sequence.
*/

#define BASE 1; // base value of the padovan sequence

int main()
{
    // input/output file control
    ifstream infile;
    ofstream outfile;
    openFiles(infile, outfile);
    
    // main program loop
    //   execute padovan sequence on dedicated input file
    //   output to both console and to dedicated output file
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
    closeFiles(infile, outfile);

    return 0;
}

// my functions!
/* list of functions in this file:
   1. openFiles
   2. closeFiles
   3. padovanSequence
   4. iterPadovanSequence
   5. padovanSum
*/

void openFiles (ifstream& infile, ofstream& outfile) // provided by instructor
{
    char inFileName[40];
    char outFileName[40];

    cout << "Enter the input file name: ";
    cin >> inFileName;
    infile.open(inFileName); // open input file

    cout << "Enter the output file name: ";
    cin >> outFileName;
    outfile.open(outFileName); // open output file

    outfile << "input file: " << inFileName << endl;
    outfile << "output file: " << outFileName << endl;
    outfile << endl;
}

void closeFiles (ifstream& infile, ofstream& outfile)
{
    infile.close();
    outfile.close();
    cout << "files closed\n";
    outfile << "files closed\n";
}

int padovanSequence(int n)
{
    if (n <= 2)
        return BASE; // value of P(0), P(1), & P(3)
    return padovanSequence(n - 2) + padovanSequence(n - 3); // recursive computation
    // P(n) = P(n-2) + P(n-3)
}

int iterPadovanSequence(int n)
{
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

int padovanSum(int n)
{
    int sum = 0;
    for (int a = 0; a <= n; a++)
    {
        sum += padovanSequence(a);
    }
    return sum;
}