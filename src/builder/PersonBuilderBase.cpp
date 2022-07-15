#include "PersonBuilderBase.hpp"

PersonBuilderBase::PersonBuilderBase(Person& person) : person{person} {}

PersonAddressBuilder PersonBuilderBase::lives() const
{
    return PersonAddressBuilder{person};
}

