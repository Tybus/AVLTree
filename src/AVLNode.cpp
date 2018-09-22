#include "../include/AVLNode.h"
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
  this->fixHightUpwards();
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
  m_NameAndID.Name = i_sName;
  m_NameAndID.Cedula = i_Cedula;
  m_pParent = nullptr;
  m_pRightChild = nullptr;
  m_pLeftChild = nullptr;
  m_Hight = 0;
}
AVLNode * AVLNode::AVL_Insert(NameAndID i_NameAndID){
  AVLNode * insertedNode;
  AVLNode * unbalancedNode;
  Direction direction;

  insertedNode = this->BST_Insert(i_NameAndID);
  unbalancedNode = insertedNode->AVL_SearchUnbalanced(&direction);
  if(unbalancedNode != nullptr)
    unbalancedNode->RotateNode(direction);
  return insertedNode;
}

AVLNode * AVLNode::AVL_Remove(NameAndID i_NameAndID){
  AVLNode * replaceNode;
  AVLNode * unbalancedNode;
  Direction direction;

  replaceNode = this->BST_Remove(i_NameAndID); //Watch Out!, deletednode might be a leaf!, nullptr
                                              //Leave the father as the previous node.
  if(replaceNode != nullptr){
    unbalancedNode = replaceNode->AVL_SearchUnbalanced(&direction);
    if(unbalancedNode != nullptr)
      unbalancedNode->RotateNode(direction);
  }
  return replaceNode;
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
        exParent->fixHightUpwards();
        replaceNode = exParent;
      }
      else if (exParent->m_pRightChild == removedNode){
        exParent->m_pRightChild = nullptr;
        exParent->fixHightUpwards();
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
        exParent->m_pRightChild->m_pParent = exParent;
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
        exParent->m_pLeftChild = removedNode->m_pLeftChild->RemoveMax(); //Nodo Maximo de subarbold izquierdo
                                                                        //This should unset the sons parent
        exParent->m_pLeftChild->m_pParent = exParent;
        exParent->m_pLeftChild->fixHightUpwards(); //

        replaceNode = exParent->m_pLeftChild;
      }
      else if(exParent->m_pRightChild == removedNode){
        exParent->m_pRightChild = removedNode->m_pLeftChild->RemoveMax();
        exParent->m_pRightChild->m_pParent = exParent;
        exParent->m_pRightChild->fixHightUpwards();
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
    currentNode = currentNode->m_pRightChild;
  }
  return maxNode;
}
AVLNode * AVLNode::AVL_Search(NameAndID i_NameAndID){
  uint32_t i_Cedula = i_NameAndID.Cedula;
  AVLNode * returnValue = nullptr;
  AVLNode * leftChild = this->m_pLeftChild;
  AVLNode * rightChild = this->m_pRightChild;

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
        returnValue = rightChild->AVL_Search(i_NameAndID);
      else
        returnValue = nullptr;
    }
    else
      printf("You should have not entered Here");
  }
  return returnValue;
}
void AVLNode::fixHightUpwards(void){
  AVLNode * leftChild = this->m_pLeftChild;
  AVLNode * rightChild = this->m_pRightChild;
  AVLNode * parent = this->m_pParent;
  AVLNode * currentNode = this;

  if(leftChild == nullptr && rightChild == nullptr){
    currentNode->m_Hight = 0;
    if(parent != nullptr)
      parent->fixHightUpwards();
  }
  else if(leftChild == nullptr){
    currentNode->m_Hight = rightChild->m_Hight + 1;
    if(parent != nullptr)
      parent->fixHightUpwards();
  }
  else if(rightChild == nullptr){
    currentNode->m_Hight = leftChild->m_Hight +1;
    if(parent != nullptr) //Think About this.nullptr)
      parent->fixHightUpwards();
  }
  else{
    currentNode->m_Hight = rightChild->m_Hight > leftChild->m_Hight ?
                           rightChild->m_Hight +1 : leftChild->m_Hight +1;
    if(parent != nullptr)
      parent->fixHightUpwards();
  }
}

