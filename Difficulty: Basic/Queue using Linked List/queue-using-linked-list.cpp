class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    
  private:
    int currsize;
    Node* front;
    Node* rear;

  public:
    myQueue() {
        currsize = 0;
        front = rear = nullptr;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front == nullptr;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* node = new Node(x);
        if(isEmpty()) {
            front = rear = node;
        }
        else {
            rear->next = node;
            rear = node;
        }
        currsize++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()) {
            cout<<"Queue Underflow\n";
            return;
        }
        else {
            Node* temp = front;
            front = temp->next;
            delete temp;
            if(front == nullptr) {
                rear = nullptr;
            }
            currsize--;
        }
        
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty()) {
            return -1;
        }
        else {
            return front->data;
        }
    }

    int size() {
        // Returns the current size of the queue.
        return currsize;
    }
};
