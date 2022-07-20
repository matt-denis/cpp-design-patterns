#ifndef TEXT_FORMATTER_H
#define TEXT_FORMATTER_H

#include <string>
#include <cstdint>
#include <vector>
#include <iostream>

class FormattedText
{
public:
    struct TextRange
    {
        int32_t start, end;
        bool capitalize;
        bool italic;
        bool bold;

        TextRange(int32_t start, int32_t end,
                  bool capitalize = false,
                  bool italic = false,
                  bool bold = false)
            : start{start}, end{end},
              capitalize{capitalize},
              italic{italic},
              bold{bold} {}

        constexpr bool covers(int32_t position) const noexcept
        {
            return position >= start && position <= end;
        }

    };

    TextRange& get_range(int32_t start, int32_t end)
    {
        formatting.emplace_back(TextRange{start, end});
        return *formatting.rbegin();
    }
    friend std::ostream& operator<<(std::ostream& ost, const FormattedText& text)
    {
        std::string s;

        for (size_t i{0}; i < text.plain_text.length(); ++i) {
            auto c{text.plain_text[i]};
            for (const auto& range : text.formatting) {
                if (range.covers(i)) {
                    if (range.capitalize) c = std::toupper(c);
                    // ...
                }
            }
        }

        return ost << s;
    }

private:
    std::string plain_text;
    std::vector<TextRange> formatting;

};

#endif
