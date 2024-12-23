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
    class Stack {
        Node<T> *head;
    public:
        Stack();

        ~Stack();

        T Pop();

        void Push(T value);
    };

    template<typename T>
    Stack<T>::Stack() {
        head = nullptr;
    }

    template<typename T>
    Stack<T>::~Stack() {

    }

    template<typename T>
    void Stack<T>::Push(const T value) {
        auto newNode = new Node<T>;
        newNode->value = value;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head) {
            head->prev = newNode;
        }
        head = newNode;
    }

    template<typename T>
    T Stack<T>::Pop() {
        if (!head) {
            return 0;
        }
        auto tmpNode = head;
        T returnValue = tmpNode->value;
        head = head->next;
        if (head) head->prev = nullptr;
        delete tmpNode;
        return returnValue;
    }
}

#endif
