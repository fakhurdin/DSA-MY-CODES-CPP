import java.util.LinkedList;
import java.util.Queue;
public class BinnarySearch {
    public NodeBST root;

    public BinnarySearch() {
        root = null;
    }

    public void insert(int data) {
        root = insertRec(root, data);
    }

    public NodeBST insertRec(NodeBST root, int data) {
        if (root == null) {
            root = new NodeBST(data);
            root.left = null; // Initialize left node for the new root
            root.right = null; // Initialize right node for the new root
            return root;
        }

        if (data < root.data)
            root.left = insertRec(root.left, data);
        else if (data > root.data)
            root.right = insertRec(root.right, data);

        return root;
    }
    public boolean search(int key) {
        return searchRec(root, key);
    }

    private boolean searchRec(NodeBST root, int key) {
        if (root == null)
            return false;
        if (root.data == key)
            return true;
        if (key < root.data)
            return searchRec(root.left, key);
        return searchRec(root.right, key);
    }

    public void preOrder() {
        preOrderRec(root);
        System.out.println();
    }

    private void preOrderRec(NodeBST root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preOrderRec(root.left);
            preOrderRec(root.right);
        }
    }

    public void inOrder() {
        inOrderRec(root);
        System.out.println();
    }

    private void inOrderRec(NodeBST root) {
        if (root != null) {
            inOrderRec(root.left);
            System.out.print(root.data + " ");
            inOrderRec(root.right);
        }
    }

    public void postOrder() {
        postOrderRec(root);
        System.out.println();
    }

    private void postOrderRec(NodeBST root) {
        if (root != null) {
            postOrderRec(root.left);
            postOrderRec(root.right);
            System.out.print(root.data + " ");
        }
    }

    public int height() {
        return heightRec(root);
    }

    private int heightRec(NodeBST root) {
        if (root == null)
            return -1;

        int leftHeight = heightRec(root.left);
        int rightHeight = heightRec(root.right);

        return Math.max(leftHeight, rightHeight) + 1;
    }

    public int findMin() {
        return findMinRec(root);
    }

    private int findMinRec(NodeBST root) {
        if (root.left == null)
            return root.data;
        return findMinRec(root.left);
    }

    public boolean isBinaryTree() {
        return isBSTUtil(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private boolean isBSTUtil(NodeBST root, int min, int max) {
        if (root == null)
            return true;

        if (root.data < min || root.data > max)
            return false;

        return isBSTUtil(root.left, min, root.data - 1) && isBSTUtil(root.right, root.data + 1, max);
    }

    public void printNodeAtDistance(int distance) {
        printNodeAtDistanceRec(root, distance);
        System.out.println();
    }

    private void printNodeAtDistanceRec(NodeBST root, int distance) {
        if (root == null)
            return;
        if (distance == 0) {
            System.out.print(root.data + " ");
            return;
        }
        printNodeAtDistanceRec(root.left, distance - 1);
        printNodeAtDistanceRec(root.right, distance - 1);
    }

    public boolean isEqual(BinnarySearch other) {
        return isEqualRec(this.root, other.root);
    }

    private boolean isEqualRec(NodeBST root1, NodeBST root2) {
        if (root1 == null && root2 == null)
            return true;
        if (root1 != null && root2 != null) {
            return (root1.data == root2.data) &&
                    isEqualRec(root1.left, root2.left) &&
                    isEqualRec(root1.right, root2.right);
        }
        return false;
    }

    public void printPreOrder() {
        preOrder();
    }

    public int leafNodes() {
        return countLeafNodes(root);
    }

    private int countLeafNodes(NodeBST root) {
        if (root == null)
            return 0;
        if (root.left == null && root.right == null)
            return 1;
        else
            return countLeafNodes(root.left) + countLeafNodes(root.right);
    }

    public boolean isParentNode(int key) {
        return isParentNodeRec(root, key);
    }

    private boolean isParentNodeRec(NodeBST root, int key) {
        if (root == null)
            return false;
        if ((root.left != null && root.left.data == key) || (root.right != null && root.right.data == key))
            return true;
        return isParentNodeRec(root.left, key) || isParentNodeRec(root.right, key);
    }

    public Integer getRightSibling(NodeBST root, int key) {
        return getRightSiblingRec(root, key);
    }
    
    private Integer getRightSiblingRec(NodeBST root, int key) {
        if (root == null)
            return null;
    
        Queue<NodeBST> queue = new LinkedList<>();
        queue.add(root);
    
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                NodeBST curr = queue.poll();
                if (curr.data == key) {
                    if (i < size - 1) {
                        return queue.peek().data;
                    } else {
                        return null; // No right sibling found
                    }
                }
                if (curr.left != null)
                    queue.add(curr.left);
                if (curr.right != null)
                    queue.add(curr.right);
            }
        }
        return null; // Key not found
    }

    public static void main(String[] args) {
        BinnarySearch bst = new BinnarySearch();

        int[] elements = {5, 3, 8, 1, 4, 7, 9};
        for (int el : elements) {
            bst.insert(el);
        }
    
        // Perform operations on the tree
        System.out.println("Search for a key: " + bst.search(7));
        System.out.print("Pre-order traversal: ");
        bst.preOrder();
        System.out.print("In-order traversal: ");
        bst.inOrder();
        System.out.print("Post-order traversal: ");
        bst.postOrder();
        System.out.println("Height of the tree: " + bst.height());
        System.out.println("Minimum element in the tree: " + bst.findMin());
        System.out.println("Is the tree a Binary Search Tree? " + bst.isBinaryTree());
        System.out.print("Nodes at distance 2 from root: ");
        bst.printNodeAtDistance(2);
        System.out.println("Is the tree equal to itself? " + bst.isEqual(bst));
        System.out.println("Number of leaf nodes: " + bst.leafNodes());
        System.out.println("Is 12345 a parent node");
    }
}

