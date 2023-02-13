#include "hash.h" 
#include <iostream>
using namespace std;

Hash::Hash(int max) {  
  lenght = 0;
  max_items = max;
  structure = new Cliente[max_items];
}

Hash::~Hash(){
  delete [] structure;
}

bool Hash::isFull() const {
  return (lenght == max_items);
}

int Hash::getLenght() const {
  return lenght;
}

void Hash::retriveItem(Cliente& cliente, bool& found) {
  int startLoc = getHash(cliente);
  bool moreToSearch = true; 
  int location = startLoc;
  do {
    if (structure[location].getImei() == cliente.getImei() ||
	structure[location].getImei() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);
  
  found = (structure[location].getImei() == cliente.getImei() );   
  if (found) { 
    cliente = structure[location];
  }
}

void Hash::insertItem(Cliente cliente) {
  int location;
  location = getHash(cliente);
  while (structure[location].getImei() > 0)
    location = (location + 1) % max_items;
  structure[location] = cliente;
  lenght++;
}

void Hash::deleteItem(Cliente cliente) {
  int startLoc = getHash(cliente);
  bool moreToSearch = true; 
  int location = startLoc;
  do {
    if (structure[location].getImei() == cliente.getImei() ||
	structure[location].getImei() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);

  if (structure[location].getImei() == cliente.getImei()) {       
    structure[location] = Cliente(-2,"");
    lenght--;
  }
}

void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<< structure[i].getImei()<<", "<<structure[i].getLogin()<<endl;
  }
}

int Hash::getHash(Cliente cliente){
  return cliente.getImei() % max_items;
}