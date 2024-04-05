/* Sarah Miller
Assignment 3 */

#include <iostream> // a standard c++ library that incldues input and output from users.
#include <queue> // a standard c++ library that provides queues (FIFO)
#include <vector> // library that 

using namespace std; // library that excludes the std:: requirment

template <typename T> 
class Queue { // define template class as queue
private:
    queue<T> q; // private member q, which is a queue (FIFO) structure.

public:
    void push(T val) { // add a new element  to the back of the queue. Takes the argument T, template parameter. 
        q.push(val); // def of the push function. Calls push methos.
    }

    void pop() { //returns no value bc of void
        if (!q.empty()) { //def of pop func. checks queue 'q' is not empty. 
            q.pop(); // 
        }
    }

    T front() { // returns a value of type 'T', which is the type of elements in the queue.
        return q.front();
    }

    int size() { // declaration of the size func. member of queue class. returns an int value. represents the # of elements in the queue.
        return q.size();
    }

    bool empty() { // returns boolean value where true indcates that the queue is empty and false is not empty.
        return q.empty(); 
    }

    void move_to_rear() { // moves the elements at the front of the queue to the rear of the queue, effectively rotating the queue.
        if (!q.empty()) { // 
            T frontElement = q.front();
            q.pop();
            q.push(frontElement);
        }
    }
};

// Recursive linear search to find the last occurrence of a target in a vector
template <typename T>
int recursive_linear_search(const vector<T>& vec, const T& target, int index = 0, int lastIndex = -1) {
    if (index >= vec.size()) {
        return lastIndex;
    }

    if (vec[index] == target) {
        lastIndex = index;
    }

    return recursive_linear_search(vec, target, index + 1, lastIndex);
}

// Insertion sort for a list of integers stored in a queue
void insertion_sort_queue(Queue<int>& q) {
    if (q.empty()) {
        return;
    }

    Queue<int> sortedQ;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        while (!sortedQ.empty() && sortedQ.front() < current) {
            q.push(sortedQ.front());
            sortedQ.pop();
        }

        sortedQ.push(current);
    }

    while (!sortedQ.empty()) {
        q.push(sortedQ.front());
        sortedQ.pop();
    }
}

int main() {
    // Instantiate queue with integers and push 10 values into the queue
    Queue<int> q;
    for (int i = 1; i <= 10; i++) {
        q.push(i);
    }

    // Display all elements in the queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.move_to_rear();
    }
    cout << endl;

    // Recursive linear search example
    vector<int> vec = {1, 2, 3, 4, 2, 5, 2, 6};
    int target = 2;
    int lastIndex = recursive_linear_search(vec, target);
    cout << "Last occurrence of " << target << " is at index " << lastIndex << endl;

    // Insertion sort for a list of integers stored in a queue
    Queue<int> unsortedQ;
    unsortedQ.push(3);
    unsortedQ.push(1);
    unsortedQ.push(4);
    unsortedQ.push(1);
    unsortedQ.push(5);
    unsortedQ.push(9);
    unsortedQ.push(2);
    insertion_sort_queue(unsortedQ);

    cout << "Sorted queue: ";
    while (!unsortedQ.empty()) {
        cout << unsortedQ.front() << " ";
        unsortedQ.pop();
    }
    cout << endl;

    return 0;
}