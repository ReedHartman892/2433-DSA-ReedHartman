// libraries, input/output file reader/writer, console formating
#include <iostream> // console input/output
using namespace std;

// some char variable testing
int main() {
   // frequency of each letter in a string
   char letters[6] = {'a','A', 'b','B', 'z','Z'};
   for (int i = 0; i < 6; i++){
      bool lowercase = false;
      int letter = letters[i];
      int enletter = letter - 65; // convert to number? 1 to 26. how does lowercase work?
   // lowercase detection
      if (enletter > 26) {
         enletter -= 32;
         lowercase = true;
      }
      cout << "the letter is: " << enletter;
      if (lowercase)
         cout << " (lowercased)";
      cout << endl;
   }
   return 0;
}