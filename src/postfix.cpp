// Copyright 2020 Ksuvot
#include <string>
#include "MyStack.h"
#include "postfix.h"

bool isNumber(char number) {
  if ((number >= '0' && number <= '9') || number == '.')
    return true;
  else
    return false;
}

int priority(char operation) {
  switch (operation) {
    case '(':
      return 0;
      break;
    case ')':
      return 1;
      break;
    case '+':
    case '-':
      return 2;
      break;
    case '*':
    case '/':
      return 3;
      break;
    default:
      return -1;
      break;
  }
}

std::string infix2postfix(std::string infix) {
  MyStack<char> stack(10);
  std::string postfix;

  for (unsigned int i = 0; i < infix.size(); i++) {
    switch (infix[i]) {
      case ' ': break;
      case '(':
        stack.push(infix[i]);
        break;
      case ')':
        while ((stack.get() != '(')) {
          postfix += stack.pop();
          postfix += ' ';
        }
        stack.pop();
        break;
      case '+':
      case '-':
      case '*':
      case '/':
        if (stack.isEmpty() || ( priority(infix[i]) > priority(stack.get()))) {
          stack.push(infix[i]);
        }
        else {
          while (priority(infix[i]) <= priority(stack.get())) {
            postfix += stack.pop();
            postfix += ' ';
          }
          stack.push(infix[i]);
        }
        break;
      default:
        if (isNumber(infix[i]) && !isNumber(infix[ i + 1])) {
          postfix += infix[i];
          postfix += ' ';
        }
        else {
          postfix += infix[i];
        }
        break;
    }
  }
  while (!stack.isEmpty()) {
    postfix += stack.pop();
    postfix += ' ';
  }
  postfix.pop_back();
  return postfix;
}
