#include <iostream>
#include "node.h"
#include "pessoa.h"
using namespace std;


template<typename Tkey>
class avl
{
private:
    /* data */
    Node<Tkey>* root;
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
    
    Node<Tkey>* clear(Node<Tkey>* no);
    


    //Cria um novo nó que será incluido na Árvore AVL.
    Node<Tkey>* create_node(Tkey key);

public:
    
    avl(Pessoa x); //cria a árvore
    ~avl();
    
    

    //deletará todos os nós presente na arvore, passando a arvore a partir da sua raiz.
    //Node<Tkey>* avl_delete(Node<Tkey> *no);
    
    // Impressão da árvore em pre-ordem (raiz->esq->dir).
    void avl_pre_ordem(Node<Tkey> *no);
    // Impressão da árvore em pos-ordem (esq->dir->raiz).
    void avl_pos_ordem(Node<Tkey> *no);
    // Impressão da árvore no estilo de ordem simétrica (esq->raiz->dir).
    void avl_in_ordem(Node<Tkey> *no);

    Pessoa get_pessoa(Node<Tkey> *no);

    Node<Tkey>* get_raiz();

    Node<Tkey>* search(Tkey key);

    // Faz a inserção de um nó na árvore AVL, onde nesse nó tera uma chave um valor do tipo string
    Node<Tkey>* avl_insert(Node<Tkey> *no,Tkey key);

    //retorna true caso a arvore esteja vazia e false caso contrário
    bool avl_empty();


};


template<typename Tkey>
avl<Tkey>::avl(Pessoa x){
    Node<Tkey> *NewNode = new Node<Tkey>;
    NewNode->pes = x;
    NewNode->left = nullptr;
    NewNode->right = nullptr;
    NewNode->height = 1;
    root = NewNode;
}
/*
RBTree ::RBTree()
{
    nil = new Node{};
    nil->key = 0;
    nil->left = nil->right = nil->parent = nil;
    nil->color = BLACK;
    root = nil;
}

// Destructor
RBTree ::~RBTree(){   
    clear(root);
        
    root = nullptr;
        
}


Node* RBTree::clear(Node *node){                    //remove a arvore enquanto desaloca memória
    

    if (node != nil){

        node->left = clear(node->left);
        node->right =clear(node->right);
        cout << "Removendo chave " << node->key << endl;
        delete node;

    }
    return nil;
}


*/


template<typename Tkey>
Node<Tkey>* avl<Tkey>::clear(Node<Tkey> *no){
    
    if (no != nullptr){

        no->left = clear(no->left);
        no->right =clear(no->right);
        cout << "Removendo chave " << no->pes.get_nome() << endl;
        delete no;

    }
    return NULL;

}

template<typename Tkey>
avl<Tkey>::~avl(){
    clear(root);

    root = nullptr;
}

template<typename Tkey>
Node<Tkey>* create_node(Tkey &key, Pessoa pes){  
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
Node<Tkey> *rightRotation(Node<Tkey> *no){
        Node<Tkey>* aux;
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
template<typename Tkey>
Node<Tkey>* rightLeft(Node<Tkey>* no){
    no->right = rightRotation(no->right);
    return leftRotation(no);
}

// ##################################################################################################




// Fator de balanceamento, onde o seu resultado é fazer subtração da altura do nó direito com a altura do nó
// esquerdo.  
// O fator de balanceamento tem que ser somente -1, 0 ou 1.
template<typename Tkey>
int balancing_factor (Node<Tkey> *node) {
     if(node == nullptr ){
        return 0;
    }
    return avl_height (node -> right) - avl_height (node ->left);
}


// Essa função fica responsável em fazer todas as rotações possíveis na árvore ALV para que ela se mantenha 
// regulada
// O fator de balanceamento tem que ser somente -1, 0 ou 1.
template<typename Tkey> 
Node<Tkey>* avl_balance(Node<Tkey> *no, Tkey key){
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

//      Funções para percorrer e imprimir a árvore em ordem definida
/*
template<typename Tkey>        //(raiz,esq,dir)
void avl_pre_ordem(Node<Tkey> *no){
    if (no != nullptr) {        
        std::cout << "Chave " << no->key << ", " << "Valor "<< no->pes << std::endl;
        avl_pre_ordem(no ->left);
        avl_pre_ordem(no ->right);
    }

}

template<typename Tkey>        //(esq,dir,raiz)
void avl_pos_ordem(Node<Tkey> *no){
    if (no != nullptr) {
        avl_pos_ordem(no ->left);
        avl_pos_ordem(no ->right);
        std::cout << "Chave " << no->key << ", " << "Valor "<< no->value << std::endl;
    }
}


template<typename Tkey>       //(esq,raiz,dir)
void avl_in_ordem(Node<Tkey> *no){
    if (no != nullptr) {
        avl_in_ordem(no ->left);
        std::cout << "Chave " << no->key << ", " << "Valor "<< no->value << std::endl;
        avl_in_ordem(no ->right);
    }
}
*/

//############################################################

//                Funções auxiliares
template<typename Tkey>
Pessoa get_pessoa(Node<Tkey> *no){
    return no->pes;
}

/*
template<typename Tkey>
Node<Tkey>* get_raiz(){
    return root;
}
*/

template<typename Tkey>    // retorna boleano, true caso a árvore esteja vazia
bool avl<Tkey>::avl_empty(){
    return( root == NULL);
}



template<typename Tkey>    //retorna a altura do nó, 0 caso a árvore esteja vazia
int avl_height(Node<Tkey> *no){
    
    if (no == NULL)
        return 0;
    else
        return no->height;
}

template<typename Tkey>
Node<Tkey>* avl<Tkey>::search(Tkey key){
    // se a chave estiver na raiz, retorna o valor imediatamente
    if(root->key==key){
        return root;    //complexidade O(1)
    }
    
    //A ideia desse método 
    Node<Tkey>* aux_minus = root->left; //Guarda o lado esquerdo da árvore
    Node<Tkey>* aux_plus = root->right; // Guarda o lado direito da árvore
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
