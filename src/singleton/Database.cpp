#include "Database.hpp"

std::unique_ptr<Database> Database::__database{nullptr};

const std::unique_ptr<Database>& Database::get_database()
{
    if (! __database)
    {
        __database.reset(new Database{});
    }

    return __database;
}
