#include "AVLNode.h"
AVLNode::AVLNode(void){
  //m_NameAndID = 0;find out what to assign
  m_pParent = nullptr;
  m_pRightChild = nullptr;
  m_pLeftChild = nullptr;
  m_Hight = 0;
}
AVLNode::AVLNode(NameAndID i_NameAndID, AVLNode * i_pParentNode){
  m_NameAndID = i_NameAndID;
  m_pParent = i_pParentNode;
  m_pRightChild = nullptr;
  m_pLeftChild = nullptr;
  m_Hight = 0;
  this->fixHightUpWards();
}
AVLNode::AVLNode(NameAndID i_NameAndID, AVLNode * i_pLeftChild,
                 AVLNode * i_pRightChild){
  m_NameAndID = i_NameAndID;
  m_pParent = nullptr;
  m_pRightChild = i_pRightChild;
  m_pLeftChild = i_pLeftChild;
  this->fixHightUpwards();
}
AVLNode::AVLNode(NameAndID i_NameAndID, AVLNode * i_pLeftChild,
                 AVLNode * i_pRightChild, AVLNode * i_pParentNode){
  m_NameAndID = i_NameAndID;
  m_pParent = i_pParentNode;
  m_pRightChild = i_pLeftChild;
  m_pLeftChild = i_pRightChild;
  this->fixHightUpwards();
}
AVLNode::AVLNode(NameAndID i_NameAndID){
  m_NameAndID = i_NameAndID;
  m_pParent = nullptr;
  m_pRightChild = nullptr;
  m_pLeftChild = nullptr;
  m_Hight = 0;
}
AVLNode::AVLNode(string i_sName, uint32_t i_Cedula){
  m_NameAndID->Name = i_sName;
  m_NameAndID->Cedula = Cedula;
  m_pParent = nullptr;
  m_pRightChild = nullptr;
  m_pLeftChild = nullptr;
  m_Hight = 0;
}
AVLNode * AVLNode::AVL_Insert(NameAndID i_NameAndID){
  AVLNode * insertedNode, unBalancedNode;
  Direction direction;

  insertedNode = this->BST_Insert(i_NameAndID);
  unbalancedNode = insertednode->SearchUnbalanced(&direction);
  if(unbalancedNode != nullptr)
    unbalancedNode->rotateNode(direction);
  return insertedNode;
}
AVLNode * AVLNode::AVL_Remove(NameAndId i_NameAndID){
  AVLNode * replaceNode;
  Direction direction;

  replaceNode = this->BST_Remove(i_NameAndID); //Watch Out!, deletednode might be a leaf!, nullptr
                                              //Leave the father as the previous node.
  if(replaceNode != nullptr){
    unbalancedNode = replaceNode->SearchUnbalanced(&direction);
    if(unBalancedNode != nullptr)
      unBalancedNode->rotateNode(direction);
  }
}
//fix this function later
AVLNode * AVLNode::BST_Remove(NameAndID i_NameAndID){//Could not encoutner the thing //Fix this in order to set the correct Highness.
  AVLNode * removedNode = this->AVL_Search(i_NameAndID); //Search should modify Hights.
  AVLNode * exParent = nullptr;
  AVLNode * replaceNode = nullptr;
  if(removedNode != nullptr)
    exParent = removedNode->m_pParent;
  if(exParent != nullptr){
    if(removedNode->m_pLeftChild ==  nullptr &&
       removedNode->m_pRightChild == nullptr){ // Node to be deleted is leaf
      if(exParent->m_pLeftChild == removedNode){
        exParent->m_pLeftChild = nullptr;
        exParent->fixHightUpWards();
        replaceNode = exParent;
      }
      else if (exParent->m_pRightChild == removedNode){
        exParent->m_pRightChild = nullptr;
        exParent->fixHightUpWards();
        replaceNode =exParent;
      }
      else
        printf("You should have not entered here");
    }
    else if(removedNode->m_pLeftChild == nullptr){ //Node deleted has only one child
      if(exParent->m_pLeftChild == removedNode){
        exParent->m_pLeftChild = removedNode->m_pRightChild;
        exParent->m_pLeftChild->m_pParent = exParent;
        exParent->fixHightUpwards();
        replaceNode = exParent->m_pLeftChild;
      }
      else if(exParent->m_pRightChild == removedNode){
        exParent->m_pRightChild = removedNode->m_pRightChild;
        exParent->m_pRightChild->m_pPartent = exParent;
        exParent->fixHightUpwards();
        replaceNode = exParent->m_pRightChild;
      }
      else
        printf("You should have not entered here");
    }
    else if(removedNode->m_pRightChild == nullptr){ //Node deleted has only one child
      if(exParent->m_pLeftChild == removedNode ){
        exParent->m_pLeftChild = removedNode->m_pLeftChild;
        exParent->m_pLeftChild->m_pParent = exParent;
        exParent->fixHightUpwards();
        replaceNode = exParent->m_pLeftChild;
      }
      else if(exParent->m_pRightChild == removedNode){
        exParent->m_pRightChild = removedNode->m_pLeftChild;
        exParent->m_pRightChild->m_pParent = exParent;
        exParent->fixHightUpwards();
        replaceNode =exParent->m_pLeftChild;
      }
      else
        printf("You Should Have not Entered Here");
    }
    else{ //Node has both right and left child
      if(exParent->m_pLeftChild == removedNode){
        exParent->m_pLeftChild = removedNode->m_pLeftChild.RemoveMax(); //Nodo Maximo de subarbold izquierdo
                                                                        //This should unset the sons parent
        exParent->m_pLeftChild->m_pParent = exParent;
        exParent->m_pLeftChild->fixHightUpWards(); //

        replaceNode = exParent->m_pLeftChild;
      }
      else if(exParent->m_pRightChild == removedNode){
        exParent->m_pRightChild = removedNOde->m_pLeftChild.RemoveMax();
        exParent->m_pRightChild->m_pParent = exParent;
        exParent->m_pRightChild->fixHightUpWards();
        replaceNode = exParent->m_pLeftChild;
      }
      else
        printf("You should have not entered here");
    }
  }
  delete(removedNode);
  return replaceNode;
}
AVLNode * AVLNode::RemoveMax(){
  AVLNode * currentNode = this->m_pRightChild;
  AVLNode * maxNode;
  while(currentNode->m_pRightChild != nullptr){
    maxNode = currentNode;
    currentNode->m_pRightChild;
  }
  return maxNode;
}
AVLNode * AVLNode::AVL_Search(NameAndID i_NameAndID){
  uint32_t i_Cedula = i_NameAndID.Cedula;
  AVLNode * returnValue = nullptr;
  AVLNode * leftChild = this->leftChild;
  AVLNode * rightChild = this->rightChild;

  if(this->m_NameAndID.Cedula == i_Cedula){
    returnValue = this;
  }
  else{
    if(i_Cedula < this->m_NameAndID.Cedula){
      if(leftChild != nullptr)
        returnValue = leftChild->AVL_Search(i_NameAndID);
      else
        returnValue = nullptr;
    }
    else if(i_Cedula > this->m_NameAndID.Cedula){
      if(rightChild != nullptr)
        returnValue = rightChild->AVL_Seach(i_NameAndID);
      else
        returnValue = nullptr;
    }
    else
      printf("You should have not entered Here");
  }
  return returnValue;
}
void AVLNode::fixHightUpWards(void){
  AVLNode * leftChild = this->m_pLeftChild;
  AVLNode * rightChild = this->m_pRightChild;
  AVLNode * parent = this->m_pParent;
  AVLNode * currentNode = this;

  if(leftChild == nullptr && rightChild == nullptr){
    currentNode->m_Hight = 0;
    if(parent != nullptr)
      parent->fixHightUpWards();
  }
  else if(leftChild == nullptr){
    currentNode->m_Hight = rigthChild->m_Hight + 1;
    if(parent != nullptr)
      parent->fixHightUpWards();
  }
  else if(rightChild == nullptr){
    currentNode->m_Hight = leftChild->m_Hight +1;
    if(parent != nullptr)
      parent->fixHightUpWards();
  }
  else{
    currentNode->m_Hight = rightChild->m_Hight > leftChildHight ?
                           rigthChild->m_Hight +1 : leftChild->m_Hight +1;
    if(parent != nullptr)
      parent->fixHightUpWards();
  }
}

