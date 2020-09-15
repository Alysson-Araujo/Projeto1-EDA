#ifndef NODE_H
#define NODE_H

template<typename Tkey, typename Tvalue>
struct Node{
        Tkey key;
        Tvalue value;
        int height;
        Node<Tkey,Tvalue>* left;
        Node<Tkey,Tvalue>* right;

};


#endif