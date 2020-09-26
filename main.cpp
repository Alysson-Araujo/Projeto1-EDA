#include <iostream>
#include "avl.h" 
#include "pessoa.h"     
#include <fstream>
#include <string>
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
      
    
        
        
        menu(); //volta para o menu
        break;

    case 2:                             //Remover pessoa pelo nome



        
        menu(); //volta para o menu
        break;
    
    case 3:                             //Remover pessoa pelo CPF


       
        menu(); //volta para o menu
        break;

    case 4:                             //Remover pessoa pela data de nasc


        menu(); //volta para o menu
        break;
    
    case 5:                             //Percurso pre-ordem



        
        menu(); //volta para o menu
        break;
    

    case 6:                             //Percurso em-ordem


      
        menu(); //volta para o menu
        break;

    case 7:                             //Percurso pos-ordem




        
        menu(); //volta para o menu
        break;
    
    case 8:                             //Buscar pessoa pelo nome



        menu(); //volta para o menu
        break;
    
    
    case 9:                            //Buscar pessoa pelo CPF



        menu(); //volta para o menu
        break;
    
    
    case 10:                            //Buscar pessoa pela data de nasc




        
        menu(); //volta para o menu
        break;
       

    case 0:                             //Finaliza o programa


        cout<<"Árvores esvaziadas"<< endl;
        cout<<"Finalizado" << endl;
        break;

    default:                           //numero invalido

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
    avl<string> teste;
    Node<string>* raiz1=nullptr;
    
    
    

    //raiz1 = teste.avl_insert(raiz1, "Alysson Araújo",  corona); 
    //raiz1 = teste.avl_insert(raiz1, "João Almir" ,  falstao); 
    //raiz1 = teste.avl_insert(raiz1, "Rafael Sousa" ,  seu);
    //raiz1 = teste.avl_insert(raiz1, "Gustavo Santos" ,  atilio);
    //raiz1 = teste.avl_insert(raiz1, "João Almir" ,  alysson);
    //raiz1 = teste.avl_insert(raiz1, "Wladimir Tavares" ,  alysson);
    //raiz1 = teste.avl_insert(raiz1, "Atílio Tavares" ,  alysson);
    //raiz1 = teste.avl_insert(raiz1, "Alysson Araújo" ,  alysson);
    //raiz1 = teste.avl_insert(raiz1, "João Almir" ,  alysson);
    ////raiz1 = teste.avl_insert(raiz1, 50 ,  alysson);
    //teste.avl_in_ordem(raiz1);
    ////teste.avl_in_ordem(raiz1);
    //raiz1 = teste.clear(raiz1);
    
    string linha;

    ifstream myfile ("data.csv"); // ifstream = padrão ios:in
  if (myfile.is_open())
  {
    while (! myfile.eof() ) //enquanto end of file for false continua
    {
      getline(myfile, linha); // como foi aberto em modo texto(padrão)
                             //e não binário(ios::bin) pega cada linha
      cout << linha << endl;
    }
    myfile.close();
  }
    //teste.mainInsert(teste.get_raiz(),outro.get_nome(), outro); 
    //teste.mainInsert(14, corona); 
    //teste.mainInsert(53, falstao); 
    //teste.mainInsert(40, seu);
    //teste.mainInsert(12, atilio);
    //teste.mainInsert(1, alysson);
    //teste.avl_pre_ordem(teste.get_raiz());

    
        

    return 0;

}