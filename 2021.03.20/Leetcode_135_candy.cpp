#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=0;        
        vector<int> candy_num;
        for (int i=0; i<ratings.size(); i++)
        {
            candy_num.push_back(1);
        }

        for (int i=0; i< ratings.size()-1; i++)
        {
            if (ratings[i+1]>ratings[i])
            {
                candy_num[i+1]= candy_num[i]+1; 
            }
        }

        for (int j=ratings.size()-1; j >=1; j--)
        {
            if(ratings[j]<ratings[j-1] && candy_num[j-1]<=candy_num[j] )
            {
                candy_num[j-1] = candy_num[j]+1;
            }
        }

        for (int k=0; k<ratings.size();k++)
        {
            sum+=candy_num[k];
        }
        return sum;
    }

};

// Beautiful Solutions;


class Solution {
public:
int candy(vector<int> & ratings){
    int size = ratings.size();
    if (size<2)
    {
        return  size;
    }
    vector<int> num(size,1); //初始化vector数组为1
    for(int i=1; i<size; ++i){
        if(ratings[i]>ratings[i-1]){
            num[i]=num[i-1]+1;
        }
    }
    for(int i=size-1; i>0; --i){
        num[i-1] = max(num[i-1],num[i]+1);
    }
        
    return accumulate(num.begin(),num.end(),0); // std:accumulate 可以很方便地求和
    
}
};

