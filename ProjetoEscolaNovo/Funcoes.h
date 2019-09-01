#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <locale.h>
#include <conio2.h>
#include <iomanip>
#include <stdio.h>
#include "graphicLibrary.h"

using namespace std;
typedef double* pontmedia;
const char* ArquivoAlunos = "Alunos.txt";
const char* ArquivoProfessores = "Professores.txt";
char* arquivofun = "Funcionarios.txt";
int qtdaluno = 50;
int qtdprof = 20;
void InsereFaltas();
void MenuProfessor();
void MenuCoordenacao();
void DadosAlunos();
void DadosFun();
void DadosProf();
void IniciarArquivoAlunos();
void IniciarArquivoProf();
void CadastraAlunos();
void CadastraProf();
void ListarAlunoUnicoCord();
void RemoverAluno();
void AtualizarAluno();
void FuncaoAlunoMenu();
void AlterarNotasAluno();
void ListarAlunoUnico();
void MenuInicial(int verificadordelogin);


int VerificaArquivoAluno(int matricula);
int VerificaArquivoProf(int id);
int VerificaArquivoFun(int id);



struct StructAlunos
{
    int Matricula;
    char Nome[50];
    char NomeMae[50];
    char NomePai[50];
    char Sexo[15];
    char Telefone[15];
    char Endereco[50];
    float Nota1;
    float Nota2;
    float Nota3;
    float Nota4;
    int faltas;
};

struct StructProfessor
{
    int id;
    char nome[50];
    char sexo[25];
    char endereco[50];
    char telefone[15];
    double salario;
};


