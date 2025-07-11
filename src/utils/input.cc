#include "input.h"

#include <iostream>
#include <string>
#include <string_view>

std::string input(std::string_view prompt) {
  if (!prompt.empty()) std::cout << prompt;

  std::string line;
  std::getline(std::cin, line);

  return line;
}
