#include "testAvlTree.h"
#include <memory>

using namespace std;

TEST(AvlTreeTest, OneNodeTest) {
    AvlTree a;
    a.insert(5);
    EXPECT_TRUE(a.search(5));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5));
}

TEST(AvlTreeTest, TwoNodeLeftTest) {
    AvlTree a;
    a.insert(5);
    a.insert(3);
    EXPECT_TRUE(a.search(5));
    EXPECT_TRUE(a.search(3));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,3));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(3,5));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(3,5));
}

TEST(AvlTreeTest, TowNodeRightTest) {
    AvlTree a;
    a.insert(5);
    a.insert(8);
    EXPECT_TRUE(a.search(5));
    EXPECT_TRUE(a.search(8));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,8));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,8));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(8,5));
}

TEST(AvlTreeTest, ThreeNodeTest) {
    AvlTree a;
    a.insert(5);
    a.insert(3);
    a.insert(8);
    EXPECT_TRUE(a.search(5));
    EXPECT_TRUE(a.search(3));
    EXPECT_TRUE(a.search(8));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,3,8));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(3,5,8));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(3,8,5));
}

TEST(AvlTreeTest, rotateLeftTest) {
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
}

TEST(AvlTreeTest, rotateRightTest) {
    AvlTree a;
    a.insert(20);
    a.insert(10);
    a.insert(15);
    a.insert(5);
    a.insert(1);
    a.insert(25);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(10,5,1,20,15,25));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(1,5,10,15,20,25));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(1,5,15,25,20,10));
}

TEST(AvlTreeTest, rotateLeftRightTest) {
    AvlTree a;
    a.insert(20);
    a.insert(10);
    a.insert(25);
    a.insert(5);
    a.insert(15);
    a.insert(12);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(15,10,5,12,20,25));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,10,12,15,20,25));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5,12,10,25,20,15));
}