#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
   map<int, string> ID_name;
   ID_name = {
      {2015, "Jim"},
      {2016, "Tob"},
      {2017, "Bob"}
   };
   ID_name[2018] = "zongdoaming";
   system("pause");
   return 0;
};


