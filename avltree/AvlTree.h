#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include <vector>

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

        vector<int> *preorder() const;  // (Hauptreihenfolge)
        vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
        vector<int> *postorder() const; // (Nebenreihenfolge)

        Node* insert(const int, Node*);

        int getBal(Node*);
        int getHeight(Node*);

        Node* rotateLeft(Node*);
        Node* rotateRight(Node*);
        Node* rotateLeftRight(Node*);
        Node* rotateRightLeft(Node*);
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
};

#endif //AVLTREE_AVLTREE_H
