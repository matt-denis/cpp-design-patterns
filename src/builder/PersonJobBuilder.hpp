#ifndef PERSON_JOB_BUILDER_H
#define PERSON_JOB_BUILDER_H

#include "PersonBuilderBase.hpp"

class PersonJobBuilder : public PersonBuilderBase
{
    typedef PersonJobBuilder& self;
public:
    PersonJobBuilder(Person& person);

    self at(const std::string&);
    self as_a(const std::string&);
    self earning(int32_t);

};

#endif
