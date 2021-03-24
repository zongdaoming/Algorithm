#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;



class Solution {
public:
    // 先直接快慢双指针暴力排序
    string findLongestWord(string s, vector<string>& dictionary) {
        
        string res=""; 
        for(const auto &d_elem: dictionary){

          int i = 0, j = 0, count = 0;
        //  compare string "s" and "d_elem" 
          while(i<d_elem.size() && j<s.size()){
              if(d_elem[i]==s[j]){
                  i++;
                  j++;
                  count++;
              }else{
                  j++;
              }
             
          }
          if (count==d_elem.size())
          {
              if(d_elem.size()>res.size() || (d_elem.size()==res.size() && d_elem<res)){
                  res = d_elem;
              } 
          } 
          }
        return res;  
    }
};

// 先排序再找是否匹配
class Solution2
{
    private:
    bool check(string &s, string & d_elem)
    {
        int i=0;
        for(char ch: s)
        {
            if (ch==d_elem[i])
            {
                i++;
            }
            if (i==d_elem.size()) break;
        }
        return i==d_elem.size();
    }
    public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        sort(dictionary.begin(),dictionary.end(),[] (const string &a, const string &b){
         return a.size()==b.size()?a<b:a.size()<b.size();
        });
        int n = dictionary.size();
        string res;
        // for (string d_elem:dictionary)
        for (auto & d_elem:dictionary)
        {
            if(d_elem.size()==res.size()) continue;
            if(check(s,d_elem)){
                res =d_elem;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> dictionary ={ "ale","apple","monkey","plea" };
    string  s = "abpcplea";  // length of s is 8;
    Solution Solution;
    string res = Solution.findLongestWord(s,dictionary);
    cout<<" "<<res.c_str()<<endl;

    system("pause");
    return 0;
}
