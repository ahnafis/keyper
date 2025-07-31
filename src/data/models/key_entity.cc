#include "data/models/key_entity.h"

#include <string>

#include "types/unique_id.h"

#include "data/models/key.h"

KeyEntity::KeyEntity(
    const UniqueId& id,
    const std::string& site,
    const std::string& username,
    const std::string& password
) {
    this->id = id;
    this->site = site;
    this->username = username;
    this->password = password;
}

bool KeyEntity::operator==(const KeyEntity& other) const {
    return (
        // clang-format off

      (this->id == other.id) &&
      (this->site == other.site) &&
      (this->username == other.username) &&
      (this->password == other.password)

        // clang-format on
    );
}

bool KeyEntity::operator!=(const KeyEntity& other) const {
    return !(*this == other);
}

bool operator==(const Key& key, const KeyEntity& entity) {
    return (
        // clang-format off

      key.site == entity.site &&
      key.username == entity.username &&
      key.password == entity.password

        // clang-format on
    );
}

bool operator!=(const Key& key, const KeyEntity& entity) {
    return !(key == entity);
}

bool operator==(const KeyEntity& entity, const Key& key) {
    return key == entity;
}

bool operator!=(const KeyEntity& entity, const Key& key) {
    return !(key == entity);
}
