#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        unordered_map<int,int> record;
        unordered_map<int,int>::iterator it;
        for(int i=0; i< numbers.size();i++){
            it = record.find(target-numbers[i]);
            if(it != record.end())
            {
               res.push_back(record[target-numbers[i]]+1);
               res.push_back(i+1);
               return res;
            }
            record[numbers[i]]=i;            
        }
        return res;
    }
    
};


// 双指针:缩减搜索空间

class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i =0;
        int j = numbers.size() -1;
        while(i<j){
            int sum = numbers[i]+numbers[j];
            if(sum<target)
            {
                i++;
            }
            else if (sum>target)
            {
                j--;
            }
            else
            {
                return vector<int>{i+1,j+1};
            }
        }
        return vector<int>{-1, -1};
    }
};

int main(int argc, char const *argv[])
{
    
    system("pause");
    return 0;
}

