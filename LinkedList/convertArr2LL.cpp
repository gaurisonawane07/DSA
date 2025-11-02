#include<iostream>
#include<vector>
using namespace std;
struct Node{
    public:
    int data;
    Node* next; 

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]); //first element is the head of the LL
    Node* mover = head; // initially mover is at the first place

    for(int i = 1;i<arr.size();i++){
        Node* temp  = new Node(arr[i]); // storing arr elements in temp
        mover->next = temp;
        mover = temp; //move mover to the next
    }
    return head;
}
int main(){
    vector<int>arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    cout<<head->data;//head->data prints the element at that  position and head prints the memory location of that specific element
}