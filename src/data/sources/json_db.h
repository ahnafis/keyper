#ifndef SRC_DATA_SOURCES_JSON_DB_H
#define SRC_DATA_SOURCES_JSON_DB_H

#include <string>
#include <vector>

#include "data/models/key.h"
#include "data/models/key_entity.h"
#include "data/sources/interface.h"
#include "types/json.h"
#include "types/unique_id.h"

class JsonKeyDataSource: public IKeyDataSource {
 public:
  explicit JsonKeyDataSource(const std::string& db_file);
  ~JsonKeyDataSource();

  std::vector<KeyEntity> fetch() const override;
  std::vector<KeyEntity> fetch(const Query& query) const override;
  KeyIterator find_id(const UniqueId& id) const override;

  void insert(const Key& key) override;
  void update(const UniqueId& id, const Key& key) override;
  void erase(const UniqueId& id) override;

 private:
  std::string db_file;
  std::vector<KeyEntity> keys;

  bool exists(const UniqueId& id) const;
  bool is_unique(const std::string& site, const std::string& username) const;

  json to_json(const KeyEntity& key) const;
  KeyEntity to_key(const json& json_key) const;
};

#endif  // SRC_DATA_SOURCES_JSON_DB_H
