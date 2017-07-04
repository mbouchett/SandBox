// Lab 3 table.cpp
// This program reads data from a file and 
// prints it in a nicely aligned table.
// Mark Bouchett

#include <iostream>
#include <fstream>
#include <string>

void quickSort(std::string [], int, int);

using namespace std;

int main()
{
   string data;            // number in file of an inventory item
   ifstream dataIn;        // Define an input file stream object
   int recordCount = 0;
   
   
   dataIn.open("flatfile.dat");
   if(!dataIn){
       cout << "file error!";
   }else{
       while(!dataIn.eof()){
           recordCount++;
           dataIn >> data;
       }
        string datArr[recordCount];
        recordCount = 0;       
        dataIn.clear();
        dataIn.seekg(0, ios::beg);
   	while (!dataIn.eof())
	{
	   // Read in five data records and display them
	   dataIn >> datArr[recordCount];        // Record 1
           /*
            *here we can process the input
            *insert or remove leading zeros
            *and insert it into our data structure
            * ?linked list we would need to decide on the data type
            * ?leading zeros would be strings 
            */
	   cout   << datArr[recordCount] << endl;
           recordCount++;
	}
        quickSort(datArr,0,recordCount);
        // insert a blank line
	cout << endl;
   }
   // Close the file
   dataIn.close();
  
   return 0;
}

void quickSort(string arr[], int left, int right) {

      int i = left, j = right;

      string tmp;

      string pivot = arr[(left + right) / 2];

 

      /* partition */

      while (i <= j) {

            while (arr[i] < pivot)

                  i++;

            while (arr[j] > pivot)

                  j--;

            if (i <= j) {

                  tmp = arr[i];

                  arr[i] = arr[j];

                  arr[j] = tmp;

                  i++;

                  j--;

            }

      };

 

      /* recursion */

      if (left < j)

            quickSort(arr, left, j);

      if (i < right)

            quickSort(arr, i, right);

}