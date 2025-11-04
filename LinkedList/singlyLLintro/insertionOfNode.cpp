#include<iostream>
#include<vector>
using namespace std;

struct Node {
    public:
    int value;
    Node*next;

    Node(int value1, Node* next1 = NULL){
        value = value1;
        next = next1;
    }
};

Node* createLL(vector<int> arr){
    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }

    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
    cout<<head->value << " ";
    head = head->next;
    }
    cout<<endl;
}
// 1. insert element at the head of the linked list
 /* Logic
- suppose the linked list is 2->3->1->8 and we have given the element 5 to insert at the hed of the linked list
 so, the linked list becomes 5->2->3->1->8

- we will create a new node and put 5 into it and call this node as temperory ans we will return temp instead of head we will no more return head
 */

 Node* insertHead(Node* head , int val){
    return new Node(val, head);
    
}

// insert element at the tail of the linked list
/*
 Logic:
 we initially point temp to the head and move the temp until temp=>next == null
 and just create new node there
*/

Node* insertTail(Node*head , int val){
    if(head == NULL){
        return new Node (val);
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    Node* newNode = new Node(val,nullptr);
    temp -> next = newNode;
    return head;
}

//inserting node at kth position
//we have to insert a new node at kth position
/*let's consider about the edge cases
1. if the linked list is null then we can only insert ata the first position and return the head of the linked list
2. if k = 1, we will create the new node at 1st position and return temp
3. if k = 3, we will stop temp at 2nd position insert new node at 3rd and point temp-> next to newNode
*/
Node* insertPosition(Node* head, int val, int k ){
    if(head == NULL){
        if(k==1){
            return new Node(val);
        }else{
            return head;
        }
    }
    if(k == 1){
        return new Node(val,head);
        
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt== (k-1)){
            Node* x = new Node(val, temp->next);
            temp -> next = x;
            break;
        }
        temp = temp->next;  
    }
    return head;

}

int main(){
    vector<int> arr = {12,5,8,7};
    Node* head = createLL(arr);
    // head = new Node(100, head);
    // head = insertTail(head, 20);
    head = insertPosition(head,90,3);
    print(head);
}
