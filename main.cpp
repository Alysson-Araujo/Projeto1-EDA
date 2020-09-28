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
    cout << "4: Imprimir todas as pessoa de um arvore em ordem" << endl;
    cout << "0: Finaliza o programa" << endl;
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
    
    // Vamos usar o objeto Pessoa chamado pessoa para colocar as informações de cada pessoa em cada nó presente a árvore
    // ...
    Pessoa pessoa;

    // A string linha ficará responsável em receber linha por linha do arquivo contendo dados de uma pessoa de cada vez. 
    string linha;

    //Eu (Alysson) observei que quando estávamos adicionando os dados das pessoas, vi que estava sendo adicionado, também, tipos de cada 
    // coluna da tabela, sendo elas: NationalID, GivenName, Surname, Birthday, City.
    // Então para evitar que os nomes dos tipos das colunas fossem adicionadas nas árvores, eu criei 3 bool chamados de nPegaPrimeiraLinha1,
    // 
    bool nPegaPrimeiraLinha = true;



    fstream arquivo;
    
   
    
    arquivo.open("data.csv", ios::in);



    // construção da árvore avl, onde cada no tem chave sendo o cpf da pessoa e o seus dados em um objeto pessoa
   if(!arquivo.is_open()){
        throw std::runtime_error ("Não é facin po");
        }
    
    
    while( getline(arquivo, linha)){
        
        if(nPegaPrimeiraLinha==true){
            getline(arquivo,linha);
            nPegaPrimeiraLinha = false;
        }
        dados.clear();
        stringstream s_stream(linha);
        while( s_stream.good() ){
            string substr;
            getline(s_stream, substr, ',');
            dados.push_back(substr);
        }
        
        
            pessoa.set_cpf(dados[0]);
            pessoa.set_nome(dados[1]);
            pessoa.set_sobrenome(dados[2]);
            pessoa.set_dataNascimento(dados[3]);
            pessoa.set_cidade_nasc(dados[4]);
        raiz_cpf = arv_cpf.avl_insert(raiz_cpf, pessoa.to_long_int(dados[0]) ,pessoa);
        
    }
  
    //Fechando o arquivo data.csv
    arquivo.close();
    
    nPegaPrimeiraLinha = true;
    

    arquivo.open("data.csv", ios::in);



    // construção da árvore avl, onde cada no tem chave sendo o primeiro nome da pessoa e os seus dados em um objeto pessoa
    if(!arquivo.is_open()){
        throw std::runtime_error ("Error");
        }
    
    
    
    while( getline(arquivo, linha)){
        
        if(nPegaPrimeiraLinha==true){
            getline(arquivo,linha);
            nPegaPrimeiraLinha = false;
        }
        dados.clear();
        stringstream s_stream(linha);
        while( s_stream.good() ){
            string substr;
            getline(s_stream, substr, ',');
            dados.push_back(substr);;
            
        }
        
        pessoa.set_cpf(dados[0]);
        pessoa.set_nome(dados[1]);
        pessoa.set_sobrenome(dados[2]);
        pessoa.set_dataNascimento(dados[3]);
        pessoa.set_cidade_nasc(dados[4]);
        
        
        raiz_nome = arv_nome.avl_insert(raiz_nome,dados[1],pessoa);
        
    }


    ////Fechando o arquivo data.csv
    arquivo.close();
    

    nPegaPrimeiraLinha = true;

 
    
    
    //bool nPegaPrimeiraLinha3 = true;
    
    arquivo.open("data.csv", ios::in);

    

    // construção da árvore avl, onde cada no tem chave sendo o primeiro nome da pessoa e os seus dados em um objeto pessoa
    if(!arquivo.is_open()){
        throw std::runtime_error ("Error");
        }
    
    
    
    while( getline(arquivo, linha)){
        
        if(nPegaPrimeiraLinha==true){
            getline(arquivo,linha);
            nPegaPrimeiraLinha = false;
        }
        dados.clear();
        stringstream s_stream(linha);
        while( s_stream.good() ){
            string substr;
            getline(s_stream, substr, ',');
            dados.push_back(substr);
            
        }
        
    
        pessoa.set_cpf(dados[0]);
        pessoa.set_nome(dados[1]);
        pessoa.set_sobrenome(dados[2]);
        pessoa.set_dataNascimento(dados[3]);
        pessoa.set_cidade_nasc(dados[4]);
        
 

        
        long int somaTUDO = pessoa.converte_ano(dados[3]) * 10000 + pessoa.converte_mes(dados[3]) * 100 + pessoa.converte_dia(dados[3]);

        raiz_data = arv_data.avl_insert(raiz_data,somaTUDO ,pessoa);
        
    }

    
    arquivo.close();
    
  
    bool menu_ativo = true;                         //deixa o menu ativo


    //Opção do menu
    int num;

    //cpf
    long int cpf_user;

    //nome
    string nome_user;
    
    //data
    string data_user_i, data_user_f;
    long int peso_i, peso_f;

    //escolha da arvore para percorrer em ordem
    int escolha_arvore;


    while (menu_ativo){
        
        imprime_menu();
        cin >> num;
        switch (num)
        {
        case 1: //Pesquisa pelo CPF
            
            cout << "Digite o cpf que deseja buscar no seguinte formato: xxxxxxxxxxx | exemplo: 38862473257 " << "\n"
            << "O programa aceita apenas os números do cpf!" << endl;
            
            cin >> cpf_user;
            arv_cpf.avl_imprime_csv(raiz_cpf, cpf_user);
            
            break;
        
        case 2: //Pesquisa pelo Nome
            cout <<"Escreva o primeiro nome das pessoas que deseja buscar: ";
            cin >> nome_user;   
            arv_nome.search_repetido(raiz_nome, nome_user);
            break;
            
        case 3: //Pesquisa pelo Intervalo da data de nasc
            cout <<"Digite o mes, dia e ano respectivamente no formato MM/DD/AAAA do intervalo\n";
            cin >> data_user_i;
            cout <<"Digite o mes, dia e ano respectivamente no formato MM/DD/AAAA do outro intervalo\n";
            cin >> data_user_f;

            //Conversão das datas de string para long int
            peso_i = pessoa.converte_ano(data_user_i) * 10000 + pessoa.converte_mes(data_user_i) * 100 + pessoa.converte_dia(data_user_i);
            peso_f = pessoa.converte_ano(data_user_f) * 10000 + pessoa.converte_mes(data_user_f) * 100 + pessoa.converte_dia(data_user_f);

            if(peso_i < 0 || peso_f < 0){
                cout << endl << "\t\t>>> FORMATO DE DATA INVALIDO <<<\n";  //Erro caso o numero de caracteres for diferente do formato
            }


            arv_data.avl_intervalo(raiz_data, peso_i, peso_f);
            break;
           
        case 4: //Imprime todos os dados em ordem de uma arvore escolhida
            cout << "\tinsira a arvore que quer percorrer\n1:CPF 2:Nome 3: Data de nasc\n";
            cin >> escolha_arvore;

            switch (escolha_arvore)
            {
            case 1:
                arv_cpf.avl_in_ordem(raiz_cpf);     //Imprime todos os dados da arvore CPF
                break;

            case 2:
                arv_nome.avl_in_ordem(raiz_nome);   //Imprime todos os dados da arvore nome
                break;

            case 3:
                arv_data.avl_in_ordem(raiz_data);   //Imprime todos os dados da arvore data
                break;
            
            default:
                cout << "\n\t >> NUMERO INVALIDO <<\n";
                break;
            }
            
            break;

            
        case 0:
            menu_ativo = false;
            cout << "arvores esvaziadas\nfinalizado\n";
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