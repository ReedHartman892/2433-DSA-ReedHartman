// libraries, input/output file reader/writer, console formating
#include <iostream> // console input/output
#include <iomanip> // text formatting
#include <fstream> // open input/output files
#include <vector> // dynamic array option
using namespace std;

// Function prototypes
void openFiles(ifstream& infile, ofstream& outfile);
/* Purpose: prompts which input/output files the program uses, doesn't close them.
   Recieves: infile, input file at direct address; outfile, output file at direct address.
   Returns: nothing. */
 
void closeFiles(ifstream& infile, ofstream& outfile);
/* Purpose: closes input/output files. it closes files. the snoot drooped.
   Recieves: 
   Returns:  */

void debugOpenFiles(ifstream& infile, ofstream& outfile);
// debug version of openFiles, makes testing quicker by removing the input prompts.

vector<unsigned short> fillArray(ifstream& infile);
// fills the array (or vector in this case) with the data values from the selected infile from openFiles

short twoPower(short exp);
// finds two to a power of exp, used in the masking portion of the program.

int findSumOfArray(vector<unsigned short> array);
// finds the sum of an array

// Program Definitions
#define ODD 1 // definition of odd

int main() {
    ifstream infile; // input file
    ofstream outfile; // output file
    //openFiles(infile, outfile); // open input/output files
    debugOpenFiles(infile, outfile); // debug 'openFiles' option
    vector<unsigned short> numbers = fillArray(infile); // vector (dynamic array)
    
    // do-while loop iterate, 1D game of life
    bool go = true; // controls do-while iteration
    int i = 0; // generation number
    do {
        for (int j = 1; j < numbers.size(); j++) // for loop to loop through array
        {
            short numi = numbers[j];
            if (j == 1) // 1st element
            {
                numbers[j] = numi >> 1;
            }
            else if (j == numbers.size()-1) // last element
            {
                // toggles the i'th bit
                numbers[j] = numi & ~(1 << i);
            }
            else // even/odd elements
            {
                if (j & ODD)
                {
                    
                }
                else // even numbers
                {
                    
                }
            }
            cout << numbers[j] << " "; // print numbers
        }
        cout << endl;
        i++; // increment generation
        if (i >= 8) {go = false;} // failsafe

    } while(go == true);
    closeFiles(infile, outfile);

    // program end
    cout << "program ended\n";
    return 0;
}

void debugOpenFiles (ifstream& infile, ofstream& outfile)
{
    infile.open("bits1.dat");
    outfile.open("hartman_bits2.out");
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
    cout << "files closed\n";
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

short twoPower(short exp)
{
    short x = 2;
    short result = 1;
    for (int i = 0; i < exp; ++i){
        result *= x;
    }
    return result;
}

int findSumOfArray(vector<unsigned short> array)
{
    return 0;
}