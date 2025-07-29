#pragma once

#include <string>

#include "data/models/key.h"
#include "types/unique_id.h"

class KeyEntity {
  public:
    UniqueId id;
    std::string site;
    std::string username;
    std::string password;

    KeyEntity() = default;

    KeyEntity(
        const UniqueId& id,
        const std::string& site,
        const std::string& username,
        const std::string& password
    );

    bool operator==(const KeyEntity& other) const;
    bool operator!=(const KeyEntity& other) const;
};

bool operator==(const Key& key, const KeyEntity& entity);
bool operator!=(const Key& key, const KeyEntity& entity);
bool operator==(const KeyEntity& entity, const Key& key);
bool operator!=(const KeyEntity& entity, const Key& key);
