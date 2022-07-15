#ifndef PERSON_BUILDER_BASE_H
#define PERSON_BUILDER_BASE_H

#include "Person.hpp"
#include "PersonAddressBuilder.hpp"

class PersonBuilderBase
{
public:
    operator Person();

    PersonAddressBuilder lives() const;

protected:
    Person& person;

    explicit PersonBuilderBase(Person& person);




};

#endif
