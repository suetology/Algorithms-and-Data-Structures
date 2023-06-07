package org.example;

public class Tree<T> {
    private TreeNode<T> root = null;

    public void add(T data) {
        if (root == null) {
            root = new TreeNode<>(data);
        } else {
            TreeNode<T> s = root;
            while (s.nextSibling != null)
                s = s.nextSibling;
            s.nextSibling = new TreeNode<>(data);
        }
    }

    public void addAsChild(T parentData, T dataToAdd) {
        TreeNode<T> node = find(root, parentData);
        if (node == null)
            return;

        if (node.firstChild == null) {
            node.firstChild = new TreeNode<>(dataToAdd);
            return;
        }

        TreeNode<T> child = node.firstChild;
        while (child.nextSibling != null)
            child = child.nextSibling;
        child.nextSibling = new TreeNode<>(dataToAdd);
    }

    public boolean contains(T data) {
        if (root == null)
            return false;

        return find(root, data) != null;
    }

    private TreeNode<T> find(TreeNode<T> node, T data) {
        while (node != null) {
            if (node.data.equals(data))
                return node;
            if (node.firstChild != null) {
                TreeNode<T> foundNode = find(node.firstChild, data);
                if (foundNode != null)
                    return foundNode;
            }
            node = node.nextSibling;
        }
        return null;
    }

    @Override
    public String toString() {
        if (root == null)
            return "Tree is empty";
        return root.toString();
    }

    private class TreeNode<t> {
        private final t data;
        private TreeNode<t> firstChild;
        private TreeNode<t> nextSibling;

        public TreeNode(t data) {
            this.data = data;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(data.toString()).append(" - Siblings to right: ");
            TreeNode<t> node = this;
            while (node.nextSibling != null) {
                sb.append(node.nextSibling.data).append(" ");
                node = node.nextSibling;
            }
            sb.append(" Children: ");
            node = this.firstChild;
            while (node != null) {
                sb.append(node.data).append(" ");
                node = node.nextSibling;
            }
            sb.append('\n');

            if (this.nextSibling != null)
                sb.append(this.nextSibling);

            if (this.firstChild != null)
                sb.append(this.firstChild);

            return sb.toString();
        }
    }
}
