#include <iostream>

#include "dynamic_array.hpp"

int main() {
  DynamicArray dArr = DynamicArray<std::uint32_t>(100, 50);
  dArr[0] = 10;
  dArr[99] = 22;
  std::cout << dArr[0] << std::endl;
  std::cout << dArr[99] << std::endl;
}

