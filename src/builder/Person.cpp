#include "Person.hpp"
#include "PersonBuilder.hpp"


PersonBuilderBase Person::create(const std::string& name)
{
    return PersonBuilder{};
}

std::ostream& operator<<(std::ostream& output, const Person& person)
{
    output  << "Name: " << person.name
            << "\nAddress\n: " << person.street_address << "\n"
            << person.postcode << " " << person.city
            <<"\n\nWork:\n" << person.position << "\n"
            << person.company_name << std::endl;

    return output;
}

PersonBuilderBase::operator Person()
{
    return std::move(person);
}
