#ifndef SRC_CONFIG_H
#define SRC_CONFIG_H

#include <string>

#include "types/json.h"

struct KeyperConfig {
  std::string data_file;
  std::string default_email;
};

KeyperConfig load_config(std::string config_file);

#endif  // SRC_CONFIG_H
