#ifndef PERSON_H 
#define PERSON_H 

#include <string>
#include <cstdint>

class Person
{

public:
    static int build(const std::string& name);

private:
    std::string name;
    std::string street_address, postcode, city;
    std::string company_name, position;
    std::int32_t annual_income{};

};

#endif