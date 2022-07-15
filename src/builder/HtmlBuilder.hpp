#ifndef HTML_BUILDER_H
#define HTML_BUILDER_H

#include "HtmlElement.hpp"
#include <string>

class HtmlBuilder final
{
public:
    HtmlBuilder(const std::string &root_name);

    static HtmlBuilder build(const std::string &root);

    HtmlBuilder &add_child_element(const std::string &child_name, const std::string &child_text);

    operator HtmlElement();

private:
    HtmlElement root;
};

#endif
