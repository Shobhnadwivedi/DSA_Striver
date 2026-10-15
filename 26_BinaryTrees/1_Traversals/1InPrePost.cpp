#include<iostream>
#include<vector>
#include<stack>
using namespace std;



// STRUCTURE OF NODE
struct  TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;


    // Constructor:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};


// 

class Solution{
public:
    vector<vector<int>> InPrePost(TreeNode* root){
        if(root == nullptr) return {};

        vector<int> Inorder;
        vector<int> Preorder;
        vector<int> Postorder;

        // Stack
        stack<pair <TreeNode*, int> > st;

        st.push({root, 1});

        while(!st.empty()){

            TreeNode* top = st.top().first;
            int num = st.top().second;
            st.pop();

            if(num == 1){
                Preorder.push_back(top->val);
                st.push({top, num+1});
                if(top->left != nullptr) st.push({top->left,1});
            }
            else if(num == 2){
                Inorder.push_back(top->val);
                st.push({top, num+1});
                if(top->right != nullptr) st.push({top->right,1});
            }
            else{
                Postorder.push_back(top->val);
            }
        }

        return {Preorder,Inorder , Postorder};

    }
    
};




/*
       1
     /   \
    2      3
   /  \
  4    5

*/
 

int main(){
    // Make a tree:
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right  = new TreeNode(3);
    root -> left ->left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);


    // Create objct
    Solution sol;
    // vector to store ans:
    vector<vector<int>> res;

    res = sol.InPrePost(root);

    // print the Preorder = res[0] array 
    cout << "Preorder array : " ;
    for(int i =0; i< res[0].size(); i++){
        cout << res[0][i] << " ";
    }
    cout << endl;

    // print the Inorder = res[1] array
    cout << "Inorder array : "  ;
    for(int i =0; i< res[1].size(); i++){
        cout << res[1][i] << " ";
    }
    cout << endl;

    // print the Postorder = res[2] array
    cout << "Postorder array : "  ;
    for(int i =0; i< res[2].size(); i++){
        cout << res[2][i] << " ";
    }
}

