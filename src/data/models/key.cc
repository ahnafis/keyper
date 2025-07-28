#include "key.h"

#include <string>

Key::Key(
    const std::string& site,
    const std::string& username,
    const std::string& password
) {
    this->site = site;
    this->username = username;
    this->password = password;
}

bool Key::operator==(const Key& other) const {
    return (
        // clang-format off

      (this->site == other.site) &&
      (this->username == other.username) &&
      (this->password == other.password)

        // clang-format on
    );
}

bool Key::operator!=(const Key& other) const {
    return !(*this == other);
}
