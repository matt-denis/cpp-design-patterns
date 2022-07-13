#ifndef PERSON_BUILDER_BASE_H
#define PERSON_BUILDER_BASE_H

#include "Person.hpp"

class PersonBuilderBase
{
public:
    constexpr Person& operator()() const noexcept;
protected:
    PersonBuilderBase(Person& person);
private:
    Person& person;



};

#endif