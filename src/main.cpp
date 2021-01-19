// Copyright 2020 Ksuvot
#include <iostream>
#include "postfix.h"

int main() {
  std::string s1("2 + 2");
  std::string s2 = infix2postfix(s1);
  std::cout << s2;  // 2 2 +

  std::string s3("2 + 6 * 3 / (4 - 2)");
  std::string s4 = infix2postfix(s3);
  std::cout << s4;  // 2 6 3 * 4 2 - / +
  return 0;
}
