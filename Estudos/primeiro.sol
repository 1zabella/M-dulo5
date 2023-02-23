// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Contract1{
    //variáveis
   address private _owner;
    
    address[] public group; // carteiras de todos os integrantes do grupo em questão
    bytes10 public fee; // taxa única que deve ser paga no momemnto da contratação do seguro 
    bytes10 public minMembers; // quantidade mínima de membros para que seja possível iniciar o grupo 
    bytes10 public maxMembers; // quantidade máxima de membros que possibilitará o fechamento automático do grupo
    bytes10 public totalMembers; // quantidade total de membros do grupo (número a ser utilizado no front-end)
    uint public totalBalance; // saldo total do contrato em questão
    bool public refund; // solicitação de reembolso. Se for true, o reembolso foi solicitado
    bool public indemnity; //solicitação de indenização. se for true, a indenização foi solicitada
    
    function removeMember(address walletToRemove) public {
        require(_owner == msg.sender, "Only the owner can modify the group!");
        for (uint256 i = 0; i < group.length; i++){
            if (group[i] == walletToRemove){
                delete group[i];
                break;
            }
        }
    }
}
