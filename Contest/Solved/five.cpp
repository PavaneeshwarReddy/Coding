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
		vector<int>v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		vector<int>ones(n,0);
		vector<int>zeroes(n,0);
		int o=0,z=0;
		for(int i=n-1;i>=0;i--)
		{
			if(v[i]==1)
				o++;
			else
				z++;
			zeroes[i]=z;
			ones[i]=o;
		}



			// for(int i=0;i<n;i++)
			// 	cout<<ones[i]<<" ";
			// cout<<endl;
			// for(int i=0;i<n;i++)
			// 	cout<<zeroes[i]<<" ";
			// cout<<endl;




		
	}
}


/*
1
6
0 1 0 0 1 0


0 1 0 0 1 0
4 3 3 2 1 1
2 2 1 1 1 0 
0 3 0 0 1 0

1 1 1
0 0 0
3 2 1 

*/
