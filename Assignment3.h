/*
contains class template 'Queue', the recursive linear search function, and insertion sort function. other C++ libraries
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class Queue {
private:
    queue<T> q;

public:
    void push(T val) {
        q.push(val);
    }

    void pop() {
        if (!q.empty()) {
            q.pop();
        }
    }

    T front() {
        return q.front();
    }

    int size() {
        return q.size();
    }

    bool empty() {
        return q.empty();
    }

    void move_to_rear() {
        if (!q.empty()) {
            T frontElement = q.front();
            q.pop();
            q.push(frontElement);
        }
    }
};

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

#endif
