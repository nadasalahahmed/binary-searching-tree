#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left, *right;
  Node()
  {
    data = 0;
    left = right = NULL;
  }
  Node(int d)
  {
    data = d;
    left = right = NULL;
  }
};

Node *insert(Node *root, int data)
{
  if (root == NULL)
    return new Node (data);
  
  if (data < root->data)
  {
    root->left = insert(root->left, data);
  }
  else
  {
    root->right = insert(root->right, data);
  }
  return root;
}

void Postorder(Node *root)
{
  if (root == NULL)
    return;

  Postorder(root->left);
  Postorder(root->right);
  cout << root->data << "\t";
}

void Preorder(Node *root)
{
  if (root == NULL)
    return;

  cout << root->data << "\t";
  Preorder(root->left);
  Preorder(root->right);
}

void Inorder(Node *root)
{
  if (root == NULL)
    return;

  Inorder(root->left);
  cout << root->data << "\t";
  Inorder(root->right);
}


int treeSize(Node *root)
{
  if (root == NULL)
    return 0;
  return 1 + treeSize(root->left) + treeSize(root->right);
}


int treeHeight(Node *element)
{
  if (element == NULL)
    return 0;
  int x, y;
  x = treeHeight(element->left);
  y = treeHeight(element->right);
  if (x > y)
    return 1 + x;
  else
    return 1 + y;
}



Node* deleteNode(Node* root, int key) {

  if (root == NULL)
    return root;

  if (key < root->data)
    root->left = deleteNode(root->left, key);


  else if (key > root->data)
    root->right = deleteNode(root->right, key);

  else {
    if (root->left == NULL && root->right == NULL) {
      delete root;
      return NULL;
    }

    else if (root->left == NULL) {
      Node* temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL) {
      Node* temp = root->left;
      delete root;
      return temp;
    }

    else {
      Node* temp = root->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }

      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
    }
  }

  return root;
}

int treeMin(Node *element)
{
  Node *current = element;
  while (current->left != NULL)
  {
    current = current->left;
  }
  return (current->data);
}

int treeMax(Node *element)
{
  Node *current = element;
  while (current->right != NULL)
  {
    current = current->right;
  }
  return (current->data);
}


int main()
{
    Node* root = NULL;


    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    Postorder(root);
    cout << endl;

    cout << "\nTree Size: " << treeSize(root) << endl;
    cout << "Tree Height: " << treeHeight(root) << endl;
    cout << "Minimum Value: " << treeMin(root) << endl;
    cout << "Maximum Value: " << treeMax(root) << endl;


    cout << "\nDeleting 70...\n";
    root = deleteNode(root, 70);

    cout << "\nInorder Traversal After Deletion: ";
    Inorder(root);
    cout << endl;

    return 0;


}