#include "MyCircle.hpp"

#include <print>

MyCircle::MyCircle(std::istringstream &iss, int wW, int wH, sf::Font &font)
  : m_wWidth(wW), m_wHeight(wH) {
    iss >> m_name >> m_x >> m_y >> m_xspeed >> m_yspeed >> m_rgb[0] >>
      m_rgb[1] >> m_rgb[2] >> m_radius;
    cir.setRadius(m_radius);
    cir.setPosition(m_x, m_y);
    cir.setFillColor(sf::Color(m_rgb[0], m_rgb[1], m_rgb[2]));
    text = sf::Text(m_name, font, 20);
    text.setOrigin(m_radius, m_radius);
    text.setPosition(m_x, m_y);
  }

void MyCircle::Update() {
  cir.setPosition(cir.getPosition().x + m_xspeed,
      cir.getPosition().y + m_yspeed);

  if (cir.getPosition().x + cir.getRadius() * 2 > m_wWidth) {
    m_xspeed *= -1;
  }
  if (cir.getPosition().y + cir.getRadius() * 2 > m_wHeight) {
    m_yspeed *= -1;
  }
  if (cir.getPosition().x < 0) {
    m_xspeed *= -1;
  }
  if (cir.getPosition().y < 0) {
    m_yspeed *= -1;
  }
  text.setPosition(cir.getPosition().x + cir.getRadius(),
      cir.getPosition().y + cir.getRadius());
}

void MyCircle::Print() const {
  std::println(
      "name {}, x {}, y {}, xspeed {}, yspeed {}, rgb {}{}{}, radius {}",
      m_name, m_x, m_y, m_xspeed, m_yspeed, m_rgb[0], m_rgb[1], m_rgb[2],
      m_radius);
}
