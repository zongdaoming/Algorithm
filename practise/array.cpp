#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int array_name[10];
    for(int i=0; i<10; i++){
        array_name[i] = i+1;
    }
    cout <<"begin to output"<<endl;
    for(int j=0; j<10; j++){

       cout<<array_name[j]<<endl;
    }
    system("pause");
    return 0;
}
