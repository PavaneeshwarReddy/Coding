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
		string str;
		cin>>str;
		int ar[27]={0};
		for(int i=0;i<n;i++)
		{
			ar[str[i]-96]=1;
		}
		int res=0;
		for(int i=1;i<=26;i++)
			if(ar[i]==1)
				res=i;
		cout<<"Result - "<<res<<endl;
	}
}