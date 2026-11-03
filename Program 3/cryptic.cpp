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

#define DEBUG true // optional debug mode, actives certain alternate things for debugging.
#define ENDCASE '#' //

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

void frequencyCount(string, int[]);
/* Purpose:
   Recieves: 
   Returns: 
*/

int maxFrequency();
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

    int letterFrequency[27] = {0};
    /* Array containing the frequency count (quantity) of alphabetical letters in a given sentence.
       Index 0 is ignored.
    */
    
    string sentence;
    // do-while loop to read for all test cases. I do not know how to force it to stop repeating once more even when it has nothing left to read.
    do {
        getline(infile, sentence, ENDCASE); // read line in infile, output to sentence, delim is ENDCASE: '#'
        frequencyCount(sentence, letterFrequency); // find frequency of letters in sentence
        
        if (true) // (DEBUG) show frequency of letters
        {
            for (int x = 1; x < 27; x++) {
                char temp_ch = 64 + x;
                cout << temp_ch << letterFrequency[x] << ", ";
            }
            cout << endl;
        }

        // reset list
        for (int x = 1; x < 27; x++) {
            letterFrequency[x] = 0;
        }
    } while(!infile.eof());

    closeFiles(infile, outfile); // close files
    return 0;
}

void debugOpenFiles (ifstream& infile, ofstream& outfile)
{
    infile.open("CipherText.txt");
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

void frequencyCount(string str, int frequency[])
{
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i]; // read letter at this line
        cout << ch; // debug print
        if (false) {cout << endl;}
        // check letter frequency using ascii-equivalences
        for (int j = 0; j < 26; j++) {
            // ignore spaces
            if (ch == ' ') {break;}
            char c_ch = j+65; // "compare ch"
            
            // this is going to make a fuckton of comparisons
            if (false) {cout << "(" << ch << " == " << c_ch << ")\n";}
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