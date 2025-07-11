#include "keyper.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "config.h"
#include "data/models/key.h"
#include "data/sources/json_db.h"
#include "data/vault.h"
#include "types/json.h"
#include "types/unique_id.h"
#include "utils/input.h"

Keyper::Keyper(const KeyperOptions& options) {
  this->options = options;
  KeyperConfig config(this->options.config_file);

  auto data_source = std::make_shared<JsonKeyDataSource>(config.db_file);
  this->vault = Vault(data_source);
}

void Keyper::show_keys(const ShowKeysOptions& options) const {
  const auto [show_id, reveal_password] = options;
  const auto placeholder = "******";

  const auto keys = this->vault.fetch();

  for (const auto& [id, site, username, password] : keys) {
    if (show_id) std::cout << "ID: " << id << '\n';

    std::cout << "Site: " << site << '\n'
              << "Username: " << username << '\n'
              << "Password: " << (reveal_password ? password : placeholder)
              << '\n';

    if (id != keys.back().id) std::cout << '\n';
    std::cout << std::flush;
  }
}

void Keyper::add_key() {
  const auto key = this->ask();
  this->vault.add(key);
}

void Keyper::update_key(const UniqueId& id) {
  const auto [site, username, password] = this->ask();
  this->vault.update(id, {site, username, password});
}

void Keyper::delete_keys(const std::vector<UniqueId>& id_array) {
  for (const auto& id : id_array)
    this->vault.erase(id);
}

Key Keyper::ask() const {
  const auto site = input<std::string>("Site: ");
  const auto username = input<std::string>("Username: ");
  const auto password = input<std::string>("Password: ");

  return Key(site, username, password);
}
