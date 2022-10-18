// Program to  implement  QuickSort 

#include <iostream>
#include <cstdlib>
using namespace std;
 
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
       *a = *b;
       *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Function to print an array */
void printArray( int A[], int size ) 
{ 
    int i; 
    cout << " \n\t\t\t ";
    for( i = 0; i < size; i++ ) 
    cout << A[i] << " "; 
    cout << " \n\n ";
} 
 
// Driver program to test above functions
int main()
{
    int arr[20], n;
    
    cout << "\n\t\t\tEnter the number of elements in array\n\t\t\t";
    cin >> n;
    
    if ( n >= 20)
    {
     cout << "\n\t\t\tArray Index is Out of Bound\n\n";
     exit(0);
    } 
    
    cout << "\n\t\t\tEnter the elements of array\n\t\t\t";
    for( int i = 0; i < n; i++ ) { cout << "\n\t\t\t"; cin >> arr[i]; } 
    
    quickSort(arr, 0, n-1);
    
    cout<<"\n\t\t\tSorted array via Quick Sorting\n\t\t\t";
    printArray(arr, n);
 
    return 0;
}
