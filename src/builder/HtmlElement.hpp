#ifndef HTML_ELEMENT_H
#define HTML_ELEMENT_H

#include "HtmlBuilder.hpp"
#include <string>
#include <vector>

class HtmlElement
{
    friend class HtmlBuilder;
public:
    HtmlElement(const const HtmlElement&);
    HtmlElement(HtmlElement&&);

    HtmlElement& operator=(const HtmlElement&);
    HtmlElement& operator=(HtmlElement&&);

    constexpr const std::string& get_name() const noexcept;
    const std::string& get_text() const noexcept;

    void set_name(std::string name);
    void set_text(std::string text);

    const std::vector<HtmlElement>& get_child_elements() noexcept;

    static HtmlBuilder build(const std::string& root_name);
    

private:
    std::string name;
    std::string text;
    std::vector<HtmlElement> child_elements;

    HtmlElement();
    HtmlElement(std::string name, std::string text);
    

};

#endif