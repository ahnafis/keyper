#include "data/models/key.h"
#include "data/models/key_entity.h"
#include "data/sources/json_db.h"
#include "types/unique_id.h"

void JsonKeyDataSource::update(const UniqueId& id, const Key& key)
{
    if (!this->exists(id))
        return;

    const KeyEntity old_key = *(this->find_id(id));

    if (old_key == key)
        return;

    const auto [site, username, password] = key;
    const auto new_key = KeyEntity(
        id,
        site.empty() ? old_key.site : site,
        username.empty() ? old_key.username : username,
        password.empty() ? old_key.password : password
    );

    std::replace(this->keys.begin(), this->keys.end(), old_key, new_key);
}
