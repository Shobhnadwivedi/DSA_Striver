#include <iostream>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == nullptr) return head;


        int total=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            temp = temp->next;
            total++;
        }
        int f = total - n+1;
        // remove head
        if(f==1){
            ListNode* temp2 = head ;
            head = head->next;
            delete temp2;
            return head;
        }
        

        int cnt= 0;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            cnt++;
            if(cnt==f){
                ListNode* temp3 = prev->next;
                prev->next = prev ->next -> next;
                delete temp3;
                break;

            }
            prev = curr;
            curr = curr->next;
        }

        return head;
        
    }
};


class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;

        if(head->next == nullptr && n==1) {
            delete head;
            return nullptr;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left = head;
        ListNode* right= head ;

        int i=1;
        while(i<=n){
            if( right == nullptr) return head; // n is more than length of linked list
            right = right->next;
            i++;
        }
        
        ListNode* temp = dummy;
        while(right ){
            temp = left;
            left = left->next;
            right= right->next;
        }

        
        temp->next = temp->next->next;
        delete left;
        return dummy->next;   // we can't return head because head pointer might be deleted if n is equal to length of linked list

    }
};


// correct solution
class Solution3{ 
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == nullptr) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    // For this pattern, it's cleaner to start the slow pointer at the dummy.
    ListNode* slow = dummy;
    ListNode* fast = head;
    
    // 1. Advance 'fast' n steps into the list
    for(int i = 0; i < n; ++i) {
        if(fast == nullptr) return head;
        fast = fast->next;
    }
    
    // 2. Move both pointers until 'fast' reaches the end
    while(fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    
    // 'slow' is now the node BEFORE the target
    // --- THE FIX ---
    ListNode* node_to_delete = slow->next;
    slow->next = node_to_delete->next; // Unlink the target node
    delete node_to_delete;             // Delete the CORRECT node
    
    ListNode* new_head = dummy->next;
    delete dummy;
    return new_head;
}
};


int main(){
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);

    head->next = second;
    second->next = third;
    third-> next = nullptr;

    

    Solution3 sol;
    head = sol.removeNthFromEnd(  head , 5); // Deleting 4th element from end

    ListNode* temp = head;
    while(temp != nullptr){ 
        cout<< temp->val << " ";
        temp = temp->next;
    }
    

}