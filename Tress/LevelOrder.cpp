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
    left=nullptr;right=nullptr;
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


void inorder(Node *root)
{
  if(root==nullptr)
    return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void levelOrder(Node *root)
{
    queue<Node *>q;
    if(root==nullptr)
      return;
    q.push(root);
    while(q.size()!=0)
    {
        int s=q.size();
        while(s--)
        {
          Node *temp=q.front();
          q.pop();
          cout<<temp->data<<" ";
          if(temp->left!=nullptr)
            q.push(temp->left);
          if(temp->right!=nullptr)
            q.push(temp->right);
        }
        cout<<endl;
    }


}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int temp,n;
    cin>>n;
    Node *root=nullptr;
    while(n--)
    {
      cin>>temp;
      root=insert(root,temp);
    }
    //inorder(root);
    levelOrder(root);
    cout<<endl;
  }
}

