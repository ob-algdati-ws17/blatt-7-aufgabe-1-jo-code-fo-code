#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include <vector>
#include <iostream>


using namespace std;


/// class for creating a self balancing avl tree.
/// \authors jo-code, fo-code
class AvlTree {

private:

     /// Struct with information about a node
    struct Node {

        /// Key of the node.
        int key;

        /// Height of the node.
        int height = 0;

        ///Left chlild of the node.
        Node *left = nullptr;

        ///Right child of the node.
        Node *right = nullptr;

        ///Creates a node with given key.
        Node(const int);

        ///Creates a node with given key and given childs.
        Node(const int, Node *, Node *);

        ///Destructor for a node.
        ~Node();

        ///Recursively inserting a node to the tree.
        /// \return current node in recursion process.
        Node* insert(const int, Node*);

        ///Returns balance of specified node.
        /// \return balance
        int getBal(Node*);

        ///Returns height of specified node.
        /// \return height
        int getHeight(Node*);

        ///left rotation to re-balance the tree.
        /// \return node which is now at the position of the node handed over
        Node* rotateLeft(Node*);

        ///right rotation to re-balance the tree.
        /// \return node which is now at the position of the node handed over
        Node* rotateRight(Node*);

        ///left-right rotation to balance the tree using methods for single left/right rotation.
        /// \return node which is now at the position of the node handed over
        Node* rotateLeftRight(Node*);

        ///right-left rotation to balance the tree using methods for single right/left rotation.
        /// \return node which is now at the position of the node handed over
        Node* rotateRightLeft(Node*);

        ///recursive removing the node with specified key including auto balancing the avl tree.
        ///Auto balancing is made during recursion.
        /// \return current node in recursion process.
        Node* remove(const int, Node*);

        ///Returns the symmetric predecessor of the node.
        /// \return node which is the symmetric predecessor
        Node* symPredecessor(Node *node);

        ///Getting preorder of the avl tree. Used for testing.
        vector<int> *preorder() const;  // (Hauptreihenfolge)

        ///Getting inorder of the avl tree. Used for testing.
        vector<int> *inorder() const;   // (Symmetrische Reihenfolge)

        ///Getting postorder of the avl tree. Used for testing.
        vector<int> *postorder() const; // (Nebenreihenfolge)

        ///Returns all balances of a tree ordered by postorder.
        vector<int>* getAllBalances();
    };

    ///Root & top node of avl tree.
    Node *root = nullptr;

public:
    ///Destructor for the avl tree.
    ~AvlTree();

    ///Searching a node with specified key in the tree.
    /// \return true if node with key found, false if not found.
    bool search(const int);

    ///States if tree is empty.
    bool isEmpty();

    ///Begins recursion to insert new node with key handed over.
    void insert(const int);

    ///Begins recursion to remove a node with key handed over.
    void remove(const int);

    ///Getting preorder of the avl tree. Used for testing.
    vector<int> *preorder() const;  // (Hauptreihenfolge)

    ///Getting postorder of the avl tree. Used for testing.
    vector<int> *inorder() const;   // (Symmetrische Reihenfolge)

    ///Getting postorder of the avl tree. Used for testing.
    vector<int> *postorder() const; // (Nebenreihenfolge)

    ///Returns all balances of a tree ordered by postorder.
    vector<int>* getAllBalances();

    ///Used to print the avl tree to an image file.
    friend ostream &operator<<(ostream &, const AvlTree &);
};

#endif //AVLTREE_AVLTREE_H
