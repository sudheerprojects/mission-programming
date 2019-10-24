#include <iostream>
using namespace std;

struct Node{
    int key {0};
    int height {0};
    Node* left{nullptr};
    Node* right{nullptr};
    Node(int k):key(k){}
};

int height(Node* node){
    if (node == nullptr)
        return 0;
    return node->height;
}

inline int max(int a, int b){
    return a>b?a:b;
}

int balanceFactor(Node* node){
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* node){
    Node* newNode = node->left;
    node->left = newNode->right;
    newNode->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    newNode->height = max(height(newNode->left), height(newNode->right)) + 1;
    return newNode;
}

Node* leftRotate(Node* node){
    Node* newNode = node->right;
    node->right = newNode->left;
    newNode->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    newNode->height = max(height(newNode->left), height(newNode->right)) + 1;
    return newNode;
}

Node* minValueNode(Node* node){
    Node* minNode = node;
    while (node->left){
        node = node->left;
        if (node->data < minNode->data)
            minNode = node;
    }
    return minNode;
}

Node* insert(Node* node, int k){
    if (node == nullptr)
        return new Node(k);
    if (node->left && k < node->left->key)
        node->left = insert(node->left, k);
    else if (node->right && k>node->right->key)
        node->right = insert(node->right, k);
    
    else // Equal keys not allowed  
        return node;  
  
    // Update height of this ancestor node
    node->height = 1 + max(height(node->left),  
                           height(node->right));
    
    int balance = balanceFactor(node);
    //left left
    if (balance > 1 && k < node->left->key)
        rightRotate(node);
    
    //right right
    else if (balance < -1 && k > node->right->key)
        leftRotate(node);
    
    //left right
    else if (balance > 1 && k>node->left->key){
        node->left = leftRotate(node->left);
        rightRotate(node);
    }
    //right left
    else if (balance < -1 && k < node->key){
        node->right = rightRotate(node->right)
        leftRotate(node);
    }
    return node;
}

Node* deleteNode(Node* node, k){
    if (node == nullptr)
        return node;
    if (node->left && k>node->key)
        node->left = deleteNode(node->left, k);
    else if (node->right && k>node->right)
        node->right = deleteNode(node->right, k)
    else{
        if (node->left == nullptr || node->right == nullptr){
            temp = node->left?node->right:node->left;
            delete node;
            return temp;
        }
        else {
            Node* temp = minValueNode(node);
            node->key = temp->key;
            node->right = deleteNode(node->right, node->key)
        }
    }
    if (node == nullptr)
        return node;
    
    // Update height of this ancestor node
    node->height = 1 + max(height(node->left),  
                           height(node->right));
    
    int balance = balanceFactor(node);
    //left left
    if (balance > 1 && balanceFactor(root->left)>=0)
        rightRotate(node);
    
    //right right
    else if (balance < -1 && balanceFactor(root->right)<=0)
        leftRotate(node);
    
    //left right
    else if (balance > 1 && balanceFactor(root->left)<0){
        node->left = leftRotate(node->left);
        rightRotate(node);
    }
    //right left
    else if (balance < -1 && balanceFactor(root->right)>0){
        node->right = rightRotate(node->right)
        leftRotate(node);
    }
    return node;
}
    
       
    


    