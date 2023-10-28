/*

Problem Link: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/
Time Complexity: O(tree_size)
Space Complexity: O(tree_size + recurstion_stack_memory)

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
    void DFS_prefix(TreeNode* currNode, unordered_map<int, int>& longestPath, int depth, int &maxDepth){
        if(currNode == NULL) return;
        longestPath[currNode -> val] = max(longestPath[currNode -> val], maxDepth);
        maxDepth = max(maxDepth, depth);
        DFS_prefix(currNode -> left, longestPath, depth + 1, maxDepth);
        DFS_prefix(currNode -> right, longestPath, depth + 1, maxDepth);
    }
    void DFS_suffix(TreeNode* currNode, unordered_map<int, int>& longestPath, int depth, int &maxDepth){
        if(currNode == NULL) return;
        longestPath[currNode -> val] = max(longestPath[currNode -> val], maxDepth);
        maxDepth = max(maxDepth, depth);
        DFS_suffix(currNode -> right, longestPath, depth + 1, maxDepth);
        DFS_suffix(currNode -> left, longestPath, depth + 1, maxDepth);
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map <int, int> longestPath;

        int maxDepth = 0;
        DFS_prefix(root, longestPath, 0, maxDepth);
        maxDepth = 0;
        DFS_suffix(root, longestPath, 0, maxDepth);

        vector<int> ans;
        for(auto& x: queries)
            ans.push_back(longestPath[x]);
        return ans;
    }
};
