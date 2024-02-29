#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>


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

  void trickledown(int idx);
  void trickleup(int idx);

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> items_;
  unsigned int mary;
  PComparator compare;

};

// Add implementation of member functions here

//constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) { //pcomparator is a functor we can just use compare to call
  mary = m;
  compare = c;
}

//destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  // add item to end of heap array
  items_.push_back(item);
  // needs to trickleup from last index
  trickleup(items_.size()-1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {

  return items_.empty();

}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {

  return items_.size();
  
}

// finding smaller child *** MUST ACCOUNT FOR ALL CHILDREN SO ALL M OF M-ARY ***
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickledown(int idx) {

  size_t leftchild = mary*idx+1;
  size_t smallerchild = leftchild; // starting by making smallervalue leftchild
  
  if (leftchild >= items_.size()) return; // skipping leaves

  for (size_t i=0; i<mary; ++i) {
    size_t rightchild = leftchild +i;
    if (rightchild < items_.size()) { // if right child exists
      if (compare(items_[rightchild], items_[smallerchild])) {
        smallerchild = rightchild; // so if this was minheap, if right < left -> right becomes smallerchild
      }
    } // if right child doesn't exist, it will just swap with left child
    else {
      break;
    }
  }
  // swapping
  if(compare(items_[smallerchild], items_[idx])) {
    std::swap(items_[idx], items_[smallerchild]);
    trickledown(smallerchild);
  }

  // size_t leftchild = 2*idx+1;
  // size_t smallerchild = leftchild; // starting by making smallervalue leftchild
  // size_t rightchild = 2*idx+2;
  
  // if (leftchild >= items_.size()) return; // skipping leaves

  // // finding smaller child **MUST ACCOUNT FOR ALL CHILDREN SO ALL M OF M-ARY

  // if (rightchild < items_.size()) { // if right child exists
  //   if (compare(items_[rightchild], items_[leftchild])) {
  //     smallerchild = rightchild; // so if this was minheap, if right < left -> right becomes smallerchild
  //   }
  // } // if right child doesn't exist, it will just swap with left child

  // // swapping
  // if(compare(items_[smallerchild], items_[idx])) {
  //   std::swap(items_[idx], items_[smallerchild]);
  //   trickledown(smallerchild);
  // }

  // minheap version for finding smaller child and swapping:
  //   if(items_[rChild]<items_[smallerchild]) { // if the rchild is smaller than the left
  //     smallerchild = rChild; //we make the smallerchild the rightchild's value
  //   }
  // }
  // if (items_[idx] > items_[smallerchild]) { // if current node's value is bigger than the child, swap for minheap
  //   swap(items_[idx], items_[smallerchild]);
  //   trickledown(smallerchild); // recursive call
  // }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleup(int idx) { // for leaves that need to be promoted up
  while (idx>0) {
    size_t parent = (idx-1)/mary;

    if (compare(items_[idx], items_[parent])) {
      std::swap(items_[idx], items_[parent]);
      idx = parent;
    }
    else {
      break;
    }
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){ // calling top() on an empty heap
    throw std::underflow_error("stack is empty");
    // ================================
    // throw the appropriate exception
    // ================================
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  //return "best" element of heap aka first item in line 
  return items_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{ //need to swap best item with last item and delete last item and then trickledown the top item back to its place
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("stack is empty");
    }

    // swap(best, last);
    // erase(last);
    // trickledown(best);


    std::swap(items_[0], items_[items_.size()-1]);
    items_.erase(items_.end()-1);
    trickledown(0); //heapifying the first item in heap array back to its original order

}



#endif

