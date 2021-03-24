#include <iostream>
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
};

int main(int argc, char const *argv[])
{
    ListNode *head = nullptr;
    // Create first node with 12.5
    head = new ListNode; //Allocate new node
    head->value = 12.5; //Store the value
    head->next =  nullptr; //Signify end of list
    // Create secode node with 13.5
    ListNode *secondePtr = new ListNode;
    secondePtr->value = 13.5; 
    secondePtr->next = nullptr; // Second node is the end of the list 
    head->next =  secondePtr;  // First node points to second

    // Print the list
    cout<<"First term is "<<head->value <<endl;
    cout<<"Second item is "<<head->next->value<<endl;


    system("pause");
    return 0;

// Output:
// First term is 12.5
// Second item is 13.5
}

