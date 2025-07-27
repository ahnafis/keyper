#include "config.h"

#include <doctest/doctest.h>

const auto config_file = "./config.json";
const KeyperConfig config = load_config(config_file);

TEST_CASE("Should read config") {
  CHECK_EQ(config.data_file, "./data.json");
}

TEST_CASE("Should find the config file") {
  CHECK(std::filesystem::exists(config_file));
}
