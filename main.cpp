#include <iostream>
#include <fstream>
#include <string>

void quickSort(int[], int, int);

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
        int datArr[recordCount];
        recordCount = 0;       
        dataIn.clear();
        dataIn.seekg(0, ios::beg);
   	while (!dataIn.eof())
	{
            // Read in five data records and display them
            dataIn >> data;        // Get a Record
            if(!dataIn.eof()){
                datArr[recordCount] = stoi(data, nullptr, 10);//convert it to an int
                recordCount++;
            }
        }
        
        quickSort(datArr,0,recordCount);
        
        for(int i = 0; i < recordCount; i++){
            cout   << datArr[i] << endl;
        }
   }
   // Close the file
   dataIn.close();
   return 0;
}

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      
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
      }
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}