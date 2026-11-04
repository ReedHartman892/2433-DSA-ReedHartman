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
#define ENDCASE '#' // endcase for getline operation

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
/* Purpose: finds the frequency (really just the quantity) of each letter in a string.
   Recieves: a string and an array
   Returns: no return value.
*/

int findIndexOfMax(int array[], int array_size);
/* Pupose: finds the maximum value in a given array
   Recieves: a pointer to a given array
   Returns: index of the maximum value in an array
*/

int determineShift(int max);
/* Pupose: determines the shift amount
   Recieves: 
   Returns: 
*/

string decrypt(string, int shift_amount);
/* Pupose: converts a ciphered text back to a sentence
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
    
    int letterFrequency[26] = {0};
    /* Array containing the frequency count (quantity) of alphabetical letters in a given sentence.
       Index 0 is ignored.
    */
    string sentence;
    /* stores the sentence */

    // do-while loop to read for all test cases.
    while(!infile.eof())
    {
        // TODO: add a thing for the number of test cases
        getline(infile, sentence, ENDCASE); // read line in infile, output to sentence, delim is ENDCASE: '#'
        
        if (infile.eof()) {break;} // force-out to stop the program from doing an extra iteration, idk how to do it any other way.

        frequencyCount(sentence, letterFrequency); // STEP 1: find frequency of letters in sentence
        if (DEBUG) // (DEBUG) show frequency of letters
        {
            for (int x = 1; x < 27; x++) {
                char temp_ch = 64 + x;
                cout << temp_ch << letterFrequency[x] << ", ";
            }
            cout << endl;
        }
        
        int max_i = findIndexOfMax(letterFrequency, sizeof(letterFrequency)/sizeof(letterFrequency[0])); // STEP 2: find maximum of frequency
        if (DEBUG) {
            cout << "index of most frequent letter: " << max_i << endl;
            cout << "most frequent letter: " << (char)(64 + max_i) << ", with " << letterFrequency[max_i] << " cases." << endl;
        }
        //int shift_amount = determineShift(index_of_max); // STEP 3: determine cipher shift amount
        //string plain_text = decrypt(sentence, shift_amount); // STEP 4: convert sentence back to plaintext
        
        // STEP 5: ask the user if the decryption was correct or not
        string answer;
        cout << endl << "does the previous decrypted text look correct? (does it give a legible output?) (y/n) ";
        getline(cin, answer);
        cout << endl;

        // reset frequency list for next test case the in input file
        for (int x = 1; x < 27; x++) {letterFrequency[x] = 0;}
    }

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

int findIndexOfMax(int array[], int array_size) // non-standard findMax algorithm, returns the index of the location of the maximum value, not the max value itself.
{
    //cout << "array_size " << array_size << endl;
    int index_of_max = 1;
    int max = 1;
    for (int i = 1; i < array_size-1; ++i){
        if (max < array[i]) {
            max = array[i];
            index_of_max = i;
        }
    }
    return index_of_max;
}