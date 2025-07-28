#include "data/sources/json_db.h"
#include "types/unique_id.h"

void JsonKeyDataSource::erase(const UniqueId& id)
{
    if (this->exists(id))
        this->keys.erase(this->find_id(id));
}
