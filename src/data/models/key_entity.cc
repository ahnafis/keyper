#include "data/models/key_entity.h"

#include <string>

#include "types/unique_id.h"

KeyEntity::KeyEntity(
    const UniqueId& _id,
    const std::string& _site,
    const std::string& _username,
    const std::string& _password
) {
  this->id = _id;
  this->site = _site;
  this->username = _username;
  this->password = _password;
};

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
