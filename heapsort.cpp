// Program to implement Heap Sorting

#include <iostream>
#define LEFT(X) 2*X
#define RIGHT(X) ( 2*X + 1 )
using namespace std;

int size;
int count = 0;

void maxHeapify( int a[], int i )
{
 int largest;
 int l = LEFT(i);
 int r = RIGHT(i);
 
 if( l <= size && a[l] > a[i] )
 largest = l;
 
 else
 largest = i;
 
 if( r <= size && a[r] > a[largest] )
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

void build_max_heap( int a[] )
{ 
 for( int i = (size / 2); i > 0; i-- )
 maxHeapify( a, i );
}

void heapsort( int a[] )
{
 int i;
 int temp;
 int heap_size = size;
 build_max_heap(a);
 
 for( i = size; i >= 2; i-- )
 {
  temp = a[1];
  a[1] = a[i];
  a[i] = temp;
  heap_size--;
  maxHeapify( a, 1 );
 }
}

int main()
{
 cout << " \n\t\t\t Heap Sorting \n\t\t\t ";
 cout << " \n\t\t\t Enter the size of array: \n\t\t\t ";
 cin >> size;
 
 int *a = new int [size + 1];
 
 cout << " \n\t\t\t Enter the elements of an unsorted array \n\t\t\t ";
 for( int i = 1; i <= size; i++ )
 { cout << " \n\t\t\t "; cin  >> a[i]; }

 heapsort(a);
 
 cout << " \n\t\t\t Sorted array \n\t\t\t ";
 for( int j = 1; j <= size; j++ )
 {
  cout << a[j] << " ";
 }
 
 cout << " \n\n\t\t\t The no. of comparisons are: " << count;
 
 cout << "\n\n";
 return 0;
}

