#include <iostream>
using namespace std;

void displayArray(int*, int);
void MergeSort(int*, int, int);
void Merge(int*, int, int, int);

int main()
{
	int myArr[5] = {85, 42, 7, 186, 18};
	
	//display the array
	displayArray(myArr, 5);
	//sort the array
	MergeSort(myArr, 0, 4);
	//display the array
	displayArray(myArr, 5);
	
	return 0;
}

void MergeSort(int arr[], int beg, int end) {
   int mid = 0;
   
   if (beg < end) {
      mid = (beg + end) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSort(arr, beg, mid);
      MergeSort(arr, mid + 1, end);
      
      // Merge left and right partition in sorted order
      Merge(arr, beg, mid, end);
   }
}

void Merge(int arr[], int beg, int mid, int end) {
   int mergedSize = end - beg + 1;                // Size of merged partition
   int mergePos = 0;                          // Position to insert merged number
   int leftPos = 0;                           // Position of elements in left partition
   int rightPos = 0;                          // Position of elements in right partition
   int* mergedNumbers = new int[mergedSize];  // Dynamically allocates temporary array
                                              // for merged arr
   
   leftPos = beg;                               // Initialize left partition position
   rightPos = mid + 1;                          // Initialize right partition position
   
   // Add smallest element from left or right partition to merged arr
   while (leftPos <= mid && rightPos <= end) {
      if (arr[leftPos] < arr[rightPos]) {
         mergedNumbers[mergePos] = arr[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = arr[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= mid) {
      mergedNumbers[mergePos] = arr[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= end) {
      mergedNumbers[mergePos] = arr[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to arr
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      arr[beg + mergePos] = mergedNumbers[mergePos];
   }
}

void displayArray(int *arr, int size)
{
	cout << "\n--------------------The array:  ";
	for(int i=0; i<size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "--------------------\n";
}