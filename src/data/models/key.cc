#include "key.h"

#include <string>

Key::Key(
    const std::string& _site,
    const std::string& _username,
    const std::string& _password
)
{
    this->site = _site;
    this->username = _username;
    this->password = _password;
}

bool Key::operator==(const Key& other) const
{
    return (
        // clang-format off

      (this->site == other.site) &&
      (this->username == other.username) &&
      (this->password == other.password)

        // clang-format on
    );
}

bool Key::operator!=(const Key& other) const
{
    return !(*this == other);
}
