#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>

class MyCircle {
  std::string m_name;
  int m_x;
  int m_y;
  int m_wWidth;
  int m_wHeight;
  float m_xspeed;
  float m_yspeed;
  int m_rgb[3];
  int m_radius;
  sf::CircleShape cir;
  sf::Text text;

 public:
  MyCircle(std::istringstream &iss, int wW, int wH, sf::Font &font);
  void Update();
  inline sf::CircleShape &getSfCir() { return cir; }
  inline sf::Text &getText() { return text; }
  void Print() const;
};
