#include<bits/stdc++.h>
using namespace std;

class Node 
{
  public:
    int data;
    Node *left,*right;
    Node(int val)
    {
      left=nullptr;right=nullptr;data=val;
    }
};


Node* insert(Node *root,int val)
{
  if(root==nullptr)
    return new Node(val);
  if(root->data>val)
    root->left=insert(root->left,val);
  else
    root->right=insert(root->right,val);
  return root;
}


int height(Node * root)
{
  if(root==nullptr)
    return -1;
  return max(height(root->left),height(root->right))+1;
}

bool isBalanced(Node *root)
{
  if(root==nullptr)
    return true;
  
  if(abs(height(root->left)-height(root->right))>1)
    return false;
  return (isBalanced(root->left) && isBalanced(root->right));
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    Node *root=nullptr;
    while(n--)
    {
      int q;
      cin>>q;
      root=insert(root,q);
    }
    if(isBalanced(root))
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
}

