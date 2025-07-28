#include "utils/fs.h"

#include <doctest/doctest.h>

#include <filesystem>
#include <string>

const std::string file_name = "./hello.txt";
const std::string content = "Hello world!";

TEST_CASE("Should write to a file")
{
    fs::write_file(file_name, content);
    CHECK(fs::exists(file_name));
}

TEST_CASE("Should read a file")
{
    CHECK_EQ(fs::read_file(file_name), content + '\n');
}
