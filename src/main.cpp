#include <iostream>
#include "arena.hpp"

int main(){
  Arena<int> areninha(100);
  areninha.allocate();
  int* ptr=areninha.give();
  int* ptr2=areninha.give();
  *ptr2=10;
  *ptr=5;
  std::cout<<"alocado com sucesso e valor de ptr é: "<<*ptr<<" e "<<*ptr2<<std::endl;
  return 0;
}
