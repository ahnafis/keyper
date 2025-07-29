/**
 * Wrappers for file system API's.
 */

#pragma once

#include <filesystem>
#include <string>

#include "types/json.h"

namespace fs {

using namespace std::filesystem;

std::string read_file(const std::string& file_name);
json read_json_file(const std::string& file_name);

void write_file(const std::string& file_name, const std::string& content);
void write_json_file(const std::string& file_name, const json& content);

void create_file(const std::string& file_name);
path expand(const std::string& path);

}  // namespace fs
