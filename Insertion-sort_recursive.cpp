/*Presented by:
	Sakshi Jain
   14/5017
*/

#include<iostream>
#include<conio.h>

int counter = 0;

int shiftVacRec(int a[], int vacant, int x);
void insertionsort(int a[],int n);

int shiftVacRec(int a[], int vacant, int x)
{
	int loc;
   if(vacant == 0)
   	loc=vacant;
   else if(a[vacant-1] <= x)
   {
   	counter++;
   	loc=vacant;
   }
   else
   {
   	a[vacant] = a[vacant-1];
      loc = shiftVacRec(a,vacant-1,x);
      counter++;
   }
   return loc;
}

void insertionsort(int a[],int n)
{
	int xindex;
   for (xindex=1;xindex<n;xindex++)
   {
   	int current = a[xindex];
      int loc = shiftVacRec(a,xindex,current);
      a[loc] = current;
   }
   return;
}

void main()
{
	int n;
   cout << "\nEnter the size of the array: ";
   cin  >> n;
   int * a = new int[n];
   cout <<"Enter the elements of an unsorted array: ";
   for (int i=0;i<n;i++)
   	cin  >> a[i];
   insertionsort(a,n);
   cout << "New array is : " << endl;
   for(int j=0; j<n ;  j++)
   {
   	cout << " "<< a[j];
   }
   cout << "\nThe total no. of comparisons are: " << counter;
   getch();
}
