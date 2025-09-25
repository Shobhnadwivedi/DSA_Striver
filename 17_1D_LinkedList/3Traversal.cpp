#include <iostream>
using namespace std;

class Node{
  public:

    int data;
    Node* next;

    Node(int d){
        data = d;
        next = nullptr;
    }

};

// Count nodes in Linked List
class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        Node* ptr = head;
        int cnt;

        while(ptr){
            ptr = ptr-> next;
            cnt++;
        }
        return cnt;

    }
};

// Search in Linked List
class Solution2 {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        bool isthere= false;
        Node* ptr = head;
        
        while(ptr != nullptr){
            if(ptr->data == key){
                isthere = true;
            }
            else{
                ptr = ptr->next;
            }
        }
        return isthere;
    }
};