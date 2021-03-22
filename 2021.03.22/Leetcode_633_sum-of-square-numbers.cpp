#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool judgeSquareSum(int c) {
        // 双指针
        int max = c/2+1;
        long int i=0, j=max;
        bool flag = false;
        long int temp = -1;
        while(i<=max && j>=0)
        {
            temp = i*i + j*j; 
            if(temp==c){
                flag=true;
                break;
            }else if(temp>c){
                j--;
                continue;
            }else if(temp<c)
            {
                i++;
                continue;
           }
        }
       return flag;
    }
};