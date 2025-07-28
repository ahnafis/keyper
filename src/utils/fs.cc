#include "utils/fs.h"

#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "types/json.h"

namespace fs {

void create_file(const std::string& file_name)
{
    fs::write_file(file_name, "");
}

void write_file(const std::string& file_name, const std::string& content)
{
    const auto parent_path = fs::path(file_name).parent_path();
    if (!fs::exists(parent_path)) {
        fs::create_directories(parent_path);
    }

    std::ofstream stream(file_name);

    if (stream.is_open()) {
        stream << content << '\n';
    }

    stream.close();
}

void write_json_file(const std::string& file_name, const json& content)
{
    fs::write_file(file_name, content.dump());
}

std::string read_file(const std::string& file_name)
{
    std::string content;
    std::string line;

    try {
        std::ifstream stream(file_name);

        if (!stream.is_open()) {
            stream.close();
        }

        while (std::getline(stream, line)) {
            content += line + '\n';
        }

        stream.close();
    }

    catch (const std::exception& error) {
        std::cout << error.what() << std::endl;
    }

    return content;
}

json read_json_file(const std::string& file_name)
{
    json content;
    std::ifstream stream(file_name);

    if (stream.is_open()) {
        stream >> content;
    }

    stream.close();
    return content;
}

fs::path expand(const std::string& path)
{
    if (path.starts_with("~")) {
        const std::string HOME = std::getenv("HOME");
        return fs::path(HOME + path.substr(1));
    }

    return fs::path(path);
}

};  // namespace fs
