#include <iostream>
#include "../include/consts.hpp"

namespace consts{
    sf::Font font;
    sf::Font font_2;
    void loadFont(void){
        if (!font.loadFromFile("resource/varsity_regular.ttf")){
            std::cout << "can not load font\n";
        }
        if (!font_2.loadFromFile("resource/nusamd.ttf")){
            std::cout << "can not load font\n";
        }

    }
}