namespace FunSpace
{

struct StructFuns
{
    int id;
    char nome[50];
    char cargo[50];
    char sexo[15];
    char telefone[15];
    char local[50];
    double salario;
};

void CriarArquivoFun(char *arquivofun);
void CadastrarFun(char *arquivofun);
void ListarFuncionarios(char *arquivofun);
void AlterarDadosFun(char *arquivofun);
void RemoveFuncionario(char *arquivofun);
void FuncaoMenuFun(char *arquivofun);
void MenuFunMenu(char *arquivofun);
int  VerificaArquivoFun(int id);
const int MAXFUNCIONARIOS = 100;

void CriarArquivoFun(char *arquivofun)
{
    system("CLS");


    system("color 9f"); /* Muda a cor do fundo */
    textcolor(LIGHTBLUE);
    textbackground(WHITE);

    gotoxy(15, 5);
    cout <<"                                                                                            ";
    gotoxy(15, 6);
    cout <<"                            CRIAR ARQUIVO INICIAL DO FUNCIONARIO                            ";
    gotoxy(15, 7);
    cout <<"                                                                                            ";
    char opcao;
    textcolor(WHITE);
    textbackground(RED);
    gotoxy(30, 9);
    cout << "Isso ira apagar sua base de dados! Deseja continuar [s/n] ? ";
    cin >> opcao;
    textcolor(WHITE);
    textbackground(LIGHTBLUE);

    if ((opcao == 's') || (opcao == 'S'))
    {
        ofstream saida(arquivofun, ios::out | ios::trunc);
        if (saida.fail())
        {
            gotoxy(15, 12);
            cout << "Não foi possível acessar o arquivo!" << endl;
            exit(1);
        }

        StructFuns fichaVazia = {0, "", " ", " ", " ", " ", 0.0};

        for (int i = 0; i < MAXFUNCIONARIOS; i++)
        saida.write((const char *)(&fichaVazia), sizeof(StructFuns));
        namespaceGraphic::createFile();
        textcolor(WHITE);
        textbackground(GREEN);
        gotoxy(15,13);
        cout << "Arquivo criado com sucesso!" << endl;
        textcolor(WHITE);
        textbackground(LIGHTBLUE);
        gotoxy(15, 15);
        cout << "Enter para continuar";
        saida.close();
    }
    else
    {
        gotoxy(15, 15);
        cout << "Operacao cancelada!" << endl;
    }
    gotoxy(36,15);
    getch();
    system("cls");

    DadosFun();

}
void CadastrarFun(char *arquivofun)
{
    StructFuns fun;
    fstream saida;
    saida.open(arquivofun, ios::out | ios::in | ios::ate);
    if (saida.fail())
    {
        cout << "Não foi possível acessar o arquivo!" << endl;
        exit(1);
    }
    system("CLS");
    textcolor(LIGHTBLUE);
    textbackground(WHITE);
    gotoxy(15, 5);
    cout <<"                                                                                            ";
    gotoxy(15, 6);
    cout <<"                                   CADASTRO DE FUNCIONARIO                                  ";
    gotoxy(15, 7);
    cout <<"                                                                                            ";

    do
    {
    gotoxy(15, 9);
    textcolor(WHITE);
    textbackground(LIGHTBLUE);
    cout << "Entre com o ID do Funcionário: ";
    cin >> fun.id;
    }while(VerificaArquivoFun(fun.id)!=0);
    if ((fun.id > 0) && (fun.id <= MAXFUNCIONARIOS))
    {
        fstream saida;
        saida.open(arquivofun, ios::out | ios::in | ios::ate);
        gotoxy(15, 11);
        cout<<"Informe o nome do funcionário: ";
        fflush(stdin);
        cin.getline(fun.nome,50);
        gotoxy(15, 13);
        cout<<"Informe o cargo do funcionário na escola: ";
        fflush(stdin);
        cin.getline(fun.cargo,50);
        gotoxy(15, 15);
        cout<<"Informe o sexo do funcionário: ";
        fflush(stdin);
        cin.getline(fun.sexo,15);
        gotoxy(15, 17);
        cout<<"Informe o telefone para contato do funcionário: ";
        fflush(stdin);
        cin.getline(fun.telefone,15);
        gotoxy(15, 19);
        cout<<"Informe o endereço do funcionário: ";
        fflush(stdin);
        cin.getline(fun.local,50);
        gotoxy(15, 21);
        cout<<"Informe o salário que o funcionário irá receber: ";
        cin>>fun.salario;

        saida.seekp((fun.id - 1) * sizeof(StructFuns));
        saida.write((const char *)(&fun), sizeof(StructFuns));
        namespaceGraphic::insertFuncionario();

        gotoxy(15, 25);
         textcolor(WHITE);
        textbackground(GREEN);
        cout << "Funcionário inserido com sucesso!";
        textcolor(WHITE);
        textbackground(LIGHTBLUE);
        gotoxy(15, 27);
        cout <<"Enter para continuar";
        getch();
        system("cls");
    }
    else
    {
        gotoxy(15, 12);
        textcolor(WHITE);
        textbackground(RED);
        cout << "Não foi possível inserir o funcionário!";
        gotoxy(15, 14);
        textcolor(WHITE);
        textbackground(LIGHTBLUE);
        cout <<"Enter para continuar";
        getch();
        system("cls");
    }
    saida.close();
}

void AlterarDadosFun(char *arquivofun)
{
    StructFuns fun;
    fstream saida;
    saida.open(arquivofun, ios::out | ios::in | ios::ate);

    if (saida.fail())
    {
        cout << "Não foi possível acessar o arquivo!" << endl;
        exit(1);
    }
    system("CLS");
    FunSpace::ListarFuncionarios(arquivofun);
    cout << endl;
    cout << "Menu de alteração de dados do funcionário " << endl;
    cout << "                                                               ";
    cout << endl;

    int id;
    cout << "Digite o ID do funcionário a ser atualizado: ";
    cin >> id;

    saida.seekg((id - 1) * sizeof(StructFuns));
    saida.read((char *)(&fun), sizeof(StructFuns));
    saida.close();
    if ((fun.id > 0) && (strcmp(fun.nome, "") != 0) && (fun.id <= MAXFUNCIONARIOS))
    {
        fstream saida;
        saida.open(arquivofun, ios::out | ios::in | ios::ate);

        cout << "Entre com o nome a ser alterado"<<endl;
        fflush(stdin);
        cin.getline(fun.nome,50);
        cout <<"Entre com o cargo a ser alterado"<<endl;
        fflush(stdin);
        cin.getline(fun.cargo,50);
        cout <<"Entre com o sexo do funcionário a ser alterado"<<endl;
        fflush(stdin);
        cin.getline(fun.sexo,15);
        cout <<"Entre com o novo telefone do funcionário"<<endl;
        fflush(stdin);
        cin.getline(fun.telefone,15);
        cout <<"Entre com o novo endereço do funcionário"<<endl;
        fflush(stdin);
        cin.getline(fun.local,50);
        cout <<"Entre com o novo salário do funcionário"<<endl;
        cin >> fun.salario;

        saida.seekp((fun.id - 1) * sizeof(StructFuns));
        saida.write((const char *)(&fun), sizeof(StructFuns));
        cout << "\nDados atualizados com sucesso!" << endl;
        namespaceGraphic::updateData();
        cout <<"Pressione qualquer tecla para continuar"<<endl;
        getch();
        saida.close();
    }
    else
    {
        cout << "Funcionário não encontrado!" << endl;
        getch();
        saida.close();
    }

}

int VerificaArquivoFun(int id)
{
    StructFuns LerFun;
    ifstream entrada(arquivofun);
    while(entrada&&!entrada.eof())
    {
      entrada.read((char*)(&LerFun),sizeof(StructFuns));
        if(id==LerFun.id)
        {
            cout<<"O dado informado já existe no arquivo, informe outro para evitar conflito no arquivo."<<endl;
            return 1;
        }
    entrada.read((char*)(&LerFun),sizeof(StructFuns));
    }
    return 0;
}


void RemoveFuncionario(char *arquivofun)
{
    ifstream entrada(arquivofun);

    if (entrada.fail())
    {
        cout << "Não foi possível acessar o arquivo!" << endl;
        exit(1);
    }
    StructFuns fun;

    system("CLS");
    cout << endl;
    cout << "Remover Funcionário " << endl;

    int id;
    cout << "Digite o ID do Funcionário a ser removido:";
    cin >> id;

    entrada.seekg((id - 1) * sizeof(StructFuns));
    entrada.read((char *)(&fun), sizeof(StructFuns));
    entrada.close();
    if ((fun.id > 0) && (strcmp(fun.nome, "") != 0))
    {

        cout << setiosflags(ios::left)
             << setw(5) << "ID"
             << setw(15) << "Funcionário"
             << setw(15) << "Cargo"
             << setw(8) << "Sexo"
             << setw(15) << "Telefone"
             << setw(10) << "Local"
             << resetiosflags(ios::left)
             << setw(10) << "Salário" << endl;

        cout << setiosflags(ios::left)
             << setw(5) << fun.id
             << setw(15) << fun.nome
             << setw(15) << fun.cargo
             << setw(8) << fun.sexo
             << setw(15) << fun.telefone
             << setw(10) << fun.local
             << setw(10) << setprecision(2) << resetiosflags(ios::left)
             << setiosflags(ios::fixed | ios::showpoint) << fun.salario << '\n';

        char opcao;
        cout << "\nDeseja mesmo remover este funcionário [s/n] ? ";
        cin >> opcao;
        if ((opcao == 's') || (opcao == 'S'))
        {
            fstream saida(arquivofun, ios::out | ios::in | ios::ate);
            StructFuns fichaVazia = {0, " ", " ", " ", " ", " ", 0.0};
            if (saida.fail())
            {
                cout << "Não foi possável acessar o arquivo!" << endl;
                exit(1);
            }

            saida.seekp((fun.id - 1) * sizeof(StructFuns));
            saida.write((const char *)(&fichaVazia), sizeof(StructFuns));
            saida.close();
            namespaceGraphic::removeFuncionario();
            cout << "\nFuncionário Removido com sucesso!" << endl;
            getch();
        }
        else
        {
            cout << "\nOperação Cancelada!" << endl;
        }
    }
    else
    {
        cout << "\nFuncionário não encontrado!" << endl;
        getch();
    }
}
void ListarFuncionarios(char *arquivofun)
{
    StructFuns fun;
    ifstream entrada(arquivofun);

    if (entrada.fail())
    {
        cout << "Não foi possível acessar o arquivo!" << endl;
        exit(1);
    }
    system("CLS");

    textcolor(LIGHTBLUE);
    textbackground(WHITE);
    gotoxy(15, 5);
    cout <<"                                                                                            ";
    gotoxy(15, 6);
    cout <<"                                    LISTA DE FUNCIONARIOS                                   ";
    gotoxy(15, 7);
    cout <<"                                                                                            ";
    textcolor(WHITE);
    textbackground(WHITE+29);
    gotoxy(15, 8);
    cout << setiosflags(ios::left)
         << setw(5) << "ID"
         << setw(15) << "Funcionário"
         << setw(15) << "Cargo"
         << setw(8) << "Sexo"
         << setw(15) << "Telefone"
         << setw(10) << "Local"
         << resetiosflags(ios::left)
         << setw(10) << "Salário" << endl;

    for (int counter = 0; counter <= MAXFUNCIONARIOS; counter++)
    {
        entrada.seekg((counter) * sizeof(StructFuns));
        entrada.read((char *)(&fun), sizeof(StructFuns));

        if ((fun.id > 0) && (strcmp(fun.nome, "") != 0))
        {
            gotoxy(15, 9);
            textcolor(WHITE);
            textbackground(WHITE+ 18);
            cout << setiosflags(ios::left)
                 << setw(5) << fun.id
                 << setw(15) << fun.nome
                 << setw(15) << fun.cargo
                 << setw(8) << fun.sexo
                 << setw(15) << fun.telefone
                 << setw(10) << fun.local
                 << setw(10) << setprecision(2) << resetiosflags(ios::left)
                 << setiosflags(ios::fixed | ios::showpoint) << fun.salario << '\n';
        }
    }

    gotoxy(15, 14);
    textcolor(WHITE);
    textbackground(LIGHTBLUE);
    cout <<"Enter para continuar";
    getch();
    system("cls");
    entrada.close();

}
}
void MenuInicial(int verificadordelogin)
{
    int Menu, i, inteiro;
    char senha[10] = "";
    char senhaa[12] = "";
    char senhapadrao[12] = "senhapadrao";
    char senhapadraop[10] = "professor";
    if (verificadordelogin<0)
    {
        cout << "Tentativa de logins excedidas, por favor inicie o programa novamente."<<endl;
        exit(1);
    }
    do
    {
        system("color 9f"); /* Muda a cor do fundo */
        textcolor(LIGHTBLUE);
        textbackground(WHITE);

        gotoxy(15, 5);
        cout <<"                                                                                            ";
        gotoxy(15, 6);
        cout <<"                                 BEM VINDO AO MENU PRINCIPAL                                ";
        gotoxy(15, 7);
        cout <<"                                                                                            ";

        cout <<endl;
        gotoxy(15, 11);
        cout << "                            ";
        gotoxy(15, 12);
        cout << "  1- Menu da Coordenação  ";
        gotoxy(15, 13);
        cout << "                            ";

        gotoxy(15, 15);
        cout << "                            ";
        gotoxy(15, 16);
        cout << "    2- Menu do Professor    ";
        gotoxy(15, 17);
        cout << "                            ";

        gotoxy(15, 19);
        cout << "                            ";
        gotoxy(15, 20);
        cout << "      3- Menu do Aluno      ";
        gotoxy(15, 21);
        cout << "                            ";

        gotoxy(79, 11);
        cout << "                            ";
        gotoxy(79, 12);
        cout << "   4- Menu do Funcionario   ";
        gotoxy(79, 13);
        cout << "                            ";

        gotoxy(79, 15);
        cout << "                            ";
        gotoxy(79, 16);
        cout << " 5- Info. sobre o programa  ";
        gotoxy(79, 17);
        cout << "                            ";

        gotoxy(79, 19);
        cout << "                            ";
        gotoxy(79, 20);
        cout << "   6- Encerrar o programa   ";
        gotoxy(79, 21);
        cout << "                            ";

        textcolor(WHITE);
        textbackground(LIGHTBLUE);
        gotoxy(53,25);
        cout << "Digite a opcao: ";
        cin>>Menu;

        switch(Menu)
        {
        case 1:
            system("CLS");
            system("color 9f"); /* Muda a cor do fundo */
            textcolor(LIGHTBLUE);
            textbackground(WHITE);

            gotoxy(15, 5);
            cout <<"                                                                                            ";
            gotoxy(15, 6);
            cout <<"                              ENTRE COM A SENHA DO COORDENADOR                              ";
            gotoxy(15, 7);
            cout <<"                                                                                            ";
            gotoxy(15, 9);
            textcolor(WHITE);
            textbackground(LIGHTBLUE);
            cout << "Senha: ";
            for(int i = 0; i < 11; i++)
            {
               *(senhaa + i) = getch();
               printf("*");
            }

            inteiro = strcmp(senhaa, senhapadrao);
            if(inteiro == 0)
            {
                getch();
                namespaceGraphic::verificarSenha();
                MenuCoordenacao();
            }
            else
            {
                namespaceGraphic::verificarSenha();
                gotoxy(15,15);
                cout << "Senha Errada! Tente Novamente";
                getch();
                system("cls");
                MenuInicial(verificadordelogin -1 );
            }
            break;
        case 2:
            system("CLS");
            textcolor(LIGHTBLUE);
            textbackground(WHITE);
            gotoxy(15, 5);
            cout <<"                                                                                            ";
            gotoxy(15, 6);
            cout <<"                                INFORME A SENHA DO PREFESSOR                                ";
            gotoxy(15, 7);
            cout <<"                                                                                            ";
            gotoxy(15, 9);
            textcolor(WHITE);
            textbackground(LIGHTBLUE);
            cout << "Senha:";

            for(int i = 0; i < 9; i++)
            {
               *(senha + i) = getch();
               printf("*");
            }

            inteiro = strcmp(senha, senhapadraop);

            if(inteiro == 0)
            {
                getch();
                namespaceGraphic::verificarSenha();
                MenuProfessor();
            }
            else
            {
                namespaceGraphic::verificarSenha();
                gotoxy(15,15);
                cout << "Senha Errada! Tente Novamente";
                getch();
                system("cls");
                MenuInicial(verificadordelogin -1 );
            }
            break;
        case 3:
            system("cls");
            system("color 9f"); /* Muda a cor do fundo */
            textcolor(LIGHTBLUE);
            textbackground(WHITE);

            gotoxy(15, 5);
            cout <<"                                                                                            ";
            gotoxy(15, 6);
            cout <<"                                 BEM VINDO AO MENU DO ALUNO                                 ";
            gotoxy(15, 7);
            cout <<"                                                                                            ";
            ListarAlunoUnico();
            break;
        case 4:
            system("cls");
            system("color 9f"); /* Muda a cor do fundo */
            textcolor(LIGHTBLUE);
            textbackground(WHITE);

            gotoxy(15, 5);
            cout <<"                                                                                            ";
            gotoxy(15, 6);
            cout <<"                              BEM VINDO AO MENU DO FUNCIONARIO                              ";
            gotoxy(15, 7);
            cout <<"                                                                                            ";
            DadosFun();
            break;
        case 5:
            system("cls");
            string s;
            ifstream ler("Tutorial.txt");
            while(getline(ler,s))
            {
                cout<<s<<endl;
            }
            system("pause");
            system("CLS");
            break;

        }
    }
    while(Menu!=6);
}

