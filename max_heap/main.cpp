#include <iostream>
#include <vector>
#include "max_heap.h"

using namespace std;
int main() {
    MaxHeap<long> heap;
    vector<long> res;

    heap.insert(2);
    heap.insert(3);
    heap.insert(5);
    heap.insert(18);
    heap.insert(12);
    res.push_back(heap.extractMax());
    res.push_back(heap.extractMax());
    res.push_back(heap.extractMax());
    res.push_back(heap.extractMax());
    res.push_back(heap.extractMax());

//    heap.insert(200);
//    heap.insert(10);
//    heap.insert(5);
//    heap.insert(500);
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());

//    heap.insert(20);
//    heap.insert(20);
//    heap.insert(20);
//    heap.insert(2);
//    heap.insert(3);
//    heap.insert(18);
//    heap.insert(15);
//    heap.insert(18);
//    heap.insert(12);
//    heap.insert(12);
//    heap.insert(2);
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());
//    res.push_back(heap.extractMax());

    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}
