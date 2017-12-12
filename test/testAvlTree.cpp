#include "testAvlTree.h"
#include <memory>

using namespace std;

TEST(AvlTreeTest, OneNode) {
    AvlTree a;
    a.insert(5);
    EXPECT_TRUE(a.search(5));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5));
}

TEST(AvlTreeTest, TwoNodeLeft) {
    AvlTree a;
    a.insert(5);
    a.insert(3);
    EXPECT_TRUE(a.search(5));
    EXPECT_TRUE(a.search(3));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,3));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(3,5));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(3,5));
}

TEST(AvlTreeTest, TowNodeRight) {
    AvlTree a;
    a.insert(5);
    a.insert(8);
    EXPECT_TRUE(a.search(5));
    EXPECT_TRUE(a.search(8));
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,8));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,8));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(8,5));
}

TEST(AvlTreeTest, ThreeNode) {
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