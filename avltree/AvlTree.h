#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

class AvlTree {

private:

    struct Node {
        const int key;
        Node *left = nullptr;
        Node *right = nullptr;
        Node(const int);
        Node(const int, Node *, Node *);
        ~Node();
    };

    Node *root = nullptr;

public:

    ~AvlTree();
    bool search(const int) const;
    void insert(const int);
    void remove(const int);
};


#endif //AVLTREE_AVLTREE_H
