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

// like full mode
void Conv2(vector<vector<float>> &filter, vector<vector<float>> &arr, vector<vector<float>> &res, int filterW, int filterH, int arrW, int arrH)  
{  
    int temp;  

    for (int i=0; i<filterH+arrH-1; i++)  
    {  
        for (int j=0; j<filterW+arrW-1; j++)  
        {  
            temp = 0;  
            for (int m=0; m<filterH; m++)  
            {  
                for (int n=0; n<filterW; n++)  
                {  
                    if ((i-m)>=0 && (i-m)<arrH && (j-n)>=0 && (j-n)<arrW)  
                    {  
                        temp += filter[m][n]*arr[i-m][j-n];  
                    }  
                }  
            }  
            res[i][j] = temp;  
        }  
    }  
} 
