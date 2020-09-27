#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "node.h"
#include "pessoa.h"
using namespace std;


template<typename Tkey>
class avl
{
private:
    /* data */
    
    // Calcula a altura que a Árvore possui.
    int avl_height(Node<Tkey> *no);
    // Vai calcular o fator de balanceamento da árvore.
    int balancing_factor(Node<Tkey> *no);
    // Essa função fica responsável em fazer todas as rotações possíveis na árvore ALV para que ela se mantenha 
    // regulada
    Node<Tkey>* avl_balance(Node<Tkey> *no, Tkey key);
    // ######################################### Rotações #########################################

    Node<Tkey> *rightRotation(Node<Tkey> *no);

    Node<Tkey> *leftRotation(Node<Tkey> *no);

    Node<Tkey>* leftRight(Node<Tkey>* no);

    Node<Tkey>* rightLeft(Node<Tkey>* no);

    // ######################################### ######## #########################################

    //Cria um novo nó que será incluido na Árvore AVL.
    Node<Tkey>* create_node(Tkey key, Pessoa pes);

public:
    
    avl(); //cria a árvore
    ~avl(); // destrói a árvore
    
    //deletará todos os nós presente na arvore, passando a arvore a partir da sua raiz.
    Node<Tkey>* clear(Node<Tkey>* no);
    void search_repetido(Node<Tkey>* no, Tkey Key);
    

    // Impressão da árvore em pre-ordem (raiz->esq->dir).
    void avl_pre_ordem(Node<Tkey> *no);
    // Impressão da árvore em pos-ordem (esq->dir->raiz).
    void avl_pos_ordem(Node<Tkey> *no);
    // Impressão da árvore no estilo de ordemmain.cpp:
    // Faz a inserção de um nó na árvore AVL, onde nesse nó tera uma chave um valor do tipo string

    Node<Tkey>* avl_insert(Node<Tkey> *no, Tkey key, Pessoa pes);
    
    

    void avl_in_ordem(Node<Tkey> *no);
    void avl_search(Node<Tkey> *node,Tkey key);

    

};


template<typename Tkey>
avl<Tkey>::avl(){

}


// O método clear pecorre a árvore em sentido pré-ordem, deletando todos os nós no qual ele visita e, no fim, ele retorna nullptr
// para Node raiz criado main.cpp, assim limpando por completo a árvore.
template<typename Tkey>
Node<Tkey>* avl<Tkey>::clear(Node<Tkey> *no){
    
    if (no != nullptr){

        no->left = clear(no->left);
        no->right = clear(no->right);
        cout << "\nRemovendo chave " << no->key;
        delete no;

    }
    return nullptr;

}

template<typename Tkey>
avl<Tkey>::~avl(){
    //clear(raiz);

}

//Método na qual vai criar um novo nó para a árvore. Nela será contida uma chave e um objeto Pessoa que contém todos os dados de uma
// pessoa pega no arquivo data.csv. Vai retornar esse novo nó criado.
template<typename Tkey>
Node<Tkey>* avl<Tkey>::create_node(Tkey key, Pessoa pes){  
    Node<Tkey> *node = new Node<Tkey>;
    node->key = key;
    node->pes = pes;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}


// ######################################### Rotações e max #########################################

// Faz uma rotação a direita
template<typename Tkey>
Node<Tkey>* avl<Tkey>::rightRotation(Node<Tkey> *no){
        Node<Tkey>* aux;
        aux = no->left;
        no->left = aux->right;
        aux->right = no;
        
        // ###### atualzará as alturas dos nós ######
        no->height = std::max(avl_height(no->left), avl_height(no->right)) + 1;
        aux->height = std::max(avl_height(aux->left), avl_height(aux->right)) + 1;
        // ###### ############################ ######

        return aux;
}

template<typename Tkey>
Node<Tkey>* avl<Tkey>::leftRotation(Node<Tkey> *no){
        Node<Tkey> *aux = no->right;
        no->right = aux->left;
        aux->left = no;
        // ###### atualzará as alturas dos nós ######
        no->height = 1 + max(avl_height(no->left),
                            avl_height(no->right));
        aux->height = 1 + max(avl_height(aux->left),
                            avl_height(aux->right));
        // ###### ############################ ######                    
        return aux; // nova raiz
}

    //Rotação dupla a esquerda. // Acho que os nomes estão trocados
    template<typename Tkey>
    Node<Tkey>* avl<Tkey>::rightLeft(Node<Tkey>* no){
        no->right = rightRotation(no->right);
        return leftRotation(no);
    }

    //Rotação dupla a esquerda.
    template<typename Tkey>
    Node<Tkey>* avl<Tkey>::leftRight(Node<Tkey>* no){
        no->left = leftRotation(no->left);
        return rightRotation(no);
    }


