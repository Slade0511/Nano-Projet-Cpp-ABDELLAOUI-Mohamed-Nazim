#ifndef BUTTON_H
#define BUTTON_H

#include <string>

class Button {
public:
    std::string id;

    Button(const std::string& buttonId);
    void changeValue();
};

#endif // BUTTON_H
