#include <iostream>

// Node class for holding data
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

// Stack class using the Node class
template <typename T>
class Stack {
private:
    Node<T>* top;

public:
    Stack() : top(nullptr) {}

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Push an element onto the stack
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop (remove and return) the top element from the stack
    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        T value = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Peek (view) the top element of the stack without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return top->data;
    }

    // Destructor to release memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element: " << myStack.peek() << std::endl;

    while (!myStack.isEmpty()) {
        std::cout << "Popped: " << myStack.pop() << std::endl;
    }

    return 0;
}
