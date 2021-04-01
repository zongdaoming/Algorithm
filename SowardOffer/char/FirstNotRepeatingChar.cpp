#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int FirstNotRepeatingChar(string str){
        unordered_map<char,int> cMap;
        for(int i = 0; i<str.size(); i++)
        {
            unordered_map<char,int>::iterator it;
            it = cMap.find(str[i]);
            if (it==cMap.end()){
                // cMap.insert(map<char,int>::value_type(str[i],1));
                cMap.insert(pair<char,int>(str[i],1));
            }
            else{
                cMap[str[i]]++;
            }
        }
        for (int i = 0; i<str.size(); i++)
        {
            if(cMap[str[i]]==1)
            {
                return i;
            }
        }
        return -1;
        }
};