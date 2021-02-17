#include <stdlib.h>
#include <stdio.h>

#include "binary_tree.h"
#include "binary_treeTypes.h"

struct BTNodeArray
{
	struct BTNodeArray *lchild;
	BTItem item;
	struct BTNodeArray *parent;
	struct BTNodeArray *rchild;
} BTNodeArray;

struct BTTreeArray
{
	int treeSize;
	BTNode *nodes;
} BTTreeArray;


BTTree BTCreate(int maxlem)//create an empty binary tree (maxelem is not ignored)
{
	BTTree tree = malloc(sizeof(BTTreeArray));
	tree->treeSize=0;
	tree->nodes = malloc(maxlem * sizeof(struct BTNodeArray));

	for (int i = 0; i < maxlem; i++)
	{
	    tree->nodes[i]->item = -1;
	}
	return tree;
}

static int BTHeightTraversal(BTNode node)
{
    if (BTIsNil(node) || (BTIsNil(node->lchild) == 1 && BTIsNil(node->rchild) == 1))
    {
        return 0;
    }
    else
    {
        int heightOfLeftSubTree = BTHeightTraversal(node->lchild);
        int heightOfRightSubTree = BTHeightTraversal(node->rchild);
        if (heightOfLeftSubTree > heightOfRightSubTree)
        {
            return heightOfLeftSubTree+1;
        }
        else
        {
            return heightOfRightSubTree+1;
        }
    }
}

int BTHeight(BTTree tree) //return the height of the tree
{
    return BTHeightTraversal(tree->nodes[0]);
}


int BTSize(BTTree tree) //return the number of elements in the tree
{
 	return tree->treeSize;
}


BTNode BTGetRoot(BTTree tree) //returns the root node (can be Nil)
{
	return tree->nodes[0];
}

BTNode BTGetParent(BTTree tree, BTNode node) //returns the parent of a node (prints error if node is root)
{
	if (node->parent == NULL)
	{
		printf("Error : The node is the root\n");
		return NULL;
	}
	else
	{
		return node->parent;
	}
}


BTNode BTGetChildLeft(BTTree tree, BTNode node) //returns the left child of a node (can be Nil)
{
	return node->lchild;
}


BTNode BTGetChildRight(BTTree tree, BTNode node) //returns the right child of a node (can be Nil)
{
	return node->rchild;
}


int BTIsNil(BTNode node) // returns true if the node is Nil, otherwise return false
{
	return node == NULL;//Nil==1 Nil!=0
}


BTItem BTGetItem(BTTree tree, BTNode node) //returns the value of the given node (error if node is Nil)
{
	if(BTIsNil(node)==1)
	{
		printf("Error : The node is Nil\n");
        return BT_ITEM_NIL;
	}
	else 
	{
		return node->item;
	}
}


void BTInsertRoot(BTTree tree, BTItem item) //insert item as root of empty tree (prints error if not empty)
{
    if(tree->nodes[0]!=NULL)
    {
        printf("Error : The tree has already root\n");
    }
    else
    {
        printf("Inserting root...\n");
        tree->nodes[0] = malloc(sizeof(struct BTNodeArray));
        tree->nodes[0]->item=item;
        tree->nodes[0]->lchild=NULL;
        tree->nodes[0]->rchild=NULL;
        tree->nodes[0]->parent=NULL;
        tree->treeSize++;
    }
}


void BTInsertLeft(BTTree tree, BTNode node, BTItem item) //insert item as left child of node (error if left child exists)
{
	if(node->lchild!=NULL)
	{
		printf("Error : Left child exists\n");
	}
	else
	{
		node->lchild = malloc(sizeof(BTNodeArray));
		node->lchild->lchild=NULL;
		node->lchild->item=item;
		node->lchild->parent=node;
		node->lchild->rchild=NULL;
		tree->treeSize++;
	}
}


void BTInsertRight(BTTree tree, BTNode node, BTItem item) //insert item as right child of node (error if right child exists)
{

	if(node->rchild!=NULL)
	{
		printf("Error : Right child exists\n");
	}
	else
	{
		node->rchild = malloc(sizeof(BTNodeArray));
		node->rchild->lchild = NULL;
		node->rchild->item = item;
		node->rchild->parent = node;
		node->rchild->rchild = NULL;
		tree->treeSize++;
	}
}


void BTRemove(BTTree tree, BTNode node) //removes node (error if it has children)
{
	
	if (node->lchild != NULL || node->rchild != NULL)
	{
		printf("Error : The node has children");
	}
	else
	{
		if (node->parent != NULL)// node is not root
		{
			if (node->parent->lchild == node) 
			{
				node->parent->lchild = NULL;
			}
			else 
			{
                node->parent->rchild = NULL;
            }
		}
		else
        {
		    // removing root
		    tree->nodes[0] = NULL;
        }
		free(node);
		tree->treeSize--;
	}	
}


void BTChange(BTTree tree, BTNode node, BTItem item) //sets item as the new value of the given node
{
	node->item=item;
}


static void BTPreOrderTraversal(BTTree tree, BTNode node, BTFun visit) 
{
	if (node == NULL)
	{
		return;//end
	}

	visit(tree, node);

	BTPreOrderTraversal(tree, node->lchild, visit);

	BTPreOrderTraversal(tree, node->rchild, visit);
}

void BTPreOrder(BTTree tree, BTFun visit) 
{
	BTPreOrderTraversal(tree, tree->nodes[0], visit);
}



static void BTInOrderTraversal(BTTree tree, BTNode node, BTFun visit)
{
	if (node == NULL)
	{
		return;//end
	}

	BTInOrderTraversal(tree, node->lchild, visit);

	visit(tree, node);

	BTInOrderTraversal(tree, node->rchild, visit);
}

void BTInOrder(BTTree tree, BTFun visit) 
{
	BTInOrderTraversal(tree, tree->nodes[0], visit);
}

static void BTPostOrderTraversal(BTTree tree, BTNode node, BTFun visit)
{
	if (node == NULL)
	{
		return;//end
	}

	BTPostOrderTraversal(tree, BTGetChildLeft(tree, node), visit);

	BTPostOrderTraversal(tree, BTGetChildRight(tree, node), visit);

	visit(tree, node);
}

void BTPostOrder(BTTree tree, BTFun visit) 
{
	BTPostOrderTraversal(tree, tree->nodes[0], visit);
}

static void BTLevelOrderTraversal(BTTree tree, BTNode node, int level, BTFun visit)
{
	if (node == NULL)
	{
		return;//end
	}

	if (level == 0)//root
	{
		visit(tree, node);
	}
	else if (level > 0)
	{
		BTLevelOrderTraversal(tree, node->lchild, level -1, visit);
		BTLevelOrderTraversal(tree, node->rchild, level -1, visit);
	}
}

void BTLevelOrder(BTTree tree, BTFun visit)
{
	int treeHeight = BTHeight(tree);
	int i;
	for (i = 0; i <= treeHeight; i++)
		BTLevelOrderTraversal(tree, tree->nodes[0], i, visit);
	
}

void BTDestroy(BTTree tree) 
{
	BTPostOrder(tree, BTRemove);
	free(tree);
}
