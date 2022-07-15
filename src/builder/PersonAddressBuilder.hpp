#ifndef PERSON_ADDRESS_BUILDER_H
#define PERSON_ADDRESS_BUILDER_H

#include "PersonBuilderBase.hpp"

class PersonAddressBuilder : public PersonBuilderBase
{
    typedef PersonAddressBuilder& self;
public:
    PersonAddressBuilder(Person& person);

    self at(const std::string&);
    self with_postcode(const std::string&);
    self in(const std::string&);
};

#endif
