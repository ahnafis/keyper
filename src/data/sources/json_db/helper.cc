#include <string>

#include "data/models/key_entity.h"
#include "data/sources/json_db.h"
#include "types/json.h"
#include "types/unique_id.h"

json JsonKeyDB::to_json(const KeyEntity& key) const {
    return json::object({
        {"id",       key.id      },
        {"site",     key.site    },
        {"username", key.username},
        {"password", key.password}
    });
}

KeyEntity JsonKeyDB::to_key(const json& json_key) const {
    return KeyEntity(
        json_key.at("id").get<UniqueId>(),
        json_key.at("site").get<std::string>(),
        json_key.at("username").get<std::string>(),
        json_key.at("password").get<std::string>()
    );
}
