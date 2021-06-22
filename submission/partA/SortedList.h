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

    /**
     * @brief Construct a new Sorted List< T>:: Sorted List object
     * 
     * @tparam T - generic value
     */
    template <class T>
    SortedList<T>::SortedList(){
        first = new Node<T>(); 
    }

    /**
     * @brief cop constructor - Construct a new Sorted List< T>:: Sorted List object
     * 
     * @tparam T - generic value
     * @param list - list to copy
     */
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

    /**
     * @brief adding a new value to the sorted list
     * 
     * @tparam T  - generic value
     * @param value - the T value to insert
     */
    template <class T>
    void SortedList<T>::insert(const T& value){
        Node<T>* ptr = first;
        while(ptr->getNext() != nullptr && ptr->getNext()->getValue() < value){
            ptr = ptr->getNext();
        }
        Node<T>* node = new Node<T>(value,ptr->getNext());
        ptr->setNext(node);
    }

    /**
     * @brief removing the value from the sorted list
     * 
     * @tparam T  - generic value
     * @param it - this iterator points on the value to remove 
     */
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

    /**
     * @brief deletes the entire list
     * 
     * @tparam T  - generic value
     * @param current - the first node in the list
     */
    template <class T>
    void deleteList(Node<T>* current){
        while(current != nullptr){
            Node<T>* temp = current;
            current = current->getNext();
            delete temp;
        }
    }

    /**
     * @brief assignment opertor
     * 
     * @tparam T - generic value
     * @param list 
     * @return SortedList<T>& 
     */
    template <class T>
    SortedList<T>& SortedList<T>::operator=(const SortedList& list) {
        if(this == &list) { 
            return *this; 
        }
        deleteList(first->getNext());
        first->setNext(nullptr);
        Node<T>* current = list.first->getNext();
        while(current != nullptr){
            this->insert(current->getValue());
            current = current->getNext();
        }
        return *this;
    }
 
    /**
     * @brief Destroy the Sorted List< T>:: Sorted List object
     * 
     * @tparam T - generic value
     */
    template <class T>
    SortedList<T>::~SortedList(){
        deleteList(this->first);
    }

    /**
     * @brief returns the lenght of the list
     * 
     * @tparam T - generic value
     * @return int - lenght of the list
     */
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

    /**
     * @brief returns const iterator to the first real node in the list
     * 
     * @tparam T   - generic value
     * @return SortedList<T>::const_iterator 
     */
    template <class T>
    typename SortedList<T>::const_iterator SortedList<T>::begin() const{
        return SortedList<T>::const_iterator(first->getNext());
    }

    /**
     * @brief returns const iterator to one after the last real node in the list
     * 
     * @tparam T -  generic value
     * @return SortedList<T>::const_iterator 
     */
    template <class T>
    typename SortedList<T>::const_iterator SortedList<T>::end() const{
        return const_iterator(nullptr);
    }

    /**
     * @brief returns a list with only the values who follow the rule provided
     * 
     * @tparam T - generic value
     * @tparam Condition - class with loaded () opertor, which this fuction object belongs. 
     * @param rule - the condition who all the values in the filtered list need to follow
     * @return filtered SortedList<T> 
     */
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

    /**
     * @brief return a new list with the rule applies to each value;
     * 
     * @tparam T - generic value
     * @tparam Condition - class with loaded () opertor, which this fuction object belongs. 
     * @param rule - the condition who applied to all the values new list.
     * @return applied SortedList<T> 
     */
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

    /**
     * @brief Construct a new SortedList<T>::const_iterator::const_iterator object
     * 
     * @tparam T - generic value
     * @param node 
     */
    template <class T>
    SortedList<T>::const_iterator::const_iterator(Node<T>* node){ 
        current = node; 
    }
    
    /**
     * @brief return the value which the iterator points on 
     * 
     * @tparam T - - generic value
     * @exception std::out_of_range ("Out of rannge!") if the iterator points on nullptr
     * @return const T& - T value
     */
    template <class T>
    const T& SortedList<T>::const_iterator::operator*() const{ 
        if(current == nullptr){
            throw std::out_of_range ("Out of range!");
        }
        return current->getValue();
    }

    /**
     * @brief moving the iterator one step forword
     * 
     * @tparam T - generic value
     * @exception std::out_of_range ("Out of rannge!") if the iterator points on nullptr
     * @return SortedList<T>::const_iterator& 
     */
    template <class T>
    typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator++(){
        if(current == nullptr){
            throw std::out_of_range ("Out of range!");
        }
        current = current->getNext();
        return *this;
    }

    /**
     * @brief checking if 2 iterators are equal
     * 
     * @tparam T - generic value 
     * @param it - the iterator to compare with 
     * @return true - if they equal 
     * @return false - if they are not equal 
     */
    template <class T>
    bool SortedList<T>::const_iterator::operator==(const const_iterator& it) const{ 
        return *this->current == it.current;
    }

    /**
     * @brief - checking if 2 iterators are not equal
     * 
     * @tparam T - generic value 
     * @param it - the iterator to compare with
     * @return true - if they are not equal 
     * @return false - if they equal 
     */
    template <class T>
    bool SortedList<T>::const_iterator::operator!=(const const_iterator& it) const{ 
        return !(*this == it);
    }

    /**
     * @brief moving the const iterator this number of steps forword
     * 
     * @tparam T  - generic value
     * @exception std::out_of_range ("Out of rannge!") if the iterator points on nullptr 
     * @return SortedList<T>::const_iterator& 
     */
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