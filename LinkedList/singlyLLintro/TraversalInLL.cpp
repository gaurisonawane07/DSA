#include<iostream>
#include<vector>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = NULL){
        data = data1;
        next = next1;
    }

};

Node* createLL(vector<int> arr){
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode; 
            tail = newNode;
        }
    }
    return head;

}

//find the length of the  ll
int lengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cout<<temp<<" ";
        temp = temp ->next;
        cnt ++;
    }
    return cnt;
}

//search in a  ll
//given a linked lst and an element we have to check if that elementexist or not

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp -> data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = createLL(arr);
    // traversal in ll
    // Node*temp = head;
    // while(temp){
    //     cout<<temp->data<<" ";
    //     temp = temp -> next;
    // }

    // cout << lengthOfLL(head);

    cout<<checkIfPresent(head, 22);
    
}