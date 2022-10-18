// Program to implement Counting Sort

#include <iostream>
using namespace std;

void counting_sort( int a[], int b[], int k, int n )
{
 int *c = new int [k + 1];
 
 for( int i = 0; i <= k; i++ )
 c[i] = 0;
   
 for( int j = 0; j < n; j++ )
 ++c[ a[j] ];
  
 for( int i = 1; i <= k; i++ )
 c[i] += c[i - 1];
   
 for( int j = n - 1; j >= 0; j-- )
 {
  b[c[a[j]] - 1] = a[j];
  c[a[j]] = c[a[j]] - 1;
 }
}

int main()
{
 cout << " \n\t\t\t COUNTING SORT \n\t\t\t ";
 
 int size;
 int k;
	
 cout << " \n\t\t\t Enter the size of array: \n\t\t\t ";
 cin >> size;
   
 int *a = new int [size];
 int *b = new int [size];
 
 cout << " \n\t\t\t Enter the elements of an unsorted array: \n\t\t\t ";
 
 for( int i = 0; i < size; i++ )
 { cout << " \n\t\t\t "; cin  >> a[i]; }
 k = a[0];
   
 for( int i = 1; i < size; i++ )
 {
  if( k < a[i] )
  k = a[i];
 }

 counting_sort(a,b,k,size);
 
 cout << " \n\t\t\t New array is :\n\t\t\t ";
 for( int j = 0; j < size ;  j++ )
 {
  cout << b[j] << " ";
 }
   
 cout << "\n\n";
 return 0;
}
