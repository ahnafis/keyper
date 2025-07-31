#include "data/models/key.h"
#include "data/models/key_entity.h"
#include "data/sources/json_db.h"

void JsonKeyDB::insert(const Key& key) {
    if (!this->is_unique(key.site, key.username))
        return;

    const UniqueId id = this->keys.empty() ? 1 : this->keys.back().id + 1;
    const auto new_key = KeyEntity(id, key);

    this->keys.push_back(new_key);
}
