// Reed Hartman
// CMPS 2433
// Catherine Stringfellow
// Program 1 Assignment

// libraries, input/output file reader/writer, console formating
#include <iostream> // console input/output
#include <iomanip> // text formatting
#include <fstream> // open input/output files
#include <vector> // dynamic array option
#include <string> // strings, only used for the simulation prompt.
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

vector<unsigned short> fillArray(ifstream& infile);
/* Purpose: fills the array (or vector in this case) with the data values from the selected infile from openFiles
   Recieves: infile, input file at direct address
   Returns: filled vector of unsigned short values from the passed file.
*/

int findSumOfArray(vector<unsigned short> array);
/* Purpose: finds the sum all values within an array
   Recieves: vector<unsigned short> array (copied over from numbers in int main())
   Returns: integer sum of the passed array
*/

// Program Definitions
#define ODD 1 // definition of odd
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

    outfile << "Reed Hartman" << endl;
    outfile << "Program #1" << endl << endl;

    // do-while loop iterate, 1D game of life
    bool go = true; // controls do-while iteration
    int i = 0; // generation number

    do {
        if (i == 0) // first generation runs this code only
        {
            cout << "Generation 0: ";
            outfile << "Generation 0: ";
            for (int k = 0; k < numbers.size(); k++) // for loop to print numbers
            {
                cout << setw(5) << right << numbers[k];
                outfile << setw(5) << right << numbers[k];
            }
        }
        else // all subsequent generations run this code
        {
            cout << "Generation " << i << ": ";
            outfile << "Generation " << i << ": ";
            for (int j = 0; j < numbers.size(); j++) // for loop to loop through array
            {
                unsigned short numi = numbers[j]; // temporary number value, "number at index"
                if (j == 0) // 1st element
                {
                    numbers[j] = numi >> 1;
                }
                else if (j == numbers.size()-1) // last element
                {
                    numbers[j] = numi & ~(MASK << i); // toggles the i'th bit
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
                cout << setw(5) << right << numbers[j]; // print numbers
                outfile << setw(5) << right << numbers[j];
            }
        }

        // take sum of the current generation
        cout << "    sum: " << findSumOfArray(numbers);
        outfile << "    sum: " << findSumOfArray(numbers);

        // prompt to continue simulation
        cout << "    "; // space
        string answer;
        cin >> answer;
        if (answer == "y"){go = true;}
        else              {go = false;}
        outfile << endl;

        // increment generation number
        i++;

    } while(go == true);
    cout << endl << "Generations complete!" << endl;
    outfile << endl << "Generations complete!" << endl;
    closeFiles(infile, outfile);

    // program end
    cout << "program ended\n";
    outfile << "program ended\n";
    return 0;
}

// my functions!

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
    unsigned int sum = 0; // temporary value to store additive sum
    for (int x = 0; x < array.size(); x++) {
        sum += array[x]; // add each value at each index to sum
    }
    return sum;
}