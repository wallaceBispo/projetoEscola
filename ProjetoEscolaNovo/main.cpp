#include <iostream>
#include "Funcoes.h"
using namespace std;


int main()
{
    setlocale(LC_ALL,"portuguese");
    SetConsoleTitle(" Gerenciamento escolar");
    system("color 9f"); /* Muda a cor do fundo */

    int verificador=2;
    MenuInicial(verificador);


    return 0;

}


//Criar o menu do case 4 do menu principal (Menu de funcionarios, onde ele só pode alterar dados especificos, como nome,sexo telefone e locall)
//Fazer tratamento de erro para os menus e funções !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//PADRONIZAR TODOS  OS MENUS IMPRESSOS NA TELA DO USUARIO ex: Frase para voltar ao menu anterior, etc etc etc
//Caso queiram fazer tratamento de erro para verificar se o id ou matricula informados já existem, usem as funções verificaArquivoprof,aluno etc



