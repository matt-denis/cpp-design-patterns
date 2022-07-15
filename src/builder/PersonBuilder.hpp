#ifndef PERSON_BUILDER_H
#define PERSON_BUILDER_H

#include "PersonBuilderBase.hpp"

class PersonBuilder : public PersonBuilderBase
{
public:
    PersonBuilder();

private:
    Person person;

};

#endif
