#include "data/vault.h"

#include <memory>
#include <string>
#include <vector>

#include "data/models/key.h"
#include "data/models/key_entity.h"
#include "data/models/query.h"
#include "data/sources/interface.h"
#include "types/unique_id.h"

using std::string;

Vault::Vault(std::shared_ptr<IKeyDataSource> _data_source)
{
    this->data_source = _data_source;
}

std::vector<KeyEntity> Vault::fetch() const
{
    return this->data_source->fetch();
}

std::vector<KeyEntity> Vault::fetch(const Query& query) const
{
    return this->data_source->fetch(query);
}

KeyEntity Vault::find_id(const UniqueId& id) const
{
    return *this->data_source->find_id(id);
}

void Vault::add(const Key& key)
{
    return this->data_source->insert(key);
}

void Vault::update(const UniqueId& id, const Key& key)
{
    return this->data_source->update(id, key);
}

void Vault::erase(const UniqueId& id)
{
    this->data_source->erase(id);
}
