//Linked list is a data structure which helps to increase as well as decrease the size
//elemements are not in contigous location (location one after another)
//size of the linked list can be increased and decreased at any moment
//the starting point of the linked list is the head of the linked list
//end point is konwn as tail of the linked list and its next pointer is null

//it is used in stack,queue

#include<iostream>
#include<vector>
using namespace std;
struct Node{ //self define datatype for node to store data and next pointer
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){ //constructor
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){ //constructor
        data = data1;
        next = nullptr;
    }
};
int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node*y = new Node(arr[0]);
    cout<<y;
}