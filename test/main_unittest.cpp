#include "AVLTree.h"
#include <iostream>
using namespace std;
int main(void){
  //Create an AVL Tree with 5 numbers.
  int i_ammount = 5;
  AVLNode::NameAndID i_aNameAndID[5];

  i_aNameAndID[0].Cedula = 116220762;
  i_aNameAndID[0].Name = "David Martinez Garcia";

  i_aNameAndID[4].Cedula = 222838909;
  i_aNameAndID[4].Name = "Pedro Perez Aguilar";

  i_aNameAndID[3].Cedula = 3958302005;
  i_aNameAndID[3].Name = "Rodrigo Rodriguez Rojas";

  i_aNameAndID[2].Cedula = 4958292005;
  i_aNameAndID[2].Name = "Armando Casas Rojas";

  i_aNameAndID[1].Cedula = 5728395490;
  i_aNameAndID[1].Name = "Ash Ketchum";

  AVLTree AVLTree5(i_ammount,i_aNameAndID);

  //Get The max Height of the AVLTree
  cout << "The max Height is: ";
  cout << AVLTree5.AVLTreeGetMaxHeight() << "\n";

  //Try to get the max hight of a Tree without root.
  AVLTree noRootAVLTree = AVLTree();

  try{
    noRootAVLTree.AVLTreeGetMaxHeight();
  }
  catch( const std::out_of_range &e){
    std::cerr << e.what();
  }
  //Out of bounds. i_ammount > i_aNameAndID Range
  i_ammount  = 7;
  try{
    AVLTree oobTree(i_ammount, i_aNameAndID);
  }
  catch(const std::out_of_range &e){
    std::cerr<< e.what();
  }
  return 0;
}
