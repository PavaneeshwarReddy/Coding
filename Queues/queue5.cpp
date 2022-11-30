/*
Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.
*/


#include<bits/stdc++.h>
using namespace std;


class ProductOfNumbers {
public:
vector<int>v;
    ProductOfNumbers() {
        
            v.clear();
        v.push_back(1);
    }
    
    void add(int num) {
        if(num==0)
        {
         
            v.clear();
            v.push_back(1);
        }
        else
        v.push_back(num*v.back());
    }
    
    int getProduct(int k) {
        int x=v.size();
        if(x-k-1<0) return 0;
        return v.back()/v[x-k-1];
    }
};