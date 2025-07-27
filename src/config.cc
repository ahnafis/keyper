#include "config.h"

#include <string>

#include "types/json.h"
#include "utils/fs.h"

KeyperConfig load_config(std::string config_file) {
  KeyperConfig config;
  json data;

  // Resolve config file.
  if (config_file.empty()) {
    const std::string HOME = std::getenv("HOME");
    config_file = HOME + "/.config/keyper/" + "config.json";
  }

  // TODO: Move this to a separate json file.
  const json default_config = json::object({
      {"data_file",     "./data.json"},
      {"default_email", ""           }
  });

  data = fs::read_json_file(config_file);

  if (data.empty() || data.is_null()) {
    data = default_config;
    fs::write_json_file(config_file, data);
  }

  config.data_file = fs::expand(data.at("data_file").get<std::string>());
  config.default_email = data.at("default_email").get<std::string>();

  return config;
}
