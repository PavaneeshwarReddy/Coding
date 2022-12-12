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


void bottomUp(Node * root)
{
    if(root==nullptr)
      return;
    queue<Node *>q;
    stack<int>ele;
    stack<int>count;

    q.push(root);
    while(q.size()!=0)
    {
      int s=q.size();
      //for maintaining no of elements in each level
      count.push(s);
      while(s--)
      {
        Node * temp=q.front();
        q.pop();
        //sotring all the elements such that when popped and print they print in reverse level-order
        ele.push(temp->data);
        if(temp->left!=nullptr)
          q.push(temp->left);
        if(temp->right!=nullptr)
          q.push(temp->right);

      }
    }

    while(ele.size()!=0){
      int s=count.top();
      int s2=s;
      count.pop();
      stack<int>temp;
      while(s--)
        {
          temp.push(ele.top());
          ele.pop();
        }
      while(s2--)
      {
        cout<<temp.top()<<" ";
        temp.pop();
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
    int n,temp;
    cin>>n;
    Node *root=nullptr;
    while(n--)
    {
      cin>>temp;
      root=insert(root,temp);
    }
    bottomUp(root);
    cout<<endl;
  }
  

}
