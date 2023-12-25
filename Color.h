#ifndef COLOR_H
#define COLOR_H

#include <string>

class Color {
public:
    std::string id;
    std::string color;

    void setColor(const std::string& newColor, const std::string& newId);
};

// Sous-classe pour la couleur Rouge
class RedColor : public Color {
public:
    RedColor() {
        setColor("Rouge", "1");
    }
};

// Sous-classe pour la couleur Bleue
class BlueColor : public Color {
public:
    BlueColor() {
        setColor("Bleu", "2");
    }
};

// Sous-classe pour la couleur Verte
class GreenColor : public Color {
public:
    GreenColor() {
        setColor("Vert", "3");
    }
};

// Sous-classe pour la couleur Jaune
class YellowColor : public Color {
public:
    YellowColor() {
        setColor("Jaune", "4");
    }
};

// Sous-classe pour la couleur Blanche
class WhiteColor : public Color {
public:
    WhiteColor() {
        setColor("Blanc", "5");
    }
};

#endif // COLOR_H
