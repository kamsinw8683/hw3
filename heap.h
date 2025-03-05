#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <string>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m_;
  std::vector<T> data_;
  PComparator comp_;
  void heapifyUp(size_t index);
  void heapifyDown(size_t index);
  


};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const {
  if (empty())
    throw std::underflow_error("top(): heap is empty");
  return data_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop() {
  if (empty())
    throw std::underflow_error("pop(): heap is empty");
  data_.front() = data_.back();
  data_.pop_back();
  if (!empty())
    heapifyDown(0);
}
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

#endif

