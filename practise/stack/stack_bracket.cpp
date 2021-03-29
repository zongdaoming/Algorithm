#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isRight(vector<char> & vec)
{
    stack<char> mystack;
    if(vec.size()<=1 || vec[0]!='(' || vec.size()%2!=0)
    {
        return false;
    }
    for (int i = 0; i<vec.size(); i++)
    {
        if (vec[i]=='(')
        {
            mystack.push(vec[i]);
        }else if(vec[i]==')')
        {
            mystack.pop();
        }
    }
    return mystack.empty();
};

int main(int argc, char const *argv[])
{ 
    vector<char> vec;
    char tmpCh;
    char t;
    do{
        cin>> tmpCh;
        vec.push_back(tmpCh);
    }while((t=cin.get())!='\n');

    bool ans = isRight(vec);
    cout<<ans<<endl;

    system("pause");
    return 0;
}
