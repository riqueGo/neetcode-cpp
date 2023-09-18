#include <iostream>

template <typename T>
class Node {
    public:
        T data;
        Node* next;

        Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Queue {
    private:
        Node<T>* front;
        Node<T>* rear;

    public:
        Queue() : front(nullptr), rear(nullptr) {}
    
    bool isEmpty() const { return front == nullptr; }

    //Enqueue an element to the rear of the queue
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);

        if(isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    //dequeue an element from the front of the queue
    T dequeue() {
        if(isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }

        T value = front->data;
        Node<T>* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }

        return value;
    }

    //Get the front element without removing it
    T peek() const {
        if(isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return front->data;
    }

    void print() const {
        if(isEmpty()) {
            std::cout << "[]" << std::endl;
            return;
        }

        std::cout << "[" << front->data;

        Node<T>* curr = front->next;
        while(curr != nullptr) {
            std::cout << "," << curr->data;
            curr = curr->next;
        }
        std::cout << "]" << std::endl;
    }

    //Destructor to release memory
    ~Queue() {
        while(!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue<int> myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Front element: " << myQueue.peek() << std::endl;

    myQueue.print();

    while(!myQueue.isEmpty()){
        std::cout << "Dequeue: " << myQueue.dequeue() << std::endl;
    }

    myQueue.print();
}
