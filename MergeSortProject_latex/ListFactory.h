#ifndef LISTFACTORY_H
#define LISTFACTORY_H

#include "DoublyLinkedList.h"

template <typename T>
class ListFactory {
public:
    static DoublyLinkedList<T>* createList() {
        return new DoublyLinkedList<T>();
    }
};

#endif
