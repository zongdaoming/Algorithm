#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param height int整型vector 木桩的高度数组，数组长度不大于100000
     * @return int整型
     */
    int maxWater(vector<int>& height) {
        // write code here
        int length = height.size();
        // lenght = 9
        if(length == 0 ||length==1) return 0;

        int ans = 0;
        vector<int> lMax(length,0);
        vector<int> rMax(length,0);

        // initialize left max vector
        lMax[0] = height[0];
        for(int i = 1; i<length; i++)
        {
            lMax[i] = max(lMax[i-1],height[i]);
            cout<< "lmax i" <<lMax[i]<<endl;
        }
        
        // initialize right max vector
        rMax[length-1] = height[length-1];

        for(int i = length-2; i>=0; i--)
        {
            rMax[i] = max(rMax[i+1],height[i]);
            cout<< "rmax i" <<lMax[i]<<endl;
        }

        int i, j =0;

        // 严格控制边界
        while(j<length)
        {
            int flag = height[i];
            while(i<length-1 && height[i]==height[i+1])
            {
                i++;
            }
            j = i+1;
            int sum = 0;
            while(height[j]<flag && j<length)
            {
                sum += min(lMax[j],rMax[j])-height[j];
                j++;
            }
            ans = max(ans,sum);
            i = j;
        }
        return ans;
        // for(int i = 0;i<length;i++)
        // {
        //     ans+= min(lMax[i],rMax[i])-height[i];
        // }
        // return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    vector<int> height={4, 3, 2, 1, 3, 0, 5, 5, 0, 1,1, 4};
    Solution solu;
    int ans = solu.maxWater(height);
    cout<<ans<<endl;
    return 0;
}
