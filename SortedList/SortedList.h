#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include <iostream>
#include "Node.h"

namespace mtm{

    template <class T>
    class SortedList{
        class Node<T>* first;

    public:
        class const_iterator;
        SortedList();
        SortedList(const SortedList& list);
        ~SortedList();
        SortedList& operator=(const SortedList&);
        void insert(const T& value);
        void remove(const const_iterator& it);
        const_iterator begin() const;
        const_iterator end() const;
        int length();
        template <class Condition>
        SortedList filter(Condition rule) const;

        template<class Condition>
        SortedList apply(Condition rule);
    };

    template <class T>
    class SortedList<T>::const_iterator{
        class Node<T>* current;

        const_iterator(Node<T>* node);
        friend class SortedList;
    public:
        const T& operator*() const;
        const_iterator& operator++();
        bool operator==(const const_iterator& it) const;
        bool operator!=(const const_iterator& it) const;
        const_iterator& operator++(int);
    };

    template <class T>
    SortedList<T>::SortedList(){
        first = new Node<T>(); 
    }

    template <class T>
    SortedList<T>::SortedList(const SortedList& list){
        first = new Node<T>();
        Node<T>* current = list.first->getNext();
        if(current == nullptr){
            return;
        }
        while(current != nullptr){
            insert(current->getValue());
            current = current->getNext();
        }
    }

    template <class T>
    void SortedList<T>::insert(const T& value){
        Node<T>* ptr = first;
        while(ptr->getNext() != nullptr && ptr->getNext()->getValue() < value){
            ptr = ptr->getNext();
        }
        Node<T>* node = new Node<T>(value,ptr->getNext());
        ptr->setNext(node);
    }

    template <class T>
    void SortedList<T>::remove(const SortedList<T>::const_iterator &it){
        Node<T>* ptr = first;
        while(ptr->getNext()->getValue() != *it){
            ptr = ptr->getNext();
        }
        Node<T>* temp = ptr->getNext();
        ptr->setNext(temp->getNext());
        delete temp;
    }

    template <class T>
    void deleteList(Node<T>* current){
        while(current != nullptr){
            Node<T>* temp = current->getNext();
            delete current;
            current = temp;
        }
    }

    template <class T>
    SortedList<T>& SortedList<T>::operator=(const SortedList& list) {
        if(this == &list) { 
            return *this; 
        }
        deleteList(first->getNext());
        Node<T>* current = list.first->getNext();
        while(current != nullptr){
            this->insert(current->getValue());
            current = current->getNext();
        }
        return *this;
    }
 
    template <class T>
    SortedList<T>::~SortedList(){
        deleteList(this->first);
    }

    template <class T>
    int SortedList<T>::length(){
        int count = 0;
        Node<T>* current = first;
        while(current->getNext() != nullptr){
            count++;
            current = current->getNext();
        }
        return count;
    }

    template <class T>
    typename SortedList<T>::const_iterator SortedList<T>::begin() const{
        if(first->getNext() == nullptr){
            throw std::out_of_range ("Out Of Range!");
        }
        return SortedList<T>::const_iterator(first->getNext());
    }

    template <class T>
    typename SortedList<T>::const_iterator SortedList<T>::end() const{
        return const_iterator(nullptr);
    }

    template<class T>
    template<class Condition>
    SortedList<T> SortedList<T>::filter(Condition rule) const{
        SortedList<T> list = SortedList<T>();
        Node<T>* ptr = first->getNext();
        while(ptr != nullptr){
            if(rule(ptr->getValue())){
                list.insert(ptr->getValue());
            }
            ptr = ptr->getNext();
        }
        return list;
    }

    template<class T>
    template<class Condition>
    SortedList<T> SortedList<T>::apply(Condition rule){
        SortedList<T> list = SortedList<T>();
        Node<T>* ptr = first->getNext();
        while(ptr != nullptr){
            list.insert(rule(ptr->getValue()));
            ptr = ptr->getNext();
        }
        return list;
    }

    template <class T>
    SortedList<T>::const_iterator::const_iterator(Node<T>* node){ 
        current = node; 
    }

    template <class T>
    const T& SortedList<T>::const_iterator::operator*() const{ 
        if(current == nullptr){
            throw std::out_of_range ("Out of rannge!");
        }
        return current->getValue();
    }

    template <class T>
    typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator++(){
        if(current == nullptr){
            throw std::out_of_range ("Out of range!");
        }
        current = current->getNext();
        return *this;
    }

    template <class T>
    bool SortedList<T>::const_iterator::operator==(const const_iterator& it) const{ 
        return *this->current == it.current;
    }

    template <class T>
    bool SortedList<T>::const_iterator::operator!=(const const_iterator& it) const{ 
        return !(*this == it);
    }

    template <class T>
    typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator++(int){
        if(current == nullptr){
            throw std::out_of_range ("Out of range!");
        }
        const_iterator& temp = *this;
        current = current->getNext();
        return temp;
    }
}

#endif