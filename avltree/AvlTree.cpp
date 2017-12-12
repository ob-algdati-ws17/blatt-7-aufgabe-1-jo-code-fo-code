#include "AvlTree.h"

using namespace ::std;


/********************************************************************
 * Konstruktoren
 ********************************************************************/
AvlTree::Node::Node(const int k) : key(k) {};

AvlTree::Node::Node(const int k, Node* l, Node* r) : key(k), left(l), right(r) {};


/********************************************************************
* Destruktoren
*********************************************************************/
AvlTree::~AvlTree() {
    delete root;
}
AvlTree::Node::~Node() {
    delete left;
    delete right;
}


void AvlTree::insert(const int key) {
    root = root->insert(key, root);
}

AvlTree::Node* AvlTree::Node::insert(const int key, Node *node) {
    if(node == nullptr)
        node = new Node(key);
    else if(node->key < key) {
        node->right = insert(key, node->right);
        if(getBal(node) > 1) {
            //ROTATING left
        }
    }
    else {
        node->left = insert(key, node->left);
        if(getBal(node) < -1) {
            //ROTATING right
        }
    }

    if (getHeight(node->left) < getHeight(node->right))
        node->height = getHeight(node->right) + 1;
    else
        node->height = getHeight(node->left) + 1;

    return node;
}

AvlTree::Node* AvlTree::Node::rotateLeft(Node* node) {
    Node* top = node->right;
    node->right = top->left;
    top->left = node;

    if (getHeight(node->left) < getHeight(node->right))
        node->height = getHeight(node->right) + 1;
    else
        node->height = getHeight(node->left) + 1;

    if (getHeight(top->left) < getHeight(top->right))
        top->height = getHeight(top->right) + 1;
    else
        top->height = getHeight(top->left) + 1;

    return top;
}

AvlTree::Node* AvlTree::Node::rotateRight(Node* node) {
    Node* top = node->left;
    node->left = top->right;
    top->right = node;

    if (getHeight(node->left) < getHeight(node->right))
        node->height = getHeight(node->right) + 1;
    else
        node->height = getHeight(node->left) + 1;

    if (getHeight(top->left) < getHeight(top->right))
        top->height = getHeight(top->right) + 1;
    else
        top->height = getHeight(top->left) + 1;

    return top;
}

AvlTree::Node* AvlTree::Node::rotateLeftRight(Node* node) {

}

AvlTree::Node* AvlTree::Node::rotateRightLeft(Node* node) {

}


void AvlTree::remove(const int key) {

}

bool AvlTree::search(const int key) const {

    Node *curr = root;

    while (true) {
        if (curr == nullptr) {
            return false;
        } else if (curr->key > key) {
            curr = curr->left;
        } else if (curr->key < key) {
            curr = curr->right;
        } else if(curr->key == key){
            return true;
        }
    }
}

int AvlTree::Node::getBal(Node *node) {
    return getHeight(node->right) - getHeight(node->left);
}

int AvlTree::Node::getHeight(Node *node) {
    if(node == nullptr)
        return -1;
    else
        return node->height;
}



vector<int> *AvlTree::preorder() const {
    if (root == nullptr)
        return nullptr;
    return root->preorder();
}

vector<int> *AvlTree::Node::preorder() const {
    auto vec = new vector<int>();
    // Wurzel in vec
    vec->push_back(key);
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->preorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->preorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

vector<int> *AvlTree::inorder() const {
    if (root == nullptr)
        return nullptr;
    return root->inorder();
}

vector<int> *AvlTree::Node::inorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->inorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->inorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

vector<int> *AvlTree::postorder() const {
    if (root == nullptr)
        return nullptr;
    return root->postorder();
}

vector<int> *AvlTree::Node::postorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->postorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->postorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    return vec;
}