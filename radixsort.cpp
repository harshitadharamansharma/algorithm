// Program to implement Radix Sort using Counting Sort as intermediate sort

#include <iostream>
#include <math.h>
using namespace std;

void counting_sort( int a[], int n, int d )
{
 int p, k = 9;
 int *b = new int [n + 1];
 int *c = new int [k + 1];
 
 for( p = 1; p < pow( 10, d - 1); p *= 10 );
 for( int i = 0; i <= k; i++ )
 c[i] = 0;
 
 for( int j = 1; j <= n; j++ )
 ++c[((a[j] / p) % 10)];
 
 for( int i = 1; i <= k; i++ )
 c[i] += c[i - 1];
 
 for( int j = n; j > 0; j-- )
 {
  b[c[((a[j] / p) % 10)]] = a[j];
  c[((a[j]/p) % 10)] = c[((a[j] / p) % 10)] - 1;
 }
 
 for( int i = 1;i <= n; i++ )
 a[i] = b[i];
}

void radix_sort( int a[], int d, int n )
{
 for( int i = 1; i <= d; i++ )
 counting_sort( a, n, i );
}

int main()
{
 cout << " \n\t\t\t RADIX SORTING \n\t\t\t ";
 
 int size;
 
 cout << " \n\t\t\t Enter the size of array: \n\t\t\t ";
 cin >> size;
 
 int *a = new int [size + 1];
 
 cout << " \n\t\t\t Enter the elements of an unsorted array: \n\t\t\t ";
 for( int i = 1; i <= size; i++ )
 { cin  >> a[i]; cout << " \n\t\t\t "; }

 int k = a[0];
 
 for( int i = 1; i < size; i++ )
 {
  if( a[i] > k )
  k = a[i];
 }
  
 int d = 0;
 
 for( int exp = 1; k / exp > 0; exp *= 10 )
 d++;
 radix_sort(a,d,size);
 
 cout << " \n\t\t\t New array is : \n\t\t\t ";
 for( int j = 1; j <= size ;  j++ )
 {
  cout << a[j] << " ";
 }
   
 cout << "\n\n";
 return 0;
}
