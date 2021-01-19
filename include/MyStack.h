//  Copyright © 2021 Ksuvot

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>

template <class T>
class MyStack{
 private:
  T *ptr;
  int size;
  int index = 0;

 public:
  explicit MyStack(int size) {
    this->size = size;
    this->ptr = new T[size];
  }

  MyStack(const MyStack<T> &my_stack) {
    this->size = my_stack.size;
    this->index = my_stack.index;
    this->ptr = new T[my_stack.size];
    for (int i = 0; i < my_stack.size; i++) {
      this->ptr[i] = my_stack.ptr[i];
    }
  }

  ~MyStack() {
    delete[] this->ptr;
  }

  T get() const {
    return this->ptr[this->index-1];
  }

  T pop() {
    return this->ptr[--this->index];
  }

  void push(T key) {
    this->ptr[index++] = key;
  }

  bool isFull() const {
    return this->index == this->size;
  }

  bool isEmpty() const {
    return this->index == 0;
  }
};

#endif  // INCLUDE_MYSTACK_H_
