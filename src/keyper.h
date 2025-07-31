#pragma once

#include <string>

#include "types/unique_id.h"

#include "config.h"
#include "data/models/key.h"
#include "data/vault.h"

struct KeyperOptions {
    std::string config_file;
};

struct ShowKeysOptions {
    bool show_id;
    bool reveal_password;
};

class Keyper {
  public:
    explicit Keyper(const KeyperOptions& options);

    void show_keys(const ShowKeysOptions& options) const;
    void add_key();
    void update_key(const UniqueId& id);
    void delete_keys(const std::vector<UniqueId>& id_array);

  private:
    KeyperOptions options;
    KeyperConfig config;
    Vault vault;

    Key ask() const;
};
