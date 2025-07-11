#include <csignal>
#include <cstdlib>
#include <exception>
#include <iostream>

#include "keyper.h"

void handle_keyboard_interrup(int signum);

int main() {
  signal(SIGINT, handle_keyboard_interrup);

  auto app = Keyper({.config_file = "./config.json"});

  try {
    std::cout << "Adding a key..." << std::endl;
    app.add_key();

    std::cout << "Showing keys..." << std::endl;
    app.show_keys({.show_id = true, .reveal_password = true});

    std::cout << "Updating a key..." << std::endl;
    app.update_key(1);

    std::cout << "Showing keys..." << std::endl;
    app.show_keys({.show_id = true, .reveal_password = true});

    std::cout << "Deleting a key..." << std::endl;
    app.delete_keys({1});

    std::cout << "Showing keys..." << std::endl;
    app.show_keys({.show_id = true, .reveal_password = true});
  }

  catch (const std::exception& error) {
    std::cout << error.what() << std::endl;
  }

  return EXIT_SUCCESS;
}

void handle_keyboard_interrup(int signum) {
  std::cout << std::endl;
  exit(signum);
}
