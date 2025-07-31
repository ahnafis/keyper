#include "types/unique_id.h"

#include "data/sources/json_db.h"

void JsonKeyDB::erase(const UniqueId& id) {
    if (this->exists(id))
        this->keys.erase(this->find_id(id));
}
