#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;    //统计满足的孩子数目
        //贪心：用最小的饼干满足孩子，所以需要将胃口和饼干排序，
        sort(g.begin(),g.end());    
        sort(s.begin(),s.end());
        int i=0,j=0;
        while(i<g.size() && j<s.size()){
            //试图用最小的饼干去满足孩子，如果可以满足，则考虑下一个孩子和下一块饼干；如果无法满足，则考虑下一块饼干
            if(g[i]<=s[j]){
                count++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return count;
    }
};