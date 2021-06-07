namespace mtm{
    typedef int T;
    class Node{
        T value;
        Node* next;

    public:
        Node() = default;
        ~Node() = default;
        Node(T value, Node* next = nullptr);
        Node(const Node& node) = default;
        Node& operator=(const Node&);
        Node& getNext() const;
        T& getValue() const;
        void setNext();
        void setValue();

    };
}