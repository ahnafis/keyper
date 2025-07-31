#include <algorithm>
#include <vector>

#include "types/unique_id.h"

#include "data/models/key_entity.h"
#include "data/models/query.h"
#include "data/sources/interface.h"
#include "data/sources/json_db.h"

std::vector<KeyEntity> JsonKeyDB::fetch() const {
    return this->keys;
}

std::vector<KeyEntity> JsonKeyDB::fetch(const Query& query) const {
    std::vector<KeyEntity> matched_keys = {};

    bool site_matched = false;
    bool username_matched = false;

    for (const auto& key : this->keys) {
        site_matched = query.site.empty() || key.site == query.site;
        username_matched =
            query.username.empty() || key.username == query.username;

        if (site_matched && username_matched)
            matched_keys.push_back(key);
    }

    return matched_keys;
}

KeyIterator JsonKeyDB::find_id(const UniqueId& id) const {
    return std::find_if(
        this->keys.begin(),
        this->keys.end(),
        [&id](const KeyEntity& key) -> bool {
            return key.id == id;
        }
    );
}
