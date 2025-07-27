#include "config.h"

#include <iostream>
#include <string>

#include "types/json.h"
#include "utils/fs.h"

KeyperConfig::KeyperConfig(const std::string& _config_file) {
  this->config_file = _config_file;

  if (this->config_file.empty()) {
    const std::string HOME = std::getenv("HOME");
    this->config_file = HOME + "/.config/keyper/" + "config.json";
  }

  auto config = fs::read_json_file(this->config_file);

  this->default_config = {
      {"db_file", "./data.json"}
  };

  if (config.empty() || config.is_null()) {
    config = this->default_config;
    fs::write_json_file(this->config_file, config);
    std::cout << this->config_file << std::endl;
  }

  this->db_file = config.at("db_file").get<std::string>();
  this->db_file = fs::expand(this->db_file);

  this->default_email = config.at("default_email").get<std::string>();
}

json KeyperConfig::to_json() const {
  auto config = json::object();

  config["db_file"] = this->db_file;
  config["default_email"] = this->default_email;

  return config;
}
