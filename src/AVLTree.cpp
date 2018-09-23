#include "AVLTree.h"

AVLTree::AVLTree(int i_ammount, AVLNode::NameAndID * i_aNameAndID){
  AVLNode * insertedNode;
  this->m_rootNode = nullptr;
  this->m_size = 0 ;
  try{
  this->m_rootNode = new AVLNode(i_aNameAndID[0]);

  for(int i = 1; i < i_ammount; i++){
    insertedNode = this->m_rootNode->AVL_Insert(i_aNameAndID[i]);
    this->m_rootNode = insertedNode->AVL_GetRoot();
  }
  this->m_size = i_ammount;
  }
  catch(std::exception & e){
    //std::cerr << "Exception Ocurred: " <<e.what() << std::endl;
    throw std::out_of_range("Out of Bounds Access of an array \n");
  }
}
AVLTree::AVLTree(){
  this->m_rootNode = nullptr;
  this->m_size = 0;
}
AVLTree::AVLTree(AVLNode::NameAndID i_NameAndID){
  this->m_rootNode = new AVLNode(i_NameAndID);
  this->m_size = 1;
}

void AVLTree::AVLTreeInsert(AVLNode::NameAndID i_NameAndID){
  AVLNode * insertedNode;
  if(this->m_rootNode != nullptr){
    this->m_size++;
    insertedNode = this->m_rootNode->AVL_Insert(i_NameAndID);
    this->m_rootNode = insertedNode->AVL_GetRoot();
  }
  else{
    this->m_rootNode = new AVLNode(i_NameAndID);
    this->m_size =1;
  }
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
  if(this->m_rootNode != nullptr)
    return this->m_rootNode->m_Hight;
  else
    throw std::out_of_range("RootNode does not exist \n");
}
uint64_t AVLTree::AVLTreeGetHighest(void){
  return this->m_rootNode->getMax();
}
uint64_t AVLTree::AVLTreeGetLowest(void){
  return this->m_rootNode->getMin();
}
