#include "MyRectangle.hpp"

#include <print>

MyRectangle::MyRectangle(std::istringstream& iss, int wW, int wH,
    sf::Font& font)
    : m_wWidth(wW)
    , m_wHeight(wH)
{
    iss >> m_name >> m_x >> m_y >> m_xspeed >> m_yspeed >> m_rgb[0] >> m_rgb[1] >> m_rgb[2] >> m_w >> m_h;
    rec.setSize(sf::Vector2f(m_w, m_h));
    rec.setPosition(m_x, m_y);
    rec.setFillColor(sf::Color(m_rgb[0], m_rgb[1], m_rgb[2]));
    text = sf::Text(m_name, font, 20);
}

void MyRectangle::Update()
{
    rec.setPosition(rec.getPosition().x + m_xspeed,
        rec.getPosition().y + m_yspeed);

    if (rec.getPosition().x + rec.getSize().x > m_wWidth) {
        m_xspeed *= -1;
    }
    if (rec.getPosition().y + rec.getSize().y > m_wHeight) {
        m_yspeed *= -1;
    }
    if (rec.getPosition().x < 0) {
        m_xspeed *= -1;
    }
    if (rec.getPosition().y < 0) {
        m_yspeed *= -1;
    }
    text.setPosition(rec.getPosition().x, rec.getPosition().y);
}

void MyRectangle::Print() const
{
    std::println(
        "name {}, x {}, y {}, xspeed {}, yspeed {}, rgb {}{}{}, w {}, h {}",
        m_name, m_x, m_y, m_xspeed, m_yspeed, m_rgb[0], m_rgb[1], m_rgb[2], m_w,
        m_h);
}
