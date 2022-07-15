#include "HtmlBuilder.hpp"

HtmlBuilder::HtmlBuilder(const std::string &root_name)
{
    root.name = root_name;
}

HtmlBuilder &HtmlBuilder::add_child_element(const std::string &child_name, const std::string &child_text)
{
    root.child_elements.emplace_back(HtmlElement{child_name, child_text});

    return *this;
}


HtmlBuilder HtmlBuilder::build(const std::string &root_name)
{
    return HtmlBuilder{root_name};
}

HtmlBuilder::operator HtmlElement()
{
    return std::move(root);
}
