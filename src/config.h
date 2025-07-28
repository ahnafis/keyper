#pragma once

#include <string>

struct KeyperConfig {
    std::string data_file;
    std::string default_email;
};

KeyperConfig load_config(std::string config_file);
