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
    bool judge(vector<int> &sequence, int left, int right)
    {
        if(left >= right)
        {
            return true;
        }
        //  后一半的元素都比根元素大
        int mid = right - 1;
        while(sequence[mid]>sequence[right])
        {
            mid--;
        }
        // 那么前面的元素都应该比根小
        int i = left;
        while (i < mid && sequence[i] < sequence[right])
        {
            i++;
        }
        if (i < mid)
        {
            return false;
        }
        return judge(sequence, left, mid) && judge(sequence, mid + 1, right - 1);
    }
    
    bool VerifySquenceOfBST(vector<int> sequence) {
        // 根（最后一个节点）前面被划分为小于它（左子树）和大于它（右子树）的两部分
        if (sequence.size() == 0)
        {
            return false;
        }
        return judge(sequence, 0, sequence.size()-1);
    }    
};  