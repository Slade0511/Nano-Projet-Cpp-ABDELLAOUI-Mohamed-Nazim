/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

//#include "mbed.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <unistd.h> // Pour la fonction sleep
#include <cstdlib> // Pour la génération de nombres aléatoires
#include <ctime>
#include "Color.h"  // Inclure le fichier d'en-tête de la classe Color
#include "LCD.h"    // Inclure le fichier d'en-tête de la classe LCD
#include "Button.h" 
#include "grove_lcd_rgb_backlight.h"  // Incluez le bon chemin vers votre bibliothèque



// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


void threadComparaison(Color& color, LCD& lcd, Button& button) {
    while (true) {
        // Lecture de la valeur de l'id référence dans le code principal
        std::string idReference = color.id;  // Remplacer par la lecture réelle

        // Lecture de la valeur de l'attribut id de la classe Button
        std::string buttonId = button.id;

        // Création d'un objet aléatoire parmi les couleurs
        Color randomColor;
        int randomIndex = std::rand() % 5;
        switch (randomIndex) {
    case 0: {
        YellowColor yellowColor;
        randomColor.setColor(yellowColor.color, yellowColor.id);
        break;
    }
    case 1: {
        GreenColor greenColor;
        randomColor.setColor(greenColor.color, greenColor.id);
        break;
    }
    case 2: {
        BlueColor blueColor;
        randomColor.setColor(blueColor.color, blueColor.id);
        break;
    }
    case 3: {
        RedColor redColor;
        randomColor.setColor(redColor.color, redColor.id);
        break;
    }
    case 4: {
        WhiteColor whiteColor;
        randomColor.setColor(whiteColor.color, whiteColor.id);
        break;
    }
    default:
        break;
}


        // Comparaison des valeurs
        if (idReference == buttonId) {
            lcd.setString(randomColor.color); // Afficher une nouvelle couleur
        } else {
            std::string erreur;
            lcd.setError(); // Envoyer l'erreur dans le lcd
            sleep(1);  // Attendre 1 seconde
            lcd.setString(randomColor.color); // Afficher une nouvelle couleur
        }

    }
}

void threadPrint(LCD& lcd) {
    while (true) {
        // Simulation d'une opération de comparaison
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        Grove_LCD_RGB_Backlight lcdPrinter;
        // Affichage de la valeur de la classe LCD
        lcdPrinter.clear();
        lcdPrinter.print(lcd.value);

    }
}

void threadButton(Button& button) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        button.changeValue();
    }
}

void Initalisation() {        
        Color randomColor;
        int randomIndex = std::rand() % 5;
        switch (randomIndex) {
    case 0: {
        YellowColor yellowColor;
        randomColor.setColor(yellowColor.color, yellowColor.id);
        break;
    }
    case 1: {
        GreenColor greenColor;
        randomColor.setColor(greenColor.color, greenColor.id);
        break;
    }
    case 2: {
        BlueColor blueColor;
        randomColor.setColor(blueColor.color, blueColor.id);
        break;
    }
    case 3: {
        RedColor redColor;
        randomColor.setColor(redColor.color, redColor.id);
        break;
    }
    case 4: {
        WhiteColor whiteColor;
        randomColor.setColor(whiteColor.color, whiteColor.id);
        break;
    }
    default:
        break;
}


        // Comparaison des valeurs
       
}

int main()
{
    Initalisation()

    while (true) {
        Thread comparaisonThread(osPriorityNormal, 1024);  // Priorité normale, 1024 octets de pile
        Thread valueButtonThread(osPriorityNormal, 1024);  // Priorité normale, 1024 octets de pile
        Thread affichageThread(osPriorityNormal, 1024);

    // Démarrage des threads
    comparaisonThread.start(callback(threadComparaison));
    affichageThread.start(callback(threadPrint));
    valueButtonThread.start(callback(threadButton));
    }
}