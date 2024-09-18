/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Left_Most(TreeNode* root){
        if(root == nullptr)
            return nullptr;
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        TreeNode* parent = root;
        TreeNode* new_root = root;
        while(root != nullptr && key != root->val){
            parent = root;
            if(key < root->val){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        if(root == nullptr) // key not found
            return new_root;
        // Case 1: Leaf node
        if(root->left == nullptr && root->right == nullptr){
            if(root == new_root)
                new_root = nullptr;
            if(root == parent->left){
                parent->left = nullptr;
            }
            else{
                parent->right = nullptr;
            }
        }
        // Case 3: 2 child node
        else if(root->left != nullptr && root->right != nullptr){
            TreeNode* successor = Left_Most(root->right);
            // Use successor to replace root
            int value = successor->val;
            deleteNode(root, successor->val);
            root->val = value;
        }
        // Case 2: 1 child node
        else{
            TreeNode* child = root->left == nullptr?root->right:root->left;
            if(root == new_root)
                new_root = child;
            if(root == parent->left){
                parent->left = child;
            }
            else{
                parent->right = child;
            }
        }
        return new_root;
    }
};