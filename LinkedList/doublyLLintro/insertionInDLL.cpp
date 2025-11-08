#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    public:
    int val;
    ListNode* next;
    ListNode* prev;

    public:
    ListNode(int val1, ListNode*next1, ListNode* prev1){
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

ListNode *createDLL(vector<int>arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* prev = head;
    for(int i = 1;i<arr.size();i++){
        ListNode* temp = new ListNode(arr[i],nullptr,prev);
            prev->next = temp;
            prev = prev -> next;
    }
    return head;
}
void print(ListNode* head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
//inserting node
//inserting at the head of dll
ListNode* insertBeforeHead(ListNode* head, int val){
    ListNode* newhead =  new ListNode(val, head,nullptr);
    head->prev = newhead;
    return newhead;

}

// insert before the head of the linked list
ListNode* insertBeforeTail(ListNode* head, int val){
    ListNode* tail = head;
    while (tail->next != NULL){
        tail = tail->next;
    }
    ListNode* back = tail->prev;
        ListNode* newback = new ListNode(val,tail,tail->prev);
        if(back!=NULL){
            back->next = newback;

        }else{
            head = newback;
        }
        return head;
}

//Inserting before the kth node of the linked list
ListNode* insertKthPosition(ListNode* head, int val, int k){
    if(head == NULL){
        if(k==1){
            return new ListNode(val,nullptr,nullptr);
        }
        return NULL;
    }
    if(k==1){
        return insertBeforeHead(head,val);
    }
    ListNode* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        cnt ++;
        if(cnt == k){
            break;
        }
        temp = temp ->next;
    }
    ListNode* back = temp->prev;
    ListNode* newNode = new ListNode(val, temp, back);
    back -> next = newNode;
    temp -> prev = newNode;
    return head;
    
}

int main(){
    vector<int> arr = {2,5,7,9};
    ListNode* head = createDLL(arr);
    head = insertKthPosition(head, 6,2);
    print(head);
    return 0;

}