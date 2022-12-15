#include<bits/stdc++.h>
using namespace std;


class Node
{
  public:
  int data;
  Node *left,*right;
  Node(int val)
  {
    data=val;
    left=nullptr;
    right=nullptr;
  }
};

Node * insert(Node *root,int val)
{
  if(root==nullptr)
    return new Node(val);
  if(root->data>val)
    root->left=insert(root->left,val);
  else
    root->right=insert(root->right,val);
  return root;
}

int getMin(Node * root)
{
  int min=INT_MAX;
  Node *temp=root;
}

int res=0;

bool isCurr(int curr,int prev)
{
    if(curr>prev)
    {
      curr=prev
      return true;
    }
    prev=INT_MIN;
    return false;


bool isBST(Node *root,int prev)
{
  if(root==nullptr)
    return true;
  

  return (isBST(root->left,prev) && () && isBST(root->right,prev));


//we can solve this question using (LRange,RRange) for each node and checking whether it is a BST node or not
bool bst(Node * root,int prev)
{
  if(root==nullptr)
    return 0;
  if((isBST(root->left,prev) && isBST(root->right,prev))
    res++;
}






int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int totalBST=0,prev=INT_MIN;
    Node *root=nullptr;
    while(n--)
    {
      int temp;
      cin>>temp;
      root=insert(root,temp);
    }
    
    bst(root,prev);
    cout<<totalBST<<endl;
    
  }
}
