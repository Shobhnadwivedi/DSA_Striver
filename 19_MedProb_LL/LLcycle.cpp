#include <iostream>
#include<unordered_set>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//  WRONG SOLUTION  for cases with duplicate values kyunki we are storing the data of nodes in the set 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<int> v1 ;

        ListNode* temp = head;

        while(temp != nullptr){
            for(int i=0; i< v1.size(); i++){
                if(v1[i]== temp->val){
                    return true;
                }
            }
            
            v1.push_back(temp->val);
            temp = temp->next;
        }
        return false;
    }
};


//   Store the address of nodes in the set to avoid this issue

// even as a brute force = Inefficient approach = bcuz hash set ki main property , i.e, search in O(1) is lost here.

// T.C = O(N^2) , S.C = O(N)

//  use set1.count() function to check if the element is present =  O(1) time
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s1 ;   

        ListNode* temp = head;

        while(temp != nullptr){
            for(ListNode* element : s1){
                if( element == temp->next){
                    return true;
                }
            }
            
            s1.insert(temp->next);
            temp = temp->next;
        }
        return false;
    }
};


class Solution3 {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s1 ;   

        ListNode* temp = head;

        while(temp != nullptr){
            if(s1.count(temp->next)){
                return true;
            }
            
            s1.insert(temp->next);
            temp = temp->next;
        }
        return false;
    }
};







int main(){
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);


    head->next = second;
    second->next = third;
    third-> next = fourth;
    fourth-> next = second;  // cycle created here

    

    Solution sol;
    cout <<  sol.hasCycle(  head); // Deleting 4th element from end


    

}