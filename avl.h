#include <iostream>
#include "node.h"
using namespace std;


template<typename Tkey, typename Tvalue>
class avl
{
private:
    /* data */
    // Calcula a altura que a Árvore possui.
    int avl_height(Node<Tkey,Tvalue> *no);
    // Vai calcular o fator de balanceamento da árvore.
    int balancing_factor(Node<Tkey,Tvalue> *no);
    // Essa função fica responsável em fazer todas as rotações possíveis na árvore ALV para que ela se mantenha 
    // regulada
    Node<Tkey,Tvalue>* avl_balance(Node<Tkey,Tvalue> *no, Tkey key);
    // ######################################### Rotações #########################################

    Node<Tkey,Tvalue> *rightRotation(Node<Tkey,Tvalue> *no);

    Node<Tkey,Tvalue> *leftRotation(Node<Tkey,Tvalue> *no);

    Node<Tkey,Tvalue>* leftRight(Node<Tkey,Tvalue>* no);

    Node<Tkey,Tvalue>* rightLeft(Node<Tkey,Tvalue>* no);
    
    
    //Cria um novo nó que será incluido na Árvore AVL.
    Node<Tkey,Tvalue>* create_node(Tkey key, Tvalue value);

public:
    avl(/* args */); //cria a árvore
    ~avl();
    
    //deletará todos os nós presente na arvore, passando a arvore a partir da sua raiz.
    Node<Tkey,Tvalue>* avl_delete(Node<Tkey,Tvalue> *no);
    
    // Impressão da árvore em pre-ordem (raiz->esq->dir).
    void avl_pre_ordem(Node<Tkey,Tvalue> *no);
    // Impressão da árvore em pos-ordem (esq->dir->raiz).
    void avl_pos_ordem(Node<Tkey,Tvalue> *no);
    // Impressão da árvore no estilo de ordem simétrica (esq->raiz->dir).
    void avl_in_ordem(Node<Tkey,Tvalue> *no);

    // irá pegar a chave de um nó e retornará o seu valor correspondente.
    // RValue = Return Value
    Tvalue get_key_RValue(Node<Tkey,Tvalue> *no, Tkey key);
    // Faz a inserção de um nó na árvore AVL, onde nesse nó tera uma chave um valor do tipo string
    Node* avl_insert(Node *no,Tkey key, Tvalue value);

    //retorna true caso a arvore esteja vazia e false caso contrário
    bool avl_empty(Node<Tkey,Tvalue>* no);

};


template<typename Tkey, typename Tvalue>
avl<Tkey,Tvalue>::avl(){
    return nullptr;
}

template<typename Tkey, typename Tvalue>
avl<Tkey,Tvalue>::~avl(){
    if(no!=NULL){
        no->left = avl_delete(no->left);
        no->right = avl_delete(no->right);
        std::cout << "excluindo o nó com chave " << no->key << " e com valor de " << no->value << std::endl;
        delete no;
    }
    return nullptr;
}

template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue>* create_node(Tkey &key, Tvalue &value){  
    Node<Tkey,Tvalue> *node = new Node<Tkey,Tvalue>;
    this.node->key = key;
    this.node->value = value;
    this.node->left = nullptr;
    this.node->right = nullptr;
    this.node->height = 1;
    return node;
}



// ######################################### Rotações e max #########################################

// Faz uma rotação a direita
template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue> *rightRotation(Node<Tkey,Tvalue> *no){
        Node* aux;
        aux = no->left;
        no->left = aux->right;
        aux->right = no;
        
        // ###### atualzará as alturas dos nós ######
        no->height = max(avl_height(no->left), avl_height(no->right)) + 1;
        aux->height = max(avl_height(aux->left), avl_height(aux->right)) + 1;
        // ###### ############################ ######

        return aux;
    }


//Rotação dupla a esquerda.
template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue>* rightLeft(Node<Tkey,Tvalue>* no){
    no->right = rightRotation(no->right);
    return leftRotation(no);
}

// ##################################################################################################




// Fator de balanceamento, onde o seu resultado é fazer subtração da altura do nó direito com a altura do nó
// esquerdo.  
// O fator de balanceamento tem que ser somente -1, 0 ou 1.
template<typename Tkey, typename Tvalue> 
int balancing_factor (Node<Tkey,Tvalue> *node) {
     if(node == nullptr ){
        return 0;
    }
    return avl_height (node -> right) - avl_height (node ->left);
}


// Essa função fica responsável em fazer todas as rotações possíveis na árvore ALV para que ela se mantenha 
// regulada
// O fator de balanceamento tem que ser somente -1, 0 ou 1.
template<typename Tkey, typename Tvalue> 
Node<Tkey,Tvalue>* avl_balance(Node<Tkey,Tvalue> *no, Tkey key){
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
    
    else if(balancing_factor(no) < -1 && key > no->left->key)
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
    else if(balancing_factor(no) > 1 && key > no->right->key )
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

//      Funções para percorrer a árvore em ordem definida

template<typename Tkey, typename Tvalue>        //(raiz,esq,dir)
void avl_pre_ordem(Node<Tkey,Tvalue> *no){
    if (no != nullptr) {        
        std::cout << "Chave " << no->key << ", " << "Valor "<< no->value << std::endl;
        avl_pre_ordem(no ->left);
        avl_pre_ordem(no ->right);
    }

}

template<typename Tkey, typename Tvalue>        //(esq,dir,raiz)
void avl_pos_ordem(Node<Tkey,Tvalue> *no){
    if (no != nullptr) {
        avl_pos_ordem(no ->left);
        avl_pos_ordem(no ->right);
        std::cout << "Chave " << no->key << ", " << "Valor "<< no->value << std::endl;
    }
}


template<typename Tkey, typename Tvalue>       //(esq,raiz,dir)
void avl_in_ordem(Node<Tkey,Tvalue> *no){
    if (no != nullptr) {
        avl_in_ordem(no ->left);
        std::cout << "Chave " << no->key << ", " << "Valor "<< no->value << std::endl;
        avl_in_ordem(no ->right);
    }
}


//############################################################

//                Funções auxiliares

template<typename Tkey, typename Tvalue>    //
bool avl_empty(Node<Tkey,Tvalue>* no){
    return(no == NULL);
}

//############################################################

/*
Comentei pq ainda não sei se uso essa forma para deletar a árvore ou uso outra forma

//Irá pecorrer toda a árvore, deletando todos os nós.
template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue>* avl_delete(Node<Tkey,Tvalue>* no){
    if(no!=NULL){
        no->left = avl_delete(no->left);
        no->right = avl_delete(no->right);
        std::cout << "excluindo o nó com chave " << no->key << " e com valor de " << no->value << std::endl;
        delete no;
    }
    return nullptr;
}
*/
