#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <locale.h>
#include <conio.h>
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
    cout << "  CRIAR ARQUIVO INICIAL     " << endl;
    char opcao;
    cout << "\nIsso ira apagar sua base de dados!" << endl;
    cout << "Deseja continuar [s/n] ? ";
    cin >> opcao;
    if ((opcao == 's') || (opcao == 'S'))
    {
        ofstream saida(arquivofun, ios::out | ios::trunc);
        if (saida.fail())
        {
            cout << "Não foi possivel acessar o arquivo!" << endl;
            exit(1);
        }

        StructFuns fichaVazia = {0, "", " ", " ", " ", " ", 0.0};

        for (int i = 0; i < MAXFUNCIONARIOS; i++)
            saida.write((const char *)(&fichaVazia), sizeof(StructFuns));
        namespaceGraphic::createFile();
        cout << "\nArquivo criado com sucesso!" << endl;
        saida.close();
    }
    else
    {
        cout << "\nOperação cancelada!" << endl;
    }
    getch();
}
void CadastrarFun(char *arquivofun)
{
    StructFuns fun;
    fstream saida;
    saida.open(arquivofun, ios::out | ios::in | ios::ate);
    if (saida.fail())
    {
        cout << "Não foi possivel acessar o arquivo!" << endl;
        exit(1);
    }
    system("CLS");
    cout << "      Cadastro de  Funcionário           " << endl;
    cout << "                                          " << endl;
    do
    {
    cout << "Entre com o ID do Funcionário " << endl;
    cin >> fun.id;
    }while(VerificaArquivoFun(fun.id)!=0);
    if ((fun.id > 0) && (fun.id <= MAXFUNCIONARIOS))
    {
        fstream saida;
        saida.open(arquivofun, ios::out | ios::in | ios::ate);
        cout<<"Informe o nome do funcionário"<<endl;
        fflush(stdin);
        cin.getline(fun.nome,50);
        cout<<"Informe o cargo do funcionário na escola"<<endl;
        fflush(stdin);
        cin.getline(fun.cargo,50);
        cout<<"Informe o sexo do funcionário "<<endl;
        fflush(stdin);
        cin.getline(fun.sexo,15);
        cout<<"Informe o telefone para contato do funcionário"<<endl;
        fflush(stdin);
        cin.getline(fun.telefone,15);
        cout<<"Informe o endereço do funcionário"<<endl;
        fflush(stdin);
        cin.getline(fun.local,50);
        cout<<"Informe o salário que o funcionário irá receber"<<endl;
        cin>>fun.salario;

        saida.seekp((fun.id - 1) * sizeof(StructFuns));
        saida.write((const char *)(&fun), sizeof(StructFuns));
        namespaceGraphic::insertFuncionario();
        cout << "\nFuncionário inserido com sucesso!" << endl;
        getch();
    }
    else
    {
        cout << "Não foi possivel inserir o funcionário!" << endl;
        getch();
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
        cout << "Não foi possivel acessar o arquivo!" << endl;
        exit(1);
    }
    system("CLS");
    FunSpace::ListarFuncionarios(arquivofun);
    cout << endl;
    cout << "Menu de alteração de dados do funcionario " << endl;
    cout << "                                                               ";
    cout << endl;

    int id;
    cout << "Digite o ID do funcionario a ser atualizado: ";
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
        cout <<"Entre com o novo salario do funcionário"<<endl;
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
        cout << "Não foi possivel acessar o arquivo!" << endl;
        exit(1);
    }
    StructFuns fun;

    system("CLS");
    cout << endl;
    cout << "Remover Funcionario " << endl;

    int id;
    cout << "Digite o ID do Funcionario a ser removido:";
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
                cout << "Não foi possivel acessar o arquivo!" << endl;
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
        cout << "Não foi possivel acessar o arquivo!" << endl;
        exit(1);
    }
    system("CLS");

    cout << " Lista de Funcionários" << endl;
    cout << "                                                                 ";
    cout << setiosflags(ios::left)
         << endl
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
    cout << endl;
    cout<<"Pressione qualquer tecla para continuar"<<endl;
    getch();
    entrada.close();

}
}
void MenuInicial(int verificadordelogin)
{
    setlocale(LC_ALL,"portuguese");
    int Menu;
    int senha;
    int senhapadrao=9999;
    int senhapadraop=1000;
    if (verificadordelogin<0)
    {
        cout << "Tentativa de logins excedidas, por favor inicie o programa novamente."<<endl;
        exit(1);
    }
    do
    {
        cout <<"Bem vindo ao Menu Principal "<<endl;
        cout <<"    "<<endl;
        cout<< "O que voce deseja acessar?\n[1]- Menu da Coordenação\n[2]- Menu do Professor\n[3]- Menu do Aluno\n[4]- Menu do Funcionario\n[5]- Informações sobre o programa \n[6]- Encerrar o programa"<<endl;
        cin>>Menu;

        switch(Menu)
        {
        case 1:
            system("CLS");
            cout <<"Informe sua senha, coordenador :\n";
            cin >> senha;
            if(senha==senhapadrao)
            {
                cout << "Bem Vindo ao menu da coordenação!";
                MenuCoordenacao();
            }
            else
            {
                cout << "Senha Errada! Tente Novamente";
                MenuInicial(verificadordelogin -1 );
            }
            break;
        case 2:
            system("CLS");
            cout <<"Informe sua senha, professor:\n";
            cin >> senha;
            if(senha==senhapadraop)
            {
                cout << "Bem vindo ao menu do professor";
                system("cls");
                MenuProfessor();
            }
            else
            {
                cout << "Senha Errada! Tente novamente pelo menu principal"<<endl;
                cout <<"\n"<<endl;
                MenuInicial(verificadordelogin -1 );
            }
            break;
        case 3:
            system("cls");
            cout << "Bem vindo ao menu do aluno";
            cout <<" \n"<<endl;
             ListarAlunoUnico();
            break;
        case 4:
            cout<<"FALTA IMPLEMENTAÇÃO"<<endl;
            //cout<<"Bem vindo ao menu do funcionario"<<endl;
            //MenuCordFun();
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
        cout<<"Bem vindo ao menu da coordenação"<<endl;
        cout<<"Agora informe a opção que você deseja acessar:\n 1- Dados dos Alunos \n 2- Dados de professores \n 3- Dados dos funcionarios \n 4- Voltar ao menu principal"<<endl;
        cout <<"Informe a opção desejada: ";
        cin>>opnovo;
        system("cls");
        switch(opnovo)
        {
        case 1:
            DadosAlunos();
            cout<<"Pressione qualquer tecla para continuar"<<endl;
            getch();
            system("cls");
            break;
        case 2:
            DadosProf();
            cout<<"Pressione qualquer tecla para continuar."<<endl;
            getch();
            system("cls");
            break;
        case 3:
            DadosFun();
            cout<<"Pressione qualquer tecla para continuar"<<endl;
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
        cout<< "O que deseja fazer ?\n[1]-Iniciar ou formatar o arquivo do aluno\n[2]-Listar Alunos\n[3]-Cadastrar aluno\n[4] Para alterar os dados do aluno\n[5]-Remover aluno\n[6]-Voltar ao menu da coordenação"<<endl;
        cin>>menucord;
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
                cout<<"Deseja cadastrar outro aluno?"<<endl;
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
        cout<<"Você deseja criar ou formatar o arquivo dos alunos do zero?"<<endl
            << "S para sim e N para nao"<<endl;
        cin>>opchar;
        if(opchar=='s' || opchar == 'S')
        {
            opchar= ' ';
            cout<<"Tem certeza? O arquivo dos alunos ira ser criado ou formatado."<<endl;
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
        cout<<"Digite a matricula do aluno"<<endl;
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
    cout << "Informe sua matrícula" <<endl;
    cin >> listar.Matricula;
    system("cls");

    if(arquivo.fail())
    {
        cout<<"Falha na abertura do arquivo! "<<endl;
    }

    cout << setiosflags(ios::left)
         << setw(10) << "Matricula"
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
    cout<<"Informe a matrícula do Aluno que você deseja atualizar dados:"<<endl;
    cin>>inserir.Matricula;

    arquivo.seekg((inserir.Matricula-1)*sizeof(StructAlunos));
    arquivo.read((char*)(&inserir),sizeof(StructAlunos));

    do
    {
        cout<< "O que você deseja atualizar?\n[1]-Nome do aluno\n[2]-Nome do Pai\n[3]-Nome da Mãe\n[4]-Sexo\n[5]-Telefone\n[6]-Endereço\n[7]-Voltar"<<endl;
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
        getch();
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
        system("CLS");
        cout << "1-Criar Arquivo Inicial" << endl;
        cout << "2-Inserir Funcionario" << endl;
        cout << "3-Listar Funcionarios" << endl;
        cout << "4-Atualizar dados do funcionario" << endl;
        cout << "5-Remover Funcionario" << endl;
        cout << "0-Sair" << endl;
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;
        if(opcao<0 && opcao>5)
            do
            {
                cout<<"Opção inválida! Informe uma opção válida, por favor."<<endl;
                cin>>opcao;
            }
            while(opcao<0 || opcao>5);
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
        cout<<"O que você deseja, professor?"<<endl;
        cout<<"1 - Para colocar faltas nos alunos\n2 -Para inserir as notas dos alunos\n3 - Para voltar ao menu principal"<<endl;
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

    cout << "Informe sua matricula" <<endl;
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
