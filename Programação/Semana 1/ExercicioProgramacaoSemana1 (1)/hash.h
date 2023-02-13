#include "cliente.h"


class Hash{
public:
  Hash(int max_items = 15);
  ~Hash();
  bool isFull() const;
  int getLenght() const;

  void retriveItem(Cliente& cliente, bool& found);
  void insertItem(Cliente cliente);
  void deleteItem(Cliente cliente);
  void print();

private:
  int getHash(Cliente cliente);
  int max_items;
  int lenght;
  Cliente* structure;
};