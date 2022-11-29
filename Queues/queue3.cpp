#include<bits/stdc++.h>
using namespace std;



/*
The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int>sand;
		queue<int>stud;
		for(int i=0;i<students.size();i++)
		stud.push(students[i]);
		for(int i=0;i<sandwiches.size();i++)
		sand.push(sandwiches[i]);

		int counter=0;
		while(sand.size()!=0 && stud.size()!=0)
		{
			if(sand.top()==stud.front())
			{
				sand.pop();
				stud.pop();
				counter=0;
			}
			else
			{
				int temp=stud.front();
				stud.pop();
				stud.push(temp);
				counter++;
				if(counter==stud.size())
				break;
			}
		}

		return stud.size();

    }
};