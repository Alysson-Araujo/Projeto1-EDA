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
    
    //Pessoa eu("123.459.789-10","João", "Almir", "1/10/2000", "Guarulhos");
    
    //cout << eu.converte_ano("1/1/2000") << endl;
    
    
    //criação das arvores
    avl<long int> arv_cpf;
    avl<string> arv_nome;
    avl<long int> arv_data;
    //criação das raizes
    Node<long int>* raiz_cpf=NULL;
    Node<string>* raiz_nome=NULL;
    Node<long int>* raiz_data=NULL;

    //Vamos usar um vector para pegar os dados das pessoas separadamente e colocar seus dados nela e, em seguida,
    //colocar em um objeto pessoa para, assim, colocar em um nó da árvore
    /**dados[0] = CPF
     * dados[1] = Primero nome
     * dados[2] = Sobrenome
     * dados[3] = data de nascimento
     * dados[4] = Cidade
     */
    vector<string> dados;
    
    // Vamos usar o objeto Pessoa chamado pes para colocar as informações de cada pessoa em cada nó presente a árvore
    // ...
    Pessoa pes;

    // A string linha ficará responsável em receber linha por linha do arquivo contendo dados de uma pessoa de cada vez. 
    string linha;

    //Eu (Alysson) observei que quando estávamos adicionando os dados das pessoas, vi que estava sendo adicionado, também, tipos de cada 
    // coluna da tabela, sendo elas: NationalID, GivenName, Surname, Birthday, City.
    // Então para evitar que os nomes dos tipos das colunas fossem adicionadas nas árvores, eu criei 3 bool chamados de nPegaPrimeiraLinha1,
    // 
    bool nPegaPrimeiraLinha = true;



    fstream fin;
    vector<string> row;
    string line;
    
    fin.open("data.csv", ios::in);



    // construção da árvore avl, onde cada no tem chave sendo o cpf da pessoa e o seus dados em um objeto pessoa
   if(!fin.is_open()){
        throw std::runtime_error ("Não é facin po");
        }
    
    
    while( getline(fin, line)){
        
        if(nPegaPrimeiraLinha==true){
            getline(fin,line);
            nPegaPrimeiraLinha = false;
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
    
    nPegaPrimeiraLinha = true;
    //arv_cpf.avl_in_ordem(raiz_cpf);
    //cout << "#################################################################################" << endl;
//
    //
    //arv_cpf.clear(raiz_cpf);
    //raiz_cpf = nullptr;
    
    //bool nPegaPrimeiraLinha2 = true;

    fin.open("data.csv", ios::in);



    // construção da árvore avl, onde cada no tem chave sendo o primeiro nome da pessoa e os seus dados em um objeto pessoa
    if(!fin.is_open()){
        throw std::runtime_error ("Error");
        }
    
    
    
    while( getline(fin, line)){
        
        if(nPegaPrimeiraLinha==true){
            getline(fin,line);
            nPegaPrimeiraLinha = false;
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
    //cout << "#################################################################################" << endl;
    
    ////Fechando o arquivo data.csv
    fin.close();
    
    //arv_nome.clear(raiz_nome);
    nPegaPrimeiraLinha = true;
    //arv_nome.search_repetido(raiz_nome, "Kai", raiz_nome->pes);
    //arv_nome().
    //arv_nome.avl_in_ordem(raiz_nome);
 
    
    
    //bool nPegaPrimeiraLinha3 = true;
    
    fin.open("data.csv", ios::in);

    

    // construção da árvore avl, onde cada no tem chave sendo o primeiro nome da pessoa e os seus dados em um objeto pessoa
    if(!fin.is_open()){
        throw std::runtime_error ("Error");
        }
    
    
    
    while( getline(fin, line)){
        
        if(nPegaPrimeiraLinha==true){
            getline(fin,line);
            nPegaPrimeiraLinha = false;
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
        
    
        
        long int somaTUDO = x.converte_ano(row[3]) * 10000 + x.converte_mes(row[3]) * 100 + x.converte_dia(row[3]);

        raiz_data = arv_data.avl_insert(raiz_data,somaTUDO ,x);
        
    }

    //arv_nome.avl_in_ordem(raiz_nome);
    //cout << arv_nome.avl_search(raiz_nome, "Kai") << endl;
    //Fechando o arquivo data.csv
    //cout << "data no formato ano/mes/dia" << endl;
    //arv_data.avl_in_ordem(raiz_data);
    //cout << "#################################################################################" << endl;
    
    fin.close();
    
     //arv_data.avl_in_ordem(raiz_data);
 
    //arv_data.clear(raiz_data);
    //raiz_data = nullptr;

    
    




    //cout << endl;
    //arv_data.avl_in_ordem(raiz_data);





    

    bool menu_ativo = true;                         //deixa o menu ativo

    //long int cpf;                                   //
    //string nome, sobrenome;                         //variaveis para usar no menu;
    //int data_dia, data_mes, data_ano;               //

    //int escolha;                                    //para escolher no menu
    //int ordem;                                      //para escolher a arvore da ordem

    int num;
    //cpf
    long int cpf_user;

    //nome
    string nome_user;
    
    //data
    string data_user_i, data_user_f;
    long int peso_i, peso_f;


    while (menu_ativo){
        imprime_menu();
        cin >> num;
        switch (num)
        {
        case 1:
            
            cout << "Digite o cpf que deseja buscar no seguinte formato: xxxxxxxxxxx | exemplo: 38862473257 " << "\n"
            << "O programa aceita apenas os números do cpf!" << endl;
            
            cin >> cpf_user;
            arv_cpf.avl_search(raiz_cpf, cpf_user);
            
            break;
        
        case 2:
            cout <<"Escreva o primeiro nome das pessoas que deseja buscar: ";
            cin >> nome_user;   
            arv_nome.search_repetido(raiz_nome, nome_user);
            break;
        case 3:
            cout <<"Digite o mes, dia e ano no formato MM/DD/AAAA do intervalo inicial\n";
            cin >> data_user_i;
            cout <<"Digite o mes, dia e ano no formato MM/DD/AAAA do intervalo final\n";
            cin >> data_user_f;

            peso_i = pes.converte_ano(data_user_i) * 1000 + pes.converte_mes(data_user_i) * 100 + pes.converte_dia(data_user_i);
            peso_f = pes.converte_ano(data_user_f) * 1000 + pes.converte_mes(data_user_f) * 100 + pes.converte_dia(data_user_f);
            
            
            break;
           
        case 4:

            break;

            
        case 0:
            menu_ativo = false;
            break;
        default:
            cout <<"Por favor, digite um dos valores descritos no menu." << endl;
            break;
        }
    }
    
    arv_cpf.clear(raiz_cpf);
    arv_data.clear(raiz_data);
    arv_nome.clear(raiz_nome);
    
    raiz_cpf = nullptr;
    raiz_data = nullptr;
    raiz_nome = nullptr;










































    


    return 0;

}