#ifndef NODE_H
#define NODE_H
#include "pessoa.h"

template<typename Tkey>
class Node{
        public:
                Tkey key;
                Pessoa pes;
                int height;
                Node<Tkey>* left;
                Node<Tkey>* right;

};


#endif
/*
template<typename Tkey>        //(raiz,esq,dir)
void avl<Tkey>::avl_pre_ordem(Node<Tkey>* root){
    stack <Node<Tkey>*> pilha;
    pilha.push(root); // empilha raiz
    while (!pilha.empty()) {
        Node<Tkey>* node = pilha.top();
        pilha.pop();
        if(node != nullptr) {
            cout << "chave: " << node->key << endl; // visita raiz
                pilha.push( node->right );
                pilha.push( node->left );
        }
    }


*/