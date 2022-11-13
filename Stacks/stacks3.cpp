    //https://www.hackerrank.com/challenges/simple-text-editor/problem?isFullScreen=false

    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int q;
        cin>>q;
        stack<string>s;
        string str="";
        while(q--)
        {
            int first,sec_int;
            string sec_str;
            cin>>first;
            if(first==1)
                cin>>sec_str;
            else if(first==2||first==3)
                cin>>sec_int;
            if(first==1)
            {

            	//because the string can starts with empty...
                s.push(str);
                str+=sec_str;
                
            }
            else if(first==3)
            {
                //cout<<str<<endl;
                cout<<str[sec_int-1]<<endl;
            }
            else if(first==2)
            {
            	//the current string has to be stores before deleting
                s.push(str);
                str.erase(str.size()-sec_int);
                
            }
            else if(first==4)
            {

            	//the top string will be your undo Change
                str=s.top();
                s.pop();
            }
            
        }
    }