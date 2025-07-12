#include <csignal>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "CLI/CLI.hpp"
#include "keyper.h"
#include "types/unique_id.h"

void handle_keyboard_interrup(int signum);

int main(int argc, char* argv[]) {
  signal(SIGINT, handle_keyboard_interrup);

  CLI::App app;
  app.require_subcommand(1);

  app.description("A tool to manage passwords.");
  app.footer("Copyright (C) 2025 Ahnaf Al Nafis");

  app.get_formatter()->column_width(30);

  ShowKeysOptions show_keys_options;
  UniqueId id;
  std::vector<UniqueId> id_list;
  std::string config_file;

  try {
    app.add_option("-c, --config", config_file, "Configuration file");
    auto keyper = Keyper({.config_file = config_file});

    // Add key:
    auto add_key = app.add_subcommand("add", "To add a password");
    add_key->callback([&]() {
      keyper.add_key();
    });

    // Show keys:
    auto show_keys = app.add_subcommand("show", "To show passwords");
    show_keys->add_flag("-s, --show-id", show_keys_options.show_id, "Show IDs");
    show_keys->add_flag(
        "-r, --reveal",
        show_keys_options.reveal_password,
        "Reveal password"
    );

    show_keys->callback([&]() {
      keyper.show_keys(show_keys_options);
    });

    // Update key:
    auto update_key = app.add_subcommand("update", "To update a password");
    update_key->add_option("ID", id, "Select ID")->required();

    update_key->callback([&]() {
      keyper.update_key(id);
    });

    // Delete keys:
    auto delete_key = app.add_subcommand("delete", "To delete passwords");
    delete_key->add_option("IDs", id_list, "Select ID")->required();

    delete_key->callback([&]() {
      keyper.delete_keys(id_list);
    });

    app.parse(argc, argv);
  }

  catch (const CLI::ParseError& error) {
    app.exit(error);
    return EXIT_FAILURE;
  }

  catch (const std::exception& error) {
    std::cout << error.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

void handle_keyboard_interrup(int signum) {
  std::cout << std::endl;
  exit(signum);
}
