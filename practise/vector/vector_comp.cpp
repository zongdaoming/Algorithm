#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool compare(int a, int b);
int main()
{
    vector<int> obj;
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(3);

    sort(obj.begin(),obj.end());// 从小到大
    cout<<"从小到大:" <<endl;

    for (int i =0 ; i < obj.size(); i++)
    {
        cout<<obj[i]<<endl;
    }
    cout<<"\n"<<endl;

    cout<<"从大到小"<<endl;
    // reverse(obj.begin(),obj.end()); //从大到小
    sort(obj.begin(),obj.end(),compare);
    for (int i=0; i< obj.size(); i++)
    {
        cout<<obj[i]<<endl; 
    }
   system("pause");
   return 0;
    }


// 注意sort 需要头文件 #include <algorithm>
// 如果想sort 来降序，可重写 sort
bool compare(int a, int b)
{
    return a>b; //升序排列，if a>b，则为降序排列
}


