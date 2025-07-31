#include <string>

#include "types/json.h"
#include "types/unique_id.h"

#include "data/models/key_entity.h"
#include "data/sources/json_db.h"

json JsonKeyDB::to_json(const KeyEntity& key) const {
    return json::object({
        {"id",       key.id      },
        {"site",     key.site    },
        {"username", key.username},
        {"password", key.password}
    });
}

KeyEntity JsonKeyDB::to_key(const json& json_key) const {
    const auto id = json_key.at("id").get<UniqueId>();
    const auto site = json_key.at("site").get<std::string>();
    const auto username = json_key.at("username").get<std::string>();
    const auto password = json_key.at("password").get<std::string>();

    return KeyEntity(id, site, username, password);
}
