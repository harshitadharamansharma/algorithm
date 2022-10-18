// Menu driven program for RB-Tree 

#include <iostream>
#include <cstdlib>
using namespace std;

#define red 0
#define black 1

class node
{
 public:
 node *right;
 node *left;
 node *parent;
 int key;
 int colour;
 
 node( int k = -1 )
 {
  right = left = parent = 0;
  colour = red;
  key = k;
  
  if( key == -1 )
  colour = black;
 }
}nil;

node *tree_minimum( node *x )
{
 while( x -> left != &nil )
 {
  x = x -> left;
 }
 return x;
}

class RBT
{
 public:
 node *root;
 RBT()
 {
  root = &nil;
 }
 
 void inorder( node *x );
 void left_rotate( node *x );
 void right_rotate( node *y );
 void rb_insert( node *z );
 void rb_insertFixup( node *z );
 void rb_transplant( node *u, node *v );
 void rb_delete( node *z );
 void rb_deleteFixup( node *z );
 node *tree_search( node *x, int key );
 friend node *tree_minimum( node *x );
};

void RBT :: inorder( node *x )
{
 if( x != &nil )
 {
  inorder( x -> left );
  if( x -> colour == black )
  cout << "(" << x -> key << ",b) \t ";
  else
  cout << "(" << x -> key << ",r) \t ";
  inorder( x -> right );
 }
}

void RBT :: left_rotate( node *x )
{
 if( x -> right != &nil )
 {
  node *y = x -> right;
  x -> right = y -> left;
  if( y -> left != &nil )
  y -> left -> parent = x;
  y -> parent = x -> parent;
  if( x -> parent == &nil )
  root = y;
  else if (x == x->parent->left)
  x->parent->left = y;
  else
  x->parent->right = y;
  y->left = x;
  x->parent = y;
 }
}

void RBT :: right_rotate( node *y )
{
 if( y -> left != &nil )
 {
  node *x = y -> left;
  y -> left = x -> right;
  if( x -> right != &nil )
  x -> right -> parent = y;
  x -> parent = y -> parent;
  if( y -> parent == &nil )
  root = x;
  else if( y == y -> parent -> right )
  y -> parent -> right = x;
  else
  y -> parent -> left = x;
  x -> right = y;
  y -> parent = x;
 }
}

void RBT :: rb_insert( node *z )
{
 node *y = &nil;
 node *x = root;
 while( x != &nil )
 {
  y = x;
  if( z -> key < x -> key )
  x = x -> left;
  else
  x = x -> right;
 }
 
 z -> parent = y;
 
 if( y == &nil )
 root = z;
 
 else if( z -> key < y -> key )
 y -> left = z;
 
 else
 y -> right = z;
 z -> left = &nil;
 z -> right = &nil;
 z -> colour = red;
 rb_insertFixup(z);
}

void RBT :: rb_insertFixup( node *z )
{
 while( z->parent->colour == red )
 {
  node *y;
  if( z -> parent == z -> parent -> parent -> left )
  {
   y = z -> parent -> parent -> right;
   if( y -> colour == red )
   {
    z -> parent -> colour = black;
    y -> colour = black;
    z -> parent -> parent -> colour = red;
    z = z -> parent -> parent;
   }
            
   else
   {
    if( z == z -> parent -> right )
    {
     z = z -> parent;
     left_rotate( z -> parent -> parent );
    }
    z -> parent -> colour = black;
    z -> parent -> parent-> colour = red;
    right_rotate ( z -> parent -> parent );
   }
  }
  else
  {
   y = z -> parent -> parent -> left;
   if( y -> colour == red )
   {
    z -> parent -> colour = black;
    y -> colour = black;
    z -> parent -> parent -> colour = red;
    z = z -> parent -> parent;
   }
   else
   {
    if( z == z -> parent -> left )
    {
     z = z -> parent;
     right_rotate(z->parent->parent);
    }
    z -> parent -> colour = black;
    z -> parent -> parent -> colour = red;
    left_rotate( z -> parent -> parent );
   }
  }
 }
 root -> colour = black;
}

