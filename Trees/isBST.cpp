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

Node *findReplace(Node *root,Node *temp)
{
  if(root==nullptr)
    return temp;
  if(root->data==temp->data)
  {
    root=temp;
    return root;
  }
  if(root->data>temp->data)
    root->left=findReplace(root->left,temp);
  else
    root->right=findReplace(root->right,temp);
  return root;
}


void inorder(Node * root)
{
  if(root==nullptr)
    return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}


bool isCurrBST(int &curr,int &prev)
{
  if(curr<prev)
    return false;
  prev=curr;
  return true;
}


//inorder traversal and checking
bool isBST(Node *root,int &prev)
{
    if(root==nullptr)
      return true;
    

    return (isBST(root->left,prev) && (isCurrBST(root->data,prev)) && (isBST(root->right,prev)));
    
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int ar[n+1];
    Node *root=nullptr;
    for(int i=1;i<=n;i++)
    {
      cin>>ar[i];
    }

    for(int i=1;i<=n;i++)
    {
       Node *temp=new Node(ar[i]);
       if(2*i<=n)
       {
         Node *tempL=new Node(ar[2*i]);
         temp->left=tempL;
       }
       if(2*i+1<=n)
       {
         Node *tempR=new Node(ar[2*i+1]);
         temp->right=tempR;
       }
       root=findReplace(root,temp);

    }
    //inorder(root);
    //cout<<endl;
    int prev=INT_MIN;
    isBST(root,prev)?cout<<"Yes"<<endl:cout<<"No"<<endl;

  }
}
