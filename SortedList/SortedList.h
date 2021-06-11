#include <iostream>
#include "Node.cpp"

namespace mtm{
    typedef int T;
   // template <class T>
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
        const_iterator begin();
        const_iterator end();
    };

 //   template <class T>
    class const_iterator{
        class Node<T>* current;

        const_iterator(const Node<T>& node);
      //  friend class Node;
    
    public:
        const T& operator*() const;
        const_iterator& operator++();
        bool operator==(const const_iterator& it) const;
        const_iterator& operator++(int);
    };

    SortedList::SortedList(){ first = new Node<T>(); }

    SortedList::SortedList(const SortedList& list) : first(){
        Node<T>* current = list.first->getNext();
        while(current != nullptr){
            insert(current->getValue());
            current = current->getNext();
        }
    }

    void SortedList::insert(const T& value){
        Node<T>* ptr = first->getNext();
        while(ptr->getValue() < value && ptr->getNext() != nullptr){
            ptr = ptr->getNext();
        }
        Node<T>* node = new Node<T>(value,ptr->getNext());
        ptr->setNext(node);
    }

    SortedList& SortedList::operator=(const SortedList& list) {
        if(this == &list) { return *this; }
        SortedList::~SortedList();
        first = list.first;
    }

    SortedList::~SortedList(){
        Node<T>* current = first;
        while(current != nullptr){
            Node<T>* temp = current->getNext();
            delete current;
            current = temp;
        }
    }

    const_iterator::const_iterator(const Node<T>& node) { *current = node; }

    const T& const_iterator::operator*() const{ return current->getValue(); }

    const_iterator& const_iterator::operator++(){
        current = current->getNext();
        return *this;
    }

    bool const_iterator::operator==(const const_iterator& it) const { return *(*this) == *it; }

    const_iterator& const_iterator::operator++(int){
        const_iterator& temp = *this;
        current = current->getNext();
        return temp;
    }
}
