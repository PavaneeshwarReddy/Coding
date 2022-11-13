//Max area in the Histogram
//same as before we need to find the left nearest largest and the right nearest largest
#include<bits/stdc++.h>
using namespace std;

void prevSmaller(int ar[],vector<int>&left)
{
	stack<int>s;
	for(int i=0;i<9;i++)
	{
		
		while(s.empty()==false)
		{
			if(ar[s.top()]<ar[i])
			{
				
				left[i]=s.top();
				break;
			}
			else
				s.pop();

		}
		s.push(i);
	}
}

void nextSmaller(int ar[],vector<int>&right)
{
	
	stack<int>s;
	for(int i=8;i>=0;i--)
	{
		
		while(s.empty()==false)
		{
			if(ar[s.top()]<ar[i])
			{
			
				right[i]=s.top();
				break;
			}
			else
				s.pop();

		}
		s.push(i);
	}
}
int main()
{
	int ar[9]={4,2,1,5,6,3,2,4,2};
	vector<int>left(9,-1);
	vector<int>right(9,9);
	prevSmaller(ar,left);
	nextSmaller(ar,right);
	cout<<"Left: ";
	for(int i=0;i<9;i++)
		cout<<left[i]<<" ";
	cout<<endl;
	cout<<"Right: ";
	for(int i=0;i<9;i++)
		cout<<right[i]<<" ";
	cout<<endl;

	int maxArea=0;
	for(int i=0;i<9;i++)
	{
		maxArea=max((right[i]-left[i]-1)*ar[i],maxArea);
	}

	cout<<"maxArea "<<maxArea<<endl;




	
}