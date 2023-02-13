#include <iostream>
#include "hash.h"
#
using namespace std;


// caso de teste 1: exclusão de um ítem da tabela hash de tamanho 13
void teste1(){
  Hash clienteHash(13);
  int imeis[13] = {
  815730721, 815730722, 815730723, 815730724, 815730725, 815730726, 815730727, 815730728, 815730729, 815730730, 815730731, 815730732, 815730733};
  
  string logins[13] = {"amelia@gmail.com", "caio@gmail.com", "pedro@gmail.com", "joana@gmail.com", "lucas@gmail.com", "ana@gmail.com", "silvia@gmail.com", "ester@gmail.com", "joao@gmail.com", "rute@gmail.com", "roberto@gmail.com", "marcos@gmail.com", "mateus@gmail.com"};

cout << "------------------------------" << endl;
for (int i = 0; i < 13; i++){
  Cliente cliente = Cliente(imeis[i], logins[i]);
clienteHash.insertItem(cliente);
};
clienteHash.print();
cout<< "-----------------------------"<< endl;

Cliente cliente(815730721, "");
bool found = false;
clienteHash.retriveItem(cliente, found);
if (found = false){
  cout << cliente.getLogin() << "-> não encontrado!" << endl;
  cout << "Não é possível remover esse ítem pois ele não está na tabela." << endl;
}
  else{
    cout << cliente.getLogin() << " -> encontrado!" << endl;
    cout << endl << "Esse cliente será excluído da tabela." << endl;
  }
cout << "----------------------------" << endl;
clienteHash.deleteItem(cliente);
clienteHash.print();
cout << endl <<"Exclusão concluída!" << endl << endl;
}



// caso de teste número 2: inserção de um elemento na tabela hash, de tamanho 13, sem colisão 
void teste2(){
  Hash clienteHash(13);
  int imeis[12] = {815730722, 815730723, 815730724, 815730725, 815730726, 815730727, 815730728, 815730729, 815730730, 815730731, 815730732, 815730733};
  
  string logins[12] = {"caio@gmail.com", "pedro@gmail.com", "joana@gmail.com", "lucas@gmail.com", "ana@gmail.com", "silvia@gmail.com", "ester@gmail.com", "joao@gmail.com", "rute@gmail.com", "roberto@gmail.com", "marcos@gmail.com", "mateus@gmail.com"};

cout << "*****************************" << endl;
for (int i = 0; i < 12; i++){
  Cliente cliente = Cliente(imeis[i], logins[i]);
clienteHash.insertItem(cliente);
};
clienteHash.print();
cout<< "-----------------------------"<< endl;

Cliente cliente(815730721, "amelia@gmail.com");
bool found = false;
clienteHash.retriveItem(cliente, found);

if (found = true){
  cout << cliente.getLogin() << " -> não encontrado!" << endl;
  cout << endl <<  "A inserção será realizada." << endl;
}
  else{
    cout << cliente.getLogin() << " -> encontrado!" << endl;
    cout << endl << "Esse cliente já foi inserido na tabela." << endl;
  }

cout << "----------------------------" << endl;

clienteHash.insertItem(cliente);
clienteHash.print();
cout << endl<<"Inserção concluída!" << endl << endl;
}



// caso de teste 3: inserção da tabela hash, de tamanho 13, com colisão tratada.
void teste3(){
  Hash clienteHash(15);
  int imeis[13] = {815739720, 815730722, 815730723, 815730724, 815730725, 815730726, 815730727, 815730728, 815730729, 815730730, 815730731, 815730732, 815730733};
  
  string logins[13] = {"caio@gmail.com", "pedro@gmail.com", "joana@gmail.com", "lucas@gmail.com", "ana@gmail.com", "silvia@gmail.com", "ester@gmail.com", "joao@gmail.com", "rute@gmail.com", "roberto@gmail.com", "marcos@gmail.com", "mateus@gmail.com", "marilucia@gmail.com"};

cout << "*****************************" << endl;
for (int i = 0; i < 13; i++){
  Cliente cliente = Cliente(imeis[i], logins[i]);
clienteHash.insertItem(cliente);
};
clienteHash.print();
cout<< "-----------------------------"<< endl;

cout << "Existe um cliente inserido nessa posição" << endl << "A inserção do novo cliente será feita no próximo espaço vazio." << endl;

Cliente cliente(815730735, "mariana@gmail.com");
bool found = false;
clienteHash.retriveItem(cliente, found);
cout << "----------------------------" << endl;

clienteHash.insertItem(cliente);
clienteHash.print();
cout << "Inserção com colisão tratada concluída!" << endl;
}



