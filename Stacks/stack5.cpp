//previous smaller element in the array, for every element
//5 15 20 25 12 20
//-1 5 15 20  5 12


//same can be applied for previous greater element
// 5 15 20 25 12 20
//-1 12 12 12 -1 -1
#include<bits/stdc++.h>
using namespace std;

void prevSmaller()
{
	int ar[6]={5,15,20,25,12,20};
	stack<int>s;
	for(int i=0;i<6;i++)
	{
		int flag=0;
		while(s.empty()==false)
		{
			if(s.top()<ar[i])
			{
				flag=1;
				cout<<s.top()<<endl;
				break;
			}
			else
				s.pop();

		}
		s.push(ar[i]);
		if(flag==0)
			cout<<-1<<endl;
	}
}

void nextSmaller()
{
	int ar[6]={5,15,20,25,12,20};
	stack<int>s;
	for(int i=5;i>=0;i--)
	{
		int flag=0;
		while(s.empty()==false)
		{
			if(s.top()<ar[i])
			{
				flag=1;
				cout<<s.top()<<endl;
				break;
			}
			else
				s.pop();

		}
		s.push(ar[i]);
		if(flag==0)
			cout<<-1<<endl;
	}
}
int main()
{
	cout<<"prev:"<<endl;
	prevSmaller();
	cout<<"next:"<<endl;
	nextSmaller();
}