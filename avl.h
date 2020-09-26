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
    
    Node<Tkey>* fixup_node(Node<Tkey> *p, Tkey key);
    
    Node<Tkey>* allocateNode(Tkey key, Pessoa value);

    int balance(Node<Tkey> *node);

    //Cria um novo nó que será incluido na Árvore AVL.
    Node<Tkey>* create_node(Tkey key, Pessoa pes);

public:
    
    avl(); //cria a árvore
    ~avl();
    
    Node<Tkey>* clear(Node<Tkey>* no);

    //deletará todos os nós presente na arvore, passando a arvore a partir da sua raiz.
    //Node<Tkey>* avl_delete(Node<Tkey> *no);
    
    // Impressão da árvore em pre-ordem (raiz->esq->dir).
    void avl_pre_ordem(Node<Tkey> *no);
    // Impressão da árvore em pos-ordem (esq->dir->raiz).
    void avl_pos_ordem(Node<Tkey> *no);
    // Impressão da árvore no estilo de ordemmain.cpp:
    // Faz a inserção de um nó na árvore AVL, onde nesse nó tera uma chave um valor do tipo string

    Node<Tkey>* avl_insert(Node<Tkey> *no, Tkey key, Pessoa pes);
    
    void mainInsert(Tkey key, Pessoa pes);

    void avl_in_ordem(Node<Tkey> *no);
    Node<Tkey>* avl_search(Node<Tkey> *node,Tkey key);

    void insertMain(Tkey key, Pessoa pes);
    
    //retorna true caso a arvore esteja vazia e false caso contrário
    bool avl_empty();



    Node<Tkey>* get_raiz();

};


template<typename Tkey>
avl<Tkey>::avl(){

}


template<typename Tkey>
Node<Tkey>* avl<Tkey>::clear(Node<Tkey> *no){
    
    if (no != nullptr){

        no->left = clear(no->left);
        no->right = clear(no->right);
        cout << "\nRemovendo chave " << no->key << endl;
        delete no;

    }
    return nullptr;

}

template<typename Tkey>
avl<Tkey>::~avl(){
    //clear(raiz);

}

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
/*
template<typename Tkey>
void avl<Tkey>::mainInsert(Tkey key, Pessoa pes){
    avl_insert(raiz, key, pes);
}
*/

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
        // atualiza alturas dos nós
        no->height = 1 + max(avl_height(no->left),
                            avl_height(no->right));
        aux->height = 1 + max(avl_height(aux->left),
                            avl_height(aux->right));
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

//                Funções auxiliares
/*
template <typename Tkey>
Node<Tkey>* avl<Tkey>::get_raiz(){
    return raiz;
}
*/
/*
template<typename Tkey>    // retorna boleano, true caso a árvore esteja vazia
bool avl<Tkey>::avl_empty(){
    return( raiz == NULL);
}

*/

template<typename Tkey>    //retorna a altura do nó, 0 caso a árvore esteja vazia
int avl<Tkey>::avl_height(Node<Tkey> *no){
    
    if (no == NULL)
        return 0;
    else
        return no->height;
}
/*
template<typename Tkey>
Node<Tkey>* avl<Tkey>::search(Tkey key){
    // se a chave estiver na raiz, retorna o valor imediatamente
    if(raiz->pes.get_nome()==key){
        return raiz;    //complexidade O(1)
    }
    
    
    //A ideia desse método 
    Node<Tkey>* aux_minus = raiz->left; //Guarda o lado esquerdo da árvore
    Node<Tkey>* aux_plus = raiz->right; // Guarda o lado direito da árvore
    // fará a busca para o lado esquerdo da árvore caso a chave desejada seja menor do que a chave do no
    if(key <= aux_minus->key){// chave está no lado esquerdo da árvore
        while (aux_minus!=nullptr){
            if(aux_minus->key == key){ //Significa que foi achado a chave
                return aux_minus; // retorna o valor achado
            }
            else if(aux_minus->left->key <= key){ //Verifica se a chave a esquerda é menor ou igual a chave a ser buscada
                aux_minus = aux_minus->left; //desce para a esquerda
            }
            else if(aux_minus->right->key >= key){ //Verifica se a chave a direita é menor ou igual a chave a ser buscada
                aux_minus= aux_minus->right;//desce para a direita
            }
        }
    }       
    else if(key>=aux_plus->key){// chave está no lado direito da árvore
        while (aux_plus!=NULL){
            if(aux_plus->key ==key){ //Significa que foi achado a chave
                return aux_plus;// retorna o valor achado
            }
            else if(aux_plus->left->key <= key){//Verifica se a chave a esquerda é menor ou igual a chave a ser buscada
                aux_plus = aux_plus->left;//desce para a esquerda
            }
            else if(aux_plus->right->key >= key){//Verifica se a chave a direita é menor ou igual a chave a ser buscada
                aux_plus= aux_plus->right; //desce para a direita
            }
        }
    }


    
    cout << "A pessoa não foi encontrada.";
    return NULL;
}
*/

template<typename Tkey>
Node<Tkey>* avl<Tkey>::avl_search(Node<Tkey> *node, Tkey key){

    if(node == NULL)                            //retorna NULL se não encontrar
        return NULL;

    if(key < node->key)
        return avl_search(node->left, key);

    else if(key > node->key)
        return avl_search(node->right, key);
    
    else
        return node;

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
        return p; // não permite chaves repetidas

    // atualiza altura deste ancestral p
    p->height = 1 + std::max(avl_height(p->left), avl_height(p->right));

    p = avl_balance(p, key); // Regula o nó

    return p; // 
}

template<typename Tkey>
Node<Tkey>* avl<Tkey>::fixup_node(Node<Tkey> *p, Tkey key){                    //testa o balanço e realiza rotação se necessario

    int bal = balance(p); // obtém balanço de node
    // caso 4(a)
    if (bal < -1 && key < p->left->key)
        return rightRotation(p);

    // caso 4(b)
    else if (bal < -1 && key >= p->left->key){
        p->left = leftRotation(p->left);
        return rightRotation(p);
    }

    // simétrico do caso 4(a)
    else if (bal > 1 && key >= p->right->key)
        return leftRotation(p);

    // simétrico do caso 4(b)
    else if (bal > 1 && key < p->right->key){

        p->right = rightRotation(p->right);
        return leftRotation(p);

    }
    return p;
}

template<typename Tkey>
Node<Tkey>* avl<Tkey>::*allocateNode(Tkey key, Pessoa value){                 //aloca um novo node com os dados dos parâmetros

    Node<Tkey> *node = new Node<Tkey>;
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
template <typename Tkey>
int avl<Tkey>::balance(Node<Tkey> *node){                                   //retorna a diferença entre a altura dos filhos
    if (node == NULL)
        return 0;
    return avl_height(node->right) - avl_height(node->left);
}



//############################################################

/*
Comentei pq ainda não sei se uso essa forma para deletar a árvore ou uso outra forma

//Irá pecorrer toda a árvore, deletando todos os nós.
template<typename Tkey>
Node<Tkey>* avl_delete(Node<Tkey>* no){
    if(no!=NULL){
        no->left = avl_delete(no->left);
        no->right = avl_delete(no->right);
        std::cout << "excluindo o nó com chave " << no->key << " e com valor de " << no->value << std::endl;
        delete no;
    }
    return nullptr;
}
*/
#endif





