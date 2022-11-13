//https://www.hackerrank.com/challenges/waiter/problem?isFullScreen=false


#include<bits/stdc++.h>
using namespace std;

vector<int> seive()
{
	vector<bool>s(17001,true);
	s[1]=false;
	for(int i=2;i*i<=17000;i++)
	{
		for(int j=2*i;j<=17000;j+=i)
		{
			s[j]=false;
		}
	}
	vector<int>v;
	for(int i=1;i<=17000;i++)
		if(s[i])
			v.push_back(i);
	return v;


}


int main()
{
	int n,q;
	cin>>n>>q;
	int t;
	stack<int>A;
	stack<int>B;
	for(int i=0;i<n;i++)
		{
			cin>>t;
			A.push(t);
		}
	vector<int>se=seive();
	vector<int>ans;
	for(int i=1;i<=q;i++)
	{
		stack<int>temp;
		if(A.size()==0)
			break;
		while(A.size()>0)
		{
			if(A.top()%se[i-1]==0)
			{
				B.push(A.top());
			}
			else
			{
				temp.push(A.top());
			}
			A.pop();
		}

		while(B.size()>0)
		{
			ans.push_back(B.top());
			B.pop();
		}
		stack<int>temp1;
		while(temp.size()>0)
		{
			temp1.push(temp.top());
			temp.pop();
		}

		while(temp1.size()>0)
		{
			A.push(temp1.top());
			temp1.pop();
		}



	}
	while(A.size()>0)
	{
		ans.push_back(A.top());
		A.pop();
	}

	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;


	
}