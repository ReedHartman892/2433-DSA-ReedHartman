// Reed Hartman
// CMPS 2433
// Catherine Stringfellow
// Program 3 Assignment

// libraries, input/output file reader/writer, console formating
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#define DEBUG false // optional debug mode, actives certain alternate things for debugging.

// [ FUNCTION PROTOTYPES - FILES]
void debugOpenFiles(ifstream& infile, ofstream& outfile);
// debug option for file opening, opens pre-selected files for quick and easy debugging.

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

// [ FUNCTION PROTOTYPES - MISC. ]
void frequencyCount(string sentence, short frequency[]);
/* Purpose:
   Recieves: 
   Returns: 
*/

void maxFrequency();
/* Pupose:
   Recieves:
   Returns:
*/

void determineShift();
/* Pupose:
   Recieves:
   Returns:
*/

void shiftSentence();
/* Pupose:
   Recieves:
   Returns:
*/

void convertToPlain();
/* Pupose:
   Recieves:
   Returns:
*/

// [ MAIN FUNCTION ]
int main() {
    ifstream infile;
    ofstream outfile;
    // open input/output files
    if (DEBUG) {debugOpenFiles(infile, outfile);}
    else {openFiles(infile, outfile);}
    short letterFrequency[27] = {0};

    string sentence;
    getline(infile, sentence, '#');
    frequencyCount(sentence, letterFrequency); // find frequency of letters in sentence

    if (true) // (DEBUG) show frequency of letters
    {
        for (int x = 1; x < 27; x++) {
            char temp_ch = 64 + x;
            cout << temp_ch << letterFrequency[x] << ", ";
        }
        cout << endl;
    }
    closeFiles(infile, outfile); // close files
    return 0;
}

void debugOpenFiles (ifstream& infile, ofstream& outfile)
{
    infile.open("test.txt");
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

void frequencyCount(string sentence, short frequency[])
{
    for (int i = 0; i < sentence.length(); i++) {
        char ch = sentence[i]; // read letter at this line
        cout << ch; // debug print
        if (DEBUG) {cout << endl;}
        // check letter frequency using ascii-equivalences
        for (int j = 0; j < 26; j++) {
            // ignore spaces
            if (ch == ' ') {break;}
            char c_ch = j+65; // "compare ch"
            
            // this is going to make a fuckton of comparisons
            if (DEBUG) {cout << "(" << ch << " == " << c_ch << ")\n";}
            if (ch == c_ch)
            {
                
                frequency[j+1]++;
                break;
            }
            //cout << endl;
        }
    }
    cout << endl;
}