#include <string>
#include <iostream>
#include <stdio.h>
 using namespace std;
 
int main()
{
    string strOutput = "Hello World";


    for (int i=0; i<strOutput.size(); i++)
    {
        cout<<strOutput[i]<<endl;
    }
    // cout << "[cout] strOutput is: " << strOutput << endl;
    // string 转换为 char*
    // const char* pszOutput = strOutput.c_str();
    // printf("[printf] strOutput is: %s\n", pszOutput);

    system("pause");        
    return 0;

}