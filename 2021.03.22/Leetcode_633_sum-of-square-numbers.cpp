#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using namespace std;

// 二分查找

class Solution {
public:

    bool binary_search(unsigned s,unsigned e, int n){
        // 终止条件
        if(s>e){
            return false;
        }
        // 命名二分变量mid
        unsigned int mid = s+ (e-s)/2;
        
        if (mid*mid==n){
            return true;
        }
        if (mid*mid<n){
            return binary_search(mid+1, e, n);
        }
        // bool函数必须有type 为bool的返回值
        return binary_search(s, mid-1, n);

    }

    bool judgeSquareSum(int c) {
        for(unsigned int a=0; a*a<=c; a++){
            unsigned int b_square = c-a*a;
            if(binary_search(0,sqrt(b_square),b_square))
            {
                return true;
            } 
        }
        return false;
    }

};







//  简单双指针
class Solution2 {
public:
    bool judgeSquareSum(int c) {
        // 双指针
        int max = sqrt(c);
        unsigned int i=0, j=max;
        bool flag = false;
        unsigned int temp = -1;
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

int main(int argc, char const *argv[])
{
    int c;
    Solution solution;
    c=5;
    if (solution.judgeSquareSum(c)){
        cout<<"Judge Results is: True"<<endl;
    }else{
        cout<<'Judge Results is: False'<<endl;
    }
    system("pause");
    return 0;
}
