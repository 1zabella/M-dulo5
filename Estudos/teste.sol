// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Teste{
   // variáveis
   address private _admin; //administrador
   uint public saldo;
   string internal _nome;

   // constructor
   constructor(uint _saldo2, string memory _name){
    _admin = msg.sender; //o adminstrador, a partir do msg.sender,
    //passa a ser a pessoa que fez deploy do contrato
    saldo = _saldo2;
    _nome = _name;
   }

   // funcoes
   function alterar_saldo(uint _saldoNovo) public returns(uint){

    require(msg.sender == _admin , "Voce nao e um amdinistrador");

    saldo = _saldoNovo;

    return saldo;
   }
}

//msg.value -> valor enviado em transações;
// msg.sander -> endereço de quem está enviando a transação (ex: chamar a função)
// entender o contrato como se fosse uma classe