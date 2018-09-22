#include "AVLTree.h"

AVLTree::AVLTree(int i_ammount, AVLNode::NameAndID * i_aNameAndID){
  AVLNode * insertedNode;
  this->m_rootNode = nullptr;
  this->m_size = 0 ;

  this->m_rootNode = new AVLNode(i_aNameAndID[0]);

  for(int i = 1; i < i_ammount; i++){
    insertedNode = this->m_rootNode->AVL_Insert(i_aNameAndID[i]);
    this->m_rootNode = insertedNode->AVL_GetRoot();
  }
  this->m_size = i_ammount;
}

AVLTree::AVLTree(AVLNode::NameAndID i_NameAndID){
  this->m_rootNode = new AVLNode(i_NameAndID);
  this->m_size = 1;
}

void AVLTree::AVLTreeInsert(AVLNode::NameAndID i_NameAndID){
  AVLNode * insertedNode;

  this->m_size++;
  insertedNode = this->m_rootNode->AVL_Insert(i_NameAndID);
  this->m_rootNode = insertedNode->AVL_GetRoot();
}

void AVLTree::AVLTreeRemove(uint32_t i_u32Cedula){
  AVLNode::NameAndID tempNameAndID;
  tempNameAndID.Cedula = i_u32Cedula;
  AVLTreeRemove(tempNameAndID);
}

void AVLTree::AVLTreeRemove(AVLNode::NameAndID i_NameAndID){
  AVLNode * replacedNode;

  replacedNode = this->m_rootNode->BST_Remove(i_NameAndID);
  if(replacedNode != nullptr){
    this->m_rootNode = replacedNode->AVL_GetRoot();
    this->m_size --;
  }
}
uint64_t AVLTree::AVLTreeGetSize(void){
  return this->m_size;
}
uint64_t AVLTree::AVLTreeGetMaxHeight(void){
  return m_rootNode->m_Hight;
}
