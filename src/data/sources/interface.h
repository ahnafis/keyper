#ifndef SRC_DATA_SOURCES_INTERFACE_H
#define SRC_DATA_SOURCES_INTERFACE_H

#include <vector>

#include "data/models/key.h"
#include "data/models/key_entity.h"
#include "data/models/query.h"
#include "types/unique_id.h"

using KeyIterator = std::vector<KeyEntity>::const_iterator;

class IKeyDataSource {
 public:
  virtual ~IKeyDataSource() = default;

  virtual std::vector<KeyEntity> fetch() const = 0;
  virtual std::vector<KeyEntity> fetch(const Query& query) const = 0;
  virtual KeyIterator find_id(const UniqueId& id) const = 0;

  virtual void insert(const Key& key) = 0;
  virtual void update(const UniqueId& id, const Key& key) = 0;
  virtual void erase(const UniqueId& id) = 0;
};

#endif  // SRC_DATA_SOURCES_INTERFACE_H
