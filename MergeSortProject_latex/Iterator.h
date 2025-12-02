#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

template <typename T>
class Iterator {
private:
    Node<T>* node;

public:
    Iterator(Node<T>* n = nullptr) : node(n) {}

    T& operator*() { return node->data; }

    Iterator& operator++() {
        if (node) node = node->next;
        return *this;
    }

    Iterator& operator--() {
        if (node) node = node->prev;
        return *this;
    }

    bool operator!=(const Iterator& other) const { return node != other.node; }
    bool operator==(const Iterator& other) const { return node == other.node; }
};

#endif
