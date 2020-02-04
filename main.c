#include <stdio.h>
#include <stdlib.h>

// makeArrayCopy: ------------------------------------------------------------
// This function copies fromArray to to array till the size specified.
void makeArrayCopy(int fromArray[], int toArray[], int size)
{
  for(int i = 0; i < size; ++i) 
  {
    toArray[i] = fromArray[i];
  }
}

// printArr: -----------------------------------------------------------------
// just a simple print function for array for debugging purposes
void printArr(int arr[], int size)
{
  for(int i = 0; i < size; ++i) 
  {
     printf("%d,", arr[i]);
  }
  printf(" \n");
}

// bubbleSort: ---------------------------------------------------------------
// simple bubble sort implimented for sorting the array arr[] with size = size
void bubbleSort(int arr[], int size)
{
  
  for(int i = 0; i < size-1; ++i) // itterating through array n-1 times 
  {
      for(int j = 0; j < size-1-i; ++j) // itterating through to bubble the highest value to the top of the array.
      { 
        if(arr[j] > arr[j+1]){
          int temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp; 
        }
      }
      
  }

  // FIXME: lines below is for debug purposes.
  printf("\nSorted array: "); 
  printArr(arr, size);
}

// targetSum: ----------------------------------------------------------------
// looking for a target sum of to element of an array that equals to user 
// inputed value. Function takes in a sorted array followed by size of the 
// array and targetsum value to check 
int  targetSum(int arr[], int size, int val, int* index1, int* index2)
{
  int low = *index1, high = *index2; 

  while(high > low) //Terminating the loopif lower and higher index crosses.
  {
    int sum = arr[low]+arr[high];
    if(sum == val) // checking if the TargetVal is the same as sum generated.
    { 
      //updaing the to indexes to fetch it out of the function
      *index1 = low;
      *index2 = high;
      return 1;
    }
    //since we didnt find the sum in this loop we go forward and change the
    // index values depending on the conditions.
    else if( sum > val)
    { 
      --high;
    }
    else
    {
      ++low;
    }
  }
  
  // we return -1 to indicate we didnt find the sum.
  return -1;
}

int main (int argc, char** argv)
{
  int val;

  // prompt the user for input 
  printf ("Enter in a list of numbers ito be stored in a dynamic array.\n");
  printf ("End the list with the terminal value of -999\n");
 
  // creating a dynamic array
  int *arr;
  int arrSize = 10;
  arr = (int *)malloc(arrSize * sizeof(int));

  // creating a count for total entries in array 
  int count = 0;
  
  // loop until the user enters -999 
  scanf ("%d", &val);
  while (val != -999)
    {
      // store the value into an array 
      if(count >= arrSize) // if array is full expand it.
      {
        int *tempArr = arr;
        arr = (int *)malloc(arrSize * 2 * sizeof(int));
        makeArrayCopy(tempArr, arr, arrSize);
        arrSize = arrSize*2;
        free(tempArr);
      }
      arr[count] = val; //storing the value to arr.

      scanf("%d", &val); // get next value
      count++; //updating cout
    }

  printf("\nRegular array: ");  
  printArr(arr, count); // FIXME.


  // call function to make a copy of the array of values 
  int *sortedArray;
  int sortedArrSize = arrSize;
  sortedArray = (int *)malloc(sortedArrSize * sizeof(int));
  makeArrayCopy(arr, sortedArray, sortedArrSize);

  // call function to sort one of the arrays
  bubbleSort(sortedArray, count);

  // loop until the user enters -999 
  printf ("Enter in a list of numbers to use for searching.  \n");
  printf ("End the list with a terminal value of -999\n");
  scanf ("%d", &val);
  while (val != -999)
    { 
      int index1 = 0, index2 = count-1;

      // call function to perform target sum operation 
      int found = targetSum(sortedArray, count, val, &index1, &index2);
     
      // print out info about the target sum results 
      if(found == 1)
      {
        printf("%d Yes! the values are %d and %d " , val, sortedArray[index1], sortedArray[index2]);
        printf("\n");
      }
      else
      {
        printf("%d No!\n" , val);
      }
      
      // get next value
      scanf("%d", &val);
    }


  printf ("Good bye\n");
  return 0;
} 
