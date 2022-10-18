// Program for Heap Sorting

#include <iostream>
using namespace std;

#define LEFT(X) (2*X + 1)
#define RIGHT(X) (2*X + 2)

int heapsize;
int count =0;

void maxHeapify( int a[], int i )
{
 int largest;
 int l = LEFT(i);
 int r = RIGHT(i);
 
 if( l < heapsize && a[l] > a[i] )
 largest = l;
 else
 largest = i;
 
 if( r < heapsize && a[r] > a[largest] )
 largest = r;
 count++;
 
 if( largest != i )
 {
  int temp = a[i];
  a[i] = a[largest];
  a[largest] = temp;
  maxHeapify( a, largest );
 }
}

void build_max_heap(int a[], int size)
{
 heapsize = size;
 for( int i = ((size/2)-1); i >= 0; i-- )
 maxHeapify( a, i );
}

void heapsort( int a[], int size )
{
 int i;
 int temp;
 build_max_heap( a, size );
 for( i = size - 1; i >= 1; i-- )
 {
  temp = a[0];
  a[0] = a[i];
  a[i] = temp;
  heapsize--;
  maxHeapify( a, 0 );
 }
}

int main()
{
 cout << " \n\t\t\t Heap Sorting \n\t\t\t "; 
 int size;
 cout << " \n\t\t\t Enter the size of array: \n\t\t\t ";
 cin >> size;

 int *a = new int [size];

 cout << " \n\t\t\t Enter the elements of an unsorted array: \n\t\t\t ";
 for( int i = 0; i < size; i++ )
 { cin  >> a[i]; cout << " \n\t\t\t "; }

 heapsort( a, size );

 cout << " \n\t\t\t New sorted array is: \n\t\t\t ";
 for( int j = 0; j < size; j++ )
 {
  cout << a[j] << " ";
 }
 
 cout << " \n\n\t\t\t The no. of comparisons are: " << count;
 
 cout << "\n\n";
 return 0;
}
