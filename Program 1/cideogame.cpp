// libraries, input/output file reader/writer, console formating
#include <iostream> // console input/output
#include <iomanip> // text formatting
#include <stdexcept> // error handling
#include <fstream> // open input/output files
#include <vector> // dynamic array
using namespace std;

// Function prototypes
void openFiles(ifstream& infile, ofstream& outfile);
// prompts which input/output files the program uses, doesn't close them.

void debugOpenFiles(ifstream& infile, ofstream& outfile);
// debug version of openFiles, makes testing quicker by removing the input prompts.

int main() {
    // file names
    ifstream infile;
    ofstream outfile;
    debugOpenFiles(infile, outfile);
    
    vector<unsigned short> numbers;

    unsigned short number;
    // while loop to insert the numbers from the data file into a vector (dynamic array)
    while(infile >> number) {
        numbers.push_back(number);
        cout << number << ", ";
    } cout << endl;
    
    // do-while loop iterate, 1D game of life
    /*
    do {
        // bitwise operations to update state of each cell in the array, see rubric instructions for details
        // print out the data on each iteration, clean format
    } while();
    */
    // program end
    cout << "program ended\n";
    return 0;
}

void debugOpenFile (ifstream& infile, ofstream& outfile)
{
    infile.open("bits1.dat");
    outfile.open("output.txt");
}

void openFiles (ifstream& infile, ofstream& outfile)
{
    char inFileName[40];
    char outFileName[40];

    cout << "Enter the input file name: ";
    cin >> inFileName;
    infile.open(inFileName); // open input file

    cout << "Enter the output file name: ";
    cin >> outFileName;
    outfile.open(outFileName); // open output file
}

