#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Note* right;
    Node(int k):key(k), left(nullptr), right(nullptr){};
    Node* newNode(int k){
        Node *node = new Node(k);
    }    
};

class BST{
private:
    Node* root{nullptr};
    Node* insertKeyUtil(Node* node, int key);
    Node* deleteKeyUtil(Node* node, int key);
    Node* inOrderSuccessor(Node* node);
    Node* deleteMin(Node* node);
    Node* floorUtil(Node* node, int k);
    
public:
    void insertKey(Node* node, int k){
        root = insertKeyUtil(root, k);
    }
    
    void deleteKey(Node* node, int k){
        root = deleteKeyUtil(root, k);
    }
    void inOrderTraversal(Node* node);
    void preOrderTraversal(Node* node);
    void postOrderTraversal(Node* node);
    void levelOrderTraversal(Node* node);
    int floor(int k){
        Node* t = floorUtil(root, k);
        return t->key;
    }
};

Node* BST:inOrderSuccessor(Node* node){
    Node* current = node;
    while(current && current->left != nullptr)
        current = current->left;
    return current;
}      

Node* BST::insertKeyUtil(Node* node, int k){
    if (node == nullptr){
        node = new Node(key);
        return key;
    }
    if (k < node->left)
        node->left = insertKeyUtil(node->left, k);
    else if (k > node->right)
        node->right = insertKeyUtil(node->right, k);
    
    return node;
}

Node* BST::deleteKeyUtil(Node* node, int k){
    if (node == nullptr) return node;
    
    if (k < node->left)
        node->left = deleteKeyUtil(node, k);
    else if(k > node->right)
        node->right = deleteKeyUtil(node, k);
    
    else{
        if (node->left == nullptr){
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr){
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = inOrderSuccessor(node->right);
        node->key= temp->key;
        node->right = deleteMin(node->right);
    }
    return node;
}

Node* BST::deleteMin(Node* node){
    if (node == nullptr) return node;
    if (node->left == nullptr){
        Node* temp = node->right;
        delete node;
        return temp;
    }
    node->left = deleteMin(node->left);
}

Node* BST::floorUtil(Node* node, int k){
    if (node == nullptr) return node;
    if (node->key == k) return node;
    if (k < node->key){
        return floorUtil(node->left, k);
    }
    Node* t = floorUtil(node->right)
    if (t == nullptr)
        return node;
    else
        return t;
}
    
    


    
