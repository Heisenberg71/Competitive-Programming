/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    private void DFS(Node currentNode, Map<Integer, List<Node>> level_node_map, int level) {
        if(currentNode == null) {
            return;
        }
        if(!level_node_map.containsKey(level)) {
            level_node_map.put(level, new ArrayList<>());
        }
        List<Node> levelList = level_node_map.get(level);
        levelList.add(currentNode);
        level_node_map.put(level, levelList);

        DFS(currentNode.left, level_node_map, level + 1);
        DFS(currentNode.right, level_node_map, level + 1);
    }
    public Node connect(Node root) {
        Map<Integer, List<Node>> level_node_map = new HashMap<>();
        DFS(root, level_node_map, 0);

        int level = 0;
        while(level_node_map.containsKey(level)) {
            List<Node> listNode = level_node_map.get(level);
            for(int i = 1; i < listNode.size(); i++) {
                Node prevNode = listNode.get(i - 1);
                Node currentNode = listNode.get(i);
                prevNode.next = currentNode;
                prevNode = currentNode;
                currentNode = currentNode.next;
            }
            level++;
        }

        return root;
    }
}
