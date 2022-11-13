//https://www.hackerrank.com/challenges/and-xor-or/problem?isFullScreen=false

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<long long int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	long long int maxRes=0;
	stack<long long int>s;
	for(int i=0;i<n;i++)
	{
		while(s.empty()==false)
		{
			long long int t;
			t=s.top()^v[i];
			maxRes=max(t,maxRes);
			if(v[i]<s.top())
				s.pop();
			else
				break;
		}
		s.push(v[i]);
	}
	cout<<maxRes<<endl;
}