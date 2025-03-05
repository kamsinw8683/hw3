#include "heap.h"
#include <algorithm>
#include <string>
#include "logicsim/event.h"
// Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
    : m_(m), data_(), comp_(c) {
    if (m < 2)
        throw std::invalid_argument("m must be at least 2");
}

// Destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() { }

// push() implementation
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
    data_.push_back(item);
    heapifyUp(data_.size() - 1);
}

// empty() implementation
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return data_.empty();
}

// size() implementation
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return data_.size();
}

// heapifyUp() implementation
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(size_t index) {
    while (index > 0) {
        size_t parent = (index - 1) / m_;
        if (comp_(data_[index], data_[parent])) {
            std::swap(data_[index], data_[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// heapifyDown() implementation
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t index) {
    size_t n = data_.size();
    while (true) {
        size_t best = index;
        for (int i = 1; i <= m_; i++) {
            size_t child = index * m_ + i;
            if (child < n && comp_(data_[child], data_[best]))
                best = child;
        }
        if (best != index) {
            std::swap(data_[index], data_[best]);
            index = best;
        } else {
            break;
        }
    }
}

// Explicit instantiations:
// For a min-heap of ints using std::less<int>
template class Heap<int, std::less<int>>;
// For a max-heap of ints using std::greater<int>
template class Heap<int, std::greater<int>>;

// For a min-heap of strings using std::less<std::string>
template class Heap<std::string, std::less<std::string>>;
template class Heap<Event*, EventLess>;

