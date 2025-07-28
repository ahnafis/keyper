#include "data/sources/json_db.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <vector>

#include "data/models/key.h"

auto db = JsonKeyDataSource("./data/test_db.json");

auto key_1 = Key("whatever", "ahnaf", "123");
auto key_2 = Key("doodle", "ahnaf", "456");
auto key_3 = Key("doodle", "nafis", "456");

TEST_CASE("Should fetch the keys")
{
    CHECK_EQ(db.fetch().size(), 0);
}

TEST_CASE("Should insert keys")
{
    db.insert(key_1);
    db.insert(key_2);
    db.insert(key_3);

    CHECK_EQ(db.fetch()[0], key_1);
    CHECK_EQ(db.fetch()[1], key_2);
    CHECK_EQ(db.fetch()[2], key_3);
}

TEST_CASE("Should not insert identical keys")
{
    db.insert(key_1);
    CHECK_EQ(db.fetch().size(), 3);
}

TEST_CASE("Should find a key by id")
{
    CHECK_EQ(*db.find_id(1), key_1);
}

TEST_CASE("Should fetch specified keys")
{
    auto keys = db.fetch({.site = "doodle"});

    CHECK_EQ(keys[0], key_2);
    CHECK_EQ(keys[1], key_3);
}

TEST_CASE("Should update a key")
{
    key_1.site = "google";
    db.update(1, key_1);

    CHECK_EQ(*db.find_id(1), key_1);
}

TEST_CASE("Should delete all keys")
{
    db.erase(1);
    db.erase(2);
    db.erase(3);

    CHECK_EQ(db.fetch().size(), 0);
}

TEST_CASE("Should not fail if given ID is not found")
{
    db.erase(1);
    CHECK_EQ(db.fetch().size(), 0);
}
