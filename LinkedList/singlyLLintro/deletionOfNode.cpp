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
void print(Node* head){
    while(head!=NULL){
    cout<<head->data << " ";
    head = head->next;
    }
    cout<<endl;
}

Node* createLinkedList(vector<int> & arr){
    
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    return head;
}
//remove head of the linked list
Node*removeHead(Node*head){
    if(head == NULL) return head;//linked list is empty 
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
//remove tail of the linked list
//for deleting the tail we have to stop before the last element
Node* removeTail(Node *head){
    if(head == NULL || head ->next == NULL ) return NULL;
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    free (temp -> next);
    temp -> next = nullptr;
    return head;

}
// delete the kth element of the linked list
Node* removeKelement(Node* head, int k){
    if(head ==NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }

    int cnt = 0;
    Node* temp =  head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt ++;
        if(cnt == k){
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        
    }
    return head;
}

int main(){
    vector<int>arr = {12, 5, 8 , 7};
    // Node* head = createLinkedList(arr);
    // head = removeHead(head);
    Node* head = createLinkedList(arr);
    head = removeKelement(head , 4);
    print(head);
}