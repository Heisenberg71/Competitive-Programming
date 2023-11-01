/*

  Problem Link: https://leetcode.com/problems/delete-nodes-and-return-forest/
  Time Complexity: O(N)
  Space Complexity: O(N + D)

  Here,
  N = number of nodes
  D = max depth of recurstion stack
  
*/


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
private:
  TreeNode* traverse(TreeNode* currNode, unordered_map<int, bool>& isDeleted, vector<TreeNode*>& forest){
      if(currNode == NULL) return NULL;
      
      currNode -> left = traverse(currNode -> left, isDeleted, forest);
      currNode -> right = traverse(currNode -> right, isDeleted, forest);
      
      if(isDeleted.count(currNode -> val)){
          if(currNode -> left) forest.push_back(currNode -> left);
          if(currNode -> right) forest.push_back(currNode -> right);
          return NULL;
      }
      
      return currNode;
  }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, bool> isDeleted;
        for(auto& u: to_delete)
            isDeleted[u] = true;
        vector <TreeNode*> forest;
        if(traverse(root, isDeleted, forest)) forest.push_back(root);
        return forest;
    }
};
