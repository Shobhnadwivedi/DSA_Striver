#include<iostream>
using namespace std;

class TreeNode{
  public:
    int data;
    TreeNode* next;

    TreeNode(int d, TreeNode* n = nullptr){
        data  = d;
        next = nullptr;
    }   

};



// when k is given as position

void deleteatK(TreeNode* &head, int k){

    // if linked list is empty
    if(head == nullptr){
        return;
    }

    // if k=1 ,i.e. head node to be deleted

    if(k==1){
        TreeNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    int cnt=0;
    TreeNode* prev = nullptr;
    TreeNode* curr = head;

    while(curr){
        cnt++;
        
        if(cnt ==k){
            prev->next = prev->next->next;
            delete curr;
            break; 
        }

        prev = curr;
        curr= curr->next;
    }
    return;

}


int main(){

    TreeNode* head = new TreeNode(10);
    TreeNode* second = new TreeNode(20);
    TreeNode* third = new TreeNode(30);
    TreeNode* fourth = new TreeNode(40);
    TreeNode* fifth = new TreeNode(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    int k;
    cin >> k;

    deleteatK(head, k);

    TreeNode* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

}