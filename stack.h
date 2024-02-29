#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack() : std::vector<T>() {

}

template <typename T>
Stack<T>::~Stack() {

}

template <typename T>
bool Stack<T>::empty() const {
  return (std::vector<T>::size() == 0); //using vector's base function
}

template <typename T>
size_t Stack<T>::size() const {
  return (std::vector<T>::size()); //using vector's base function again
}

template <typename T>
void Stack<T>::push(const T& item) {
  // std::vector<T>::push_back(item);  //can't use pushback because we need to push to front of stack (only one end)
  std::vector<T>::insert(std::vector<T>::begin(), item); //using vector insert function
} //pushing to front since this is a stack

template <typename T>
void Stack<T>::pop() {
  if (this->empty())  { // or use std::vector::empty
    throw 
      std::underflow_error("empty stack");
  }
    std::vector<T>::erase(std::vector<T>::begin()); //popping front element bc this is stack
}

template <typename T>
const T& Stack<T>::top() const {
  if (this->empty()) { // or use std::vector::empty
    throw
      std::underflow_error("empty stack");
  }
  std::vector<T>::front(); //front of vector = stack's top

}

#endif