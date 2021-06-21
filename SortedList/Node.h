#ifndef NODE_H
#define NODE_H

#include <iostream>

namespace mtm{
    template <class T>
    class Node{
        T* value;
        Node* next;


    public:
        Node();
        ~Node();
        Node(T value, Node* next = nullptr);
        Node(const Node& node) = default;
        Node& operator=(const Node&);
        bool operator ==(const Node*) const;
        bool operator !=(const Node*) const;
        Node* getNext() const;
        const T& getValue() ;
        void setNext(Node* node);
        void setValue(T the_value);
    };
    /**
     * @brief Construct a new Node< T>:: Node object without parameters
     * 
     * @tparam T - generic value
     */

    template <class T>
    Node<T>::Node() : value(nullptr), next(nullptr) {}

    /**
     * @brief Construct a new Node< T>:: Node object with parameters
     * 
     * @tparam T - generic value
     * @param the_value - T value
     * @param next_node - next Node in the list
     */
    template <class T>
    Node<T>::Node(T the_value, Node* next_node) : next(next_node){
        value = new T(the_value);
    }

    /**
     * @brief Destroy the Node< T>:: Node object
     * 
     * @tparam T - generic value
     */
    template <class T>
    Node<T>::~Node(){
        delete value;
    }
    /**
     * @brief assignment opertor
     * 
     * @tparam T - generic value
     * @param node 
     * @return Node<T>& 
     */
    template <class T>
    Node<T>& Node<T>::operator=(const Node& node) 
    {
    if(*this == node){
        return *this;
    }
    delete value;
    this->value = new T(node.value);
    this->next = node.next;
    return *this;
    }

    /**
     * @brief - checking if 2 Nodes equal
     * 
     * @tparam T -  generic value
     * @param node 
     * @return true - if equal 
     * @return false - if not equal 
     */
    template <class T>
    bool Node<T>::operator ==(const Node* node) const{
        return (this == node);
    }

    /**
     * @brief checking if 2 Nodes not equal
     * 
     * @tparam T -  generic value
     * @param node 
     * @return true - if not equal 
     * @return false - if equal 
     */
    template <class T>
    bool Node<T>::operator !=(const Node* node) const{
        return !(*this == node);
    }

    /**
     * @brief - returns the next node in the list.
     * 
     * @tparam T - generic value
     * @return Node<T>* - next node in the list
     */
    template <class T>
    Node<T>* Node<T>::getNext() const{
        return this->next;
    }

    /**
     * @brief returns the value of this Node
     * 
     * @tparam T - generic value
     * @return const T& - the value of this Node
     */
    template <class T>
    const T& Node<T>::getValue()  {
        return *(this->value);
    }

    /**
     * @brief - link the first node to the second node, by this order 
     * 
     * @tparam T - generic value
     * @param node - this node will be placed after the node we operate on.  
     */
    template <class T>
    void Node<T>::setNext(Node* node){
        this->next = node;
    }

    /**
     * @brief - set the value of this node
     * 
     * @tparam T - generic value
     * @param the_value - T value
     */
    template <class T>
    void Node<T>::setValue(T the_value){
        *(this->value) = the_value;
    }
}

#endif