#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <class T>
class MaxHeap
{
public:
    void insert(T a);
    T getMax();
    T extractMax();

private:
    void shiftUp();
    void shiftDown();

    std::vector<T> heap;
};

template <class T>
void MaxHeap<T>::insert(T a) {
    heap.push_back(a); // add new element as a child of the first leaf
    shiftUp(); // a new elements was added to the end, so the heap is broken and needed to be repaired
}

template <class T>
T MaxHeap<T>::getMax() {
    if (heap.size() > 0) {
        return heap[0];
    } else {
        throw std::out_of_range("no elements in the heap");
    }
}

template <class T>
T MaxHeap<T>::extractMax() {
    if (heap.size() > 0) {
        T temp = heap[0]; // extract first element (head)
        heap[0] = heap[heap.size()-1]; // put the last element on this place
        heap.pop_back();
        shiftDown(); // the first number is wrong, the heap is broken and needed to be repaired
        return temp;
    } else {
        throw std::out_of_range("no elements in the heap");
    }
}

template <class T>
void MaxHeap<T>::shiftUp() {
    size_t elIndex = heap.size(), elParentInd;
    while (elIndex != 1) {
        elParentInd = elIndex / 2; // find the parent of the element
        if (heap[elIndex - 1] <= heap[elParentInd - 1]) { // break the loop if the heap is repaired
            break;
        }

        std::swap(heap[elIndex-1], heap[elParentInd-1]); // exchange the element with its parent
        elIndex = elParentInd; // calc new element index
    }
}

template <class T>
void MaxHeap<T>::shiftDown() {
    size_t elIndex = 0, leftChild, rightChild;
    while (elIndex*2 + 1 < heap.size()) { // while the element has at least one child
        leftChild = 2*elIndex + 1; // find children of the element
        rightChild = 2*elIndex + 2;

        if (heap[rightChild] > heap[leftChild]) { // the max element must be chosen
            leftChild = rightChild;
        }

        if (heap[elIndex] >= heap[leftChild]) { // break the loop if the heap is repaired
            break;
        }

        std::swap(heap[elIndex], heap[leftChild]); // exchange the element with its parent
        elIndex = leftChild; // calc new parent index
    }
}

#endif // HEAP_H
