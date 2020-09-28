#include <iostream>
#include "pessoa.h"
#include <string>
#include<sstream>
using namespace std;;
    //Contrutor
    Pessoa::Pessoa(){}
    //Contrutor
    Pessoa::Pessoa(string cpf, string nome, string sobrenome, string dataNascimento, string cidade_nasc){

        this->cpf = cpf;
        this->nome = nome;
        this->sobrenome = sobrenome;
        this->dataNascimento = dataNascimento;
        this->cidade_nasc = cidade_nasc;
    }
    //Imprime todos os dados da pessoa
    void Pessoa::imprime_csv(){

        cout << cpf<< ","
             << nome << ","
             << sobrenome << ","
             << dataNascimento << ","
             << cidade_nasc << endl;

    }

    //recebe cpf, remove os pontos e traço, e retorna em long int
    long int Pessoa::to_long_int(string cpf){
        
        int index = 0;
        string nova;

        for(int i = 0; i< 14; i++){
            if (i == 3 || i== 7 || i == 11)
                continue;
            else{
                nova[index] = cpf[i];
                index++;
            }
                
        }
        
        return stol( nova );

    }

    //converte uma string data e retorna somente o mes como long int
    long int Pessoa::converte_mes(string x){
        char nova[2];

        if(x[1] == '/')         //se o segundo caractere for barra
            nova[0] = x[0];
        else{
            nova[0] = x[0];
            nova[1] = x[1];
        }
    
        if(x.size() <= 10 && x.size() >= 8)
            return stol( nova);
        else
            return -1;              //indica erro na quantidade de digitos
    }

    //converte uma string data e retorna somente o dia como long int
    long int Pessoa::converte_dia(string x){

        char nova[2];

        if(x[1] == '/' && x[3] == '/'){    //mes e dia com 1 digito
            nova[0] = x[2];
        }
        else if(x[1] == '/' && x[4] == '/'){    //dia com 1 digito e mes com 2
            nova[0] = x[2];
            nova[1] = x[3];
        }
        else if(x[2] == '/' && x[4] == '/'){   //dia com 2 digitos e mes com 1
            nova[0] = x[3];
        }
        else{                                  //dia e mes com 2 digitos
            nova[0] = x[3];
            nova[1] = x[4];
        }
        
        if(x.size() <= 10 && x.size() >= 8)
            return stol( nova);
        else
            return -1;          //indica erro na quantidade de digitos
    }

    
   //converte uma string data e retorna somente o ano como long int
   long int Pessoa::converte_ano(string x){
        char nova[4];   

        if(x.size() == 10){         //data com tamanho 10
            nova[0] = x[6];
            nova[1] = x[7];
            nova[2] = x[8];
            nova[3] = x[9];    
        }
        else if(x.size() == 9){      //data com tamanho 9
            nova[0] = x[5];
            nova[1] = x[6];
            nova[2] = x[7];
            nova[3] = x[8];   
        }
        else{
            nova[0] = x[4];          //data com tamanho 8
            nova[1] = x[5];
            nova[2] = x[6];
            nova[3] = x[7]; 
        }
        
        if(x.size() <= 10 && x.size() >= 8)
            return stol( nova);
        else
            return -1; //indica erro na quantidade de digitos
    }
    

    //gets
    string Pessoa::get_cpf(){
        return cpf;
    }

    string Pessoa::get_nome(){
        return nome;
    }
    
    string Pessoa::get_sobrenome(){
        return sobrenome;
    }



    string Pessoa::get_cidade_nasc(){
        return cidade_nasc;
    }

    //sets
    void Pessoa::set_cpf(string cpf) {this->cpf = cpf;}
    void Pessoa::set_nome(string nome){this->nome = nome;}
    void Pessoa::set_sobrenome(string sobrenome){this->sobrenome = sobrenome;}
    void Pessoa::set_cidade_nasc(string cidade_nasc){this->cidade_nasc = cidade_nasc;}
    void Pessoa::set_dataNascimento(string data){this->dataNascimento = data;}