void MenuCoordenacao()
{
    int opnovo;
    system("CLS");
    do
    {
            system("color 9f");
            textcolor(LIGHTBLUE);
            textbackground(WHITE);

            gotoxy(15, 5);
            cout <<"                                                                                            ";
            gotoxy(15, 6);
            cout <<"                             BEM VINDO AO MENU DA COORDENAÇÃO                             ";
            gotoxy(15, 7);
            cout <<"                                                                                            ";
            gotoxy(15, 9);
            cout <<"                          Informe a opção que você deseja acessar                        \n";

            gotoxy(15, 14);
            cout << "                            ";
            gotoxy(15, 15);
            cout << "    1- Dados dos Alunos     ";
            gotoxy(15, 16);
            cout << "                            ";

            gotoxy(15, 18);
            cout << "                            ";
            gotoxy(15, 19);
            cout << "  2- Dados de professores   ";
            gotoxy(15, 20);
            cout << "                            ";

            gotoxy(79, 14);
            cout << "                            ";
            gotoxy(79, 15);
            cout << " 3- Dados dos funcionarios  ";
            gotoxy(79, 16);
            cout << "                            ";

            gotoxy(79, 18);
            cout << "                            ";
            gotoxy(79, 19);
            cout << "4- Voltar ao menu principal ";
            gotoxy(79, 20);
            cout << "                            ";

        gotoxy(54,25);
        cout << "Digite a opção: ";
        cin>>opnovo;

        system("cls");
        switch(opnovo)
        {
        case 1:
            DadosAlunos();
            system("pause");
            system("cls");
            break;
        case 2:
            DadosProf();
            system("pause"); //Pressione qualquer tecla para continuar
            system("cls");
            break;
        case 3:
            DadosFun();
            system("pause");
            getch();
            system("cls");
            break;
        case 4:
            system("cls");
            break;
        }
    }
    while(opnovo!=4);
}

