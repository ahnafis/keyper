#ifndef SRC_DATA_VAULT_H
#define SRC_DATA_VAULT_H

#include <memory>
#include <string>
#include <vector>

#include "data/models/key.h"
#include "data/models/key_entity.h"
#include "data/models/query.h"
#include "data/sources/interface.h"
#include "types/unique_id.h"

using std::string;

class Vault {
 public:
  Vault() = default;
  explicit Vault(std::shared_ptr<IKeyDataSource> data_source);

  std::vector<KeyEntity> fetch() const;
  std::vector<KeyEntity> fetch(const Query& query) const;
  KeyEntity find_id(const UniqueId& id) const;

  void add(const Key& key);
  void update(const UniqueId& id, const Key& key);
  void erase(const UniqueId& id);

 private:
  std::shared_ptr<IKeyDataSource> data_source;
};

#endif  // SRC_DATA_VAULT_H
