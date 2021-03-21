#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N=5, M=6;
    vector<vector<int>> obj(5); // 定义二维动态数组大小5行
    for(int i=0; i< obj.size(); i++){
        obj[i].resize(M);  //动态数组为5行6列，值全为0
    }
    for(int i=0; i<obj.size(); i++){  //输出二维动态数组
       for (int j=0; j<obj[i].size();j++){
           cout<<obj[i][j]<<" ";
       }
       cout<<endl;
    }
    system("pause");
    return 0;
}

void out2array()
{
   int N=5, M=6;
   vector<vector<int>> obj(N, vector<int> (6));
   for (int i=0; i < obj.size();i++){
    for (int j=0; j<obj[i].size() ; j++){
        cout<<obj[i][j]<<" ";
    }
    cout<<"\n";
}
}