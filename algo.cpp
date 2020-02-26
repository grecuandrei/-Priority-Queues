#include <iostream>

class Node{
    friend class AVL;

private:
    int data;
    int height;
    Node* left;
    Node* right;

public:
    Node(int key) {
        data= key;
        left = nullptr;
        right = nullptr;
        height = 0;
    }

    ~Node() {

    }
};

class AVL {
private:
    Node* root;

    Node* rotR(Node* n) {
        Node* node = n->left;
        n->left = node->right;
        node->right = n;
        n->height = std::max(nodeHeight(n->left), nodeHeight(n->right));
        node->height = std::max(nodeHeight(node->left), nodeHeight(node->right));
        return node;
    }

    Node* rotL(Node* n) {
        Node* node = n->right;
        n->right = node->left;
        node->left = n;
        n->height = std::max(nodeHeight(n->left), nodeHeight(n->right));
        node->height = std::max(nodeHeight(node->left), nodeHeight(node->right));
        return node;
    }

    Node* maxNode(Node* node) {
        if(node->right == nullptr) return node;
        else return maxNode(node->right);
    }

    Node* minNode(Node* node) {
        if(node->left == nullptr) return node;
        else return minNode(node->left);
    }

    Node* rotLR(Node* n) {
        n->left = rotL(n->left);
        return rotR(n);
    }

    Node* rotRL(Node* n) {
        n->right = rotR(n->right);
        return rotL(n);
    }

    int nodeHeight(Node* node) {
        return (node != nullptr)? node->height + 1:0;
    }

    Node* insert_(int key, Node* node) {
        if(node == nullptr) {
            return node = new Node(key);
        } else if(key < node->data) {
            node->left = insert_(key, node->left);
        } else if(key >= node->data) {
            node->right = insert_(key, node->right);
        }

        node->height = std::max(nodeHeight(node->left), nodeHeight(node->right));

        int balance = nodeHeight(node->left) - nodeHeight(node->right);
        if(balance > 1) { ///L
            if(key < node->left->data) { ///L
                return node = rotR(node);
            } else { ///R
                return node = rotLR(node);
            }
        } else if(balance < -1) { ///R
            if(key < node->right->data) { ///L
                return node = rotRL(node);
            } else { ///R
                return node = rotL(node);
            }
        }
        return node;
    }

    Node* pop(int key, Node* node) {
        if(node == nullptr) {
            return nullptr;
        }

        if(key < node->data) {  /// if the key is smaller than the curr node
            node->left = pop(key, node->left);
        } else if(key > node->data) {  /// if is bigger
            node->right = pop(key, node->right);
        } else { /// if(node->data == key)
            if(node->left == nullptr && node->right == nullptr) {
                /// if it is a leaf
                delete node;
                return nullptr;
            } else if(node->left == nullptr && node->right != nullptr) {
                /// if it has a node to the right
                Node* sub_right_tree = node->right;
                delete node;
                return sub_right_tree;
            } else if(node->left != nullptr && node->right == nullptr) {
                /// if it has a node to the left
                Node* sub_left_tree = node->left;
                delete node;
                return sub_left_tree;
            } else {
                /// else if it has both child
                Node* maxNodeSubLeftT = maxNode(node->left);
                node->data = maxNodeSubLeftT->data;
                node->left = pop(maxNodeSubLeftT->data, node->left);
            }
        }

        node->height = std::max(nodeHeight(node->left), nodeHeight(node->right));

        int balance = nodeHeight(node->left) - nodeHeight(node->right);
        if(balance > 1) { ///L
            if(nodeHeight(node->left->left) > nodeHeight(node->left->right)) { ///L
                return node = rotR(node);
            } else { ///R
//                node->left = rotL(node->left);
//                return node = rotR(node);
                return node = rotLR(node);
            }
        } else if(balance < -1) { ///R
            if(nodeHeight(node->right->left) > nodeHeight(node->right->right)) { ///L
//                node->right = rotR(node->right);
//                return node = rotL(node);
                return node = rotRL(node);
            } else { ///R
                return node = rotL(node);
            }
        }
        return node;
    }

public:
    /// inti tree
    AVL() {
        root = nullptr;
    }

    ~AVL() {

    }

    void insertKey(int key) {
        root = insert_(key, root);
    }

    void deleteKey(int key) {
        root = pop(key, root);
    }

    Node* getRoot() {
        return root;
    }

    int getMax() {
        return maxNode(root)->data;
    }

    int getMin() {
        return minNode(root)->data;
    }

    void preOrder(Node* root) {
        if(root != nullptr) {
            std::cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};
