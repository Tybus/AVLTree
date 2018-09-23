#include "AVLTree.h"
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;

int main(void){
  ifstream lista[5];
  ofstream maxAndMinID, runningTimes;
  AVLNode::NameAndID NameAndID[5][10000];
  string line, segment;
  stringstream lineStream;
  uint64_t maxCedula;
  uint64_t minCedula;
  clock_t t;

  lista[0].open("misc/input/lista_10.txt");
  lista[1].open("misc/input/lista_100.txt");
  lista[2].open("misc/input/lista_1000.txt");
  lista[3].open("misc/input/lista_5000.txt");
  lista[4].open("misc/input/lista_10000.txt");

  int j[5] = {0,0,0,0,0};
  for(int i = 0; i< 5; i++){
    try{
      if(lista[i].is_open()){
        while(getline(lista[i], line)){
          //std::cout << "1"<< std::endl;
          lineStream = stringstream(line);
          //std::cout << "2"<< std::endl;
          getline(lineStream, segment, ',');
          //std::cout << "3" << std::endl;
          NameAndID[i][j[i]].Name = segment;
          //std::cout << "4" << std::endl;
          //std::cout << NameAndID[i][j].Name << std::endl;
          getline(lineStream, segment, ',');
          //std::cout << "4" << std::endl;
          NameAndID[i][j[i]].Cedula = stoi(segment);
          //std::cout << "5" << std::endl;
          //std::cout << j<< std::endl;
          if(to_string(NameAndID[i][j[i]].Cedula).length() ==9 )
            j[i]++;
        }
      }
      lista[i].close();
    }
    catch(...){

    }
    cout << j[i]<<endl;
  }
    maxAndMinID.open("misc/output/max_and_min_id.txt");
    runningTimes.open("misc/output/running_times.txt");

    t = clock();
    AVLTree list10Tree(j[0],NameAndID[0]);
    maxCedula = list10Tree.AVLTreeGetHighest();
    minCedula = list10Tree.AVLTreeGetLowest();
    t = clock() - t;

    maxAndMinID <<"10 Nodes:\n";
    maxAndMinID <<"Max: " << maxCedula << "\n";
    maxAndMinID <<"Min: " << minCedula << "\n";
    runningTimes << "10 Nodes: \n";
    runningTimes << t << "ms"<< "\n";

    t =clock();
    AVLTree list100Tree(j[1],NameAndID[1]);
    maxCedula = list100Tree.AVLTreeGetHighest();
    minCedula = list100Tree.AVLTreeGetLowest();
    t= clock() -t;


    maxAndMinID <<"100 Nodes:\n";
    maxAndMinID <<"Max: " << maxCedula << "\n";
    maxAndMinID <<"Min: " << minCedula << "\n";
    runningTimes << "100 Nodes: \n";
    runningTimes << t << "ms"<< "\n";

    t = clock();
    AVLTree list1000Tree(j[2], NameAndID[2]);
    maxCedula = list1000Tree.AVLTreeGetHighest();
    minCedula = list1000Tree.AVLTreeGetLowest();
    t = clock() - t;

    maxAndMinID <<"1000 Nodes:\n";
    maxAndMinID <<"Max: " << maxCedula << "\n";
    maxAndMinID <<"Min: " << minCedula << "\n";
    runningTimes << "1000 Nodes: \n";
    runningTimes << t << "ms"<< "\n";

    t = clock();
    AVLTree list5000Tree(j[3], NameAndID[3]);
    maxCedula = list5000Tree.AVLTreeGetHighest();
    minCedula = list5000Tree.AVLTreeGetLowest();
    t = clock() - t;

    maxAndMinID <<"5000 Node:\n";
    maxAndMinID <<"Max: " << maxCedula << "\n";
    maxAndMinID <<"Min: " << minCedula << "\n";
    runningTimes << "5000 Nodes: \n";
    runningTimes << t << "ms"<< "\n";

    t = clock();
    AVLTree list10000Tree(j[4], NameAndID[4]);
    maxCedula = list10000Tree.AVLTreeGetHighest();
    minCedula = list10000Tree.AVLTreeGetLowest();
    t = clock() - t;

    maxAndMinID <<"10000 Nodes:\n";
    maxAndMinID <<"Max: " << maxCedula << "\n";
    maxAndMinID <<"Min: " << minCedula << "\n";
    runningTimes << "10000 Nodes: \n";
    runningTimes << t << "ms"<< "\n";    //}
  //}

  return 0;
}
