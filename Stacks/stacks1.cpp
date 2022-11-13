
//https://www.hackerrank.com/challenges/balanced-brackets/problem?isFullScreen=true
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string in;
		cin>>in;
		map<char,char>m;
		m={{'{','}'},{'[',']'},{'(',')'}};
		int flag=0;
		stack<int>st;
		for(int i=0;i<in.length();i++)
		{
			if(in[i]=='{'||in[i]=='['||in[i]=='(')
				st.push(in[i]);
			else
			{
				if(st.size()>0&&(m[st.top()]==in[i] || m[st.top()]==in[i]||m[st.top()]==in[i]))
					st.pop();
				else
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0&&st.top()==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}

					


			
