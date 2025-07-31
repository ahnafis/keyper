#include <filesystem>
#include <iostream>
#include <string>

#include "types/json.h"

#include "data/models/key_entity.h"
#include "data/sources/json_db.h"

#include "utils/fs.h"

JsonKeyDB::JsonKeyDB(const std::string& data_file) {
    this->data_file = data_file;
    const auto db_dir = fs::path(this->data_file).parent_path();

    if (!fs::exists(db_dir))
        fs::create_directories(db_dir);

    auto json_data = fs::read_json_file(this->data_file);
    this->keys = {};

    if (json_data.empty())
        json_data = json::array();

    if (!json_data.is_array()) {
        std::cout << "Invalid JSON data" << std::endl;
        return;
    }

    for (const auto& entry : json_data)
        this->keys.push_back(this->to_key(entry));
}

JsonKeyDB::~JsonKeyDB() {
    json data = json::array();

    for (const KeyEntity& key : this->keys)
        data.push_back(this->to_json(key));

    fs::write_json_file(this->data_file, data);
}
