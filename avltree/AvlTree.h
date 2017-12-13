#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include <vector>
#include <iostream>


using namespace std;

class AvlTree {

private:

    struct Node {
        const int key;
        int height = 0;
        Node *left = nullptr;
        Node *right = nullptr;
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

        vector<int> *preorder() const;  // (Hauptreihenfolge)
        vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
        vector<int> *postorder() const; // (Nebenreihenfolge)

        vector<int>* getAllBalances();
    };

    Node *root = nullptr;

public:

    ~AvlTree();
    bool search(const int) const;
    void insert(const int);
    void remove(const int);

    vector<int> *preorder() const;  // (Hauptreihenfolge)
    vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
    vector<int> *postorder() const; // (Nebenreihenfolge)

    vector<int>* getAllBalances();

    friend ostream &operator<<(ostream &, const AvlTree &);
};

#endif //AVLTREE_AVLTREE_H
