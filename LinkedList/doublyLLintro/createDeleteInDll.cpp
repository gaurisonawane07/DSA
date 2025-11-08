#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    public:
    int val;
    ListNode* next;
    ListNode* prev;

    public:
    ListNode(int val1, ListNode* next1, ListNode* prev1){
        val = val1;
        next = next1;
        prev = prev1;
    }
    public:
    ListNode(int val1){
        val = val1;
        next = nullptr;
        prev = nullptr;
    }
};
ListNode* convertArr2DLL(vector<int> arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* prev = head;
    for(int i = 1;i<arr.size();i++){
        ListNode* temp = new ListNode(arr[i],nullptr,prev);
        prev -> next = temp;
        prev = prev->next;
    }
    return head;
}
void print(ListNode* head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head -> next;
    }
    cout<<endl;
}
//deletion at the head of DLL
ListNode*deleteHead(ListNode* head){
    if(head == NULL || head->next ==NULL){
        return NULL;
    }
    ListNode* back = head;
    head = head -> next;

    head->prev = nullptr;
    back->next = nullptr;
    delete back;
    return head;
}

ListNode*deleteTail(ListNode* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    ListNode* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    ListNode* newTail = tail->prev;
    newTail->next = NULL;
    tail->prev = nullptr;
    delete tail;
    return head;


}
//delete kth node of the DLL
ListNode* deleteKthNode(ListNode* head,int k){
    if(head == NULL) return NULL;
    int cnt = 0;
    ListNode* temp = head;
    while(temp != NULL){
        cnt ++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    ListNode*back = temp -> prev;
        ListNode*front = temp->next;
        if(back == NULL && front == NULL){
            delete temp;
            return NULL;
        }
        else if(back == NULL){
            deleteHead(head);
        }
        else if(front == NULL){
            deleteTail(head);
        }
        else{
            back->next = front;
            front->prev = back;
            temp->next = NULL;
            temp->prev = NULL;
        }
    delete temp;
    return head;
}

int main(){
    vector<int> arr = {2,4,7,9,4};
    ListNode* head = convertArr2DLL(arr);
    head = deleteKthNode(head, 5);
    print(head);
}