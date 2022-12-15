#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
  int data;
  Node *left,*right;
  Node(int val)
  {
    left=nullptr;
    right=nullptr;
    data=val;
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

//here we do preorder traversal
void verticalLevelOrder(Node *root,map<int,set<int>>&m,int vLevel)
{
  if(root==nullptr)
    return;
  m[vLevel].insert(root->data);
  verticalLevelOrder(root->left,m,vLevel-1);
  verticalLevelOrder(root->right,m,vLevel+1);
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
      int temp;
      cin>>temp;
      root=insert(root,temp);
    }
    map<int,set<int>>m;
    verticalLevelOrder(root,m,0);
    for(auto i:m)
    {
      for(auto j:i.second)
      {
        cout<<j<<" ";
      }
        cout<<endl;
    }

  }
}