// caso de teste 4: sobrescrição de elementos da tabela hash durante a sua criação. 
// as colisões, nesse caso, não estão sendo tratadas porque estão sendo realizadas no ato de criação da tabela hash.
void teste4(){
  Hash clienteHash(5);
  int imeis[5] = {
  815730721, 815730722, 815730723, 81573072, 81573072};
  
  string logins[5] = {"amelia@gmail.com", "caio@gmail.com", "pedro@gmail.com", "joana@gmail.com", "lucas@gmail.com"};

cout << "------------------------------" << endl;
for (int i = 0; i < 5; i++){
  Cliente cliente = Cliente(imeis[i], logins[i]);
clienteHash.insertItem(cliente);
};
clienteHash.print();
cout<< "-----------------------------"<< endl;

Cliente cliente(815730721, "");
bool found = false;
clienteHash.retriveItem(cliente, found);
if (found = false){
  cout << cliente.getLogin() << "-> não encontrado!" << endl;
  cout << "Não é possível remover esse ítem pois ele não está na tabela." << endl;
}
  else{
    cout << cliente.getLogin() << " -> encontrado!" << endl;
    cout << endl << "Esse cliente será excluído da tabela." << endl;
  }
cout << "----------------------------" << endl;
clienteHash.deleteItem(cliente);
clienteHash.print();
cout << endl <<"Exclusão concluída!" << endl << endl;

}


//teste de atualização de um login na tabela Hash, utilizando o mesmo Imei.
void teste5(){ 
  Hash clientesHash(5); 
   int   imeis[5]   = {
    815730721, 815730722, 815730723, 81573072, 81573072};
  
  string login[5] = { 
    "amelia@gmail.com", "caio@gmail.com", "pedro@gmail.com", "joana@gmail.com", "lucas@gmail.com"};
  for (int i = 0; i < 5; i++) { 
    Cliente cliente = Cliente(imeis[i], login[i]); 
    clientesHash.insertItem(cliente); 
  } 
  clientesHash.print(); 
  cout << "--------------------------------" <<  endl;
  
  Cliente cliente(815730722,"");
  bool found = false; 
  clientesHash.retriveItem(cliente, found); 
  if (found == false){
  cout << cliente.getLogin() << "-> não encontrado!" << endl;
  cout << "Não é possível atualizar esse ítem pois ele não está na tabela." << endl;
}
  else{
    cout << cliente.getLogin() << " -> encontrado!" << endl;
    cout << endl << "Esse cliente será atualizado na tabela." << endl;
  } 
  cout << "--------------------------------" <<  endl;
  if (found) { 
    clientesHash.deleteItem(cliente); 
    Cliente novoCliente(815730932,"mauricio@gmail.com"); 
    clientesHash.insertItem(novoCliente); 
  
  bool newFound = false; 
  clientesHash.retriveItem(novoCliente, newFound); 
  if (newFound && novoCliente.getLogin() == "mauricio@gmail.com") { 
    cout << "A atualização foi realizada com sucesso!" << endl<< endl;
  } else {
    cout << "Não foi possível completar a atualização!" << endl;
  }
clientesHash.print();
cout << "Procedimento finalizado." << endl;
}
  }

int main(){
  //teste1();
  //teste2();
  //teste3();
  // teste4();
  teste5();
}
  
