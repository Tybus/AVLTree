#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;
//! AVL Node for implementing AVL Trees.
class AVLNode{
	friend class AVLTree;
public:
	enum Route{
		LEFT,
		RIGHT
	};
	enum Direction{
		LEFTLEFT,
		LEFTRIGHT,
		RIGHTLEFT,
		RIGHTRIGHT
	};
	struct NameAndID{
		uint32_t Cedula;
		string Name;
	};
	//! Create a node assigning its parent.
	AVLNode(NameAndID i_NameAndID, AVLNode * i_pParentNode);
	//! Create a node assigning its childs.
	AVLNode(NameAndID i_NameAndID, AVLNode * i_pLeftChild,
		AVLNode * i_pRightChild);
	//! Create a node assigning its childs and Parent
	AVLNode(NameAndID i_NameAndID, AVLNode * i_pLeftChild,
		AVLNode * i_pRightChild, AVLNode * i_pParentNode);
	//! Create a node without assigning anything but the data.
	AVLNode(NameAndID i_NameAndID);
	//! Create a node using Name and ID
	AVLNode(string i_sName, uint32_t i_Cedula);

	AVLNode(void);
private:
	//! Contains the Payload (Name and ID ) of the Node.
	NameAndID m_NameAndID;
	//! Contains the parent of the node. nullptr stands for a root node
	AVLNode * m_pParent;
	//! Contains a pointer to the Right Child
	AVLNode * m_pRightChild;
	//! Contains a pointer to the Left Child
	AVLNode * m_pLeftChild;
	//! Contains the Hight of the Tree
	uint64_t  m_Hight;
	/* nOT sURE IF NEEDED
	//! Inserts data using AVL
	void AVL_Insert(AVLNode * i_AVLtoInsert);
	*/
	//! Inserts data using Data;
	AVLNode * AVL_Insert(NameAndID i_NameAndID);
	//!IInserts data using Name, ID;
	AVLNode * AVL_Insert(string i_sName, uint32_t i_Cedula);
	//! Inserts data using AVL
	AVLNode * BST_Insert(AVLNode * i_AVLtoInsert);
	//! Inserts data using Data;
	AVLNode * BST_Insert(NameAndID i_NameAndID);
	//! Inserts data using Name, ID;
	AVLNode * BST_Insert(string i_sName, uint32_t i_Cedula);
	//! Removes a entry using the NameAndID object.
	AVLNode * AVL_Remove(NameAndID i_NameAndID);
	//! Removes a entry using a Cedula.
	AVLNode * AVL_Remove(uint32_t i_Cedula);
	//! Removes an entry using BST with NameAndID
	AVLNode * BST_Remove(NameAndID i_NameAndID);
	//! Removes an entry using BST with a Cedula.
	AVLNode * BST_Remove(uint32_t i_Cedula);
	//! Searches the first unbalanced node based on this node.
	AVLNode * AVL_SearchUnbalanced(Direction * o_aDirection = nullptr);
	//! Searches the first unbalanced node from the specified node.
	AVLNode * AVL_SearchUnbalanced(AVLNode * i_StartingNode);
	//! Searches the Tree.
	AVLNode * AVL_Search(NameAndID i_NameAndID);
	//! Remove the Max Value of the node .
	AVLNode * AVLNode::RemoveMax(void);
	//! Fix the hight based on the child nodes.
	void fixHightUpWards(void);
	//! Checks wheter a node is unbalanced.
	bool CheckUnbalance();
	//! Search the first unbalanced node.
	AVLNode * AVLNode::AVL_SearchUnbalanced(Direction * o_aDirection = nullptr);
	//! Rotates the node in the specified direction.
	void RotateNode(Direction i_direction);
	//!Checks whether a node is unbalanced.
	bool CheckUnbalance(void);
	//! Rotates the node to the left
	void LeftRotate(void);
	//! Rotates the node to the right
	void RightRotate(void);
};
#endif //AVLNODE_H
