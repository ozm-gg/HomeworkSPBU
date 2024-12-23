#ifndef SEM2TASK5_STACK_H
#define SEM2TASK5_STACK_H


namespace Lessons {
    template<typename T>
    struct Node {
        Node *prev{};
        Node *next{};
        T value{};
    };

    template<typename T>
    class Queue {
    public:
        Node<T> *head;
        Node<T> *tail;
        Queue();

        ~Queue();

        T Pop();

        void Push(T value);

    };

    template<typename T>
    std::ostream& operator<<(std::ostream &os, const Queue<T> queue) {
        Node<T> *tmp = queue.head;
        if(!tmp){
            return os<<"Queue is clear";
        }
        while (tmp != queue.tail->next) {
            os << tmp->value;
            tmp = tmp->next;
        }
        return os;
    }

    template<typename T>
    Queue<T>::Queue() {
        head = nullptr;
        tail = nullptr;
    }

    template<typename T>
    Queue<T>::~Queue() {

    }

    template<typename T>
    void Queue<T>::Push(const T value) {
        auto newNode = new Node<T>;
        newNode->value = value;
        newNode->next = nullptr;
        if (tail) {
            newNode->prev = tail;
            tail->next = newNode;
        } else {
            newNode->prev = nullptr;
            head = newNode;
        }
        tail = newNode;
    }

    template<typename T>
    T Queue<T>::Pop() {
        if (!head) {
            return T{};
        }
        auto tmpNode = head;
        T returnValue = tmpNode->value;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete tmpNode;
        return returnValue;
    }

}

#endif
