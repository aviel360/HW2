#include <iostream>
#include "Node.cpp"

namespace mtm{
    template <class T>
    class SortedList{
        class Node<T>* first;

    public:
        SortedList();
        SortedList(const SortedList& list);
        ~SortedList();
        SortedList& operator=(const SortedList&);
        void insert(const T& value);
        void remove(const_iterator it);
        class const_iterator;
        const_iterator begin() const;
        const_iterator end() const;
        int length();
        template <class Condition>
        SortedList filter(Condition rule) const;
        template<class Condition>
        void apply(Condition rule);
    };

    template <class T>
    class const_iterator{
        class Node<T>* current;

        const_iterator(Node<T>* node);
    
    public:
        const Node<T>& operator*() const;
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
        while(current != nullptr){
            insert(current->getValue());
            current = current->getNext();
        }
    }

    template <class T>
    void SortedList<T>::insert(const T& value){
        Node<T>* ptr = first->getNext();
        while(ptr->getValue() < value && ptr->getNext() != nullptr){
            ptr = ptr->getNext();
        }
        Node<T>* node = new Node<T>(value,ptr->getNext());
        ptr->setNext(node);
    }

    template <class T>
    void remove(const_iterator<T> it){
        Node<T>* ptr = first;
        while(ptr->getNext() != *it){
            ptr = ptr->getNext();
        }
        Node<T>* temp = ptr->getNext();
        ptr->setNext(it.current->getNext());
        delete temp;
    }

    template <class T>
    SortedList<T>& SortedList<T>::operator=(const SortedList& list) {
        if(this == &list) { 
            return *this; 
        }
        SortedList<T>::~SortedList();
        this(list);
    }

    template <class T>
    SortedList<T>::~SortedList(){
        Node<T>* current = first;
        while(current != nullptr){
            Node<T>* temp = current->getNext();
            delete current;
            current = temp;
        }
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
    SortedList<T>::const_iterator SortedList<T>::begin() const{
        return const_iterator<T>(first->getNext());
    }

    template <class T>
    SortedList<T>::const_iterator SortedList<T>::end() const{
        return const_iterator<T>();
    }

    template<class T>
    template<class Condition>
    SortedList<T> SortedList<T>::filter(Condition rule) const{
        SortedList<T> list();
        Node<T>* ptr = first->getNext();
        while(ptr != nullptr){
            if(rule(ptr->getValue())){
                list.insert(ptr->getValue());
            }
        }
        return list;
    }

    template<class T>
    template<class Condition>
    void SortedList<T>::apply(Condition rule){
        SortedList<T> list();
        Node<T>* ptr = first->getNext();
        while(ptr != nullptr){
            list.insert(rule(ptr->getValue()));
        }
        return list;
    }

    template <class T>
    const_iterator<T>::const_iterator(Node<T>* node = nullptr){ 
        current = node; 
    }

    template <class T>
    const Node<T>& const_iterator<T>::operator*() const{ 
        return current;
    }

    template <class T>
    const_iterator<T>& const_iterator<T>::operator++(){
        current = current->getNext();
        return *this;
    }

    template <class T>
    bool const_iterator<T>::operator==(const const_iterator<T>& it) const{ 
        return *this == *it;
    }

    template <class T>
    bool const_iterator<T>::operator!=(const const_iterator<T>& it) const{ 
        return !(*this == *it);
    }

    template <class T>
    const_iterator<T>& const_iterator<T>::operator++(int){
        const_iterator& temp = *this;
        current = current->getNext();
        return temp;
    }

}