AVLNode * AVLNode::BST_Insert(NameAndID i_NameAndID){
  AVLNode * insertedNode;

  if(this->m_NameAndID.Cedula <= NameAndID->m_NameAndID.Cedula){
    if(this->leftChild == nullptr){
      insertedNode = new AVLNode(i_NameAndID, this);
      this->leftChild = insertedNode;
      this->fixHightUpWards();
    }
    else{
      insertedNode = this->leftChild->BST_Insert(i_NameAndID);
    }
  }
  else{
    if(this->rightChild == nullptr){
      insertedNode = new AVLNode(i_NameAndID, this);
      this->rightChild = insertedNode;
      this->fixHightUpWards();
    }
    else{
      insertedNode = this->leftChild->BST_Insert(i_NameAndiD);
    }
  }
  return insertedNode;
}
bool AVLNode::CheckUnbalance(){
  uint64_t leftHight = this->m_pLeftChild->m_Hight;
  uint64_t rightHight = this->m_pRightChild->mHight;
  int64_t HightDiff = leftHight - RightHight;
  bool ubalance = true;
  if(HightDiff == 0 || HightDiff == 1 || HightDiff == -1)
    retVal =false;
  return retVal;
}
AVLNode * AVLNode::AVL_SearchUnbalanced(Direction * o_aDirection = nullptr){
  AVLNode * unbalancedNode;
  AVLNode * currentNode;
  AVLNode * lastNode;
  Route lastRoutes[2];
  Route auxRoute;
  uint64_t i = 0;
  bool unbalancedFound = false;

  if(this->m_Hight != 0){
    currentNode = this->m_pParent;
    lastNode = this;
  }
  while(!unbalancedFound){
    if(currentNode->m_Hight != 0){
      lastRoutes[0] = lastRoutes[1];
      unbalancedFound = currentNode->CheckUnbalance();
      if(currentNode->m_pLeftChild == lastNode){
        lastRoutes[1] = LEFT;
      }
      else if(currentNode->m_pRightChild == lastNode){
        lastRoutes[1] = RIGHT;
      }
      else
        printf("I should not be entering here");
      if(!unbalancedFound){
        lastNode = currentNode;
        currentNode = lastNode->m_pParent;
      }
    }
    else{
      currentNode = nullptr;
      unbalancedFound = true;
    }
  }
  if(o_aDirection != nullptr){
    if(lastRoutes[0] == LEFT && lastRoutes[1] == LEFT)
      *o_aDirection = LEFTLEFT;
    else if(lastRoutes[0] == LEFT && lastRoutes[1] == RIGHT)
      *o_aDirection = LEFTRIGHT;
    else if(lastRoutes[0] == RIGHT && lastRoutes[1] == LEFT)
      *o_aDirection = RIGHTLEFT;
    else if(lastRoutes[0] == RIGHT && lastRoutes[1] == RIGHT)
      *o_aDirection = RIGHTRIGHT;
  }
  return currentNode;
}
void AVLNode::RotateNode(Direction i_direction){
  switch(i_direction){
    case LEFTLEFT:
      this->RightRotate();
      break;
    case LEFTRIGHT:
      this->m_pLeftChild->LeftRotate();
      this->RightRotate();
      break;
    case RIGHTRIGHT:
      this->LeftRotate();
      break;
    case RIGHTLEFT:
      this->m_pRightChild->RightRotate();
      this->LeftRotate();
      break;
  }
}
//! Nomenclature based on https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
void AVLNode::RightRotate(void){
  AVLNode * z = this;
  AVLNode * y = z->m_pLeftChild;
  AVLNode * x = y->m_pLeftChild;
  AVLNode * T1 = x->m_pLeftChild;
  AVLNode * T2 = x->m_pRightChild;
  AVLNode * T3 = y->m_pRightChild;
  AVLNode * T4 = z->m_pRightChild;
  AVLNode * auxParent = z->m_pParent;


  //Changes to T1
  T1->m_pParent = x;
  //Changes to T2
  T2->m_pParent = x;

  //Changes to T3
  T3->m_pParent = z;

  //Changes to T4
  T4->m_pParent = z;

  //Changes to x
  x->pPartent = y;
  x->m_pLeftChild = T1;
  x->m_pRightChild = T2;
  x->m_Hight++; //Think about this.

  //Changes to z
  z->m_pParent = z;
  z->m_pLeftChild = T3;
  z->m_pRightChild = T4;
  z->m_Hight--; //Think about this

  //Changes to y
  y->m_pParent = auxParent;
  y->m_pLeftChild = x;
  y->m_pRightChild = z;
  y->m_Hight++; //Think About this.

  //changes to the exparent of z
  if(auxParent != nullptr){
    if(auxParent->m_pLeftChild == z)
      auxParent->m_pLeftChild = y;
    else if(auxParent->m_pRightChild == z)
      auxParent->m_pRightChild = y;
    else
      printf("You should have not enterd here");
  }
}

