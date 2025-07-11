#ifndef SRC_UTILS_INPUT_H
#define SRC_UTILS_INPUT_H

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string_view>

template <typename T>
T input(std::string_view prompt) {
  std::cout << prompt;

  T value;
  std::cin >> value;

  if (!std::cin) {
    if (std::cin.eof()) {
      std::cout << std::endl;
      exit(EXIT_SUCCESS);
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return value;
};

#endif  // SRC_UTILS_INPUT_H
