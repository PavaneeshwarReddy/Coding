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


void zigZag(Node * root)
{
  if(root==nullptr)
    return;
  queue<Node *>q;
  q.push(root);
  int level=1;
  while(q.size())
  {
    int s=q.size();
    vector<int>temp_vec;
    while(s--)
    {
      Node *temp=q.front();
      q.pop();
      temp_vec.push_back(temp->data);
      if(temp->left!=nullptr)
        q.push(temp->left);
      if(temp->right!=nullptr)
        q.push(temp->right);
    }
    if(level%2!=0)
      reverse(temp_vec.begin(),temp_vec.end());
    for(int i=0;i<int(temp_vec.size());i++)
      cout<<temp_vec[i]<<" ";
    level++;
  }



}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,temp;
    cin>>n;
    Node *root=nullptr;
    while(n--)
    {
      cin>>temp;
      root=insert(root,temp);
    }
    zigZag(root);
    cout<<endl;
  }
  

}
