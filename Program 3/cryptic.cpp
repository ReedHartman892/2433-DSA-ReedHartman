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
#define ENDCASE '#' // endcase for getline operation
#define E_POSITION_FREQUENCY 5 // defined position of E, the most frequent letter in the alphabet

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

void frequencyCount(const string &str, int[]);
/* Purpose: finds the frequency (really just the quantity) of each letter in a string.
   Recieves: a string and an array
   Returns: no return value.
*/

int findIndexOfMax(int array[], int array_size);
/* Pupose: non-standard findMax algorithm, returns the index of the location of the maximum value, not the max value itself.
   Recieves: a pointer to a given array and the determined size of that array
   Returns: index of the maximum value in an array
*/

string decrypt(const string &str, int shift);
/* Pupose: converts the ciphered text back to a sentence
   Recieves: a string and the calculated shift amount.
   Returns: hopefully, the decrypted string
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
       Aggregately initialized.
       Index 0 is ignored.
    */
    string sentence; // stores the sentence

    // getline-loop to read for all test cases.
    while(getline(infile, sentence, ENDCASE)) // read line in infile, output to sentence, delim is ENDCASE: '#'
    {
        int testCase = 1;
        cout << "Test Case " << " Encrypted Text:";
        cout << sentence << endl << endl; // print the encrypted sentence
        
        // STEP 1: find frequency of letters in sentence
        frequencyCount(sentence, letterFrequency);
        if (DEBUG) // show frequency of letters
        {
            for (int x = 1; x < 27; x++) {
                char temp_ch = 64 + x;
                cout << temp_ch << letterFrequency[x] << ", ";
            }
            cout << endl;
        }
        
        // STEP 2: find maximum of frequency, this is also the shift amount
        int max_i = findIndexOfMax(letterFrequency, sizeof(letterFrequency)/sizeof(letterFrequency[0]));
        if (DEBUG) // show data concerning maximum frequency
        {
            cout << "index of most frequent letter: " << max_i << endl;
            cout << "most frequent letter: " << (char)(64 + max_i) << " with " << letterFrequency[max_i] << " cases." << endl;
        }

        // STEP 3: calculate the decryption shift amount
        int shift_amt = max_i - E_POSITION_FREQUENCY;
        if (DEBUG)
        {
            cout << "shift amount = " << shift_amt;
        }

        // STEP 4: convert sentence back to plaintext
        string plain_text = decrypt(sentence, shift_amt);

        cout << endl << "Decrypted PlainText:";
        cout << plain_text << endl; // output decrypted text
        
        // STEP 5: ask the user if the decryption was correct or not
        string answer;
        cout << "does the previous decrypted text look correct? (does it give a legible output?) (y/n) ";
        
        cin.ignore();
        getline(cin, answer);
        cout << endl;

        // 
        if (answer == "y"){cout << "The decryption method worked.";}
        else{cout << "The decryption method failed.";}
        cout << endl << endl << endl;

        // STEP 6: reset frequency and increment testCase number list for next test case in the input file
        for (int x = 1; x < 27; x++) {letterFrequency[x] = 0;}
        testCase++; 
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

void frequencyCount(const string &str, int frequency[])
{
    for (int i = 0; i < str.length(); i++) {
        char character = str[i]; // read letter at this line
        // check letter frequency using ascii-equivalences
        for (int j = 0; j < 26; j++) {
            if (character == ' ') // ignore spaces
            {
                break;
            }

            char current_character = j+65;
            
            // this is going to make a fuckton of comparisons
            if (character == current_character) // compare current character to the character being observed
            {
                frequency[j+1]++;
                break; // if the character is found, it can't be two characters at once, so break out of the loop early.
            }
        }
    }
    cout << endl;
}

int findIndexOfMax(int array[], int array_size) // non-standard findMax algorithm, returns the index of the location of the maximum value, not the max value itself.
{
    int index_of_max = 1; int max = array[1];
    for (int i = 1; i < array_size-1; ++i){
        if (max < array[i]) {
            max = array[i]; index_of_max = i;
    }   }
    return index_of_max;
}

string decrypt(const string &text, int shift)
{
    string decrypted_str = ""; // temporary string for containing the decrypted algorithm
    for (char c : text) // string-based loop
    {
        // decrpytion algorithm
        if (isalpha(c)) { // checks for alphabetical characters (A-Z)
            decrypted_str += char(((c - 65 - shift + 26) % 26) + 65); // caesar-cipher decryption
        }
        else { // for non-alphabetical characters
            decrypted_str += c; // default case
        }
    }
    return decrypted_str;
}