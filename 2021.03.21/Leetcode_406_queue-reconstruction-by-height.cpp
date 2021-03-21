#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/***
 * 
 * 渔（套路）：一般这种数对，还涉及排序的，
 * 根据第一个元素正向排序，根据第二个元素反向排序，
 * 或者根据第一个元素反向排序，根据第二个元素正向排序，
 * 往往能够简化解题过程。
***/

void printFun(vector<vector<int>>& obj)
{
    for(int i=0; i<obj.size(); i++)
    {
        for(int j=0; j<obj[i].size();j++)
        {
            cout<<" "<<obj[i][j]<<" ";
        }
        cout<<endl;
    }
};


class Solution{
    public:
        static bool cmp(const vector<int> &a, const vector<int> &b)
        {
            return (a[0]==b[0] && a[1]<b[1] || a[0]>b[0]);
        }
        vector<vector<int>> reconstructQueue(vector<vector<int>> & people)
        {
           vector<vector<int>> res;  
           sort(people.begin(),people.end(), cmp);
           printFun(people);
           return res;
        }
};



int main(int argc, char const *argv[])
{
    int M = 6, N=2;
    vector<vector<int>> people(M, vector<int> (2));
    Solution solution;

    cout<<"Please input data:  "<<endl;
    for(int i =0; i<people.size(); i++)
    {
        for(int j=0; j<people[i].size();j++)
        {
            cin>>people[i][j];
        }

    }
    solution.reconstructQueue(people);


    system("pause");
    return 0;
}
