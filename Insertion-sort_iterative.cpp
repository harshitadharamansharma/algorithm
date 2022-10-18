/*Presented by:
	Sakshi Jain
   14/5017
*/

#include<iostream>
#include<conio.h>
int count =0;

int shiftVac(int a[],int xindex, int val);
void insertionsort(int a[],int n);

int shiftVac(int a[],int xindex, int val)
{
    int i;
    int loc;
    i = xindex;
    loc = 0;
    while(i>0)
    {
      	if(a[i-1]<= val)
         {
         	count++;
           	loc = i;
            break;
         }
         else
         	count++;
         a[i] = a[i-1];
         i--;
    }
    return loc;
}


void insertionsort(int a[],int n)
{
	int xindex;
   for (xindex=1;xindex<n;xindex++)
   {
   	int current = a[xindex];
      int loc = shiftVac(a,xindex,current);
      a[loc] = current;
   }
   return;
}


void main()
{
   int n;
   cout << "\n Enter the size of the array: ";
   cin  >> n;
   int* a = new int[n];
   cout <<"\nEnter the elements of an unsorted array: ";
   for (int i=0;i<n;i++)
   	cin  >> a[i];
   insertionsort(a,n);
   cout << "New array is : " << endl;
   for(int j=0; j<n ;  j++)
   {
   	cout << " "<< a[j];
   }
   cout <<"\nThe no.of comparisons are:" << count;
   getch();
}
