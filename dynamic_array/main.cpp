#include <iostream>

#include "dynamic_array.hpp"

int main() {
  DynamicArray dArr = DynamicArray<std::uint32_t>(100, 50);
  dArr[0] = 10;
  std::cout << dArr[0] << std::endl;
}
