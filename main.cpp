#include <iostream>
#include "avl.h" 
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
    
    Pessoa eu(12345678910,"João", "Almir", 17,10,2020, "Guarulhos");
    Pessoa outro(82945178510,"Fulano", "Silva",17,10,2010,  "Rio de janeiro");
    Pessoa corona(12345678910,"Corona", "Virus", 27,2,2020, "Mundo todo");
    Pessoa falstao(12345678910,"Falstão", "tão", 9,9,1961, "Rio de janeiro");
    Pessoa seu(12345678910,"Seu", "Creysson", 1,5,1975, "Lugar lá");
    Pessoa atilio(92541608361,"Atilio", "Luis", 20,10,1985, "Fortaleza");
    Pessoa alysson(92541608361,"Alysson", "Luis", 20,10,1985, "Fortaleza");
    
    //avl<long long int> cpf_avl(eu.get_cpf(), eu);
    //avl<string> nome_avl(eu.get_nome(), eu);
    avl<int> teste(2484,eu);
    Node<int>* raiz1=nullptr;
    
    

    raiz1 = teste.avl_insert(raiz1, 60 , corona); 
    raiz1 = teste.avl_insert(raiz1, 50 , falstao); 
    raiz1 = teste.avl_insert(raiz1, 40 , seu);
    raiz1 = teste.avl_insert(raiz1, 30  , atilio);
    raiz1 = teste.avl_insert(raiz1, 20 ,  alysson);
    raiz1 = teste.avl_insert(raiz1, 10 ,  alysson);
    raiz1 = teste.avl_insert(raiz1, 60 ,  alysson);
    raiz1 = teste.avl_insert(raiz1, 60 ,  alysson);
    raiz1 = teste.avl_insert(raiz1, 40 ,  alysson);
    teste.avl_pre_ordem(raiz1);
    raiz1 = teste.clear(raiz1);
    

    //teste.mainInsert(teste.get_raiz(),outro.get_nome(), outro); 
    //teste.mainInsert(14, corona); 
    //teste.mainInsert(53, falstao); 
    //teste.mainInsert(40, seu);
    //teste.mainInsert(12, atilio);
    //teste.mainInsert(1, alysson);
    //teste.avl_pre_ordem(teste.get_raiz());

    //teste.mainInsert(teste.get_raiz(),eu.get_nome(),eu);
        

    return 0;

}