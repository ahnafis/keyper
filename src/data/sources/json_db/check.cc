#include <string>

#include "data/models/key_entity.h"
#include "data/sources/json_db.h"
#include "types/unique_id.h"

bool JsonKeyDataSource::exists(const UniqueId& id) const {
  return this->find_id(id) != this->keys.end();
}

bool JsonKeyDataSource::is_unique(
    const std::string& site, const std::string& username
) const {
  auto iterator = std::find_if(
      this->keys.begin(),
      this->keys.end(),
      [&site, &username](const KeyEntity& key) -> bool {
        return (key.site == site) && (key.username == username);
      }
  );

  return iterator == this->keys.end();
}