AVLNode * AVLNode::BST_Insert(NameAndID i_NameAndID){
  AVLNode * insertedNode;

  if(this->m_NameAndID.Cedula >= i_NameAndID.Cedula){
    if(this->m_pLeftChild == nullptr){
      insertedNode = new AVLNode(i_NameAndID, this);
      this->m_pLeftChild = insertedNode;
      this->fixHightUpwards();
    }
    else{
      insertedNode = this->m_pLeftChild->BST_Insert(i_NameAndID);
    }
  }
  else{
    if(this->m_pRightChild == nullptr){
      insertedNode = new AVLNode(i_NameAndID, this);
      this->m_pRightChild = insertedNode;
      this->fixHightUpwards();
    }
    else{
      insertedNode = this->m_pRightChild->BST_Insert(i_NameAndID);
    }
  }
  return insertedNode;
}
bool AVLNode::CheckUnbalance(){
  int64_t leftHight;
  int64_t rightHight;
  int64_t HightDiff;
  leftHight = this->m_pLeftChild == nullptr ? -1 : this->m_pLeftChild->m_Hight;
  rightHight = this->m_pRightChild == nullptr ? -1 : this->m_pRightChild->m_Hight;
  HightDiff = leftHight - rightHight;
  bool unbalance = true;

  if(HightDiff == 0 || HightDiff == 1 || HightDiff == -1)
    unbalance = false;
  return unbalance;
}
AVLNode * AVLNode::AVL_SearchUnbalanced(Direction * o_aDirection){
  //AVLNode * unbalancedNode;
  AVLNode * currentNode;
  AVLNode * lastNode;
  Route lastRoutes[2];
  bool unbalancedFound = false;

  currentNode = this->m_pParent;
  lastNode = this;

  while(!unbalancedFound){
    if(currentNode != nullptr){
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
      unbalancedFound = true;
    }
  }
  if(o_aDirection != nullptr){
    if(lastRoutes[0] == LEFT && lastRoutes[1] == LEFT)
      *o_aDirection = LEFTLEFT;
    else if(lastRoutes[0] == LEFT && lastRoutes[1] == RIGHT)
      *o_aDirection = RIGHTLEFT;
    else if(lastRoutes[0] == RIGHT && lastRoutes[1] == LEFT)
      *o_aDirection = LEFTRIGHT;
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
  AVLNode * y = nullptr;
  AVLNode * x = nullptr;
  AVLNode * T1 = nullptr;
  AVLNode * T2 = nullptr;
  AVLNode * T3 = nullptr;
  AVLNode * T4 = nullptr;


  if(z!=nullptr)
    y = z->m_pLeftChild;
  if(y!= nullptr)
    x = y->m_pLeftChild;
  if(x != nullptr)
    T1 = x->m_pLeftChild;
  if(x != nullptr)
    T2 = x->m_pRightChild;
  if(y != nullptr)
    T3 = y->m_pRightChild;
  if(z != nullptr)
    T4 = z->m_pRightChild;

  AVLNode * auxParent = z->m_pParent;
  //Changes to T1
  if(T1 != nullptr)
  T1->m_pParent = x;
  //Changes to T2
  if(T2 != nullptr)
  T2->m_pParent = x;

  //Changes to T3
  if(T3 != nullptr)
  T3->m_pParent = z;

  //Changes to T4
  if(T4 != nullptr)
  T4->m_pParent = z;

  //Changes to x
  if(x != nullptr){
    x->m_pParent = y;
    x->m_pLeftChild = T1;
    x->m_pRightChild = T2;
  }
  //Changes to z
  if(z != nullptr){
  z->m_pParent = y;
  z->m_pLeftChild = T3;
  z->m_pRightChild = T4;
  }
  //Changes to y
  if(y != nullptr){
    y->m_pParent = auxParent;
    y->m_pLeftChild = x;
    y->m_pRightChild = z;
  }
  //changes to the exparent of z
  if(auxParent != nullptr){
    if(auxParent->m_pLeftChild == z)
      auxParent->m_pLeftChild = y;
    else if(auxParent->m_pRightChild == z)
      auxParent->m_pRightChild = y;
    else
      printf("You should have not enterd here");
  }
  if(x != nullptr)
  x->fixHightUpwards();
  if(y != nullptr)
  y->fixHightUpwards();
  if(z != nullptr)
  z->fixHightUpwards();
}

//! Nomenclature based on https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
void AVLNode::LeftRotate(void){
  AVLNode * z = this;
  AVLNode * y = nullptr;
  AVLNode * x = nullptr;

  AVLNode * T1 = nullptr;
  AVLNode * T2 = nullptr;
  AVLNode * T3 = nullptr;
  AVLNode * T4 = nullptr;


  if(z != nullptr)
    y = z->m_pRightChild;
  if(y != nullptr)
    x = y->m_pRightChild;
  if(z != nullptr)
    T1 = z->m_pLeftChild;
  if(y != nullptr)
    T2 = y->m_pLeftChild;
  if(x != nullptr)
    T3 = x->m_pLeftChild;
  if(z != nullptr)
    T4 = x->m_pRightChild;

  AVLNode * auxParent = z->m_pParent;
  //Changes to T1
  if(T1 != nullptr)
    T1->m_pParent = z;

  //Changes to T2
  if(T2 != nullptr)
    T2->m_pParent = z;

  //Changes to T3
  if(T3 != nullptr)
    T3->m_pParent = x;

  //Changes to T4
  if(T4 != nullptr)
    T4->m_pParent = x;

  //Changes to z
  if(z !=nullptr){
    z->m_pParent = y;
    z->m_pLeftChild = T1;
    z->m_pRightChild = T2;
  }
  //Changes to x
  if(x != nullptr){
  x->m_pParent = y;
  x->m_pLeftChild = T3;
  x->m_pRightChild = T4;
  }
  //Changes to y
  if(y != nullptr){
  y->m_pParent = auxParent;
  y->m_pLeftChild = z;
  y->m_pRightChild = x;
  }
  //Changes to the Parent
  if(auxParent != nullptr){
    if(auxParent->m_pLeftChild == z)
      auxParent->m_pLeftChild = y;
    else if(auxParent->m_pRightChild == z)
      auxParent->m_pRightChild = y;
    else
      printf("You should have not enterd here");
  }
  if(x != nullptr)
  x->fixHightUpwards();
  if(y != nullptr)
  y->fixHightUpwards();
  if(z!= nullptr)
  z->fixHightUpwards();
}
AVLNode * AVLNode::AVL_GetRoot(void){
  AVLNode * parentNode = this->m_pParent;
  if(parentNode == nullptr)
    return this;
  else
    return parentNode->AVL_GetRoot();
}
/* Not Sure if needed
AVLNode::AVLInsert(AVLNode * i_AVLtoInsert){

}
*/
