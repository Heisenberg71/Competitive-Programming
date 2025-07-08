/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int depth_of_p, depth_of_q; 
    Map<TreeNode, TreeNode> parent_of;
    TreeNode p;
    TreeNode q;
    private void DFS(TreeNode currNode, int depth) {
        if(currNode == null) {
            return;
        }
        if(currNode == this.p) {
            depth_of_p = depth;
        }
        if(currNode == this.q) {
            depth_of_q = depth;
        }

        if(currNode.left != null) {
            parent_of.put(currNode.left, currNode);
        }
        if(currNode.right != null) {
            parent_of.put(currNode.right, currNode);
        }

        DFS(currNode.left, depth + 1);
        DFS(currNode.right, depth + 1);
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        this.p = p;
        this.q = q;
        parent_of = new HashMap<TreeNode, TreeNode>();
        DFS(root, 0);
        if(depth_of_p > depth_of_q) {
            int temp_depth = depth_of_q;
            depth_of_q = depth_of_p;
            depth_of_p = temp_depth;

            TreeNode temp_node = p;
            p = q;
            q = temp_node;
        }
        while(depth_of_p < depth_of_q) {
            q = parent_of.get(q);
            depth_of_q--;
        }
        while(p != q) {
            p = parent_of.get(p);
            q = parent_of.get(q);
        }
        return p;
    }
}
