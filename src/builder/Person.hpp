#ifndef PERSON_H
#define PERSON_H

#include "PersonBuilderBase.hpp"
#include <cstdint>
#include <iostream>
#include <string>

class Person
{

    friend std::ostream& operator<<(std::ostream&, const Person&);
    friend class PersonBuilderBase;
    friend class PersonAddressBuilder;
    friend class PersonJobBuilder;

public:
    static PersonBuilderBase create(const std::string& name);


private:
    std::string name;
    std::string street_address, postcode, city;
    std::string company_name, position;
    std::int32_t annual_income{};
};

#endif
