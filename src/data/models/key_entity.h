#ifndef SRC_DATA_MODELS_KEY_ENTITY_H
#define SRC_DATA_MODELS_KEY_ENTITY_H

#include <string>

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

#endif  // SRC_DATA_MODELS_KEY_ENTITY_H
