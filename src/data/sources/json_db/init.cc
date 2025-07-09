#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "data/sources/json_db.h"
#include "types/json.h"

namespace fs = std::filesystem;

JsonKeyDataSource::JsonKeyDataSource(const std::string& _db_file) {
  this->db_file = _db_file;

  json data;
  this->keys = {};

  const auto db_dir = fs::path(this->db_file).parent_path();
  if (!fs::exists(db_dir)) fs::create_directories(db_dir);

  std::ifstream stream(this->db_file);
  if (stream.is_open()) stream >> data;
  stream.close();

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

  std::ofstream stream(this->db_file);
  if (stream.is_open()) stream << data << '\n';
  stream.close();
}
