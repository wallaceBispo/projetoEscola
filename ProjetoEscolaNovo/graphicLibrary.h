#include <iostream>
#include <conio2.h>
#include <windows.h>

using namespace std;

void insertFuncionario();
void createFile();
void updateData();
void exitAplication();
void exitAplication();

namespace namespaceGraphic
{

void insertFuncionario()
{
    int i;
    int vet[26];
    gotoxy(15, 23);
    cout <<"Inserindo funcionario " ;
    for (i = 0; i < 26; i++)
    {
        printf(".", *(vet + i));
        Sleep(100);
    }
    cout << endl;
}
void createFile()
{
    int i;
    int vet[26];
    gotoxy(15, 12);
    cout <<"Criando arquivo ";
    for ( i = 0; i < 26; i++)
    {
        printf(".", *(vet + i));
        Sleep(100);
    }
    cout << endl;
}
void updateData()
{
    int i;
    int vet[26];
    cout << endl
         << "Atualizando dados ";
    for (i = 0; i < 26; i++)
    {
        printf(".", *(vet + i));
        Sleep(100);
    }
    cout << endl;
}
void removeFuncionario()
{
    int i;
    int vet[26];
    cout << endl
         << "Removendo Funcionario ";
    for (i = 0; i < 26; i++)
    {
        printf(".", *(vet + i));
        Sleep(100);
    }
    cout << endl;
}
void exitAplication()
{
    int i;
    int vet[26];
    system("cls");
    cout << endl
         << "Saindo da aplicacao ";
    for (i = 0; i < 26; i++)
    {
        printf(".", *(vet + i));
        Sleep(100);
    }
    cout << endl;
}
void verificarSenha()
{
    int i;
    int vet[32];
    gotoxy(15, 11);
    cout << "verificando " ;
    for (i = 0; i < 32; i++)
    {
        printf(".", *(vet + i));
        Sleep(100);
    }
}
} // namespace namespaceGraphic
