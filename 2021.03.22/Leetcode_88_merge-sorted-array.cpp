#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 双指针:把两个数组看作队列，每次从两个数组头部取出比较小的数字放到结果中
class Solution{
    public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i= 0, j = 0;
        int sorted[m+n];//空间复杂度为o(m+n)
        int cur;
        while(i<m || j<n){
            if(i==m){
                cur = nums2[j++];
            }else if(j==n){
                cur = nums1[i++];
            }else if(nums1[i]<nums2[j]){
                cur=nums1[i++];
            }else{
                cur = nums2[j++];
            }
            sorted[i+j-1]=cur;
        }
        for(int i=0; i!=m+n; ++i)
        {
            nums1[i] = sorted[i];
        }
    }
};

//逆向双指针:指针可以设置为从后向遍历，每次取两者之中的较大者放进nums1的后部






// 最直观的方法是先将数组 nums2  放进数组 nums1的尾部，然后对整个数组进行排序 
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for(int i=0;i!=n; ++i){
        nums1[m+i]=nums2[i];
    }
    sort(nums1.begin(),nums1.end());
};