//! Nomenclature based on https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
void AVLNode::LeftRotate(void){
  AVLNode * z = this;
  AVLNode * y = z->m_pRightChild;
  AVLNode * x = y->m_pRightChild;

  AVLNode * T1 = z->m_pLeftChild;
  AVLNode * T2 = y->m_pLefttChild;
  AVLNode * T3 = x->m_pRLeftChild;
  AVLNode * T4 = x->m_pRightChild;
  AVLNode * auxParent = z->m_pParent;

  //Changes to T1
  T1->m_pParent = z;

  //Changes to T2
  T2->m_pParent = z;

  //Changes to T3
  T3->m_pParent = x;

  //Changes to T4
  T4->m_pParent = x;

  //Changes to z
  z->m_pParent = y;
  z->m_pLeftChild = T1;
  z->m_pRightChild = T2;
  z->m_Hight--; //think about this

  //Changes to x
  x->m_pParent = y;
  x->m_pLeftChild = T3;
  x->m_pRightChold = T4;
  z->m_Hight++; //think about this

  //Changes to y
  y->m_pParent = auxParent;
  y->m_pLeftChild = z;
  y->m_pRightChild = x;
  y->m_Hight++; //think about this

  //Changes to the Parent
  if(auxParent != nullptr){
    if(auxParent->m_pLeftChild == z)
      auxParent->m_pLeftChild = y;
    else if(auxParent->m_pRightChild == z)
      auxParent->m_pRightChild = y;
    else
      printf("You should have not enterd here");
  }
}
/* Not Sure if needed
AVLNode::AVLInsert(AVLNode * i_AVLtoInsert){

}
*/
