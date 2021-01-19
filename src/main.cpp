// Copyright 2020 Ksuvot
#include "postfix.h"
#include <iostream>

int main() {
  std::string s1("2 + 6 * 3 / (4 - 2)");
  std::string s2=infix2postfix(s1);
  std::cout << s2;  // 2 6 3 * 4 2 - / +
  return 0;
}
