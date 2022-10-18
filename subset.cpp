// Program for subset sum problem.

#include <iostream>
using namespace std;

class SubSet
{
 int **arr;
 int *set;
 int n;
 int w;

 public:

 SubSet( int count, int sum )
 {
  n = count;
  w = sum;
  arr = new int*[n + 1];
  
  for( int i = 0; i <= n; i++ )
  arr[i] = new int[w + 1];
  
  set = new int[n + 1];
 }

 void input()
 {
  cout << " \n\t\t\t Enter the positive Set...\n\t\t\t ";
  for( int i = 1; i <= n; i++ )
  { cin >> set[i]; cout << " \n\t\t\t "; }
 }

 int max( int x, int y )
 {
  if( x > y )
  return x;
  else
  return y;
 }

 bool subset_sum()
 {
  for( int i = 0; i <= w; i++ )
  arr[0][i] = 0;

  for( int i = 0; i <= n; i++ )
  arr[i][0] = 0;

  for( int i = 1; i <= n; i++ )
  {
   for( int j = 1; j <= w; j++ )
   {
    if( j < set[i] )
    arr[i][j] = arr[i - 1][j];
    
    else
    arr[i][j] = max( arr[i - 1][j], set[i] + ( arr[i - 1][j - set[i] ] ) );
   }
  }

  /*for( int i = n; i >= 0; i-- )
  {
   for( int j = 0; j <= w; j++ )
   cout << arr[i][j] <<"   ";
   cout << endl;
  }
 */
 
  if( arr[n][w] == w )
  return true;
  else
  return false;
 }

 void backtrack( int i, int W )
 {
  if( i == 0 || W == 0 )
  return;
  else
  {
   if( set[i] > W || arr[i][W] == arr[i - 1][W] )
   backtrack( i-1, W );
   else
   {
    cout << i << " ";
    backtrack( i - 1, W - set[i] );
   }
  }
 }

 void print()
 {
  cout << " \n\t\t\t Positions of elements Included : \n\t\t\t ";
  backtrack( n, w );
  cout << endl;
 }

};

int main()
{
 cout << " \n\t\t\t SUBSET SUM PROBLEM \n\t\t\t ";
 int count,sum;
 cout << " \n\t\t\t Enter the count of Numbers in a Set : \n\t\t\t ";
 cin >> count;
 cout << " \n\t\t\t Enter the Sum Expected : \n\t\t\t ";
 cin >> sum;

 SubSet *obj = new SubSet( count, sum );
 obj -> input();

 if( obj -> subset_sum() )
 {
  cout << " \n\t\t\t Yes, A subset can be Created... \n\t\t\t ";
  obj -> print();
 }  
 
 else
 cout << " \n\t\t\t No, A subset can't be Created...\n\t\t\t ";

 cout << "\n\n";
 return 0;
}

