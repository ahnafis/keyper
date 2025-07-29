#include "utils/input.h"

#include <doctest/doctest.h>

#include <iostream>
#include <sstream>
#include <string>

class input_stream {
  public:
    explicit input_stream(const std::istringstream& input_stream) {
        this->old_buffer = std::cin.rdbuf(input_stream.rdbuf());
    }

    ~input_stream() {
        std::cin.rdbuf(old_buffer);
    }

  private:
    std::streambuf* old_buffer;
};

TEST_CASE("Should convert command-line input to int") {
    std::istringstream fake_input("42\n");
    const auto copy = input_stream(fake_input);

    CHECK_EQ(std::stoi(input()), 42);
}

TEST_CASE("Should convert command-line input to string") {
    std::string text = "C++ is the best";

    std::istringstream fake_input(text + '\n');
    const auto copy = input_stream(fake_input);

    CHECK_EQ(input(), text);
}
