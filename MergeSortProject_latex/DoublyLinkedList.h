#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include "Node.h"
#include "Iterator.h"

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t count;

    Node<T>* node_at(size_t index) const {
        if (index >= count) throw std::out_of_range("index out of range");
        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i)
            current = current->next;
        return current;
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~DoublyLinkedList() { clear(); }

    // 1. Dodaj element na początek listy
    void push_front(const T& value) {
        Node<T>* n = new Node<T>(value);
        n->next = head;
        if (head) head->prev = n;
        head = n;
        if (!tail) tail = head;
        ++count;
    }

    // 2. Dodaj element na koniec listy
    void push_back(const T& value) {
        Node<T>* n = new Node<T>(value);
        n->prev = tail;
        if (tail) tail->next = n;
        tail = n;
        if (!head) head = tail;
        ++count;
    }

    // 3. Dodaj element pod wskazany indeks
    void insert_at(size_t index, const T& value) {
        if (index == 0) { push_front(value); return; }
        if (index >= count) { push_back(value); return; }

        Node<T>* succ = node_at(index);
        Node<T>* pred = succ->prev;
        Node<T>* n = new Node<T>(value);
        n->prev = pred;
        n->next = succ;
        pred->next = n;
        succ->prev = n;
        ++count;
    }

    // 4. Usuń element z początku listy
    void pop_front() {
        if (!head) throw std::out_of_range("pop_front on empty list");
        Node<T>* old = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete old;
        --count;
    }

    // 5. Usuń element z końca listy
    void pop_back() {
        if (!tail) throw std::out_of_range("pop_back on empty list");
        Node<T>* old = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete old;
        --count;
    }

    // 6. Usuń element spod wskazanego indeksu
    void remove_at(size_t index) {
        if (!head) throw std::out_of_range("remove_at on empty list");
        if (index == 0) { pop_front(); return; }
        if (index >= count - 1) { pop_back(); return; }

        Node<T>* target = node_at(index);
        Node<T>* p = target->prev;
        Node<T>* n = target->next;
        p->next = n;
        n->prev = p;
        delete target;
        --count;
    }

    // 7. Wyświetl całą listę
    void print_forward() const {
        std::cout << "[ ";
        for (Node<T>* cur = head; cur != nullptr; cur = cur->next) {
            std::cout << cur->data;
            if (cur->next) std::cout << " <-> ";
        }
        std::cout << " ]\n";
    }

    // 8. Wyświetl listę w odwrotnej kolejności
    void print_backward() const {
        std::cout << "[ ";
        for (Node<T>* cur = tail; cur != nullptr; cur = cur->prev) {
            std::cout << cur->data;
            if (cur->prev) std::cout << " <-> ";
        }
        std::cout << " ]\n";
    }

    // 11. Czyść całą listę
    void clear() {
        Node<T>* cur = head;
        while (cur) {
            Node<T>* next = cur->next;
            delete cur;
            cur = next;
        }
        head = tail = nullptr;
        count = 0;
    }

    // Dostęp do iteratorów
    Iterator<T> begin() { return Iterator<T>(head); }
    Iterator<T> end() { return Iterator<T>(tail); }

    size_t size() const { return count; }
};

#endif
