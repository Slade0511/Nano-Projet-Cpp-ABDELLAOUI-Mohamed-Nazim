#include "Button.h"

Button::Button(const std::string& buttonId) : id(buttonId) {
    
}

void Button::changeValue() {
    // Lire la valeur de la broche analogique p15
    AnalogIn analogValue(p15);  // Supposons que p15 est la broche analogique que vous utilisez
    float analogVoltage = analogValue.read() * 5;  //  tension d'alimentation de 5V

    // Mettre à jour l'ID en fonction de la valeur lue
    if (analogVoltage < 0.6) {
        id = 0;
    } else if (analogVoltage < 2) {
        id = 1;
    } else if (analogVoltage < 3) {
        id = 2;
    } else if (analogVoltage < 4) {
        id = 3;
    } else {
        id = 4;
    }
}