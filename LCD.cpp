#include "LCD.h"
#include <iostream>


void LCD::setString(const std::string& newValue) {
    value = newValue;
}

void LCD::setError() {
    value = "Erreur";
}
