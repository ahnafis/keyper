#pragma once

#include <vector>

#include "data/models/key.h"
#include "data/models/key_entity.h"
#include "data/models/query.h"
#include "types/unique_id.h"

using KeyIterator = std::vector<KeyEntity>::const_iterator;

class KeyDB {
  public:
    virtual ~KeyDB() = default;

    virtual std::vector<KeyEntity> fetch() const = 0;
    virtual std::vector<KeyEntity> fetch(const Query& query) const = 0;
    virtual KeyIterator find_id(const UniqueId& id) const = 0;

    virtual void insert(const Key& key) = 0;
    virtual void update(const UniqueId& id, const Key& key) = 0;
    virtual void erase(const UniqueId& id) = 0;
};
