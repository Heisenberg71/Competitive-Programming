public class Node {
    int value;
    Node next;

    public Node(int value, Node next) {
        this.value = value;
        this.next = next;
    }
}

class MyLinkedList {

    Node firstNode;
    Node lastNode;
    int listSize;

    public MyLinkedList() {
        firstNode = new Node(0, null);
        lastNode = new Node(0, null);
        firstNode.next = lastNode;
        listSize = 0;
    }

    /*
        index = 3
        firstNode -> 1 -> 2 -> 3 -> (4) -> 5 -> lastNode
    */
    public int get(int index) {

        if (index >= listSize) {
            return -1;
        }

        Node currentNode = firstNode;
        while (index >= 0) {
            currentNode = currentNode.next;
            index--;
        }
        return currentNode.next.value;
    }

    public void addAtHead(int val) {
        addAtIndex(0, val);
    }

    public void addAtTail(int val) {
        addAtIndex(listSize, val);
    }

    public void addAtIndex(int index, int val) {

        if (index > listSize) {
            return;
        }

        Node currentNode = firstNode;
        while (index >= 0) {
            currentNode = currentNode.next;
            index--;
        }
        Node newNode = new Node(val, null);
        newNode.next = currentNode.next;
        currentNode.next = newNode;

        listSize++;
    }

    public void deleteAtIndex(int index) {

        if (index >= listSize) {
            return;
        }

        Node currentNode = firstNode;
        while (index >= 0) {
            currentNode = currentNode.next;
            index--;
        }
        Node deletedNode = currentNode.next;
        currentNode.next = currentNode.next.next;

        listSize--;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
