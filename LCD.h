#ifndef LCD_H
#define LCD_H

#include <string>

class LCD {
public:
    std::string value;

    void setString(const std::string& newValue);
    void setError();


#endif // LCD_H
};