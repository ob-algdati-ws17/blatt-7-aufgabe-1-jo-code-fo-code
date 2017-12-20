#include "testAvlTree.h"
#include <memory>

using namespace std;

/********************************************************************
 * insert tests
 *******************************************************************/

//tests for inserting in the beginning
TEST(AvlTreeTest, OneNodeTest) {
    AvlTree a;
    a.insert(5);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0));
}
TEST(AvlTreeTest, TwoNodeLeftTest) {
    AvlTree a;
    a.insert(5);
    a.insert(3);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,3));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(3,5));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(3,5));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,-1));
}
TEST(AvlTreeTest, TowNodeRightTest) {
    AvlTree a;
    a.insert(5);
    a.insert(8);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,8));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,8));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(8,5));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,1));
}
TEST(AvlTreeTest, ThreeNodeTest) {
    AvlTree a;
    a.insert(5);
    a.insert(3);
    a.insert(8);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,3,8));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(3,5,8));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(3,8,5));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,0));
}
TEST(AvlTreeTest, SevenNodeTest) {
    AvlTree a;
    a.insert(25);
    a.insert(10);
    a.insert(35);
    a.insert(5);
    a.insert(20);
    a.insert(30);
    a.insert(40);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(25,10,5,20,35,30,40));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,10,20,25,30,35,40));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5,20,10,30,40,35,25));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,0,0,0,0,0));
}

//testing inserting element which is already in tree
TEST(AvlTreeTest, ThreeNodeTestInsertDublicateKey) {
    AvlTree a;
    a.insert(5);
    a.insert(3);
    a.insert(8);
    a.insert(5);
    EXPECT_TRUE(a.inorder()->size() == 3);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,3,8));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(3,5,8));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(3,8,5));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,0));
}

//testing rotateLeft with inserting on right leaf
TEST(AvlTreeTest, rotateLeftVar1Test) {
    AvlTree a;
    a.insert(10);
    a.insert(5);
    a.insert(15);
    a.insert(12);
    a.insert(20);
    a.insert(25);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(15,10,5,12,20,25));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,10,12,15,20,25));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5,12,10,25,20,15));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,0,0,1,0));
}
//testing rotateLeft with inserting on left leaf
TEST(AvlTreeTest, rotateLeftVar2Test) {
    AvlTree a;
    a.insert(15);
    a.insert(10);
    a.insert(25);
    a.insert(20);
    a.insert(35);
    a.insert(30);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(25,15,10,20,35,30));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(10,15,20,25,30,35));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(10,20,15,30,35,25));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,0,0,-1,0));
}

//testing rotateRight inserting on left leaf
TEST(AvlTreeTest, rotateRightVar1Test) {
    AvlTree a;
    a.insert(20);
    a.insert(10);
    a.insert(25);
    a.insert(5);
    a.insert(15);
    a.insert(1);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(10,5,1,20,15,25));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(1,5,10,15,20,25));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(1,5,15,25,20,10));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,-1,0,0,0,0));
}
//testing rotateRight inserting on right leaf
TEST(AvlTreeTest, rotateRightVar2Test) {
    AvlTree a;
    a.insert(20);
    a.insert(25);
    a.insert(10);
    a.insert(15);
    a.insert(5);
    a.insert(7);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(10,5,7,20,15,25));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,7,10,15,20,25));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(7,5,15,25,20,10));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,1,0,0,0,0));
}

//testing rotateLeftRight with inserting on left leaf
TEST(AvlTreeTest, rotateLeftRightVar1Test) {
    AvlTree a;
    a.insert(25);
    a.insert(30);
    a.insert(10);
    a.insert(5);
    a.insert(20);
    a.insert(15);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(20,10,5,15,25,30));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,10,15,20,25,30));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5,15,10,30,25,20));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,0,0,1,0));
}
//testing rotateLeftRight with inserting on right leaf
TEST(AvlTreeTest, rotateLeftRightVar2Test) {
    AvlTree a;
    a.insert(20);
    a.insert(10);
    a.insert(25);
    a.insert(5);
    a.insert(15);
    a.insert(17);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(15,10,5,20,17,25));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,10,15,17,20,25));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5,10,17,25,20,15));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,-1,0,0,0,0));
}

//testing rotateRightLeft with inserting on left leaf
TEST(AvlTreeTest, rotateRightLeftVar1Test) {
    AvlTree a;
    a.insert(15);
    a.insert(10);
    a.insert(25);
    a.insert(30);
    a.insert(20);
    a.insert(17);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(20,15,10,17,25,30));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(10,15,17,20,25,30));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(10,17,15,30,25,20));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,0,0,1,0));
}
//testing rotateRightLeft with inserting on right leaf
TEST(AvlTreeTest, rotateRightLeftVar2Test) {
    AvlTree a;
    a.insert(15);
    a.insert(10);
    a.insert(25);
    a.insert(30);
    a.insert(20);
    a.insert(23);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(20,15,10,25,23,30));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(10,15,20,23,25,30));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(10,15,23,30,25,20));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,-1,0,0,0,0));
}

/********************************************************************
 * search tests and isEmpty test
 *******************************************************************/
