#include <iostream>
#include "ListFactory.h"

int main() {
    auto list = ListFactory<int>::createList();

    std::cout << "Dodawanie elementów na początek i koniec listy:\n";
    list->push_front(10);
    list->push_back(20);
    list->push_back(30);
    list->print_forward();

    std::cout << "\nDodawanie elementu pod indeks 1:\n";
    list->insert_at(1, 15);
    list->print_forward();

    std::cout << "\nUsuwanie elementu z początku:\n";
    list->pop_front();
    list->print_forward();

    std::cout << "\nUsuwanie elementu z końca:\n";
    list->pop_back();
    list->print_forward();

    std::cout << "\nUsuwanie elementu spod indeksu 0:\n";
    list->remove_at(0);
    list->print_forward();

    std::cout << "\nDodawanie kilku elementów i test iteracji:\n";
    list->push_back(100);
    list->push_back(200);
    list->push_back(300);
    list->print_forward();

    std::cout << "\nIterator - przejście do następnego elementu:\n";
    auto it = list->begin();
    ++it;
    std::cout << *it << std::endl;

    std::cout << "\nIterator - przejście wstecz:\n";
    auto it2 = list->end();
    --it2;
    std::cout << *it2 << std::endl;

    std::cout << "\nWyświetlanie listy od końca:\n";
    list->print_backward();

    std::cout << "\nCzyszczenie listy:\n";
    list->clear();
    list->print_forward();

    delete list;
    return 0;
}
