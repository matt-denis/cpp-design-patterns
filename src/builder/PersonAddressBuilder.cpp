#include "PersonBuilderBase.hpp"

PersonAddressBuilder::PersonAddressBuilder(Person& person) : PersonBuilderBase{person} {}

PersonAddressBuilder::self PersonAddressBuilder::at(const std::string& street_address)
{
    person.street_address = street_address;
    return *this;
}

PersonAddressBuilder::self PersonAddressBuilder::with_postcode(const std::string& postcode)
{
    person.postcode = postcode;
    return *this;
}

PersonAddressBuilder::self PersonAddressBuilder::in(const std::string& city)
{
    person.city = city;
    return *this;
}
