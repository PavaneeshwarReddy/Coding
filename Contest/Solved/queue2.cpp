//https://www.hackerrank.com/challenges/truck-tour/problem?isFullScreen=false
//circular Queue implementation
//circular Petrol Pump
#include<bits/stdc++.h>
using namespace std;
int main()
{
		int n;
		cin>>n;
		vector<pair<int,int>>pumps;
		for(int i=0;i<n;i++)
		{
			pair<int,int>p;
			cin>>p.first>>p.second;
			pumps.push_back(p);
		}
		

		int flag=0,balance=0;
		int front=0,rear=0;
		while(flag==0)
		{
			
			balance+=pumps[front].first-pumps[front].second;
			front==n-1?front=0:front++;
			if(balance<0)
			{
				rear=front;
				balance=0;
			}
			else if(front==rear)
			{
				flag=rear;
				break;
			}
			//cout<<"balance "<<balance<<endl;

		}
		cout<<rear<<endl;
		

}