void DadosAlunos()
{
    int menucord;
    char op='s';
    do
    {
            system("color 9f");
            textcolor(LIGHTBLUE);
            textbackground(WHITE);

            gotoxy(15, 5);
            cout <<"                                                                                            ";
            gotoxy(15, 6);
            cout <<"                                     O QUE DESEJA FAZER                                     ";
            gotoxy(15, 7);
            cout <<"                                                                                            ";

            gotoxy(15, 14);
            cout << "                            ";
            gotoxy(15, 15);
            cout << " 1- Criar arquivo do aluno  ";
            gotoxy(15, 16);
            cout << "                            ";

            gotoxy(15, 18);
            cout << "                            ";
            gotoxy(15, 19);
            cout << "      2- Listar Alunos      ";
            gotoxy(15, 20);
            cout << "                            ";

            gotoxy(15, 22);
            cout << "                            ";
            gotoxy(15, 23);
            cout << "     3- Cadastrar aluno     ";
            gotoxy(15, 24);
            cout << "                            ";

            gotoxy(79, 14);
            cout << "                            ";
            gotoxy(79, 15);
            cout << "4- Alterar os dados do aluno";
            gotoxy(79, 16);
            cout << "                            ";

            gotoxy(79, 18);
            cout << "                            ";
            gotoxy(79, 19);
            cout << "      5- Remover aluno      ";
            gotoxy(79, 20);
            cout << "                            ";

            gotoxy(79, 22);
            cout << "                            ";
            gotoxy(79, 23);
            cout << "6- Volt. ao menu coordenacao";
            gotoxy(79, 24);
            cout << "                            ";

        gotoxy(54,25);
        cout << "Digite a opção: ";
        cin >> menucord;

        system("cls");
        switch(menucord)
        {
        case 1:
            IniciarArquivoAlunos();
            system("cls");
            break;
        case 2:
            ListarAlunoUnicoCord();
            system("cls");
            break;
        case 3:
            do
            {
                CadastraAlunos();
                cout<<"Deseja cadastrar outro aluno [s/n]?"<<endl;
                cin>>op;
            }
            while(op=='s'||op=='S');
            break;
        case 4:
            AtualizarAluno();
            system("cls");
            break;
        case 5:
            RemoverAluno();
            system("cls");
            break;
        }
    }
    while (menucord!=6);

}
void IniciarArquivoAlunos()
{
    char opchar;

    ofstream arquivo(ArquivoAlunos,ios::trunc);

    if (arquivo.is_open())
    {
        StructAlunos Vazio= {0, " "," ", " "," "," "," ", 0.0, 0.0, 0.0, 0.0, 0};
        cout<<"Você deseja criar ou formatar o arquivo dos alunos do zero [s/n]?"<<endl
            << "S para sim e N para nao"<<endl;
        cin>>opchar;
        if(opchar=='s' || opchar == 'S')
        {
            opchar= ' ';
            cout<<"Tem certeza? O arquivo dos alunos ira ser criado ou formatado [s/n]."<<endl;
            cout << "Digite a opção: ";
            cin>>opchar;
            if(opchar=='s'||opchar=='S')
            {
                for(int i=0; i<qtdaluno; i++)
                {
                    arquivo.write((const char*)(&Vazio),sizeof(StructAlunos));
                }
            }
            cout<<"Arquivo alunos criado/formatado com sucesso"<<endl;
        }

    }
    else
    {
        cout<<"O arquivo nao existe!!!"<<endl;
        cout<<"Crie o arquivo da proxima vez, pressione qualquer tecla para continuar"<<endl;
        system("cls");
        exit(1);
    }

    arquivo.close();

}

