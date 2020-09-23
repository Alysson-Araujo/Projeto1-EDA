#include <iostream>
//#include "avl.h"    <-  Comentado para testes no menu
#include "pessoa.h"     
using std::cout;
using std::endl;
using std::cin;
using std::string;


void imprime_menu(){                                    //imprime o menu

    cout << "------------------------------" << endl;
    cout << "          ARVORE AVL" << endl;
    cout << "------------------------------" << endl;
    cout << "1: Inserir pessoa" << endl;
    cout << "2: Remover pessoa pelo nome" << endl;
    cout << "3: Remover pessoa pelo CPF" << endl;
    cout << "4: Remover pessoa pela data de nasc" << endl;
    cout << "5: Percurso pre-ordem" << endl;
    cout << "6: Percurso em-ordem" << endl;
    cout << "7: Percurso pos-ordem" << endl;
    cout << "8: Buscar pessoa pelo nome" << endl;
    cout << "9: Buscar pessoa pelo CPF" << endl;
    cout << "10: Buscar pessoa pela data de nasc" << endl;
    cout << "0: Sair" << endl;                          //Provavelmente precisará de mais opções
    cout << "       Escolha um numero:";
}
/*
       Inserir raizes no parâmetro futuramente
         |
         V
*/          
void menu(){                           //realiza as funçoes do menu
                                       //se a escolha NÃO for 0, repete recursivamente

    imprime_menu();                     //Imprime o menu
    
    int escolha;
    cin >> escolha;                     //entrada de escolha

    
    switch (escolha){
    
    case 1:                             //inserir pessoa
      
    
        
        /*  Inserir raizes no parâmetro futuramente
            |
            V    */ 
        menu(); //volta para o menu
        break;

    case 2:                             //Remover pessoa pelo nome



        /*  Inserir raizes no parâmetro futuramente
            |
            V    */ 
        menu(); //volta para o menu
        break;
    
    case 3:                             //Remover pessoa pelo CPF


        /*  Inserir raizes no parâmetro futuramente
            |
            V    */ 
        menu(); //volta para o menu
        break;

    case 4:                             //Remover pessoa pela data de nasc


        /*  Inserir raizes no parâmetro futuramente
            |
            V    */ 
        menu(); //volta para o menu
        break;
    
    case 5:                             //Percurso pre-ordem



        /*  Inserir raizes no parâmetro futuramente
            |
            V    */ 
        menu(); //volta para o menu
        break;
    

    case 6:                             //Percurso em-ordem


        /*  Inserir raizes no parâmetro futuramente
            |
            V    */ 
        menu(); //volta para o menu
        break;

    case 7:                             //Percurso pos-ordem




        /*  Inserir raizes no parâmetro futuramente
            |
            V    */ 
        menu(); //volta para o menu
        break;
    
    case 8:                             //Buscar pessoa pelo nome



        /*  Inserir raizes no parâmetro futuramente
            |
            V    */ 
        menu(); //volta para o menu
        break;
    
    
    case 9:                            //Buscar pessoa pelo CPF



        /*  Inserir raizes no parâmetro futuramente
            |
            V    */ 
        menu(); //volta para o menu
        break;
    
    
    case 10:                            //Buscar pessoa pela data de nasc




        /*  Inserir raizes no parâmetro futuramente
            |
            V    */ 
        menu(); //volta para o menu
        break;
       

    case 0:                             //Finaliza o programa


        cout<<"Árvores esvaziadas"<< endl;
        cout<<"Finalizado" << endl;
        break;

    default:                    //numero invalido

        cout << endl <<  "\t \t>>Número inválido<<" << endl;
        menu();

        break;
    
    }


}

int main(){
    
    //menu();
    
    Pessoa eu(12345678910,"João", "Almir", 17,10,2000, "Guarulhos");

    cout << eu.formato_cpf() << endl;
    
    eu.imprime_csv();
    
}