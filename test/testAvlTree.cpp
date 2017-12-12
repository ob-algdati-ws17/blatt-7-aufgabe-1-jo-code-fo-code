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