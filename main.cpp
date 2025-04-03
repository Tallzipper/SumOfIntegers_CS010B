#include <limits.h>
#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(const string& fileName);

int main(int argc, char* argv[]) {

   string filename;
   
   #ifdef CHECK_ARG //This is a flag to the compiler to include this code if CHECK_ARG is defined
      if (argc < 2) {
         cout << "Please enter a file on the command line\n"; // Too little arguements
         exit(1);
      }
      if (argc > 2) {
         cout << "Too many arguements! Only 1 file is expected\n"; // Too many arguements
         exit(1);
      }
      filename = argv[1]; // set the file name to the second element in the command line
   #endif
   #ifndef CHECK_ARG //This is a flag to the compiler to include this code if CHECK_ARG is NOT defined
      cout << "Enter the name of the input file: ";
      cin >> filename; // set the file name to what the user inputs (interactive)
      cout << "\n";
   #endif

   int sum = 0;
   sum = fileSum(filename);

   if(!(sum == INT_MAX))
   {
       cout << "Sum: " << sum << endl;
   }
   
   return 0;
}

int fileSum(const string& fileName)
{

   int temp;
   int sum = 0;

   ifstream inFS;   

   inFS.open(fileName);

   if(!inFS.is_open())
   {

      cout << "Error opening " << fileName << endl;
      return INT_MAX;

   }

   while(inFS >> temp)
   {

      sum = sum + temp;

   }

   inFS.close();

   return sum;

}