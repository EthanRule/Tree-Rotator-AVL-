#include "pch.h"
#include "../Project1/AVLTree.h"

TEST(AVLTree, NULLHEIGHT)
{
	AVLTree<int> tree = AVLTree<int>();
	EXPECT_EQ(tree.heightHelper(NULL), 0);
}

TEST(AVLTree, CONTAINSWORKS)
{
		AVLTree<int> tree = AVLTree<int>();
		tree.insert(1);
		tree.insert(2);
		tree.insert(3);
		EXPECT_EQ(tree.contains(1), true);
		EXPECT_EQ(tree.contains(2), true);
		EXPECT_EQ(tree.contains(3), true);
}