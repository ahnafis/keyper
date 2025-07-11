/**
 * This wrapper file system APIs are only project specific. They are meant to do
 * certain jobs. It may not follow some common standards.
 */

#ifndef SRC_UTILS_FS_H
#define SRC_UTILS_FS_H

#include <string>

#include "types/json.h"

namespace fs {

using namespace std::filesystem;

void create_file(const std::string& file_name);

void write_file(const std::string& file_name, const std::string& content);
void write_json_file(const std::string& file_name, const json& content);

std::string read_file(const std::string& file_name);
json read_json_file(const std::string& file_name);

}  // namespace fs

#endif  // SRC_UTILS_FS_H
