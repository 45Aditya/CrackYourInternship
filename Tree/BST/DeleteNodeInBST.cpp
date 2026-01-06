#include<bits/stdc++.h>
using namespace std;

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
    TreeNode *findSuccessor(TreeNode *node) {
        while(node->left) {
            node = node->left;
        }
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if(!root->left) {
                TreeNode *node = root->right;
                delete root;
                return node;
            } if(!root->right) {
                TreeNode *node = root->left;
                delete root;
                return node;
            } 
            TreeNode *succ = findSuccessor(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};