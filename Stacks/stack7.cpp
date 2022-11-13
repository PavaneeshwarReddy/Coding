//largest area submatrix with all one's
//it is same as we histogram but here we go column wise
#include<bits/stdc++.h>
using namespace std;
void prevSmaller(int ar[],vector<int>&left)
{
	for(int i=0;i<5;i++)
		left[i]=-1;
	stack<int>s;
	for(int i=0;i<5;i++)
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
	for(int i=0;i<5;i++)
		right[i]=5;
	stack<int>s;
	for(int i=4;i>=0;i--)
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
	int ar[6][5]={{1,1,0,1,1},{1,1,1,1,1},{0,1,1,1,1},{1,1,1,1,1},{1,0,1,1,1},{1,1,1,1,1}};
	int temp[5]={1,1,0,1,1};//a[0]
	int maxArea=0;
	vector<int>right(5,5);
	vector<int>left(5,-1);
	prevSmaller(temp,left);
	nextSmaller(temp,right);
	for(int i=0;i<5;i++)
	{
		maxArea=max((right[i]-left[i]-1)*temp[i],maxArea);
	}


	for(int i=1;i<=5;i++)
	{
		
		
		//checking the upper row values for each cell if they are one we add them(+1) to our current cell
		for(int j=0;j<5;j++)
		{
			if(ar[i][j]==0)
			{
				temp[j]=0;
			}
			else if(ar[i][j]==1 && ar[i-1][j]==1)
			{
				temp[j]+=1;
			}
			else if(ar[i][j]==1)
			{
				temp[j]=1;
			}
		}

		cout<<"temp:"<<endl;
		for(int i=0;i<5;i++)
			cout<<temp[i]<<" ";
		cout<<endl;
		prevSmaller(temp,left);
		nextSmaller(temp,right);
		cout<<"left:";
		for(int i=0;i<5;i++)
			cout<<left[i]<<" ";
		cout<<endl;
		cout<<"right:";
		for(int i=0;i<5;i++)
			cout<<right[i]<<" ";
		cout<<endl;
		for(int j=0;j<5;j++)
		{
		
				maxArea=max((right[j]-left[j]-1)*temp[j],maxArea);
		}


	}

	cout<<"maxArea: "<<maxArea<<endl;


} 