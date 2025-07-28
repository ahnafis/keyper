#include "data/models/key_entity.h"

#include <string>

#include "types/unique_id.h"

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

bool operator==(const Key& left, const KeyEntity& right) {
    return (
        // clang-format off

      left.site == right.site &&
      left.username == right.username &&
      left.password == right.password

        // clang-format on
    );
}

bool operator!=(const Key& left, const KeyEntity& right) {
    return !(left == right);
}

bool operator==(const KeyEntity& left, const Key& right) {
    return right == left;
}

bool operator!=(const KeyEntity& left, const Key& right) {
    return !(right == left);
}
