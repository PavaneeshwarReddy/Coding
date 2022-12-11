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

Node* insert(Node *root,int val)
{
    if(root==nullptr)
        return new Node(val);
    if(root->data>val)
        root->left = insert(root->left,val);
    else
        root->right=insert(root->right,val);
    return root;
}
void preorder(Node *root)
{
    if(root==nullptr)
        return;
     cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

bool search(Node * root,int val)
{
	if(root==nullptr)
	return false;
	if(root->data==val)
	return true;
	return (search(root->left,val) || search(root->right,val));
}

Node * findMinNode(Node* root)
{
	Node * temp=root;

	while(temp!=nullptr && temp->left!=nullptr)
	{
		temp=temp->left;
	}
	return temp;
}		

Node * Delete(Node *root,int val)
{
	if(root==nullptr)
	return nullptr;
	if(root->data==val)
	{
		if((root->left)==nullptr && (root->right)==nullptr)
			return nullptr;
		else if((root->left==nullptr))
			return root->right->right;
		else if(root->right==nullptr)
			return root->left->left;
		else{
			Node * temp=findMinNode(root->right);
			root->data=temp->data;
			root=Delete(root->right,temp->data);
		 }
	}
	if(root->data>val) root->left=Delete(root->left,val);
	else root->right = Delete(root->right,val);
	return root;
}
			

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int q;
		cin>>q;
		Node *root=nullptr;
		while(q--)
		{
			int n1,n2;
			cin>>n1;
			if(n1!=4)
			cin>>n2;
			if(n1==1)
			root=insert(root,n2);
			else if(n1==4)
			{ preorder(root);cout<<endl;}
			else if(n1==2)
			root=Delete(root,n2);
			else if(n1==3)
			{
			if(search(root,n2))cout<<"Yes"<<endl; else cout<<"No"<<endl;
			}
			
		}
	}


}
