#include <cstdlib>
#include <iostream>

#include "key.h"

int main() {
  auto key = Key("doodle.com", "ahnaf", "123");

  std::cout << "Site: " << key.site << std::endl
            << "Username: " << key.username << std::endl
            << "Password: " << key.password << std::endl;

  return EXIT_SUCCESS;
}
