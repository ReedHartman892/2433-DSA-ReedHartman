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

vector<unsigned short> fillArray(ifstream& infile);
// fills the array (or vector in this case) with the data values from the selected infile from openFiles

int findSumOfArray(vector<unsigned short> array);
// finds the sum of an array

void generationStatement(vector<unsigned short> array, int genNumber);
// print statement

// Program Definitions
#define ODD 1 // definition of odd
#define EVEN 0 // definition of even
#define MASK 1 // definition of mask

int main() {
    ifstream infile; // input file
    ofstream outfile; // output file
    //openFiles(infile, outfile); // open input/output files
    openFiles(infile, outfile); // debug 'openFiles' option
    vector<unsigned short> numbers = fillArray(infile); // vector (dynamic array)
    
    // print statement
    cout << endl;
    cout << "Reed Hartman" << endl;
    cout << "Program #1" << endl << endl;

    // do-while loop iterate, 1D game of life
    bool go = true; // controls do-while iteration
    int i = 0; // generation number

    do {
        if (i == 0) // first generation runs this code only
        {
            cout << "Generation 0: ";
            for (int k = 0; k < numbers.size(); k++) // vector for loop to print numbers
            {
                cout << setw(4) << right << numbers[k];
            }
            cout << endl;
        }
        else // all subsequent generations run this code
        {
            cout << "Generation " << i << ": ";
            for (int j = 0; j < numbers.size(); j++) // for loop to loop through array
            {
                unsigned short numi = numbers[j]; // temporary number value, "number at index"
                if (j == 0) // 1st element
                {
                    numbers[j] = numi >> 1;
                }
                else if (j == numbers.size()-1) // last element
                {
                    // toggles the i'th bit
                    numbers[j] = numi & ~(MASK << i);
                }
                else // even/odd elements
                {
                    if ((1 <= j <= numbers.size()-1) && (j & ODD)) // odd elements
                    {
                        numbers[j] = numi & numbers[j-1];
                    }
                    else // even elements
                    {
                        numbers[j] = numi ^ numbers[j+1];
                    }
                }
                cout << setw(4) << right << numbers[j]; // print numbers
            }
            cout << endl;
        }
        i++; // increment generation number
        if (i >= 9) {go = false;} // failsafe
    } while(go == true);
    closeFiles(infile, outfile);

    // program end
    cout << "program ended\n";
    return 0;
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
    cout << "Sample input: ";
    // while loop to insert the numbers from the data file into a vector (dynamic array)
    while(infile >> num) {
        data.push_back(num); // add next data value to the array
        cout << num << " ";
    }
    data.erase(data.begin()); // remove first value, i dont know why this is needed but everything breaks and the program instruction always excludes the first bit.
    cout << endl; // debugging, remove later
    return data;
}

int findSumOfArray(vector<unsigned short> array)
{
    return 0;
}