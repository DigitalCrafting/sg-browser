#ifndef SG_BROWSER_HTML_FORMATTER_H
#define SG_BROWSER_HTML_FORMATTER_H

#include "src/html/types/Html.h"

#include <fmt/format.h>

#define LOCAL_ENUM_NAME(val) #val

namespace SG::Html {
    static std::string_view TagToString(SG::Html::TagType tag) {
        switch (tag) {
            case SG::Html::TagType::None:
                return LOCAL_ENUM_NAME(None);
            case SG::Html::TagType::Hyperlink:
                return LOCAL_ENUM_NAME(Hyperlink);
            case SG::Html::TagType::Bold:
                return LOCAL_ENUM_NAME(Bold);
            case SG::Html::TagType::Body:
                return LOCAL_ENUM_NAME(Body);
            case SG::Html::TagType::LineBreak:
                return LOCAL_ENUM_NAME(LineBreak);
            case SG::Html::TagType::Button:
                return LOCAL_ENUM_NAME(Button);
            case SG::Html::TagType::Canvas:
                return LOCAL_ENUM_NAME(Canvas);
            case SG::Html::TagType::Col:
                return LOCAL_ENUM_NAME(Col);
            case SG::Html::TagType::ColGroup:
                return LOCAL_ENUM_NAME(ColGroup);
            case SG::Html::TagType::DataList:
                return LOCAL_ENUM_NAME(DataList);
            case SG::Html::TagType::Dialog:
                return LOCAL_ENUM_NAME(Dialog);
            case SG::Html::TagType::DivSection:
                return LOCAL_ENUM_NAME(DivSection);
            case SG::Html::TagType::SpanSection:
                return LOCAL_ENUM_NAME(SpanSection);
            case SG::Html::TagType::Footer:
                return LOCAL_ENUM_NAME(Footer);
            case SG::Html::TagType::Form:
                return LOCAL_ENUM_NAME(Form);
            case SG::Html::TagType::Heading1:
                return LOCAL_ENUM_NAME(Heading1);
            case SG::Html::TagType::Heading2:
                return LOCAL_ENUM_NAME(Heading2);
            case SG::Html::TagType::Heading3:
                return LOCAL_ENUM_NAME(Heading3);
            case SG::Html::TagType::Heading4:
                return LOCAL_ENUM_NAME(Heading4);
            case SG::Html::TagType::Heading5:
                return LOCAL_ENUM_NAME(Heading5);
            case SG::Html::TagType::Heading6:
                return LOCAL_ENUM_NAME(Heading6);
            case SG::Html::TagType::Head:
                return LOCAL_ENUM_NAME(Head);
            case SG::Html::TagType::Header:
                return LOCAL_ENUM_NAME(Header);
            case SG::Html::TagType::Image:
                return LOCAL_ENUM_NAME(Image);
            case SG::Html::TagType::Input:
                return LOCAL_ENUM_NAME(Input);
            case SG::Html::TagType::Label:
                return LOCAL_ENUM_NAME(Label);
            case SG::Html::TagType::ListItem:
                return LOCAL_ENUM_NAME(ListItem);
            case SG::Html::TagType::UnorderedList:
                return LOCAL_ENUM_NAME(UnorderedList);
            case SG::Html::TagType::OrderedList:
                return LOCAL_ENUM_NAME(OrderedList);
            case SG::Html::TagType::Menu:
                return LOCAL_ENUM_NAME(Menu);
            case SG::Html::TagType::Navigation:
                return LOCAL_ENUM_NAME(Navigation);
            case SG::Html::TagType::Dropdown:
                return LOCAL_ENUM_NAME(Dropdown);
            case SG::Html::TagType::DropdownOptionGroup:
                return LOCAL_ENUM_NAME(DropdownOptionGroup);
            case SG::Html::TagType::DropdownOption:
                return LOCAL_ENUM_NAME(DropdownOption);
            case SG::Html::TagType::Paragraph:
                return LOCAL_ENUM_NAME(Paragraph);
            case SG::Html::TagType::Table:
                return LOCAL_ENUM_NAME(Table);
            case SG::Html::TagType::TableBody:
                return LOCAL_ENUM_NAME(TableBody);
            case SG::Html::TagType::TableRow:
                return LOCAL_ENUM_NAME(TableRow);
            case SG::Html::TagType::TableCell:
                return LOCAL_ENUM_NAME(TableCell);
            case SG::Html::TagType::TableHeader:
                return LOCAL_ENUM_NAME(TableHeader);
            case SG::Html::TagType::TableHeaderCell:
                return LOCAL_ENUM_NAME(TableHeaderCell);
            case SG::Html::TagType::TableFooter:
                return LOCAL_ENUM_NAME(TableFooter);
            case SG::Html::TagType::TextArea:
                return LOCAL_ENUM_NAME(TextArea);
            default:
                return "Unknown";
        }
    }
}


namespace fmt {
    template<>
    struct fmt::formatter<SG::Html::TagType> {
        constexpr auto parse(format_parse_context &ctx) { return ctx.begin(); }

        template<typename FormatContext>
        auto format(SG::Html::TagType type, FormatContext &ctx) const {
            std::string_view name = SG::Html::TagToString(type);
            return fmt::format_to(ctx.out(), name);
        }
    };
}

#undef LOCAL_ENUM_NAME

#endif //SG_BROWSER_HTML_FORMATTER_H
