#include "PersonJobBuilder.hpp"

PersonJobBuilder::PersonJobBuilder(Person& person) : PersonBuilderBase{person} {}

PersonJobBuilder::self PersonJobBuilder::at(const std::string& company_name)
{
    person.company_name = company_name;
    return *this;
}

PersonJobBuilder::self PersonJobBuilder::as_a(const std::string& position)
{
    person.position = position;
    return *this;
}

PersonJobBuilder::self PersonJobBuilder::earning(int32_t annual_income)
{
    person.annual_income = annual_income;
    return *this;
}
