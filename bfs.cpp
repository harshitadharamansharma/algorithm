// Program to implement Breadth-First Search

#include <iostream>
#include <cstdlib>
using namespace std;

int cost[10][10], i, j, k, n, qu[10], front, rare, v, visit[10], visited[10];

int main()
{
 cout << " \n\t\t\t Breadth First Search \n\t\t\t ";
 int m;
 cout << " \n\t\t\t Enter no. of vertices \n\t\t\t ";
 cin >> n;
 cout << " \n\t\t\t Enter no. of edges \n\t\t\t ";
 cin >> m;
 cout << " \n\t\t\t Enter Edges \n\t\t\t ";
 for( k = 1; k <= m; k++ )
 {
  { cin >> i; cout << " \t\t\t "; cin >> j; cout << " \n\t\t\t "; }
  cost[i][j] = 1;
 }

 cout << " \n\t\t\t Enter Initial Vertex \n\t\t\t ";
 cin >> v;
 cout << " \n\t\t\t Visitied Vertices \n\t\t\t ";
 cout << v;
 visited[v] = 1;
 k = 1;
 while( k < n )
 {
  for( j = 1; j <= n; j++ )
  {
   if( cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1 )
   {
    visit[j] = 1;
    qu[rare++] = j;
   }
  }
  
  v = qu[ front++ ];
  cout << " " << v;
  k++;
  visit[v] = 0; visited[v] = 1;
 }
    
 cout << "\n\n";
 return 0;   
}
