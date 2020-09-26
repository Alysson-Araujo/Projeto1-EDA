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
    cout << "4: Percurso pre-ordem" << endl;
    cout << "5: Percurso em-ordem" << endl;
    cout << "6: Percurso pos-ordem" << endl;
    cout << "7: Buscar pessoa pelo nome" << endl;
    cout << "8: Buscar pessoa pelo CPF" << endl;
    cout << "0: Sair" << endl;                          //Provavelmente precisará de mais opções
    cout << "\t\tEscolha um numero:";
}



int main(){
    
    
    avl<string> arv_cpf();
    avl<long long int> arv_nome();
    avl<int> arv_ano();

    Node<string>* raiz_cpf=NULL;
    Node<long long int>* raiz_nome=NULL;
    Node<int>* raiz_ano=NULL;

    Pessoa eu(12345678910,"João","Almir",17,10,2000,"Guarulhos");

    
    
    bool menu_ativo = true;                         //deixa o menu ativo

    long long int cpf;                              //
    string nome, sobrenome;                         //variaveis para usar no menu;
    int data_dia, data_mes, data_ano;               //

    int escolha;                                     //para escolher no menu

    int ordem;                                      //para escolher a arvore da ordem

    while(menu_ativo == true){

        imprime_menu();

        cin >> escolha;
        
        switch (escolha){
        
        case 1:                             //inserir pessoa
            
            cout << "\n\t\tadicionando pessoa\n\n";                     //
                                                                        //
            cout << "\ninsira o cpf (11 digitos)\n";                    //
            cin >> cpf;                                                 //
                                                                        //                                            
            cout << "\ninsira o nome\n";                                //                
            cin >> nome;                                                //
                                                                        //
            cout << "\ninsira o sobrenome\n";                           //    entradas da pessoa                  
            cin >> sobrenome;                                           //  
                                                                        //
                                                                        //
            cout << "\ninsira o dia da data de nascimeto \n";           //                                  
            cin >> data_dia;                                            //  
                                                                        //
            cout << "\ninsira o mes da data de nascimeto \n";           //                                  
            cin >> data_mes;                                            //  
                                                                        //
            cout << "\ninsira o ano da data de nascimeto \n";           //                                  
            cin >> data_ano;                                            //  


            //Pessoa nova(cpf,nome,sobrenome,data_dia,data_mes,data_ano); nova pessoa para inserir na arvore
            //to em duvida se vai precisar de new na pessoa
            
            //arv_cpf.mainInsert(raiz_cpf,cpf,nova);
            //avl<string>::arv_nome.mainInsert(raiz_nome,nome,nova);   inserts na arvore
            //raiz_ano = raiz_ano.avl_insert(raiz_ano, data_ano,  nova);
            
            // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            //tentei inserir dessas 3 formas e nenhum tem a sintaxe certa

            cout << nome << " Criado\n\n";
            
            
            break;

        case 2:                             //Remover pessoa pelo nome
            cout << "insira o nome da pessoa que quer remover \n";
            cin >> nome;





            cout << nome << " removido\n";            
            break;
        
        case 3:                             //Remover pessoa pelo CPF
            cout << "insira CPF da pessoa que quer remover (11 digitos) \n";
            cin >> cpf;

        
            


            cout << cpf << " removido\n";
            break;

       
        
        case 4:                             //Percurso pre-ordem
            cout << "\nescolha a arvore para percorrer\n";
            cout << "1: CPF\n2: Nome\n3: Data de nasc\n";
            cin >> ordem;
            if(ordem == 1){



            }
            else if(ordem == 2){



            }   
            else if(ordem == 3){



            }
            else{
                cout << "numero invalido";
            }
            

        
            break;
        

        case 5:                             //Percurso em-ordem

            cout << "\nescolha a arvore para percorrer\n";
            cout << "1: CPF\n2: Nome\n3: Data de nasc\n";
            cin >> ordem;
            if(ordem == 1){



            }
            else if(ordem == 2){



            }   
            else if(ordem == 3){



            }
            else{
                cout << "\nnumero invalido\n";
            }
            

            
            break;

        case 6:                             //Percurso pos-ordem

            cout << "\nescolha a arvore para percorrer\n";
            cout << "1: CPF\n2: Nome\n3: Data de nasc\n";
            cin >> ordem;
            if(ordem == 1){



            }
            else if(ordem == 2){



            }   
            else if(ordem == 3){



            }
            else
                cout << "\nnumero invalido\n";
            

            
            
            break;
        
        case 7:                             //Buscar pessoa pelo nome
            cout << "\ninsira o nome\n";
            cin >>nome;




            break;
        
        
        case 8:                              //Buscar pessoa pelo CPF
            cout << "\ninsira o CPF\n";
            cin >> cpf;

        


            
            break;
        
        

        case 0:                             //Finaliza o programa

            //arv_cpf.clear(raiz_cpf);
            //arv_nome.clear(raiz_cpf);
            //arv_ano.clear(raiz_ano);
            

            cout<<"Árvores esvaziadas"<< endl;
            cout<<"Finalizado" << endl;
            menu_ativo = false;
            break;

        default:                           //numero invalido

            cout << endl <<  "\t \t>>Número inválido<<" << endl;

            break;
        
        }


    }


    


















    /*
    Pessoa eu(12345678910,"João", "Almir", 17,10,2020, "Guarulhos");
    Pessoa outro(82945178510,"Fulano", "Silva",17,10,2010,  "Rio de janeiro");
    Pessoa corona(12345678910,"Corona", "Virus", 27,2,2020, "Mundo todo");
    Pessoa falstao(12345678910,"Falstão", "tão", 9,9,1961, "Rio de janeiro");
    Pessoa seu(12345678910,"Seu", "Creysson", 1,5,1975, "Lugar lá");
    Pessoa atilio(92541608361,"Atilio", "Luis", 20,10,1985, "Fortaleza");
    Pessoa alysson(92541608361,"Alysson", "Luis", 20,10,1985, "Fortaleza");
    */
    //avl<long long int> cpf_avl(eu.get_cpf(), eu);
    //avl<string> nome_avl(eu.get_nome(), eu);
        

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
    /*
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

    */
    //teste.mainInsert(teste.get_raiz(),outro.get_nome(), outro); 
    //teste.mainInsert(14, corona); 
    //teste.mainInsert(53, falstao); 
    //teste.mainInsert(40, seu);
    //teste.mainInsert(12, atilio);
    //teste.mainInsert(1, alysson);
    //teste.avl_pre_ordem(teste.get_raiz());

       

    return 0;

}