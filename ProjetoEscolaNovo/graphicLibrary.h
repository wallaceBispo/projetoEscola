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
    cout << "Inserindo funcionario..." << endl;
    for (i = 0; i < 26; i++)
    {
        textcolor(YELLOW + 3);
        printf("%c", *(vet + i));
        Sleep(100);
    }
    textcolor(WHITE);
}
void createFile()
{
    int vet[26];
    cout << "Criando arquivo...\n";
    for (int i = 0; i < 26; i++)
    {
        textcolor(YELLOW + 3);
        printf("%c", *(vet + i));
        Sleep(100);
    }
    textcolor(WHITE);
}
void updateData()
{
    int vet[26];
    cout << "Atualizando dados...\n";
    for (int i = 0; i < 26; i++)
    {
        textcolor(YELLOW + 3);
        printf("%c", *(vet + i));
        Sleep(100);
    }
    textcolor(WHITE);
}
void removeFuncionario()
{
    int vet[26];
    cout << "Removendo Funcionario...\n";
    for (int i = 0; i < 26; i++)
    {
        textcolor(YELLOW + 3);
        printf("%c", *(vet + i));
        Sleep(100);
    }
    textcolor(WHITE);
}
void exitAplication()
{
    int vet[26];
    system("cls");
    cout << "Saindo da aplicacao...\n";
    for (int i = 0; i < 26; i++)
    {
        textcolor(YELLOW + 3);
        printf("%c", *(vet + i));
        Sleep(100);
    }
    textcolor(WHITE);
}
} // namespace namespaceGraphic