void CadastraAlunos()
{
    fstream arquivo;
    arquivo.open(ArquivoAlunos,ios::out|ios::in|ios::ate);
    if(arquivo.fail())
    {
        cout<<"Falha na abertura do arquivo!"<<endl;
        exit(1);
    }
    StructAlunos Inserir;
    do
    {
        cout<<"Digite a matrícula do aluno"<<endl;
        cin>> Inserir.Matricula;

    }while(VerificaArquivoAluno(Inserir.Matricula)!=0);
    cout<<"Digite o nome do aluno"<<endl;
    fflush(stdin);
    cin.getline(Inserir.Nome,50);
    cout<<"Digite o nome do pai do aluno"<<endl;
    fflush(stdin);
    cin.getline(Inserir.NomePai,50);
    cout<<"Digite o nome da mãe do aluno"<<endl;
    fflush(stdin);
    cin.getline(Inserir.NomeMae,50);
    cout<<"Digite o sexo do aluno(m ou f)"<<endl;
    cin>>Inserir.Sexo;
    cout<<"Informe o telefone para contato do aluno"<<endl;
    cin>>Inserir.Telefone;
    cout<<"Informe o endereço do aluno"<<endl;
    fflush(stdin);
    cin.getline(Inserir.Endereco,50);
    arquivo.seekp((Inserir.Matricula-1)*sizeof(StructAlunos));

    arquivo.write((const char*)(&Inserir),sizeof(StructAlunos));

    arquivo.close();
}

int VerificaArquivoAluno(int matricula)
{
    StructAlunos leraluno;
    ifstream entrada(ArquivoAlunos);
    while(entrada&&!entrada.eof())
    {
      entrada.read((char*)(&leraluno),sizeof(StructAlunos));
        if(matricula==leraluno.Matricula)
        {
            return 1;
        }
    entrada.read((char*)(&leraluno),sizeof(StructAlunos));
    }
    return 0;
}


int VerificaArquivoProf(int id)
{
    StructProfessor LerProf;
    ifstream entrada(ArquivoProfessores);
    while(entrada&&!entrada.eof())
    {
      entrada.read((char*)(&LerProf),sizeof(StructProfessor));
        if(id==LerProf.id)
        {
            return 1;
        }
    entrada.read((char*)(&LerProf),sizeof(StructProfessor));
    }
    return 0;
}

int VerificaArquivoFun(char* arquivofun,int id)
{
    FunSpace::StructFuns LerFun;
    ifstream entrada(arquivofun);
    while(entrada&&!entrada.eof())
    {
      entrada.read((char*)(&LerFun),sizeof(FunSpace::StructFuns));
        if(id==LerFun.id)
        {
            return 1;
        }
    entrada.read((char*)(&LerFun),sizeof(FunSpace::StructFuns));
    }
    return 0;
}



void ListarAlunoUnicoCord()
{
    fstream arquivo;
    StructAlunos listar;
    arquivo.open(ArquivoAlunos,ios::in);
    cout << "Informe sua matrícula: ";
    cin >> listar.Matricula;
    system("cls");

    if(arquivo.fail())
    {
        cout<<"Falha na abertura do arquivo! "<<endl;
        exit(0);
    }

    cout << setiosflags(ios::left)
         << setw(10) << "Matrícula"
         << setw(15) << "Nome"
         << setw(15) << "Nome do Pai"
         << setw(15) << "Nome da Mãe"
         << setw(10) << "Sexo"
         << setw(20) << "Telefone"
         <<setw(20) << "Endereço"<<endl;

    arquivo.seekp((listar.Matricula-1)*sizeof(StructAlunos));
    arquivo.read((char*)(&listar),sizeof(StructAlunos));

    cout << setiosflags(ios::left)
         << setw(10) << listar.Matricula
         << setw(15) << listar.Nome
         << setw(15) << listar.NomePai
         << setw(15) << listar.NomeMae
         << setw(10) << listar.Sexo
         << setw(20) << listar.Telefone
         <<setw(20)<<listar.Endereco<<endl;
    cout<<"Pressione qualquer tecla para continuar..."<<endl;
    getch();
    arquivo.close();
    system("cls");
}
void AtualizarAluno()
{
    StructAlunos inserir;
    int Menuatualizar;
    fstream  arquivo;

    arquivo.open(ArquivoAlunos,ios::out|ios::in|ios::ate);
    cout<<"Informe a matrícula do Aluno que você deseja atualizar dados."<<endl;
    cout << "Digite a opção: ";
    cin>>inserir.Matricula;

    arquivo.seekg((inserir.Matricula-1)*sizeof(StructAlunos));
    arquivo.read((char*)(&inserir),sizeof(StructAlunos));

    do
    {
        cout<< "O que deseja atualizar?\n[1]-Nome do aluno\n[2]-Nome do Pai\n[3]-Nome da Mãe\n[4]-Sexo\n[5]-Telefone\n[6]-Endereço\n[7]-Voltar"<<endl;
        cout << "Digite a opção: ";
        cin>>Menuatualizar;
        system("CLS");

        switch(Menuatualizar)
        {
        case 1:
            cout<<"Informe o  nome do aluno: "<<endl;
            fflush(stdin);
            cin.getline(inserir.Nome,50);
            arquivo.seekp((inserir.Matricula-1)*sizeof(StructAlunos));
            arquivo.write((const char*)(&inserir),sizeof(StructAlunos));
            system("CLS");
            break;
        case 2:
            cout<<"Informe o novo Nome do Pai: "<<endl;
            fflush(stdin);
            cin.getline(inserir.NomePai,50);
            arquivo.seekp((inserir.Matricula-1)*sizeof(StructAlunos));
            arquivo.write((const char*)(&inserir),sizeof(StructAlunos));
            system("CLS");
            break;
        case 3:
            cout<<"Informe o novo Nome da Mãe: "<<endl;
            fflush(stdin);
            cin.getline(inserir.NomeMae,50);
            arquivo.seekp((inserir.Matricula-1)*sizeof(StructAlunos));
            arquivo.write((const char*)(&inserir),sizeof(StructAlunos));
            system("CLS");
            break;
        case 4:
            cout<<"Informe o novo Sexo do Aluno: "<<endl;
            cin>>inserir.Sexo;
            arquivo.seekp((inserir.Matricula-1)*sizeof(StructAlunos));
            arquivo.write((const char*)(&inserir),sizeof(StructAlunos));
            system("CLS");
            break;
        case 5:
            cout<<"Informe o novo Telefone para Contato: "<<endl;
            cin>>inserir.Telefone;
            arquivo.seekp((inserir.Matricula-1)*sizeof(StructAlunos));
            arquivo.write((const char*)(&inserir),sizeof(StructAlunos));
            system("CLS");
            break;
        case 6:
            cout<<"Informe o novo endereço do aluno"<<endl;
            fflush(stdin);
            cin.getline(inserir.Endereco,50);
            arquivo.seekp((inserir.Matricula-1)*sizeof(StructAlunos));
            arquivo.write((const char*)(&inserir),sizeof(StructAlunos));
            system("CLS");
            break;

        }
    }
    while(Menuatualizar!=7);

    arquivo.close();

}

