#ifndef NODE_H
#define NODE_H
#include "pessoa.h"

template<typename Tkey>
struct Node{
        Tkey key;
        Pessoa pes;
        int height;
        Node<Tkey>* left;
        Node<Tkey>* right;

};


#endif