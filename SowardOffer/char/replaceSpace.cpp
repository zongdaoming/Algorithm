#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code here
        string str = "%20";
        int  i = 0;
        while(i<s.size() && str[i]==' ') {i++;}
        for(int j = i; j<s.size(); j++)
        {
            
            if ( s[j]==' ')
            {
                s.erase(j, 1);
                s.insert(j,str);
                
            }
        }
        return s;
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return string字符串
     */
    string replaceSpace(string s) {
        string a;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' '){
                a+="%20";
            }else{
                a+=s[i];
            }
        }
        return a;
        // write code here
    }
};
