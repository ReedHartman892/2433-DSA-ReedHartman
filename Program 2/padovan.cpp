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

// Function prototypes
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

long padovanSequence(int n);
/* Purpose: recursively (with functions) calculates the n'th value in the padovan sequence.
   Recieves: integer n, the value of the n'th value in the padovan sequence.
   Returns: the n'th value in the padovan sequence, recursively.
*/

long iterPadovanSequence(int n);
/* Purpose: iteratively (with a loop) calculates the n'th value in the padovan sequence.
   Recieves: integer n, the value of the n'th value in the padovan sequence.
   Returns: the n'th value in the padovan sequence, iteratively.
*/

long padovanSum(int n);
/* Purpose: finds the sum of all integers leading up to and including the n'th value in the padovan sequence.
   Utilizes: the recusrive padovan sequence function, "int padovanSequence".
   Recieves: integer n, the value of the n'th value in the padovan sequence.
   Returns: the integer sum of all padovan numbers leading up the n'th number in the padovan sequence.
*/

/* A known problem
   calculation time for the sum takes exponentially longer the higher the value of n is...
   times two because outing to an outfile and a console means all calculations run twice.
   The upper bound is around n = 70, past that point, computation takes too long.
   I don't know how to improve this, because it's a big-boy programmer problem. It might be fun to solve in my off-time.
   Internet reccomended it exists within the explicit formula for the padovan sum, which can hypothetically calculate
   the sum of the padovan sequence with a single computation instead of calculating it iteratively.
   But further sleuthing provided a very scary and precise-decimal calculation that I don't want to touch with a 50-foot pole.
*/

// program definitions
#define BASE 1; // base value of the padovan sequence

int main() // main program control
{
    // input/output file control
    ifstream infile;
    ofstream outfile;
    openFiles(infile, outfile); // open files
    
    // console/outfile stuff
    outfile << "Reed Hartman" << "\n";
    outfile << "Program #2" << "\n";

    cout << setw(8) << left << "VALUE";
    cout << setw(15) << left << "RECURSIVE";
    cout << setw(15) << left << "ITERATIVE";
    cout << "SUM" << endl;

    outfile << setw(8) << left << "VALUE";
    outfile << setw(15) << left << "RECURSIVE";
    outfile << setw(15) << left << "ITERATIVE";
    outfile << "SUM" << endl;
    
    // main program loop, priming while !eof loop
    while (!infile.eof())
    {
        string line; // note that line is a string since getline() doesn't return integers.
        int num;
        getline(infile, line); // reads current line of the input file.
        // note: I thought about overloading getline to return integers instead of strings, however this was the easiest solution.

        // code to check if line can be converted (like if theres a letter somehow)
        try
        {
            num = stoi(line); // convert string returned from getline() to integer
            // self-note: stoi means "string to integer"
        }
        catch (const invalid_argument& e)
        {
            cerr << "Invalid argument: " << e.what() << "\n";
            abort();
        }

        // output statements, console and outfile
        cout << setw(8) << left << num;
        cout << setw(15) << left << padovanSequence(num);
        cout << setw(15) << left << iterPadovanSequence(num);
        cout << padovanSum(num);
        cout << endl;
        
        outfile << setw(8) << left << num;
        outfile << setw(15) << left << padovanSequence(num);
        outfile << setw(15) << left << iterPadovanSequence(num);
        outfile << padovanSum(num);
        outfile << endl;
        
    }
    closeFiles(infile, outfile); // close files
    return 0;
}

// you are now at: THE FUNCTION
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

long padovanSequence(int n)
{
    if (n <= 2) // base cases
    {
        return BASE; // value of P(0), P(1), & P(3)
    }
    return padovanSequence(n - 2) + padovanSequence(n - 3); // recursive computation
    // P(n) = P(n-2) + P(n-3)
}

long iterPadovanSequence(int n)
{
    if (n <= 2) // base cases
    {
        return BASE;
    }

    // hardcoded base cases
    long p0 = 1, p1 = 1, p2 = BASE;
    long result = 0; // iterative output
    
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

long padovanSum(int n)
{
    long sum = 0;
    for (int a = 0; a <= n; a++)
    {
        sum += padovanSequence(a);
    }
    return sum;
}