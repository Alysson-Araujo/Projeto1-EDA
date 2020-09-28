#ifndef NODE_H
#define NODE_H
#include "pessoa.h"

//Usamos a classe Node para usar seus atributos e criar nós da  árvore avl.
// criamos 3 tipos de Node para atender as características das 3 árvores. 
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
