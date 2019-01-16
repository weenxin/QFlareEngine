#ifndef MENUCONFIRM_H
#define MENUCONFIRM_H


#include "CommonIncludes.h"
#include "Menu.h"
#include "WidgetLabel.h"

class WidgetButton;

class MenuConfirm : public Menu {
protected:
    WidgetButton *buttonConfirm;
    WidgetButton *buttonClose;
    WidgetLabel label;

    std::string boxMsg;
    bool hasConfirmButton;

public:
    MenuConfirm(const std::string&, const std::string&);
    ~MenuConfirm();

    void logic();
    void align();
    virtual void render();

    bool confirmClicked;
    bool cancelClicked;
    bool isWithinButtons;
};

#endif // MENUCONFIRM_H
