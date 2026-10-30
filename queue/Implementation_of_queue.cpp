
class Queue {
    
    int* arr;       // Array to store queue elements
    int qfront;     // Points to the front element
    int rear;       // Points to the next empty position
    int size;       // Maximum size of queue
    
public:

    // Constructor to initialize the queue
    Queue() {
        size = 100001;        // Set the size of queue
        arr = new int[size];  // Dynamically create an array
        qfront = 0;           // Initially front is at index 0
        rear = 0;             // Initially rear is also at index 0
    }

    /*----------------- Public Functions of Queue -----------------*/

    // Function to check whether queue is empty or not
    bool isEmpty() {
        
        if(qfront == rear) {  // If front and rear are equal, queue is empty
            return true;
        }
        else
        {
            return false;     // Otherwise queue contains elements
        }
    }

    // Function to insert an element into the queue
    void enqueue(int data) {
        
        if(rear == size)      // Check whether queue is full
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data; // Insert data at rear position
            rear++;           // Increment rear to next position
        }
    }

    // Function to delete an element from the queue
    int dequeue() {
        
        if(qfront == rear) {  // Check whether queue is empty
            return -1;        // Return -1 if queue is empty
        }
        else
        {
            int ans = arr[qfront]; // Store front element in ans

            arr[qfront] = -1;      // Replace deleted element with -1

            qfront++;              // Move front to next position

            // If queue becomes empty, reset front and rear
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }

            return ans;            // Return deleted element
        }
    }

    // Function to return the front element
    int front() {
        
        if(qfront == rear) {       // Check whether queue is empty
            return -1;             // Return -1 if queue is empty
        }
        else
        {
            return arr[qfront];    // Return front element without deleting it
        }
    }
};
