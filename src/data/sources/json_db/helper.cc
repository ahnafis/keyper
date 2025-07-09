#include "data/models/key_entity.h"
#include "data/sources/json_db.h"
#include "types/json.h"

json JsonKeyDataSource::to_json(const KeyEntity& key) const {
  return json::object({
      {"id",       key.id      },
      {"site",     key.site    },
      {"username", key.username},
      {"password", key.password}
  });
};

KeyEntity JsonKeyDataSource::to_key(const json& json_key) const {
  return KeyEntity(
      json_key["id"],
      json_key["site"],
      json_key["username"],
      json_key["password"]
  );
};
