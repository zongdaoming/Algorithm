#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct ListNode
{
    double value;
    ListNode *next;
    // Constructor
    ListNode(double value1, ListNode* next1=nullptr){
        value =value1;
        next = next1;
    }
};


int main(int argc, char const *argv[])
{
    
    double number; //used to read the file
    ListNode *numberList = nullptr;// List of numbers
    // Open the file
    ifstream numberFile("numberFile.dat");
    if(!numberFile)
    {
        cout<<"Error in opening the file of the numbers";
        exit(1);
    }
    // Read the file into a linked list
    cout<<"The contents of the file are: "<<endl;
    while(numberFile>>number)
    {
        cout<<number<<" ";
        // Create a node to hold this number
        // 只有尾结点的后继指针为nullptr
        numberList = new ListNode(number, numberList);
    }
    // Traverse the list while printing
    cout<<endl<<"The contents of the list are: "<<endl;
    
    ListNode *ptr = numberList;
    while(ptr!=nullptr)
    {
        cout<<ptr->value<<" ";//Process node
        ptr = ptr->next;
    }
    system("pause");
    return 0;
}