void RemoverAluno()
{
    StructAlunos inserir;
    StructAlunos Vazio = {0," "," "," "," "," "," ",0.0,0.0,0.0,0.0};

    fstream arquivo;

    arquivo.open(ArquivoAlunos,ios::out|ios::in|ios::ate);

    if(arquivo.fail())
    {
        cout<<"Falha na abertura do arquivo!"<<endl;
        exit(0);
    }

    cout<<"Informe a matrícula do aluno que você deseja remover: "<<endl;
    cin>>inserir.Matricula;
    arquivo.seekp((inserir.Matricula-1)*sizeof(StructAlunos));

    arquivo.write((const char*)(&Vazio),sizeof(StructAlunos));

    arquivo.close();
}

void DadosFun()
{
    int opcao;
    do
    {
        system("color 9f");
        textcolor(LIGHTBLUE);
        textbackground(WHITE);
        gotoxy(15, 9);
        cout <<"                                     O QUE DESEJA FAZER                                     ";

        gotoxy(15, 12);
        cout << "                            ";
        gotoxy(15, 13);
        cout << "  1-Criar Arquivo Inicial   ";
        gotoxy(15, 14);
        cout << "                            ";

        gotoxy(15, 16);
        cout << "                            ";
        gotoxy(15, 17);
        cout << "   2-Inserir Funcionario    ";
        gotoxy(15, 18);
        cout << "                            ";

        gotoxy(15, 20);
        cout << "                            ";
        gotoxy(15, 21);
        cout << "   3-Listar Funcionarios    ";
        gotoxy(15, 22);
        cout << "                            ";

        gotoxy(79, 12);
        cout << "                            ";
        gotoxy(79, 13);
        cout << "4-Atua. dados do funcionario";
        gotoxy(79, 14);
        cout << "                            ";

        gotoxy(79, 16);
        cout << "                            ";
        gotoxy(79, 17);
        cout << "   5-Remover Funcionario    ";
        gotoxy(79, 18);
        cout << "                            ";

        gotoxy(79, 20);
        cout << "                            ";
        gotoxy(79, 21);
        cout << "           0-Sair           ";
        gotoxy(79, 22);
        cout << "                            ";


        textcolor(WHITE);
        textbackground(LIGHTBLUE);
        gotoxy(54, 25);
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if(opcao < 0 || opcao > 5)
        {
            gotoxy(15, 26);
            cout<<"Opção inválida! Informe uma opção válida, por favor: ";
            getch();
            system("cls");
           DadosFun();
        }
        switch (opcao)
        {
        case 1:
            FunSpace::CriarArquivoFun(arquivofun);
            break;
        case 2:
            FunSpace::CadastrarFun(arquivofun);
            break;
        case 3:
            FunSpace::ListarFuncionarios(arquivofun);
            break;
        case 4:
            FunSpace::AlterarDadosFun(arquivofun);
            break;
        case 5:
            FunSpace::RemoveFuncionario(arquivofun);
            break;
        }

    }
    while (opcao != 0);
    MenuCoordenacao();
}

void DadosProf()
{
    int  op,aux;
    do
    {
        cout<<"O que você deseja acessar nos dados dos professores?"<<endl;
        cout<<"1 - Para criar ou recriar o arquivo dos  professores\n2 - Para cadastar um professor ao sistema\n3 - Para listar todos os professores cadastrados\n4 - Para remover um professor cadastrado\n5 - Para voltar ao menu anterior"<<endl;
        cin>>op;
        if(op<1 || op>5)
        {
            do
            {
                cout<<"Opção inválida! Informe uma opção válida, por favor."<<endl;
                cin>>aux;
            }
            while(aux<1 || aux>5);
            op=aux;
        }

        switch(op)
        {
        case 1:
            IniciarArquivoProf();
            system("cls");
            break;
        case 2:
            CadastraProf();
            system("cls");
            break;
        case 3:
            //ListarProf();
            system("cls");
            break;
        case 4:
            //RemoverProf();
            system("cls");
            break;
        }
    }
    while(op!=5);
}

void IniciarArquivoProf()
{

    char opchar;

    ofstream arquivo(ArquivoProfessores,ios::trunc);

    if (arquivo.is_open())
    {
        cout <<"Bem vindo a função de criar ou recriar arquivo de professores!"<<endl;
        StructProfessor Vazio= {0," "," "," ", " ", 0.0};
        cout<<"Você deseja criar o arquivo dos professores do zero?"<<endl
            << "S para sim e N para nao"<<endl;
        cin>>opchar;
        if(opchar=='s' || opchar == 'S')
        {
            opchar= ' ';
            cout<<"Tem certeza? O arquivo professores irá ser criado ou formatado."<<endl;
            cin>>opchar;
            if(opchar=='s'||opchar=='S')
            {
                for(int i=0; i<qtdprof; i++)
                {
                    arquivo.write((const char*)(&Vazio),sizeof(StructProfessor));
                }
            }
            cout<<"Arquivo professores criado com sucesso"<<endl;
            cout<<"Pressione qualquer tecla para continuar"<<endl;
            getch();
        }
    }
}


