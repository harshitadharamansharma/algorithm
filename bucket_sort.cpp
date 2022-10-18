// Program to implement Bucket Sort using Insertion Sort as intermediate sort

#include <iostream>
using namespace std;

class bucket
{
 public:
 
 float key;
 bucket *next;
 bucket *prev;
 bucket( float a = 0.0 )
 {
  key = a;
  next = 0;
  prev = 0;
 }
};

void insertionSort( bucket *x )
{
 float k;
 bucket *i, *j, *temp;
 
 if( x == 0 )
 return;
 
 while( x -> next != 0 )
 {
  j = x -> next;
  k = j -> key;
  i = j -> prev;
  temp = i;
  
  while( i != 0 && i -> key > k )
  {
   i -> next -> key = i -> key;
   temp = i;
   i = i -> prev;
  }
  
  if( i == 0 )
  temp -> key = k;
        
  else
  i -> next -> key = k;
  x = x -> next;
 }
}

void bucket_sort ( float a[], int n )
{
 int t;
 bucket *temp;
 bucket **b = new bucket *[n];
     
 for( int i = 0; i < n; ++i )
 b[i] = 0;
     
 for( int i = 1; i <= n; i++ )
 {
  t = n * a[i];
         
  if( b[t] == 0 )
  b[t] = new bucket( a[i] );
         
  else
  {
   temp = new bucket ( a[i] );
   b[t] -> prev = temp;
   temp -> next = b[t];
   b[t] = temp;
  }
 }
 
 for( int i = 0; i < n; ++i )
 insertionSort( b[i] );

 cout << " \n\t\t\t Sorted Array is: \n\t\t\t ";
 
 for( int i = 0; i < n; i++ )
 {
  temp = b[i];
  
  while( temp != 0 )
  {
   cout << temp -> key << " --> ";
   temp = temp -> next;
  }
 }
}

int main ()
{
 cout << " \n\t\t\t BUCKET SORTING USING INSERTION SORT AS INTERMEDIATE SORT \n\n\t\t\t ";
 cout << " \n\t\t\t Enter the size of the array: \n\t\t\t ";
 int size;
 cin  >> size;
 float *a = new float [size];
 cout << " \n\t\t\t Enter the elements of the array in the range of 0 to 1: \n\t\t\t ";
       
 for( int i = 0; i < size; i++ )
 {
  cin >> a[i]; cout << " \n\t\t\t ";
  
  if( a[i] < 0 || a[i] > 1 )
  {
   cout << " \n\t\t\t Out of range, re-enter the element: \n\t\t\t ";
   cin >> a[i];
  }
 }
 
 bucket_sort( a, size );
 
 cout << "\n\n";
 return 0;
}
