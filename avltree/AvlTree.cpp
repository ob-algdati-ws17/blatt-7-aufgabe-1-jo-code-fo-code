#include "AvlTree.h"

#include <iostream>
#include <functional>

using namespace std;


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
            if(key > node->right->key)
                node = rotateLeft(node);
            else
                node = rotateRightLeft(node);
        }
    }
    else if(node->key > key){
        node->left = insert(key, node->left);
        if(getBal(node) < -1) {
            //ROTATING right
            if(key < node->left->key)
                node = rotateRight(node);
            else
                node = rotateLeftRight(node);
        }
    }

    if (getHeight(node->left) < getHeight(node->right))
        node->height = getHeight(node->right) + 1;
    else
        node->height = getHeight(node->left) + 1;

    return node;
}

void AvlTree::remove(const int key) {
    if(search(key)) {
        root = root->remove(key, root);
    }
}

AvlTree::Node* AvlTree::Node::remove(const int key, Node *node) {
    if(key < node->key)
        node->left = remove(key, node->left);
    else if(key > node->key)
        node->right = remove(key, node->right);
    else {
        if(node->left != nullptr && node->right != nullptr) {
            Node *predecessor = symPredecessor(node);
            node->key = predecessor->key;
            node->left = remove(node->key, node->left);
        }
        else {
            if(node->left != nullptr)
                node = node->left;
            else if(node->right != nullptr)
                node = node->right;
            else {
                node = nullptr;
                return node;
            }
        }

        //balancing
    }

}

AvlTree::Node* AvlTree::Node::symPredecessor(Node *node) {
    node = node->left;
    while(node->right != nullptr) {
        node = node->right;
    }
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
    node->left = rotateLeft(node->left);
    Node* tmp = rotateRight(node);
    return tmp;
}

AvlTree::Node* AvlTree::Node::rotateRightLeft(Node* node) {
    node->right = rotateRight(node->right);
    Node* tmp = rotateLeft(node);
    return tmp;
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
    if(node == nullptr)
        return 0;
    else
        return getHeight(node->right) - getHeight(node->left);
}

int AvlTree::Node::getHeight(Node *node) {
    if(node == nullptr)
        return -1;
    else
        return node->height;
}

//returning balances in postorder
vector<int>* AvlTree::getAllBalances() {
    if(root == nullptr)
        return nullptr;
    return root->getAllBalances();
}
vector<int>* AvlTree::Node::getAllBalances() {
    auto v = new vector<int>();

    if (left != nullptr) {
        auto v_left = left->getAllBalances();
        v->insert(v->end(), v_left->begin(), v_left->end());
    }

    if (right != nullptr) {
        auto v_right = right->getAllBalances();
        v->insert(v->end(), v_right->begin(), v_right->end());
    }

    v->push_back(getBal(this));
    return v;
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
/********************************************************************
 * operator<<
 *******************************************************************/
std::ostream &operator<<(std::ostream &os, const AvlTree &tree) {
    function<void(std::ostream &, const int, const AvlTree::Node *, const string)> printToOs
            = [&](std::ostream &os, const int value, const AvlTree::Node *node, const string l) {

                static int nullcount = 0;

                if (node == nullptr) {
                    os << "    null" << nullcount << "[shape=point];" << endl;
                    os << "    " << value << " -> null" << nullcount
                       << " [label=\"" << l << "\"];" << endl;
                    nullcount++;
                } else {
                    os << "    " << value << " -> " << node->key
                       << " [label=\"" << l << "\"];" << endl;

                    printToOs(os, node->key, node->left, "l");
                    printToOs(os, node->key, node->right, "r");
                }
            };
    os << "digraph tree {" << endl;
    if (tree.root == nullptr) {
        os << "    null " << "[shape=point];" << endl;
    } else {
        printToOs(os, tree.root->key, tree.root->left, "l");
        printToOs(os, tree.root->key, tree.root->right, "r");
    }
    os << "}" << endl;
    return os;
}