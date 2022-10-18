// Menu driven program for Bubble Sort, Selection Sort, Insertion Sort.

#include <iostream>
using namespace std;

int main()
{
 char ch;
 int a[20];
 int i, j, k, n;
 int temp;
 
 cout << "\n\t\t\tEnter the number of elements in array\n\t\t\t";
 cin >> n;
 cout << "\n\t\t\tEnter the elements of array\n\t\t\t";
 for( i = 0; i < n; i++ ){ cout << "\n\t\t\t"; cin >> a[i]; } 
 
 cout << "\n\t\t\tPress a for Bubble sort\n\t\t\t";
 cout << "\n\t\t\tPress b for Selection sort\n\t\t\t";
 cout << "\n\t\t\tPress c for Insertion sort\n\t\t\t";
 cout << "\n\t\t\tEnter your choice\n\t\t\t";
 cin >> ch;
 
 if(ch == 'a' || ch == 'A')                                           // Bubble Sorting
 {
  for( i =0; i < n; i++)
   for( j = 0; j < n-1; j++)

    if( a[j] > a[j+1] )
    {
     temp = a[j+1];
     a[j+1] = a[j];
     a[j] = temp;
    }
     
  cout << "\n\t\tSorted array list in ascending order via Bubble Sort\n\n\t\t";
  for( i = 0; i < n; i++ )
  cout << a[i] << " "; 
  cout << " \n\n ";   
 }
 
 else if(ch == 'b' || ch == 'B')                                           // Selection Sort
 {
  int big;
  int index;
  
  for( i = n-1; i > 0; i-- )
  {
   big = a[0];
   index = 0;
   
   for( j = 0; j <= i; j++ )
   if( a[j] > big )
   {
    big = a[j];
    index = j;
   }
  
   a[index] = a[i];
   a[i] = big;
  }
  
  cout << "\n\t\t\tArray after Selection Sort\n\t\t\t";
  for( i = 0; i < n; i++ )
  cout << a[i] << " ";
  cout << "\n\n";
 }
 
 else if(ch == 'c' || ch == 'C')                                           // Insertion Sort
 {
  int key; 
  for( j = 1; j < n; j++ )
  {
   key = a[j];
   i = j-1;
   
   while( i >= 0 && a[i] > key )
   {
    a[i+1] = a[i];
    i = i-1;
   }                                    
    a[i+1] = key;
   
  }
  cout << "\n\t\t\tArray after Insertion Sort\n\t\t\t";
  for( i = 0; i < n; i++)
  cout << a[i] << " ";
  cout << "\n\n";
                              
 }
 
 else
 cout << "\n\t\t\tWrong Choice\n\n";
 
} 
