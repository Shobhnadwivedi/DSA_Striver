#include <iostream>
#include <stack>
using namespace std;





class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};




//  inefficient solution using stack 
// time complexity O(2n) and space complexity O(n) = Due to stack
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head== nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return head;
        }

        // stack created from the linked list
        ListNode* temp = head;
        int n=0;
        stack<int> s;
        while(temp){
            s.push(temp->val);
            temp = temp->next;
            n++;
        }

        ListNode* temp2 = head;
        while(n>0){
            temp2->val = s.top();
            s.pop();
            n--;
            temp2 = temp2->next;
           
        }

        return head;
        
    }
};


// optimal solution
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head== nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward;

        while(curr){

            //   1.   curr->next stored in forw , so after reversing of this portion , curr can be updated to curr->next.
            forward = curr -> next;

            //   2. aage ka pointer(curr->next) ko peeche link krna ....to the prev node
            curr->next = prev;

            //   3. prev and curr ko aage badhana
            prev = curr;
            curr = forward; 
        }

        return prev;


    }

};


class Solution3{
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newhead;

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
    head = sol.reverseList( head ); // Deleting 4th element from end

    ListNode* temp = head;
    while(temp != nullptr){ 
        cout<< temp->val << " ";
        temp = temp->next;
    }
    

}