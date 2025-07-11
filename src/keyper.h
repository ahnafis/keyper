#ifndef SRC_KEYPER_H
#define SRC_KEYPER_H

#include <string>

#include "data/models/key.h"
#include "data/vault.h"
#include "types/unique_id.h"

struct KeyperOptions {
  std::string config_file;
};

struct ShowKeysOptions {
  bool show_id;
  bool reveal_password;
};

class Keyper {
 public:
  Keyper(const KeyperOptions& options);

  void show_keys(const ShowKeysOptions& options) const;
  void add_key();
  void update_key(const UniqueId& id);
  void delete_keys(const std::vector<UniqueId>& id_array);

 private:
  KeyperOptions options;
  Vault vault;

  Key ask() const;
};

#endif  // SRC_KEYPER_H