// ##################################################################################################




// Fator de balanceamento, onde o seu resultado é fazer subtração da altura do nó direito com a altura do nó
// esquerdo.  
// O fator de balanceamento tem que ser somente -1, 0 ou 1.
template<typename Tkey>
int avl<Tkey>::balancing_factor (Node<Tkey> *node) {
     if(node == nullptr ){
        return 0;
    }
    return avl_height (node -> right) - avl_height (node ->left);
}


// Essa função fica responsável em fazer todas as rotações possíveis na árvore ALV para que ela se mantenha 
// regulada
// O fator de balanceamento tem que ser somente -1, 0 ou 1.
template<typename Tkey> 
Node<Tkey>* avl<Tkey>::avl_balance(Node<Tkey> *no, Tkey key){
    // Rotação a direita. 
    // suponha que existe um nó desbalanceado b que tem um filho esquerdo x e o x tem  um filho esquerdo y, 
    // deixando o fator de balanceamento de b ser igual a -2. Para fazer o balanceamento, será preciso:
    /* faz uma rotação a direita no b
                            b                x
                           /                 / \
                          x       =>        y   b
                         /
                        y
    
    */
    if(balancing_factor(no) < -1 && key < no->left->key)
        return rightRotation(no);
    
    // rotação dupla a direita
    // suponha que existe um nó desbalanceado b que tem um filho esquerdo x e o x tem um filho direito y, 
    // deixando o fator de balanceamento de b ser igual a -2. Para fazer o balanceamento, será preciso:
    /* faz uma rotação a esquerda no x e uma rotação a direita no b

                            b                 b                    y
                           /                 /                    / \
                          x       =>        y          =>        x   b
                           \               /                        
                            y             x
    
    */
    
    else if(balancing_factor(no) < -1 && key >= no->left->key)
        return leftRight(no);

    // Rotação a esquerda. 
     
    // suponha que existe um nó desbalanceado b que tem um filho direito x e o x tem um filho direito y, 
    // deixando o fator de balanceamento de b ser igual a 2. Para fazer o balanceamento, será preciso:
    /* faz uma rotação a esquerda no b
                            b                 x
                             \               / \
                              x       =>    b   y
                               \
                                y
    */
    else if(balancing_factor(no) > 1 && key >= no->right->key )
        return leftRotation(no);
    
    // Rotação dupla a esquerda
    
    // suponha que existe um nó desbalanceado b que tem um filho direito x e o x tem um filho esquerdo y, 
    // deixando o fator de balanceamento de b ser igual a 2. Para fazer o balanceamento, será preciso:
    /* fazer uma rotação a direita no x e uma rotação a esquerda no b

                        b                 b                     y
                         \                 \                   / \
                          x       =>        y         =>      b   x
                         /                   \                   
                        y                     x
    
    */
    else if(balancing_factor(no) > 1 && key < no->right->key)
        return rightLeft(no);       
    
    return no;
}


//##############################################################

//      Funções para percorrer e imprimir a árvore em ordem definida

template<typename Tkey>        //(raiz,esq,dir)
void avl<Tkey>::avl_pre_ordem(Node<Tkey> *no){
    if (no != nullptr) {        
        std::cout << "Chave " << no->key << ", " << "Valor "<< no->pes.get_cpf() << std::endl;
        avl_pre_ordem(no ->left);
        avl_pre_ordem(no ->right);
    }

}

template<typename Tkey>        //(esq,dir,raiz)
void avl<Tkey>::avl_pos_ordem(Node<Tkey> *no){
    if (no != nullptr) {
        avl_pos_ordem(no ->left);
        avl_pos_ordem(no ->right);
        cout << "Chave " << no->key <<endl;
    }
}


template<typename Tkey>       //(esq,raiz,dir)
void avl<Tkey>::avl_in_ordem(Node<Tkey> *no){
    if (no != nullptr) {
        avl_in_ordem(no ->left);
        std::cout << "Chave " << no->key << endl;
        avl_in_ordem(no ->right);
    }
}


