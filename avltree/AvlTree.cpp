#include "AvlTree.h"


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
    if (root == nullptr) {
        root = new Node(key);
        root->bal = 0;
    }


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

void AvlTree::setBal(Node *n) {
    n->bal = n->right->height - n->left->height;
}

int AvlTree::getHeight(Node *n) {
    if (n == nullptr)
        return -1;
    else
        return n->height;
}