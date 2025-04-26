#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}


//(Left -> root -> right )  
void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// (Root, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


// (Left, Right, Root)
void postorder(Node* root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


int size(Node* root) {
    if (root == nullptr)
        return 0;

    return 1 + size(root->left) + size(root->right);
}




int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    insert(root, 11);
    insert(root, 4);
    insert(root, 5);
    insert(root, 12);
    insert(root, 20);
    insert(root, 11);
    

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl << " ------------------- " << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl << " ------------------- " << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl << " ------------------- " << endl;
    
    cout << "the size of tree is :" <<size (root);
    return 0;
}
