#ifndef SG_BROWSER_HTML_H
#define SG_BROWSER_HTML_H

namespace SG::Html {
    // Not all actual HTML Tags are listed here 
    enum class TagType {
        None = 0,
        Hyperlink, // <a>
        Bold, // <b>
        Body, // <body>
        LineBreak, // <br />
        Button, // <button>
        Canvas, // <canvas>
        Col, // <col>
        ColGroup, // <colgroup>
        DataList, // <datalist>
        Dialog, // <dialog>
        DivSection, // <div>
        SpanSection, // <span>
        Footer, // <footer>
        Form, // <form>
        Heading1, // <h1>
        Heading2, // <h2>
        Heading3, // <h3>
        Heading4, // <h4>
        Heading5, // <h5>
        Heading6, // <h6>
        Head, // <head>
        Header, // <header>
        Image, // <img>
        Input, // <input>
        Label, // <label>
        ListItem, // <li>
        UnorderedList, // <ul>
        OrderedList, // <ol>
        Menu, // <menu>
        Navigation, // <nav>
        Dropdown, // <select>
        DropdownOptionGroup, // <optgroup>
        DropdownOption, // <option>
        Paragraph, // <p>
        Table, // <table>
        TableBody, // <tbody>
        TableRow, // <tr>
        TableCell, // <td>
        TableHeader, // <thead>
        TableHeaderCell, // <th>
        TableFooter, // <tfoot>
        TextArea, // <textarea> 
    };
    
    enum class AttributeType {
        None = 0,
        
    };
    
    struct TypedTag {
        explicit TypedTag(TagType _type): type(_type) {}
        
        TagType type;
        void* ptr;
    };
    
    struct Attribute {
    public:
        explicit Attribute(AttributeType _type): type(_type) {}
        
        AttributeType type;
    };
    
    struct BoxModel {
        int width;
        int height;
        int paddingTop;
        int paddingRight;
        int paddingBottom;
        int paddingLeft;
        int marginTop;
        int marginRight;
        int marginBottom;
        int marginLeft;
    };
    
    enum class BorderType {
        None = 0,
        Solid,
        Dotted,
        Dashed
    };
    
    struct BorderModel {
        BorderType type;
        int width;
    };
}

#endif //SG_BROWSER_HTML_H
