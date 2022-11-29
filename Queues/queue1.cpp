//circular queue implementation
#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
int front,rear;
vector<int>cqueue;
int n;
    MyCircularQueue(int k) {
            front=-1;
            rear=-1;
            n=k;
        cqueue.resize(k);
    }
    
    bool enQueue(int value) {
        
        if(isFull()==false)
        {
            rear=(rear+1)%n;
            if(front==-1)
                front=0;
            cqueue[rear]=value;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(isEmpty()==false)
        {
            if(rear==front)
            {
                rear=-1;
                front=-1;
            }
            else
            {
                front=(front+1)%n;
            }
            return true;
        }
        return false;
    }
    
    int Front() {
       if(isEmpty())
           return -1;
         return cqueue[front];
    }
    
    int Rear() {
        if(isEmpty())
           return -1;
         return cqueue[rear];
    }
    
    bool isEmpty() {
        if(front==-1 && rear==-1)
        return true;
        return false;
    }
    
    bool isFull() {
        if(((rear+1)%n)==front)
        return true;
        return false;
    }
};