void RBT :: rb_transplant( node *u, node *v )
{
 if( u -> parent == &nil )
 root = v;
 else if( u == u -> parent -> left )
 u -> parent -> left = v;
 else
 u -> parent -> right = v;
 v -> parent = u -> parent;
}

node *RBT :: tree_search( node *x, int k )
{
 if( x == &nil || k == x -> key )
 return x;
 if( k < x -> key )
 return tree_search( x -> left, k );
 else
 return tree_search( x -> right, k );
}

void RBT :: rb_delete( node *z )
{
 node *x;
 node *y = z;
 int y_original_colour = y -> colour;
 
 if( z -> left == &nil )
 {
  x = z -> right;
  rb_transplant( z, z -> right );
 }
 
 else if( z -> right == &nil )
 {
  x = z -> left;
  rb_transplant( z, z -> left );
 }
 
 else
 {
  y = tree_minimum (z->right);
  y_original_colour = y->colour;
  x = y->right;
  
  if (y->parent == z)
  x->parent = y;
  else
  {
   rb_transplant(y,y->right);
   y->right = z->right;
   y->right->parent = y;
  }
  rb_transplant(z,y);
  y->left = z->left;
  y->left->parent = y;
  y->colour = z-> colour;
 }
 
 delete z;
   
 if( y_original_colour == black )
 rb_deleteFixup( x );
}

void RBT :: rb_deleteFixup( node *x )
{
 node *w;
 while( x != root && x -> colour == black )
 {
  if( x == x -> parent -> left )
  {
   w = x -> parent -> right;
   if( w -> colour == red )
   {
    w -> colour == black;
    x -> parent -> colour = red;
    left_rotate( x -> parent );
    w = x->parent->right;
   }
   
   if( w -> left -> colour == black && w -> right -> colour == black )
   {
    w -> colour = red;
    x = x -> parent;
   }
   
   else if( w -> right -> colour == black )
   {
    w -> left -> colour = black;
    w -> colour = red;
    right_rotate( w );
    w = x -> parent -> right;
   }
           
   w -> colour = x -> parent -> colour;
   x -> parent -> colour = black;
   w -> right -> colour = black;
   left_rotate( x -> parent );
   x = root;
  }
  
  else
  {
   w = x -> parent -> left;
   if( w -> colour == red )
   {
    w -> colour == black;
    x -> parent -> colour = red;
    right_rotate( x -> parent );
    w = x -> parent -> left;
   }
   
   if( w -> right -> colour == black && w -> left -> colour == black )
   {
    w -> colour = red;
    x = x -> parent;
   }
   
   else if( w -> left -> colour == black )
   {
    w -> right -> colour = black;
    w -> colour = red;
    left_rotate (w);
    w = x->parent->left;
   }
   
   w -> colour = x -> parent -> colour;
   x -> parent -> colour = black;
   w -> left -> colour = black;
   right_rotate( x -> parent );
   x = root;
   }
  }
  x -> colour = black;
}

