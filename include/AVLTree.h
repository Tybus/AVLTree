#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"
#include <string>
class AVLTree{
public:
	//! Creates a AVLTree based on arrays of strings and cedulas
	AVLTree(int i_ammount, AVLNode::NameAndID * i_aNameAndID);
	//! Creates an AVLTree based on a String and a Cedula
	AVLTree(AVLNode::NameAndID i_NameAndID);
	//! Inserts a new entry to the AVL Tree
	void AVLTreeInsert(AVLNode::NameAndID i_NameAndID);
	//! Removes a entry from the AVL Tree using a Cedula
	void AVLTreeRemove(uint32_t i_u32Cedula);
	//! Removes an entry using a NameAndID data structure.
	void AVLTreeRemove(AVLNode::NameAndID i_NameAndID);
	//! Returns the Size of the AVL Tree
	uint64_t AVLTreeGetSize(void);
	//! Returns the Maxheight of the AVL Tree.
	uint64_t AVLTreeGetMaxHeight(void);

private:
	AVLNode * m_rootNode;
	uint64_t m_size;

};
#endif //AVLNODE_H
