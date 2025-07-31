#include <doctest/doctest.h>

#include "data/models/key.h"
#include "data/models/key_entity.h"

const auto key_1 = Key("foobar.com", "whoever", "6969");
const auto key_2 = Key("foobazz.com", "noone", "1234");

const auto entity_1 = KeyEntity(1, key_1.site, key_1.username, key_1.password);
const auto entity_2 = KeyEntity(2, key_2.site, key_2.username, key_2.password);

TEST_CASE("Should be able to execute Key == Key ") {
    CHECK_EQ(key_1, key_1);
}

TEST_CASE("Should be able to execute Key != Key ") {
    CHECK_NE(key_1, key_2);
}

TEST_CASE("Should be able to execute KeyEntity == KeyEntity ") {
    CHECK_EQ(entity_1, entity_1);
}

TEST_CASE("Should be able to execute KeyEntity != KeyEntity ") {
    CHECK_NE(entity_1, entity_2);
}

TEST_CASE("Should be able to execute Key == KeyEntity ") {
    CHECK_EQ(key_1, entity_1);
}

TEST_CASE("Should be able to execute Key != KeyEntity ") {
    CHECK_NE(key_2, entity_1);
}

TEST_CASE("Should be able to execute KeyEntity != Key ") {
    CHECK_EQ(entity_1, key_1);
}

TEST_CASE("Should be able to execute KeyEntity != Key ") {
    CHECK_NE(entity_1, key_2);
}
