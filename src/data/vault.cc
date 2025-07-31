#include "data/vault.h"

#include <memory>
#include <vector>

#include "types/unique_id.h"

#include "data/models/key.h"
#include "data/models/key_entity.h"
#include "data/models/query.h"
#include "data/sources/interface.h"

Vault::Vault(const std::shared_ptr<KeyDB> db) {
    this->db = db;
}

std::vector<KeyEntity> Vault::fetch() const {
    return this->db->fetch();
}

std::vector<KeyEntity> Vault::fetch(const Query& query) const {
    return this->db->fetch(query);
}

KeyEntity Vault::find_id(const UniqueId& id) const {
    return *this->db->find_id(id);
}

void Vault::add(const Key& key) {
    return this->db->insert(key);
}

void Vault::update(const UniqueId& id, const Key& key) {
    return this->db->update(id, key);
}

void Vault::erase(const UniqueId& id) {
    this->db->erase(id);
}
