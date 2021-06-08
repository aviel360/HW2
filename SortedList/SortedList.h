#include <iostream>

namespace mtm{
    typedef int T;
//    template <class T>
    class SortedList{
        class Node;
//       SortedList* next;
        class Iterator;

    public:
        SortedList();
        explicit SortedList(T& value);
        SortedList(const SortedList& list);
        ~SortedList();
        SortedList& operator=(const SortedList&);
        void insert(const T& value);
        void remove(const T& value);
        int getSize() const;
        Iterator begin();
        Iterator end();
    };

    class SortedList::Iterator{
        const SortedList current;
        int index;
        Iterator(const SortedList* list, int index);
        friend class SortedList;
    
    public:
        const int& operator*() const;
        Iterator& operator++();
        bool operator==(const Iterator& it) const;
        Iterator& operator++(int);
        bool operator!=(const Iterator& it) const;
    };
}
