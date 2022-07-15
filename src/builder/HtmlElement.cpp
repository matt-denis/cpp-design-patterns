#include "HtmlElement.hpp"

HtmlElement::HtmlElement() {}

HtmlElement::HtmlElement(const std::string name, const std::string text)
    : name{name}, text{text}
{

}

HtmlElement& HtmlElement::operator=(const HtmlElement& html_element)
{
    name = html_element.name;
    text = html_element.text;
}

HtmlElement& HtmlElement::operator=(HtmlElement&& html_element)
{
    name = std::move(html_element.name);
    text = std::move(html_element.text);
}

constexpr const std::string& HtmlElement::get_name() const noexcept
{
    return name;
}

const std::string& HtmlElement::get_text() const noexcept
{
    return text;
}

void HtmlElement::set_name(std::string name) 
{
    this->name = name;
}

void HtmlElement::set_text(std::string text)
{
    this->text = text;
}

const std::vector<HtmlElement>& HtmlElement::get_child_elements() noexcept
{
    return child_elements;
}

HtmlBuilder HtmlElement::build(const std::string& root_name)
{
    return HtmlBuilder{root_name};
}