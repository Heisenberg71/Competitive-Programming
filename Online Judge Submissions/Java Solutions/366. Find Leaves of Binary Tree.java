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
    List<List<Integer>> leafNodeList;
    int DFS(TreeNode currNode) {
        if(currNode == null) {
            return 0;
        }
        int maxDepth = 1 + Math.max(DFS(currNode.left), DFS(currNode.right));
        if(leafNodeList.size() < maxDepth) {
            leafNodeList.add(new ArrayList<>());
        }
        leafNodeList.get(maxDepth - 1).add(currNode.val);

        return maxDepth;
    }
    public List<List<Integer>> findLeaves(TreeNode root) {
        leafNodeList = new ArrayList<>();
        DFS(root);
        return leafNodeList;
    }
}
