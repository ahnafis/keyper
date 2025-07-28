#include "data/models/key_entity.h"

#include <string>

#include "types/unique_id.h"

KeyEntity::KeyEntity(
    const UniqueId& _id,
    const std::string& _site,
    const std::string& _username,
    const std::string& _password
)
{
    this->id = _id;
    this->site = _site;
    this->username = _username;
    this->password = _password;
}

KeyEntity::KeyEntity(const UniqueId& id, const Key& data)
  : KeyEntity(id, data.site, data.username, data.password)
{
}

bool KeyEntity::operator==(const KeyEntity& other) const
{
    return (
        // clang-format off

      (this->id == other.id) &&
      (this->site == other.site) &&
      (this->username == other.username) &&
      (this->password == other.password)

        // clang-format on
    );
}

bool KeyEntity::operator!=(const KeyEntity& other) const
{
    return !(*this == other);
}

bool operator==(const Key& left, const KeyEntity& right)
{
    return (
        // clang-format off

      left.site == right.site &&
      left.username == right.username &&
      left.password == right.password

        // clang-format on
    );
}

bool operator!=(const Key& left, const KeyEntity& right)
{
    return !(left == right);
}

bool operator==(const KeyEntity& left, const Key& right)
{
    return right == left;
}

bool operator!=(const KeyEntity& left, const Key& right)
{
    return !(right == left);
}
