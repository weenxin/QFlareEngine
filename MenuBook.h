#ifndef MENUBOOK_H
#define MENUBOOK_H

#include "CommonIncludes.h"
#include "EventManager.h"
#include "Menu.h"
#include "Utils.h"

class StatBlock;
class WidgetButton;

class MenuBook
{
public:

    MenuBook();
    ~MenuBook();
    void align();

    void loadGraphics();
    void logic();
    void render();
    void closeWindow();

    std::string book_name;
    std::string last_book_name;
    bool book_loaded;

private:
    class BookImage {
    public:
        Sprite* image;
        int icon;
        Point dest;
        std::vector<StatusID> requires_status;
        std::vector<StatusID> requires_not_status;

        BookImage()
            : image(NULL)
            , icon(-1)
        {}
    };

    class BookText {
    public:
        Sprite* sprite;
        std::string text;
        std::string text_raw;
        std::string font;
        Color color;
        Rect size;
        int justify;
        bool shadow;
        std::vector<StatusID> requires_status;
        std::vector<StatusID> requires_not_status;

        BookText()
            : sprite(NULL)
            , justify(0)
            , shadow(false)
        {}
    };

    class BookButton {
    public:
        WidgetButton* button;
        Point dest;
        std::string image;
        std::string label;
        Event event;

        BookButton()
            : button(NULL)
        {}
    };

    WidgetButton *closeButton;
    std::vector<BookImage> images;
    std::vector<BookText> text;
    std::vector<BookButton> buttons;
    Event* event_open;
    Event* event_close;

    void loadBook();
    void alignElements();
    void loadImage(FileParser &infile, BookImage& bimage);
    void loadText(FileParser &infile, BookText& btext);
    void loadButton(FileParser &infile, BookButton& bbutton);
    void loadBookEvent(FileParser &infile, Event& ev);
    void clearBook();
    void refreshText();
};

#endif // MENUBOOK_H