//############################################################








template<typename Tkey>    //retorna a altura do nó, 0 caso a árvore esteja vazia
int avl<Tkey>::avl_height(Node<Tkey> *no){
    
    if (no == NULL)
        return 0;
    else
        return no->height;
}

template<typename Tkey>
void avl<Tkey>::avl_search(Node<Tkey> *node, Tkey key){

    if(node == NULL){                            //retorna NULL se não encontrar
        cout << "O seguinte CPF não foi encontrado:";
        //return;
    }
    if(key < node->key)
         avl_search(node->left, key);

    else if(key > node->key)
         avl_search(node->right, key);
    
    else{
        node->pes.imprime_csv();
            
    }
    //return key;
}


/*
template<typename Tkey>
Node<Tkey>* avl<Tkey>::avl_insert(Node<Tkey> *no, Tkey key, Pessoa pes){
     /*
     * Caso base: na primeira verificação, se o no == nullptr retornar true, significa que estamos na raiz e
     * ela está vazia, logo iremos colocar os valores nela.
     * 
     * Se for na segunda ou posteriores verificações, significa que iremos adicionar uma nova folha com os 
     * valores passados nos parâmetros da função.
    
    if(no == nullptr){
        return create_node(key, pes);
    }
    // Vereficará se o valor da key passada é maior que a chave do nó atual 
        if(key < no->key){
            no->left = avl_insert(no->left, key, pes);
            //Será verificado se é preciso fazer alguma rotação para deixar balanceada. 
            no = avl_balance(no, key); //*** ocorreu Problema no balanceamento
        }
        
        
        
        
        // Vereficará se o valor da key passada é menor que a chave do nó atual 
        if(key >= no->key){
            no->right = avl_insert(no->right, key, pes);
            //Será verificado se é preciso fazer alguma rotação para deixar balanceada.
            no = avl_balance(no, key); //*** ocorreu Problema no balanceamento
            // quando a key já está presente na árvore.
        }
    // Vai corrigir a altura da árvore
    no->height = 1 + std::max(avl_height(no->left), avl_height(no->right));
    
    

    return no;
}
*/
template<typename Tkey>
Node<Tkey>* avl<Tkey>::avl_insert(Node<Tkey> *p, Tkey key, Pessoa pes){         //insere um novo nó

    if (p == NULL)
        return create_node(key, pes);
    if (key < p->key)
        p->left = avl_insert(p->left, key, pes);
    else if (key >= p->key)
        p->right = avl_insert(p->right, key, pes);
    else
        return p; 

    // atualiza altura deste ancestral p
    p->height = 1 + std::max(avl_height(p->left), avl_height(p->right));

    p = avl_balance(p, key); // Regula o nó

    return p; // 
}




//############################################################



//Como existem pessoas que podem ter nomes ou datas de nascimento repetidas, a busca de todas as pessoas que possuem tal nome ou data de 
//nascimento iguais nas chaves dos nós vai significar em que elas podem está tanto na subárvore esquerda quanto na subárvore direita
//da raiz devido as rotações feitas para deixar a árvore balanceada. Nesse caso precisaremos buscar em toda a árvore para pegar todos
//os dados de uma ou mais pessoa(s) pelo seu nome ou sua data de nascimento. O motivo de fazermos isso é devido a testes nos quais
// fizemos onde inserimos algumas chaves repetidas menores que a raiz em uma arvore avl, e as rotações para manter a árvore balanceada
// chegou a mandar chaves repetidas da subárvore esquerda da raiz para a subárvore direita da raiz, mas mantendo o seu balanceamento. 
// Para analizar melhor essa situação, fizemos a visualização da árvore em pré-ordem, pós-ordem e em in-ordem(ordem simétrica) e 
// vimos que as três estavam mostrando as chaves dos nós de forma corretamente.
template<typename Tkey>
void avl<Tkey>::search_repetido(Node<Tkey>* no, Tkey key){
    if (no != nullptr) {
        if(no->key == key){
            cout << "Chave " << no->key << endl;
            //no->pes.imprime_csv();
            no->pes.imprime_csv();
        
            search_repetido(no ->left,key);
            search_repetido(no ->right, key);
        }
        else{
            search_repetido(no ->left,key);
            search_repetido(no ->right, key);
        }
        
    }
}

#endif
