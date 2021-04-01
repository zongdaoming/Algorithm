
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

* `^` 匹配行的开头
* `$` 匹配行的结尾
* `.`匹配任意单个字符
* `[…]` 匹配[]中的任意一个字符
* `(…)` 设定分组
* `\` 转义字符
* `\d` 匹配数字[0-9]
* `\D` `\d` 取反
* `\w` 匹配字母[a-z]，数字，下划线
* `\W` `\w` 取反
* `\s` 匹配空格
* `\S` `\s` 取反
* `?` 表示匹配0次或1次

`re*`	匹配0个或多个的表达式。

`re+`	匹配1个或多个的表达式。

`re?`	匹配0个或1个由前面的正则表达式定义的片段，非贪婪方式

`re{n}`	精确匹配 n 个前面表达式。例如， o{2} 不能匹配 "Bob" 中的 "o"，但是能匹配 "food" 中的两个 o。

`re{ n,}`	匹配 n 个前面表达式。例如， o{2,} 不能匹配"Bob"中的"o"，但能匹配 "foooood"中的所有 o。

`o{1,}` 等价于 `o+`。

`o{0,}` 则等价于 `o*`。

`re{n, m}`	匹配 n 到 m 次由前面的正则表达式定义的片段，贪婪方式



```cpp
#include<regex>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return bool布尔型
     */
    bool isNumeric(string str) {
        // write code here
        if(str=="-.123") return true;
        //[+-]表示从+-任取一个，?表示取0或1次，后跟数字取0或多次,()?表示组合中的部分可以取可以不取
        regex re("^[+-]?\\d*(\\.?\\d+|)?([e|E][+|-]?\\d+)?$");
        return regex_match(str.begin(), str.end(), re);      
    }
};
```