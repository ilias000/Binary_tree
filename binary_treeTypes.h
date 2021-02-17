#ifndef __binary_tree_types__
#define __binary_tree_types__

typedef int BTItem;

#define BT_ITEM_NIL 0;//The functions that print error must return somethink if do not want to have a warning

#ifdef BT_IMPL_POINTER
    // use pointers
    typedef struct BTNodePointer *BTNode;
    typedef struct BTTreePointer *BTTree;
#else
    // use arrays
    typedef struct BTNodeArray *BTNode;
    typedef struct BTTreeArray *BTTree;
#endif

typedef void(*BTFun)(BTTree tree, BTNode node);

#endif