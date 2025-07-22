#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

class MyRectangle {
    std::string m_name;
    int m_x;
    int m_y;
    int m_wWidth;
    int m_wHeight;
    float m_xspeed;
    float m_yspeed;
    int m_rgb[3];
    int m_w;
    int m_h;
    sf::RectangleShape rec;
    sf::Text text;

public:
    MyRectangle(std::istringstream& iss, int wW, int wH, sf::Font& font);
    void Update();
    inline sf::RectangleShape& getSfRec() { return rec; }
    inline sf::Text& getText() { return text; }
    void Print() const;
};
