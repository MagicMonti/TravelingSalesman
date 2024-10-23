#include <SFML/Graphics.hpp>

#ifndef CONSTS_HPP
#define CONSTS_HPP

namespace consts{
    const double MAX_X = 800;
    const double MAX_Y = 600;
    extern sf::Font font;
    extern sf::Font font_2;
    void loadFont(void);
    float getDPIScaleFactor(void);
}

#endif