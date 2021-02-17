#ifndef __binary_tree__
#define __binary_tree__

#include "binary_treeTypes.h"

BTTree BTCreate(int maxelem); //create an empty binary tree (maxelem is ignored)

int BTHeight(BTTree tree); //return the height of the tree

int BTSize(BTTree tree); //return the number of elements in the tree

BTNode BTGetRoot(BTTree tree); //returns the root node (can be Nil)

BTNode BTGetParent(BTTree tree, BTNode node);//returns the parent of a node (prints error if node is root)

BTNode BTGetChildLeft(BTTree tree, BTNode node); //returns the left child of a node (can be Nil)

BTNode BTGetChildRight(BTTree tree, BTNode node); //returns the right child of a node (can be Nil)

int BTIsNil(BTNode node); // returns true if the node is Nil, otherwise return false

BTItem BTGetItem(BTTree tree, BTNode node); //returns the value of the given node (error if node is Nil)

void BTInsertRoot(BTTree tree, BTItem item); //insert item as root of empty tree (prints error if not empty)

void BTInsertLeft(BTTree tree, BTNode node, BTItem item); //insert item as left child of node (error if left child exists)

void BTInsertRight(BTTree tree, BTNode node, BTItem item); //insert item as right child of node (error if right child exists)

void BTRemove(BTTree tree, BTNode node); //removes node (error if it has children)

void BTChange(BTTree tree, BTNode node, BTItem item); //sets item as the new value of the given node

void BTPreOrder(BTTree tree, BTFun visit); // traverse the tree and visit its nodes in the respective order

void BTInOrder(BTTree tree, BTFun visit); // traverse the tree and visit its nodes in the respective order

void BTPostOrder(BTTree tree, BTFun visit); // traverse the tree and visit its nodes in the respective order

void BTLevelOrder(BTTree tree, BTFun visit); // traverse the tree and visit its nodes in the respective order

void BTDestroy(BTTree tree); // destroys the tree by freeing all its nodes

#endif