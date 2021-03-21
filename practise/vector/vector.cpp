#include <vector>
#include <iostream>

using namespace std;


int main ()
{
   vector<int> obj;
   for (int i=0; i<10; i++){
       obj.push_back(i);
       cout<<obj[i]<<endl;
   }
   for(int i=0; i<5;i++){
       obj.pop_back();
   }
   for(int i=0; i<obj.size();i++){
     cout<<obj[i]<<endl;
   }
//    利用迭代器访问
   
   system("pause");
   return 0;

}