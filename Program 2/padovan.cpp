// Reed Hartman
// CMPS 2433
// Catherine Stringfellow
// Program 2 Assignment

// libraries, input/output file reader/writer, console formating
#include <iostream> // console input/output
#include <iomanip> // text formatting
#include <fstream> // open input/output files
#include <string> // strings
using namespace std;

// [Function prototypes]
void debugOpenFiles(ifstream& infile, ofstream& outfile);

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
    debugOpenFiles(infile, outfile);
    
    // main program loop, priming while !eof loop
    while (!infile.eof())
    {
        string line; // note that line is a string since getline() doesn't return integers.
        getline(infile, line); // reads current line of the input file.
        int num = stoi(line); // convert string from getline() to integer, personal note: stoi means "string to integer"
        // note: I thought about overloading getline to return integers instead of strings, but this was the easiest solution.
        // note: maybe I will put this into a function add an exception case if the stoi cannot convert to an integer, to make it a "proper function".
        cout << num << " " << padovanSequence(num) << " " << iterPadovanSequence(num) << endl; // basically the answer right there, but still needs formatting
    }
    closeFiles(infile, outfile);    

    return 0;
}

// we at the function
/* list of functions in this file:
   1. debugOpenFiles
   2. openFiles
   3. closeFiles
   4. padovanSequence
   5. iterPadovanSequence
   6. padovanSum
*/

void debugOpenFiles (ifstream& infile, ofstream& outfile)
{
    infile.open("padovan.txt");
    outfile.open("output.txt");
}

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