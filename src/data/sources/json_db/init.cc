#include <filesystem>
#include <iostream>
#include <string>

#include "data/sources/json_db.h"
#include "types/json.h"
#include "utils/fs.h"

JsonKeyDataSource::JsonKeyDataSource(const std::string& _db_file) {
  this->db_file = _db_file;

  auto data = fs::read_json_file(this->db_file);
  this->keys = {};

  const auto db_dir = fs::path(this->db_file).parent_path();
  if (!fs::exists(db_dir)) fs::create_directories(db_dir);

  if (data.empty()) data = json::array();

  if (!data.is_array()) {
    std::cout << "Invalid JSON data" << std::endl;
    return;
  }

  for (const auto& entry : data)
    this->keys.push_back(this->to_key(entry));
}

JsonKeyDataSource::~JsonKeyDataSource() {
  auto data = json::array();

  for (const auto& key : this->keys)
    data.push_back(this->to_json(key));

  fs::write_json_file(this->db_file, data);
}
