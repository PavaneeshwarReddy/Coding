#include<bits/stdc++.h>
using namespace std;

vector<long long int> max_element(long long int a[], int n)
{

	long long int pre[n];
	vector<long long int>v;
	pre[0] = a[0];
	for (int i = 1; i < n; i++)
		pre[i] = max(pre[i - 1], a[i]);
	long long int suf[n];
	suf[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		suf[i] = max(suf[i + 1], a[i]);
	for (int i = 0; i < n; i++) {
		if (i == 0)
			v.push_back(suf[i + 1]);

		else if (i == n - 1)
			v.push_back(pre[i - 1]);

		else
			v.push_back(max(pre[i - 1], suf[i + 1]));
	}

	return v;
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int v[n];
		
		for(int i=0;i<n;i++)
			{
				cin>>v[i];
				
			}

		vector<long long int>res=max_element(v,n);
		for(int i=0;i<n;i++)
		{
			cout<<v[i]-res[i]<<" ";
		}
		cout<<endl;

	}
}