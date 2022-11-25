#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<long long int>v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		int flag=0;
		
		bool incre=false;
		for(int i=1;i<n;i++)
		{
			if(v[i]>v[i-1])
			{
				incre=true;
			}
			else if(v[i]<v[i-1] && incre==true)
			{
				flag=1;
				break;
			}

		}
		flag==1?cout<<"NO"<<endl:cout<<"YES"<<endl;
	}
}

