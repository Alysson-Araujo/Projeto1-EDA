#include <iostream>
#include "pessoa.h"

using std::string;
using std::cout;
using std::endl;
using std::to_string;


    Pessoa::Pessoa(long int cpf, string nome, string sobrenome, int nasc_dia, int nasc_mes, int nasc_ano, string cidade_nasc){

        this->cpf = cpf;
        this->nome = nome;
        this->sobrenome = sobrenome;
        this->nasc_dia = nasc_dia;
        this->nasc_mes = nasc_mes;
        this->nasc_ano = nasc_ano;
        this->cidade_nasc = cidade_nasc;
   
    }

    void Pessoa::imprime_csv(){

        cout << formato_cpf() << ","
             << nome << ","
             << sobrenome << ","
             << nasc_dia << "/"
             << nasc_mes << "/"
             << nasc_ano << ","
             << cidade_nasc << endl;

    }

    int Pessoa::mais_velho_que(Pessoa x){       //se a pessoa do parametro for mais velha retorna -1
                                                //se a pessoa do parametro for mais nova retorna 1
                                                //se as datas forem iguais retorna 0  
        if(nasc_dia == x.nasc_dia && nasc_mes == x.nasc_mes && nasc_ano == x.nasc_ano)    
        return 0;

        else if(nasc_ano < x.nasc_ano)
            return 1;

        else if(nasc_ano > x.nasc_ano)
            return -1;

        else if(nasc_mes < x.nasc_mes)          //compara datas com a pessoa do parametro
            return 1;

        else if(nasc_mes > x.nasc_mes) 
            return -1;
        
        else if(nasc_dia < x.nasc_dia)          
            return 1;
            
        else                                    
            return -1;

    }   



    string Pessoa::formato_cpf(){

        string aux = to_string(cpf);    //converte de int para string e guarda no aux

        int tam = 14;                   // cria int com tamanho 14

        char fmt[tam];                  //cria um vetor de char livre para colocar os numeros, pontos e traço

        int index = 0;                  //indice auxiliar
        
        for(int i = 0; i < tam; i++){

            if(i == 3 || i == 7)        //na posição 3 e 7 insere ponto
                fmt[i] = '.';

            else if(i == 11)            //na posição 11 insere traço
                fmt[i] = '-';

            else{
                fmt[i] = aux[index];    //nas outras posições insere os numeros
                index++;   

            }

        }


        return fmt;

    }



    //gets
    long int Pessoa::get_cpf(){
        return cpf;
    }

    string Pessoa::get_nome(){
        return nome;
    }
    
    string Pessoa::get_sobrenome(){
        return sobrenome;
    }

    int Pessoa::get_nasc_dia(){
        return nasc_dia;
    }

    int Pessoa::get_nasc_mes(){
        return nasc_mes;
    }

    int Pessoa::get_nasc_ano(){
        return nasc_ano;
    }

    string Pessoa::get_cidade_nasc(){
        return cidade_nasc;
    }
