#include "testAvlTree.h"
#include <memory>

using namespace std;

//tests for inserting in the beginning
TEST(AvlTreeTest, OneNodeTest) {
    AvlTree a;
    a.insert(5);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(5));
}
TEST(AvlTreeTest, TwoNodeLeftTest) {
    AvlTree a;
    a.insert(5);
    a.insert(3);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,3));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(3,5));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(3,5));
}
TEST(AvlTreeTest, TowNodeRightTest) {
    AvlTree a;
    a.insert(5);
    a.insert(8);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,8));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(5,8));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(8,5));
}
TEST(AvlTreeTest, ThreeNodeTest) {
    AvlTree a;
    a.insert(5);
    a.insert(3);
    a.insert(8);
    EXPECT_THAT(*a.preorder(), testing::ElementsAre(5,3,8));
    EXPECT_THAT(*a.inorder(), testing::ElementsAre(3,5,8));
    EXPECT_THAT(*a.postorder(), testing::ElementsAre(3,8,5));
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
}
//testing rotateLeftRight with inserting on right leaf
TEST(AvlTreeTest, rotateLeftRightVar2Test) {
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
}



