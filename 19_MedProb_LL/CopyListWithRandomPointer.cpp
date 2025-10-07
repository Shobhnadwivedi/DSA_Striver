#include <iostream>
#include<unordered_map>
using namespace std;

class Node {
  public:
    int val;
    Node *next;
    Node* random;

    // different constructors
    Node() : val(0), next(nullptr), random(nullptr) {}
    Node(int x) : val(x), next(nullptr) , random(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) , random(nullptr) {}
    Node(int x, Node *next, Node* random) : val(x), next(next) , random(random) {}

};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }

        Node* temp = head;
        unordered_map<Node*, Node*> mp;

        while(temp){
            Node* newnode = new Node(temp->val);
            mp[temp]= newnode;
            temp = temp->next;
        }

        temp = head;
        while(temp){
            mp[temp]->next = mp[temp->next];
            mp[temp]-> random = mp[temp->random];
            temp = temp->next;
        }
        
        return mp[head];
        
    }
};



class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }

        Node* temp = head;

        while(temp){
            Node* a = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = a;
            temp = a;        //  or temp = temp->next->next;
        }


        temp = head;
        while(temp != nullptr && temp->next != nullptr){
            if(temp->random != nullptr){
                temp->next ->random = temp->random ->next;
            }
            temp = temp->next ->next;
        }

        Node* dummy = new Node(0);
        Node* temp2 = dummy;
        temp = head;
        while(temp){
            Node* a = temp->next->next;
            temp2 ->next = temp->next;
            temp2 = temp2->next;
            temp ->next = a;
            temp = a;
        }

        return dummy->next;
    }
};