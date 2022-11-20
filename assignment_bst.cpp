// declare and initialize and array
int x[6] = {19, 10, 8, 17, 9, 15};
// constructing bst from array given
#include<iostream>
using namespace std;
typedef struct node
{
   int value;
   node * pLeft;
   node * pRight;
   node(int val = 0)
   {
      value = val;
      pRight = NULL;
      pLeft = NULL;
   }
}node;
void insert(node ** pRoot, int val)
{
    if(*pRoot == NULL)
        *pRoot = new node(val);
    else if((*pRoot)->value <= val)
        insert(&((*pRoot)->pRight), val);
    else if((*pRoot)->value > val)
        insert(&((*pRoot)->pLeft), val);
}
node * getBST(int * arr, int size)
{
    node * pRoot = NULL;
    for(int i = 0; i < size; i++)
        insert(&pRoot, arr[i]);
    return pRoot;
}
void inOrderTraversal(node * pRoot)
{
    if(pRoot && pRoot->pLeft)
        inOrderTraversal(pRoot->pLeft);
    if(pRoot)
        std::cout<<pRoot->value<<" , ";
    if(pRoot && pRoot->pRight)
        inOrderTraversal(pRoot->pRight);

}
// deleting node from bst
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->pLeft != NULL)
    current = current->pLeft;

  return current;
}
struct node *deleteNode(struct node *root, int  value) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if ( value < root-> value)
    root->pLeft = deleteNode(root->pLeft,  value);
  else if ( value > root-> value)
    root->pRight = deleteNode(root->pRight,  value);
  else {
    // If the node is with only one child or no child
    if (root->pLeft == NULL) {
      struct node *temp = root->pRight;
      free(root);
      return temp;
    } else if (root->pRight == NULL) {
      struct node *temp = root->pLeft;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->pRight);

    // Place the inorder successor in position of the node to be deleted
    root-> value = temp-> value;

    // Delete the inorder successor
    root->pRight = deleteNode(root->pRight, temp-> value);
  }
  return root;
}
//main code
int main(){
  
  node * pRoot = getBST(x, sizeof(x)/sizeof(int));
  cout << "\nBefore deleting \n";
  cout << "Inorder traversal: ";
  inOrderTraversal(pRoot);
  cout<<endl;
  cout<<"Deleting node of bst"<<endl;
  cout << "\nAfter deleting 10\n";
  pRoot = deleteNode(pRoot, 10);
  cout << "Inorder traversal: ";
  inOrderTraversal(pRoot);
  cout<<endl;
  cout<<"Deleting element of array"<<endl;
  int  tot=6, i, elem, j, found=0;
    cout<<"\nEnter Element to Delete: ";
    cin>>elem;
    for(i=0; i<tot; i++)
    {
        if(x[i]==elem)
        {
            for(j=i; j<(tot-1); j++)
                x[j] = x[j+1];
            found++;
            i--;
            tot--;
        }
    }
    if(found==0)
        cout<<"\nElement doesn't found in the Array!";
    else
        cout<<"\nElement Deleted Successfully!";
    cout<<endl;
    return 0;
}
//space complexity
//The space complexity for all the operations is O(n).->For BST
//If you need to create an array of size n, this will take O(n) space. If you build a two-dimensional array of size n*n, this will need O(n2) space.
