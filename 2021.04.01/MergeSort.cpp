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
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> ret;
    void Merge(vector<int> &arr, vector<int> &tmp, int left, int right)
    {
        if(left>=right) return;
        int l = left;
        int r = right;
        int mid = l + (r-l)/2;
        Merge(arr, tmp, l, mid);
        Merge(arr, tmp, mid+1, r);
        // define double pointers
        int i = l;
        int j = mid + 1;
        for(int k=l; k<=r; k++)
        {
            tmp[k] = arr[k];
        }
        for(int k=l; k<=r; k++)
        {
            if(i == (mid+1))
            {
                arr[k] = tmp[j++];
            }
            // 表示右子数组已经合并完了
            else if (j == (r+1) || tmp[i] <= tmp[j])
            {
                arr[k] = tmp[i++];
            }
            else
            {
                arr[k] = tmp[j++];
            }
        }
    }
    vector<int> MySort(vector<int>& arr) {
        int n = arr.size();
        if(n==0) 
        {
            return ret;
        }
        vector<int> tmp(n,0);
        Merge(arr,tmp, 0,n-1);
        return arr;
    }
};