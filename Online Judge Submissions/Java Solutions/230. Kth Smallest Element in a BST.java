/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int rank = 1;
    int kth_smallest;
    void DFS(TreeNode currNode, int k) {
        if(currNode == null) {
            return;
        }
        DFS(currNode.left, k);
        if(rank == k) {
            kth_smallest = currNode.val;
        }
        rank++;
        DFS(currNode.right, k);
    }
    public int kthSmallest(TreeNode root, int k) {
        DFS(root, k);
        return kth_smallest;
    }
}
