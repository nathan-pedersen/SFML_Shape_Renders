
#include <SFML/Graphics.hpp>
#include <fstream>
#include <print>
#include <sstream>
#include <string>
#include <vector>

#include "MyCircle.hpp"
#include "MyRectangle.hpp"

class Game {
    unsigned int m_wWidth;
    unsigned int m_wHeight;
    std::string m_fontFile;
    int m_fontSize;
    int m_fontRGB[3];
    std::vector<MyRectangle> recs;
    std::vector<MyCircle> circs;
    sf::RenderWindow* m_window;
    sf::Font m_font;

public:
    Game();
    ~Game();

private:
    void print_members() const;
    void drawShapes();
    bool loadConfig(std::string filename);
};
