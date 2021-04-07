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
const int N = 15;
int a[N][N];
set<int> dp[N][N];
int main()
{
    int n, m, t;
    while(cin >> n >> m >> t) {
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++) {
                cin >> a[i][j]; 
                dp[i][j].clear();
            }
        dp[0][0].insert(a[0][0]);

        for(int j = 1; j < m; j++)
            for(auto x: dp[0][j-1])
                dp[0][j].insert(x + a[0][j]);
                
        for(int i = 1;i < n;i++)
            for(auto x: dp[i-1][0])
                dp[i][0].insert(x + a[i][0]);

        for(int i = 1;i < n;i++)
            for(int j = 1;j < m;j++) {
                for(auto x : dp[i-1][j])
                    dp[i][j].insert(x + a[i][j]);
                for(auto x : dp[i][j-1])
                    dp[i][j].insert(x + a[i][j]);
            }
        int ans = -1;
        for(auto x : dp[n-1][m-1])
            if(x <= t) ans = max(ans, x);
        cout << ans << endl;
    }
    return 0;

} 