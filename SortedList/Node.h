#include <iostream>

namespace mtm{
    //typedef int T;

    template <class T>
    class Node{
        T value;
        Node* next;

        /*
        friend class SortedList;
        friend class const_iterator;
        */

    public:
        Node() = default;
        ~Node() = default;
        Node(T value, Node* next = nullptr);
        Node(const Node& node) = default;
        Node& operator=(const Node&);
        bool operator ==(const Node&) const;
        bool operator !=(const Node&) const;
        Node& getNext() const;
        T& getValue() const;
        void setNext(Node* node);
        void setValue(T the_value);
        
    };


    template <class T>
    Node<T>::Node(T the_value, Node* next_node = nullptr) : value(the_value), next(next_node)
    {}

    template <class T>
    Node<T>& Node<T>::operator=(const Node& node) 
    {
    this->value = node.value;
    this->next = node.next;
    return *this;
    }

    template <class T>
    bool Node<T>::operator ==(const Node& node) const
    {
        if (this->value == node.value){
            if (this->next == node.next){ /*is that recursia?*/
                return true;
            }
        }
        return false;
    }

    template <class T>
    bool Node<T>::operator !=(const Node& node) const
    {
        if (*this == node) {
            return false;
        }
        return true;
    }

    template <class T>
    Node<T>& Node<T>::getNext() const
    {
        return *(this->next);
    }

    template <class T>
    T& Node<T>::getValue() const 
    {
        return this->value;
    }

    template <class T>
    void Node<T>::setNext(Node* node)
    {
        this->next = node;
    }

    template <class T>
    void Node<T>::setValue(T the_value)
    {
        this->value = the_value;
    }

    



}