TEST(AvlTreeTest, SearchTestSevenNodes) {
    AvlTree a;
    a.insert(25);
    a.insert(10);
    a.insert(35);
    a.insert(5);
    a.insert(20);
    a.insert(30);
    a.insert(40);
    EXPECT_TRUE(a.search(25));
    EXPECT_TRUE(a.search(10));
    EXPECT_TRUE(a.search(35));
    EXPECT_TRUE(a.search(5));
    EXPECT_TRUE(a.search(20));
    EXPECT_TRUE(a.search(30));
    EXPECT_TRUE(a.search(40));
}
TEST(AvlTreeTest, SearchTestNodeNotFound) {
    AvlTree a;
    a.insert(25);
    EXPECT_FALSE(a.search(10));
}
TEST(AvlTreeTest, SearchTestEmptyTree) {
    AvlTree a;
    EXPECT_FALSE(a.search(10));
}
TEST(AvlTreeTest, isEmptyTest) {
    AvlTree a;
    bool isEmpty = a.inorder() == nullptr;
    EXPECT_THAT(a.isEmpty(), isEmpty);
}

/********************************************************************
 * remove tests
 *******************************************************************/

//removing from emtpy tree
TEST(AvlTreeTest, RemoveTestEmptyTree) {
    AvlTree a;
    EXPECT_TRUE(a.isEmpty());
    a.remove(5);
    EXPECT_TRUE(a.isEmpty());
}

//test removing root
TEST(AvlTreeTest, RemoveTestRoot) {
    AvlTree a;
    a.insert(25);
    a.insert(10);
    a.insert(35);
    a.insert(5);
    a.insert(20);
    a.insert(30);
    a.insert(40);
    a.insert(23);

    a.remove(25);

    EXPECT_FALSE(a.search(25));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(23,10,5,20,35,30,40));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,10,20,23,30,35,40));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5,20,10,30,40,35,23));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,0,0,0,0,0));
}

//test single right rotation removing deepest element from right side
TEST(AvlTreeTest, RemoveTestRightRotation) {
    AvlTree a;
    a.insert(25);
    a.insert(10);
    a.insert(35);
    a.insert(5);
    a.insert(20);

    a.remove(35);

    EXPECT_FALSE(a.search(35));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(10,5,25,20));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,10,20,25));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5,20,25,10));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,-1,1));
}

//test single left rotation removing deepest element from right side
TEST(AvlTreeTest, RemoveTestLeftRotation) {
    AvlTree a;
    a.insert(25);
    a.insert(10);
    a.insert(35);
    a.insert(30);
    a.insert(40);

    a.remove(10);

    EXPECT_FALSE(a.search(10));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(35,25,30,40));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(25,30,35,40));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(30,25,40,35));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,1,0,-1));
}

//removing from right side deepest element, deepest right side is left
TEST(AvlTreeTest, RemoveTestLeftRightRotatationVar1) {
    AvlTree a;
    a.insert(25);
    a.insert(30);
    a.insert(10);
    a.insert(5);
    a.insert(20);
    a.insert(40);
    a.insert(15);

    a.remove(40);

    EXPECT_FALSE(a.search(40));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(20,10,5,15,25,30));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,10,15,20,25,30));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5,15,10,30,25,20));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,0,0,1,0));
}
//removing from right side deepest element, deepest right side is right
TEST(AvlTreeTest, RemoveTestLeftRightRotatationVar2) {
    AvlTree a;
    a.insert(25);
    a.insert(30);
    a.insert(10);
    a.insert(5);
    a.insert(20);
    a.insert(40);
    a.insert(22);

    a.remove(40);

    EXPECT_FALSE(a.search(40));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(20,10,5,25,22,30));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,10,20,22,25,30));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5,10,22,30,25,20));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,-1,0,0,0,0));
}

//removing from left side deepest element, deepest right side is left
TEST(AvlTreeTest, RemoveTestRightLeftRotatationVar1) {
    AvlTree a;
    a.insert(15);
    a.insert(10);
    a.insert(25);
    a.insert(5);
    a.insert(30);
    a.insert(20);
    a.insert(17);

    a.remove(5);

    EXPECT_FALSE(a.search(5));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(20,15,10,17,25,30));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(10,15,17,20,25,30));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(10,17,15,30,25,20));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,0,0,1,0));
}
//removing from left side deepest element, deepest right side is right
TEST(AvlTreeTest, RemoveTestRightLeftRotatationVar2) {
    AvlTree a;
    a.insert(15);
    a.insert(10);
    a.insert(25);
    a.insert(5);
    a.insert(30);
    a.insert(20);
    a.insert(22);

    a.remove(5);

    EXPECT_FALSE(a.search(5));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(20,15,10,25,22,30));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(10,15,20,22,25,30));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(10,15,22,30,25,20));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,-1,0,0,0,0));
}

TEST(AvlTreeTest, RemoveTestRemoveAll) {
    AvlTree a;
    a.insert(15);
    a.insert(10);
    a.insert(25);
    a.insert(5);
    a.insert(30);
    a.insert(20);
    a.insert(17);

    a.remove(15);
    a.remove(10);
    a.remove(25);
    a.remove(5);
    a.remove(30);
    a.remove(20);
    a.remove(17);

    EXPECT_TRUE(a.isEmpty());
}

//removing not existing element
TEST(AvlTreeTest, RemoveTestNotExistingElement) {
    AvlTree a;
    a.insert(5);
    a.insert(3);
    a.insert(8);
    EXPECT_FALSE(a.search(10));
    a.remove(10);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,3,8));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(3,5,8));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(3,8,5));
    EXPECT_THAT(*a.getAllBalances(), testing::ElementsAre(0,0,0));
}

//removing from empty list
TEST(AvlTreeTest, RemoveTestEmptyList) {
    AvlTree a;
    EXPECT_TRUE(a.isEmpty());
    a.remove(10);
    EXPECT_TRUE(a.isEmpty());
}