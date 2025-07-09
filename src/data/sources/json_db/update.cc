#include "data/models/key.h"
#include "data/models/key_entity.h"
#include "data/sources/json_db.h"
#include "types/unique_id.h"

void JsonKeyDataSource::update(const UniqueId& id, const Key& key) {
  if (!this->exists(id)) return;

  const auto old_key = *this->find_id(id);

  const auto [site, username, password] = key;
  const KeyEntity new_key = {
      id,
      site.empty() ? old_key.site : site,
      username.empty() ? old_key.username : username,
      password.empty() ? old_key.password : password
  };

  if (old_key == new_key) return;

  std::replace(this->keys.begin(), this->keys.end(), old_key, new_key);
}
