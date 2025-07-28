#pragma once

#include <string>

class Key {
  public:
    std::string site;
    std::string username;
    std::string password;

    Key() = default;

    Key(const std::string& site,
        const std::string& username,
        const std::string& password);

    bool operator==(const Key& other) const;
    bool operator!=(const Key& other) const;
};