void CadastraProf()
{
     StructProfessor Cadastro;
    fstream arquivo;
    arquivo.open(ArquivoProfessores,ios::out|ios::in|ios::ate);
    if(arquivo.fail())
    {
        cout<<"Falha na abertura do arquivo!"<<endl;
        getch();
        exit(1);
    }
   do
   {
        cout<<"Id do professor"<<endl;
        cin>>Cadastro.id;
   }while(VerificaArquivoProf(Cadastro.id)!=0);

    cout<<"Informe o nome"<<endl;
    fflush(stdin);
    cin.getline(Cadastro.nome,50);
    cout<<"Informe o sexo"<<endl;
    fflush(stdin);
    cin.getline(Cadastro.sexo,25);
    cout<<"Informe o endereço do professor"<<endl;
    fflush(stdin);
    cin.getline(Cadastro.endereco,50);
    cout<<"Informe o telefone"<<endl;
    fflush(stdin);
    cin.getline(Cadastro.telefone,15);
    do
    {
        cout<<"Informe o salário"<<endl;
        cin>>Cadastro.salario;
    }while(Cadastro.salario<0);
    arquivo.seekp((Cadastro.id-1)*sizeof(StructProfessor));
    arquivo.write((const char*)(&Cadastro),sizeof(StructProfessor));
    arquivo.close();
}

void MenuProfessor()
{
    int op;
    system("cls");
    do
    {
        system("color 9f"); /* Muda a cor do fundo */
        textcolor(LIGHTBLUE);
        textbackground(WHITE);

        gotoxy(15, 5);
        cout <<"                                                                                            ";
        gotoxy(15, 6);
        cout <<"                                 O QUE VOCE DESEJA,PROFESSOR                                ";
        gotoxy(15, 7);
        cout <<"                                                                                            ";

        gotoxy(15, 12);
        cout << "                            ";
        gotoxy(15, 13);
        cout << "1- Colocar falt. nos alunos ";
        gotoxy(15, 14);
        cout << "                            ";

        gotoxy(47, 12);
        cout << "                            ";
        gotoxy(47, 13);
        cout << "2- inserir notas dos alunos ";
        gotoxy(47, 14);
        cout << "                            ";

        gotoxy(79, 12);
        cout << "                            ";
        gotoxy(79, 13);
        cout << "3- voltar ao menu principal ";
        gotoxy(79, 14);
        cout << "                            ";


        cin>>op;
        switch(op)
        {
        case 1:
            InsereFaltas();
            system("cls");
            break;
        case 2:
            AlterarNotasAluno();
         break;
        }
   }while(op!=3);
}


void InsereFaltas()
{

    StructAlunos inserir;
    fstream  arquivo;
    arquivo.open(ArquivoAlunos,ios::out|ios::in|ios::ate);
    if(arquivo.fail())
    {
        cout<<"Falha na abertura do arquivo!"<<endl;
        getch();
    }

    cout<<"informe a matrícula do Aluno que você deseja atualizar as faltas"<<endl;
    cin>>inserir.Matricula;

    arquivo.seekg((inserir.Matricula-1)*sizeof(StructAlunos));
    arquivo.read((char*)(&inserir),sizeof(StructAlunos));

    cout<<"Informe quantas faltas o aluno possui : "<<endl;
    cin>>inserir.faltas;
    arquivo.seekp((inserir.Matricula-1)*sizeof(StructAlunos));
    arquivo.write((const char*)(&inserir),sizeof(StructAlunos));
    arquivo.close();
    cout<<"As faltas foram inseridas no aluno informado"<<endl;
    system("pause");
}



