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
    Map<Integer, List<Integer>> level_nodeList;
    void DFS(TreeNode currNode, int level) {
        if(currNode == null) {
            return;
        }
        if(!level_nodeList.containsKey(level)) {
            level_nodeList.put(level, new ArrayList<>());
        }
        List<Integer> nodeList = level_nodeList.get(level);
        nodeList.add(currNode.val);

        DFS(currNode.left, level + 1);
        DFS(currNode.right, level + 1);
    }
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        level_nodeList = new HashMap<>();
        DFS(root, 0);

        int level = 0;
        while(level_nodeList.containsKey(level)) {
            if((level&1) == 1) {
                Collections.reverse(level_nodeList.get(level));
            }
            level++;
        }

        return new ArrayList<>(level_nodeList.values());
    }
}
