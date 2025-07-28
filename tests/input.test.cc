#include "utils/input.h"

#include <doctest/doctest.h>

#include <iostream>
#include <sstream>
#include <string>

class cin_redirect {
  public:
    explicit cin_redirect(const std::istringstream& input_stream);
    ~cin_redirect();

  private:
    std::streambuf* old_buffer;
};

cin_redirect::cin_redirect(const std::istringstream& input_stream)
{
    this->old_buffer = std::cin.rdbuf(input_stream.rdbuf());
}

cin_redirect::~cin_redirect()
{
    std::cin.rdbuf(old_buffer);
}

TEST_CASE("Should convert command-line input to int")
{
    std::istringstream fake_input("42\n");
    cin_redirect redirect(fake_input);

    CHECK_EQ(std::stoi(input()), 42);
}

TEST_CASE("Should convert command-line input to string")
{
    std::string text = "C++ is the best";

    std::istringstream fake_input(text + '\n');
    cin_redirect redirect(fake_input);

    CHECK_EQ(input(), text);
}
