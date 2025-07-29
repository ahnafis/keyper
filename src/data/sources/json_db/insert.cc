#include "data/models/key.h"
#include "data/models/key_entity.h"
#include "data/sources/json_db.h"

void JsonKeyDB::insert(const Key& key) {
    const auto [site, username, password] = key;

    if (!this->is_unique(site, username))
        return;

    const UniqueId id = this->keys.empty() ? 1 : this->keys.back().id + 1;
    const auto new_key = KeyEntity(id, site, username, password);

    this->keys.push_back(new_key);
}