int main()
{
 RBT tree;
 node *n;
 char ch = 'y';
 int choice;
 int k;

 cout << " \n\t\t\t PROGRAM FOR RED-BLACK-TREES \n\t\t\t ";
 while(1)
 {
  cout << " \n\t\t\t __________________________________ \n\t\t\t ";
  cout << " \n\t\t\t ---***---***---MENU***---***--- \n\t\t\t ";
  cout << " \n\t\t\t __________________________________ \n\t\t\t ";
  cout << " \n\t\t\t 1. Insertion \n\t\t\t ";
  cout << " \n\t\t\t 2. Search \n\t\t\t ";
  cout << " \n\t\t\t 3. Deletion \n\t\t\t ";
  cout << " \n\t\t\t 4. Display the tree \n\t\t\t ";
  cout << " \n\t\t\t 5. Exit \n\t\t\t ";
  cout << " \n\t\t\t __________________________________ \n\t\t\t ";
  cout << " \n\t\t\t Enter your choice: \n\t\t\t ";
  cin  >> choice;

  if( choice == 1 )
  {
   cout << " \n\t\t\t ---***--- INSERTION---***--- \n\t\t\t ";
   cout << " \n\t\t\t Enter the keys of the tree \n\t\t\t ";
   do
   {
    cout << " \n\t\t\t Enter the key: \n\t\t\t ";
    cin  >> k;
    n = new node( k );
    tree.rb_insert(n);
    if( tree.root -> colour == black )
    cout << " \n\t\t\t Root is: -> (" << tree.root->key << ",b) \n\t\t\t ";
    else
    cout << " \n\t\t\t Root is: -> (" << tree.root->key << ",r) \n\t\t\t ";
    cout << " \n\t\t\t The Red-Black Tree is: \n\t\t\t ";
	tree.inorder(tree.root);
    cout << " \n\t\t\t Do you want to insert more nodes (y/n): \n\t\t\t ";
	cin  >> ch;
   }while(ch == 'y' || ch == 'Y');
            
   if( tree.root -> colour == black )
   cout << " \n\t\t\t Root is: -> (" << tree.root->key << ",b) \n\t\t\t ";
   else
   cout << " \n\t\t\t Root is: -> (" << tree.root->key << ",r) \n\t\t\t ";
   cout << " \n\t\t\t The Red-Black Tree is: \n\t\t\t ";
   tree.inorder(tree.root);
  }
  
  else if( choice == 2 )
  {
   cout << " \n\t\t\t Enter the key of the node you want to search: \n\t\t\t ";
   cin  >> k;
   n = tree.tree_search(tree.root,k);
   if( n == &nil )
   cout << " \n\t\t\t Node not found \n\t\t\t ";
   else
   {
    if( n -> colour == red )
    cout << " \n\t\t\t Node found with RED colour \n\t\t\t ";
    else
    cout << " \n\t\t\t Node found with BLACK colour \n\t\t\t ";
   }
  }
		   
  else if(choice == 3)
  {
   cout << " \n\t\t\t ---***--- DELETION ---***--- \n\t\t\t ";
   do
   {
    cout << " \n\t\t\t Enter the element you want to delete: \n\t\t\t ";
    cin  >> k;
   
    node * z = tree.tree_search (tree.root,k);
   
    if (z != &nil)
    tree.rb_delete(z);
   
    else
    cout << " \n\t\t\t Node not found \n\t\t\t ";
   
    if( tree.root -> colour == black )
    cout << " \n\t\t\t Root is: -> (" << tree.root->key << ",b) \n\t\t\t ";
   
    else
    cout << " \n\t\t\t Root is: -> (" << tree.root->key << ",r) \n\t\t\t ";
    cout << " \n\t\t\t Now the Red-Black Tree is: \n\t\t\t ";
    tree.inorder( tree.root );
    cout << " \n\t\t\t Do you want to delete more nodes(y/n): \n\t\t\t ";
    cin  >> ch;
   }while (ch == 'y' || ch == 'Y');
  }
 
  else if( choice == 4 )
  {
   if( tree.root -> colour == black )
   cout << " \n\t\t\t Root is: -> (" << tree.root->key << ",b) \n\t\t\t ";
  
   else
   cout << " \n\t\t\t Root is: -> (" << tree.root->key << ",r) \n\t\t\t ";
   cout << " \n\t\t\t The Red-Black Tree is: \n\t\t\t ";
   tree.inorder(tree.root);
  }
 
  else if( choice == 5 )
  exit( 0 );
         
  else
  cout << " \n\t\t\t Oops!!!Wrong option \n\t\t\t ";
 }
 
 cout << "\n\n";  
 return 0;
}
