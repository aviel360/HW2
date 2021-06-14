#include <iostream>

namespace mtm{
    template <class T>
    class Node{
        T value;
        Node* next;


    public:
        Node();
        ~Node() = default;
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

    template <class T>
    Node<T>::Node() : next(nullptr){}
    
    template <class T>
    Node<T>::Node(T the_value, Node* next_node) : value(the_value), next(next_node){}

    template <class T>
    Node<T>& Node<T>::operator=(const Node& node) 
    {
    this->value = node.value;
    this->next = node.next;
    return *this;
    }

    template <class T>
    bool Node<T>::operator ==(const Node* node) const{
/*        if(this != nullptr && node == nullptr || this == nullptr && node != nullptr ){
            return false;
        }
        if(this == nullptr && node == nullptr){
            return true;
        }*/
        return (this == node);
    }

    template <class T>
    bool Node<T>::operator !=(const Node* node) const{
        return !(*this == node);
    }

    template <class T>
    Node<T>* Node<T>::getNext() const{
        return this->next;
    }

    template <class T>
    const T& Node<T>::getValue()  {
        return this->value;
    }

    template <class T>
    void Node<T>::setNext(Node* node){
        this->next = node;
    }

    template <class T>
    void Node<T>::setValue(T the_value){
        this->value = the_value;
    }
}