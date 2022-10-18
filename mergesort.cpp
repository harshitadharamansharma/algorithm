// Program for Merge Sorting

#include <iostream> 
using namespace std;
  
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m+1+j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort( int arr[], int l, int r ) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = ( l + r ) / 2; 
        
        // Sort first and second halves 
        mergeSort( arr, l, m ); 
        mergeSort( arr, m + 1, r ); 
  
        merge( arr, l, m, r ); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray( int A[], int size ) 
{ 
    int i; 
    cout << " \n\t\t\t ";
    for( i = 0; i < size; i++ ) 
    cout << A[i] << " "; 
    cout << " \n\n ";
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[20], n;
    
    cout << " \n\t\t\t Enter the number of elements in array \n\t\t\t ";
    cin >> n;
    cout << " \n\t\t\t Enter the elements of array \n\t\t\t ";
    for( int i = 0; i < n; i++ ){ cout << " \n\t\t\t "; cin >> arr[i]; } 
  
    cout << " \n\t\t\t Given Array \n\t\t\t "; 
    printArray( arr, n ); 
    
    cout << " \n\t\t\t Array Size " << n << " \n\t\t\t ";
  
    mergeSort( arr, 0, n - 1 ); 
  
    cout << " \n\t\t\t Sorted array is \n\t\t\t "; 
    printArray( arr, n );
    
    cout << "\n\n"; 
    return 0; 
} 

