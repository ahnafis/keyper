#ifndef SRC_CONFIG_H
#define SRC_CONFIG_H

#include <string>

#include "types/json.h"

class KeyperConfig {
 public:
  std::string db_file;

  explicit KeyperConfig(const std::string& config_file);

 private:
  std::string config_file;

  json default_config;
  json to_json() const;
};

#endif  // SRC_CONFIG_H