void FuncaoAlunoMenu()
{
            int faltascomp;
            double mediaaluno = 0.0;
            double mediafinal = 0.0;

    fstream arquivo;

    arquivo.open(ArquivoAlunos,ios::in);

    StructAlunos listar;

    if(arquivo.fail())
    {
            cout<<"Falha na abertura do arquivo! "<<endl;
            getch();
    }

   cout << setiosflags(ios::left)
        << setw(15) << "Matricula"
        << setw(15) << "Nome"
        << setw(15) << "Nome do Pai"
        << setw(15) << "Nome da Mãe"
        << setw(10) << "Sexo"
        << setw(10) << "Telefone"
        << resetiosflags(ios::left)
        << setw(10) << "1ª Nota"
        << setw(10) << "2ª Nota"
        << setw(10) << "3ª Nota"
        << setw(10) << "4ª Nota"
        << setw(10) <<  "Faltas"
        << setw(10) <<  "Média"
        << setw(15) <<  "Situação" <<endl;

        arquivo.read((char*)(&listar),sizeof(StructAlunos));
        pontmedia med;
        med = new double[4];

        while(arquivo && !arquivo.eof()&& listar.Matricula!=0)
        {
            mediaaluno = 0.0;
            mediafinal = 0.0;

                    med[1]=listar.Nota1;
                    med[2]=listar.Nota2;
                    med[3]=listar.Nota3;
                    med[4]=listar.Nota4;
                    for(int x=1;x<=4;x++){
                        mediaaluno = mediaaluno + med[x];
                    }
                    mediafinal = mediaaluno/4;

           cout << setiosflags(ios::left)
                << setw(15) << listar.Matricula
                << setw(15) << listar.Nome
                << setw(15) << listar.NomePai
                << setw(15) << listar.NomeMae
                << setw(10) << listar.Sexo
                << setw(10) << listar.Telefone
                << resetiosflags(ios::left)<<setprecision(2)<<setiosflags(ios::fixed|ios::showpoint)
                << setw(10) << listar.Nota1
                << setw(10) << listar.Nota2
                << setw(10) << listar.Nota3
                << setw(10) << listar.Nota4
                << setw(10) << listar.faltas
                << setw(10) << mediafinal ;
                faltascomp = listar.faltas;
                 if(mediafinal>=6.0){
                    if(faltascomp<=25){
                        cout << setw(15) << " Aprovado!" << endl;
                    }
                    else{
                        cout << setw(15) << " Rep por Faltas!" << endl;
                    };
                }
                if(mediafinal<6.0){
                    if(faltascomp<=25){
                        cout << setw(15) << " Reprovado por Média!" << endl;
                    }
                    else{
                        cout << setw(15) << " Reprovado por Média e Faltas!" << endl;
                    }  if(mediafinal>=6.0){
                    if(faltascomp<=25){
                        cout << setiosflags(ios::right)
                             << setw(15) << " Aprovado!" << endl;
                    }
                    else{
                   cout << setiosflags(ios::right)
                        << setw(15) << " Reprovado por Faltas!" << endl;
                    };
                }


            }

            arquivo.read((char*)(&listar),sizeof(StructAlunos));


          }
        delete [] med;
        med = NULL;

        arquivo.close();
        }


    void AlterarNotasAluno(){

    StructAlunos InserirNotasAlunos;
    int Menuatualizar;
    fstream  arquivo;

    arquivo.open(ArquivoAlunos,ios::out|ios::in|ios::ate);

    if(arquivo.fail())
    {
            cout<<"Falha na abertura do arquivo!"<<endl;
            getch();
    }

    cout<<"Informe a matricula do aluno que você deseja atualizar as notas:"<<endl;
    cin>>InserirNotasAlunos.Matricula;

    arquivo.seekg((InserirNotasAlunos.Matricula-1)*sizeof(StructAlunos));
    arquivo.read((char*)(&InserirNotasAlunos),sizeof(StructAlunos));

    do{
       cout<< "Que nota você deseja alterar? [1]- 1ª Nota\n[2]- 2ª Nota\n[3]- 3ª Nota\n[4]- 4ª Nota\n[5]- Sair"<<endl;
       cin>>Menuatualizar;
          switch(Menuatualizar)
          {
            case 1:
                cout<<"Informe a nova 1ª Nota: "<<endl;
                cin>>InserirNotasAlunos.Nota1;
                arquivo.seekp((InserirNotasAlunos.Matricula-1)*sizeof(StructAlunos));
                arquivo.write((const char*)(&InserirNotasAlunos),sizeof(StructAlunos));
                break;
            case 2:
                cout<<"Informe a nova 2ª Nota: "<<endl;
                cin>>InserirNotasAlunos.Nota2;
                arquivo.seekp((InserirNotasAlunos.Matricula-1)*sizeof(StructAlunos));
                arquivo.write((const char*)(&InserirNotasAlunos),sizeof(StructAlunos));
                break;
            case 3:
                cout<<"Informe a nova 3ª Nota: "<<endl;
                cin>>InserirNotasAlunos.Nota3;
                arquivo.seekp((InserirNotasAlunos.Matricula-1)*sizeof(StructAlunos));
                arquivo.write((const char*)(&InserirNotasAlunos),sizeof(StructAlunos));
                break;
            case 4:
                cout<<"Informe a nova 4ª Nota: "<<endl;
                cin>>InserirNotasAlunos.Nota4;
                arquivo.seekp((InserirNotasAlunos.Matricula-1)*sizeof(StructAlunos));
                arquivo.write((const char*)(&InserirNotasAlunos),sizeof(StructAlunos));
                break;
            }
    }
    while(Menuatualizar!=5);
    arquivo.close();

}

void ListarAlunoUnico()
{
    double mediaaluno = 0.0;
    double mediafinal = 0.0;
    int faltascomp;

    fstream arquivo;
     StructAlunos listar;
    arquivo.open(ArquivoAlunos,ios::in);

    gotoxy(15,12);
    textcolor(WHITE);
    textbackground(LIGHTBLUE);
    cout << "Informe sua matricula: ";
    cin >> listar.Matricula;
    system("CLS");

    if(arquivo.fail())
    {
            cout<<"Falha na abertura do arquivo! "<<endl;
            getch();
    }

         cout << setiosflags(ios::left)
        << setw(10) << "Matricula"
        << setw(15) << "Nome"
        << setw(15) << "Nome do Pai"
        << setw(15) << "Nome da Mãe"
        << setw(10) << "Sexo"
        << setw(20) << "Telefone"
        << setw(10) << "1ªNota"
        << setw(10) << "2ªNota"
        << setw(10) << "3ªNota"
        << setw(10) << "4ªNota"
        << setw(10) << "Faltas"
        << setw(10) <<  "Média"
        << setw(15) <<  "Situação" <<endl;

        arquivo.seekp((listar.Matricula-1)*sizeof(StructAlunos));
        arquivo.read((char*)(&listar),sizeof(StructAlunos));
            pontmedia med;
            med = new double[4];

            med[1]=listar.Nota1;
            med[2]=listar.Nota2;
            med[3]=listar.Nota2;
            med[4]=listar.Nota2;
                for(int x=1;x<=4;x++){
                    mediaaluno = mediaaluno + med[x];
                }
                mediafinal = mediaaluno/4;

                cout << setiosflags(ios::left)
                << setw(10) << listar.Matricula
                << setw(15) << listar.Nome
                << setw(15) << listar.NomePai
                << setw(15) << listar.NomeMae
                << setw(10) << listar.Sexo
                << setw(20) << listar.Telefone
                << setw(10) << listar.Nota1
                << setw(10) << listar.Nota2
                << setw(10) << listar.Nota3
                << setw(10) << listar.Nota4
                << setw(10) << listar.faltas
                << setw(10) << mediafinal;
                faltascomp = listar.faltas ;
                delete [] med;
                med = NULL;

                if(mediafinal>=6.0){
                    if(faltascomp<=25){

                        cout << setw(15) << " Aprovado!" << endl;
                    }
                    else{
                        cout << setw(15) << " Reprovado por Faltas!" << endl;
                    };
                }
                if(mediafinal<6.0){
                    if(faltascomp<=25){
                        cout << setw(12) << " Reprovado por Média!" << endl;
                    }
                    else{
                        cout << setw(15) << " Reprovado por Média e Faltas!" << endl;
                    }
                }



        arquivo.close();
        getch();
        system("cls");
}
