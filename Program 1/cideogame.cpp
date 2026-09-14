// libraries, input/output file reader/writer, console formating
#include <iostream> // console input/output
#include <iomanip> // text formatting
#include <stdexcept> // error handling
#include <fstream> // open input/output files
#include <vector> // dynamic array option
using namespace std;

// Function prototypes
void openFiles(ifstream& infile, ofstream& outfile);
// prompts which input/output files the program uses, doesn't close them.

void closeFiles(ifstream& infile, ofstream& outfile);
// closes files. the snoot drooped.

void debugOpenFiles(ifstream& infile, ofstream& outfile);
// debug version of openFiles, makes testing quicker by removing the input prompts.

vector<unsigned short> fillArray(ifstream& infile);
// fills the array (or vector in this case) with the data values from the selected infile from openFiles

int main() {
    ifstream infile; // input file
    ofstream outfile; // output file
    //openFiles(infile, outfile); // open input/output files
    debugOpenFiles(infile, outfile); // debug 'openFiles' option
    vector<unsigned short> numbers = fillArray(infile); // vector (dynamic array)
    
    // do-while loop iterate, 1D game of life
    bool go = false; // controls do-while iteration
    do {
        // bitwise operations to update state of each cell in the array, see rubric instructions for details
        // print out the data on each iteration, clean format
        // prompt yes/no to continue simulation
    } while(go == true);
    closeFiles(infile, outfile);

    // program end
    cout << "program ended\n";
    return 0;
}

void debugOpenFiles (ifstream& infile, ofstream& outfile)
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

void closeFiles (ifstream& infile, ofstream& outfile)
{
    infile.close();
    outfile.close();
}

vector<unsigned short> fillArray(ifstream& infile)
{
    vector<unsigned short> data; // dynamic array to be returned
    unsigned short num; // temporary value
    
    cout << "array: ";

    // while loop to insert the numbers from the data file into a vector (dynamic array)
    while(infile >> num) {
        data.push_back(num); // add next data value to the array
        cout << num << " "; // debugging, remove later
    }
    cout << endl; // debugging, remove later
    return data;
}