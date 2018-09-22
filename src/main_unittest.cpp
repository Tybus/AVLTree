#include "AVLTree.h"
#include <iostream>
using namespace std;
int main(void){
  //Create an AVL Tree with 5 numbers.
  int i_ammount = 5;
  AVLNode::NameAndID i_aNameAndID[5];

  i_aNameAndID[0].Cedula = 116220762;
  i_aNameAndID[0].Name = "David Martinez Garcia";

  i_aNameAndID[0].Cedula = 222838909;
  i_aNameAndID[0].Name = "Pedro Perez Aguilar";

  i_aNameAndID[0].Cedula = 3958302005;
  i_aNameAndID[0].Name = "Rodrigo Rodriguez Rojas";

  i_aNameAndID[0].Cedula = 4958292005;
  i_aNameAndID[0].Name = "Armando Casas Rojas";

  i_aNameAndID[0].Cedula = 5728395490;
  i_aNameAndID[0].Name = "Ash Ketchum";

  AVLTree CeroAVLTree(i_ammount,i_aNameAndID);

  return 0;
}
