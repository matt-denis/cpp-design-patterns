#ifndef DATABASE_H
#define DATABASE_H

#include <memory>

class Database
{
protected:
    static std::unique_ptr<Database> __database;

    Database() {/* create database instance */}

public:
    Database(const Database&) = delete;
    Database(Database&&) = delete;

    Database& operator=(const Database&) = delete;
    Database& operator=(Database&&) = delete;

    static const std::unique_ptr<Database>& get_database();

    ~Database() { /* destroy databse instance */}


};

#endif
