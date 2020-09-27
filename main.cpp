#include <iostream>
//#include <stdio> // para usar o atol()
#include <vector>
#include "avl.h" 
#include "pessoa.h"     
#include <fstream>
#include <string>
#include<sstream>
using std::cout;
using std::endl;
using std::cin;
using std::string;


void imprime_menu(){                                    //imprime o menu

    cout << "------------------------------" << endl;
    cout << "          ARVORE AVL" << endl;
    cout << "------------------------------" << endl;
    cout << "1: Buscar pessoa pelo CPF" << endl;
    cout << "2: Buscar pessoa pelo nome" << endl;
    cout << "3: Buscar pessoa pelo intervalo da data de nasc" << endl;
    cout << "4: Imprimir todas os dados de todas as pessoas" << endl;
    cout << "\t\tEscolha um numero:";
}

int main(){
    
    Pessoa eu("123.459.789-10","João", "Almir", "10/17/2000", "Guarulhos");
    
    cout << eu.converte_ano("10/10/2000") << endl;
    
    
    //criação das arvores
    avl<long int> arv_cpf;
    avl<string> arv_nome;
    avl<long int> arv_data;
    //criação das raizes
    Node<long int>* raiz_cpf=NULL;
    Node<string>* raiz_nome=NULL;
    Node<long int>* raiz_data=NULL;

    vector<string> dados;
    
    Pessoa pes;

    string linha;

        
    bool nPegaPrimeiraLinha1 = true;



    fstream fin;
    vector<string> row;
    string line;
    //fin.open("data.csv", ios::in);
    


    // construção da árvore avl, onde cada no tem chave sendo o cpf da pessoa e o seus dados em um objeto pessoa
   /*if(!fin.is_open()){
        throw std::runtime_error ("Não é facin po");
        }
    
    
    while( getline(fin, line)){
        
        if(nPegaPrimeiraLinha1==true){
            getline(fin,line);
            nPegaPrimeiraLinha1 = false;
        }
        row.clear();
        stringstream s_stream(line);
        while( s_stream.good() ){
            string substr;
            getline(s_stream, substr, ',');
            row.push_back(substr);
        }
        
        
        Pessoa teste(row[0],row[1],row[2],row[3],row[4]);
        raiz_cpf = arv_cpf.avl_insert(raiz_cpf, teste.to_long_int(row[0]) ,teste);
        
    }
  
    //Fechando o arquivo data.csv
    fin.close();
    
    arv_cpf.clear(raiz_cpf);
    raiz_cpf = nullptr;
    bool nPegaPrimeiraLinha2 = true;
    
    fin.open("data.csv", ios::in);



    // construção da árvore avl, onde cada no tem chave sendo o primeiro nome da pessoa e os seus dados em um objeto pessoa
    if(!fin.is_open()){
        throw std::runtime_error ("Error");
        }
    
    
    
    while( getline(fin, line)){
        
        if(nPegaPrimeiraLinha2==true){
            getline(fin,line);
            nPegaPrimeiraLinha2 = false;
        }
        row.clear();
        stringstream s_stream(line);
        while( s_stream.good() ){
            string substr;
            getline(s_stream, substr, ',');
            row.push_back(substr);;
            
        }
        
    
        Pessoa pessoa_para_chave_nome(row[0],row[1],row[2],row[3],row[4]);
        raiz_nome = arv_nome.avl_insert(raiz_nome,row[1],pessoa_para_chave_nome);
        
    }

    //arv_nome.avl_in_ordem(raiz_nome);
    //cout << arv_nome.avl_search(raiz_nome, "Kai") << endl;
    //Fechando o arquivo data.csv
    fin.close();
    //arv_nome.search_repetido(raiz_nome, "Kai", raiz_nome->pes);
    //arv_nome().
    //arv_nome.avl_in_ordem(raiz_nome);

    */
    /*
    bool nPegaPrimeiraLinha3 = true;
    
    fin.open("data.csv", ios::in);

    

    // construção da árvore avl, onde cada no tem chave sendo o primeiro nome da pessoa e os seus dados em um objeto pessoa
    if(!fin.is_open()){
        throw std::runtime_error ("Error");
        }
    
    
    
    while( getline(fin, line)){
        
        if(nPegaPrimeiraLinha3==true){
            getline(fin,line);
            nPegaPrimeiraLinha3 = false;
        }
        row.clear();
        stringstream s_stream(line);
        while( s_stream.good() ){
            string substr;
            getline(s_stream, substr, ',');
            row.push_back(substr);
            
        }
        
    
        Pessoa x(row[0],row[1],row[2],row[3],row[4]);
        //cout << pessoa_para_chave_data.converte_ano(row[3]) << endl;
        //cout << pessoa_para_chave_data.converte_mes(row[3]) << endl;
        //cout << pessoa_para_chave_data.converte_dia(row[3]) << endl;
        //cout << row[3] << endl;
        
        long int ano=  x.converte_ano(row[3]) * 10000;
        long int mes=  x.converte_mes(row[3]) * 100;
        long int dia = x.converte_dia(row[3]);
        cout <<row[3] << endl;
        cout << ano << endl;
        cout << mes << endl;
        cout << dia << endl;
        
        long int somaTUDO = ano + dia + mes;
        cout << somaTUDO << endl;
        cout << "##############" << endl;
        //raiz_data = arv_data.avl_insert(raiz_data, ,x);
        
    }

    //arv_nome.avl_in_ordem(raiz_nome);
    //cout << arv_nome.avl_search(raiz_nome, "Kai") << endl;
    //Fechando o arquivo data.csv
    fin.close();
    
    arv_data.avl_in_ordem(raiz_data);

    arv_data.clear(raiz_data);
    raiz_data = nullptr;

    
    




    //cout << endl;
    //arv_data.avl_in_ordem(raiz_data);





    /*

    bool menu_ativo = true;                         //deixa o menu ativo

    long int cpf;                                   //
    string nome, sobrenome;                         //variaveis para usar no menu;
    int data_dia, data_mes, data_ano;               //

    int escolha;                                    //para escolher no menu
    int ordem;                                      //para escolher a arvore da ordem

  




    while(menu_ativo == true){

        imprime_menu();

        cin >> escolha;
        
        switch (escolha){
        
        //Mas não pede para inserir assim :/
        case 1:                             //Consulta pelo CPF
            cout << insira o cpf
                
            
            break;

        case 2:                             //Consulta pelo nome
            cout << "insira o nome da pessoa que quer  \n";
            cin >> nome;


            break;
        
        case 3:                             //Consulta pelo intervalo data nasc
            cout << ""
            

        
            


            cout << cpf << " removido\n";
            break;

        case 4:
            
            
            break;

        default:                           //numero invalido

            cout << endl <<  "\t \t>>Número inválido<<" << endl;

            break;
        
        }
    

    }
*/


    


    return 0;

}