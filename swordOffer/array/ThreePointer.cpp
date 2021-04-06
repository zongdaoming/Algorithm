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

// 这道题目自己是有思路的，丑数能够分解成 `2*x 3*y 5*z`,
// 所以只需要把得到的丑数不断地乘以`2、3、5` 之后并放入他们应该放置的位置即可，
// 而此题的难点就在于如何有序的放在合适的位置。
// 1乘以 （2、3、5）=2、3、5；2乘以（2、3、5）=4、6、10；3乘以（2、3、5）=6,9,15；5乘以（2、3、5）=10、15、25；
// 从这里我们可以看到
// 如果不加策略地添加丑数是会有重复并且无序，
// 而在`2x，3y，5z`中，
// 如果x=y=z 那么最小丑数一定是乘以2的，但关键是有可能存在`x》y》z`的情况，所以我们要维持三个指针来记录当前乘以2、乘以3、乘以5的最小值。
    
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0) return 0;
        //三指针，快慢指针
        int p2 =0, p3 = 0, p5 =0; // 初始化三个指向三个潜在成为最小丑数的位置
        vector<int> ret(index);
        ret[0] = 1; //
        for(int i = 1; i<index; i++)
        {
            ret[i] =min(ret[p2]*2, min(ret[p3]*3, ret[p5]*5));
            if (ret[i]==ret[p2]*2) p2++; //为了防止重复需要三个if都能够走到;
            if (ret[i]==ret[p3]*3) p3++;
            if (ret[i]==ret[p5]*5) p5++;
        }
        return ret[index-1];
    }
};