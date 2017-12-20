#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include <vector>
#include <iostream>


using namespace std;

/**
 * class for creating a self balancing avl tree.
 *
 * \authors jo-code, fo-code
 */
class AvlTree {

private:

    /**
     * Struct with information about a node
     */
    struct Node {
        /**
         * Key of this node.
         */
        int key;
        /**
         * Height of this node.
         */
        int height = 0;
        /**
         * Left chlild of this node.
         */
        Node *left = nullptr;
        /**
         * Right child of this node.
         */
        Node *right = nullptr;
        /**
         * Creates a node with given key.
         */
        Node(const int);
        Node(const int, Node *, Node *);
        ~Node();

        Node* insert(const int, Node*);

        int getBal(Node*);
        int getHeight(Node*);

        Node* rotateLeft(Node*);
        Node* rotateRight(Node*);
        Node* rotateLeftRight(Node*);
        Node* rotateRightLeft(Node*);

        Node* remove(const int, Node*);
        Node* symPredecessor(Node *node);

        vector<int> *preorder() const;  // (Hauptreihenfolge)
        vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
        vector<int> *postorder() const; // (Nebenreihenfolge)

        vector<int>* getAllBalances();
    };

    Node *root = nullptr;

public:
    /// \testcomment
    ~AvlTree();
    bool search(const int);
    bool isEmpty();
    void insert(const int);
    void remove(const int);

    vector<int> *preorder() const;  // (Hauptreihenfolge)
    vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
    vector<int> *postorder() const; // (Nebenreihenfolge)

    vector<int>* getAllBalances();

    friend ostream &operator<<(ostream &, const AvlTree &);
};

#endif //AVLTREE_AVLTREE_H
