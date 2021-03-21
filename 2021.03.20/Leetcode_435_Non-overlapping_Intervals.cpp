#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;


/***
 * 
 *  贪心算法，
 *  按照起点排序：
 *  选择结尾最短的，后面才可能连接更多的区间
 * （如果两个区间有重叠，应该保留结尾小的）
 *  把问题转化为最多能保留多少个区间，使他们互不重复，
 *  则按照终点排序，每个区间的结尾很重要，结尾越小，则后面越有可能容纳更多的区间。
 
 ***/

class Solution{
    public:
    int eraseOverlapItervals(vector<vector<int>>& intervals){
        if (intervals.empty()){
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int> & b){
              return a[1]<b[1];
        });
        int size = intervals.size();
        int total =0, pre = intervals[0][1]; 
        for (int i=1; i < size; ++i)
        {
            if(intervals[i][0]<pre){
                ++total;
            }else{
              pre = intervals[i][1];
            }
        }
       return total;
    }
};

void printTwoDimArr(vector<vector<int>>& obj)
{
    int length = obj.size();
    for(int i=0; i<length; i++){
        for(int j=0; j<obj[i].size(); j++)
        {
            cout<<" "<<obj[i][j]<<","; 
        }
        cout<<endl;
    }
        cout<<"******************************"<<endl;
};

bool comp(vector<int> &a, vector<int>&b)
{
    return a[1]<b[1];
}


static bool compare (const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int main(){
    Solution solution;
    int N =4, M=2;
    vector<vector<int>> intervals(N, vector<int> (M));

    // 
    // for (int i=0; i<intervals.size(); i++)
    // {
    //     for (int j=0; j<intervals[i].size(); j++)
    //     { 
    //         intervals[i][j]=i+j+1;
    //     }
    // }    
     
    intervals[0][0]= 1;
    intervals[0][1]= 2;
    intervals[1][0]= 2;
    intervals[1][1]= 3;
    intervals[2][0]= 3;
    intervals[2][1]= 4;
    intervals[3][0]= 1;
    intervals[3][1]= 3;
    
    // solution.eraseOverlapItervals(intervals);
    printTwoDimArr(intervals);
    sort(intervals.begin(),intervals.end(),compare);
    printTwoDimArr(intervals);

    system("pause");
    return 0;
}