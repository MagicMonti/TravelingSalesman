#include <SFML/Graphics.hpp>

#ifndef CONSTS_HPP
#define CONSTS_HPP

namespace consts{
    const double MAX_X = 1600;
    const double MAX_Y = 1200;
    extern sf::Font font;
    extern sf::Font font_2;
    void loadFont(void);
    float getDPIScaleFactor(void);
    //template <typename T>
    bool isIn(const uint& element, std::vector<uint>& vec);
}

#endif