
# 题目抽象：给定一字符串str，将str的[0...n)子串移动到[n...len)子串的后面。


## 方法1:使用标准库
```cpp
class Solution
{
    public:
    string LeftRotateString(string str, int n)
    {
        if (n>str.size()) return str;
        return str.substr(n)+str.substr(0,n);
    }
}
```

## 方法2:自己实现
```cpp
class Solution
{
    public:
    string LeftRotateString(string str, int n)
    {
    if(n>str.size()) return str;
    string ret = "";
    for(int i = n; i<str.size();i++)
    {
        ret+=str[i];
    }
    for(int i=0; i<n; ++i)
    {
        ret+= str[i];
    }
    return ret;
    }
}
```


