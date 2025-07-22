
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <print>
#include <fstream>
#include <sstream>

#include "MyRectangle.hpp"
#include "MyCircle.hpp"

class Game {
  unsigned int m_wWidth;
  unsigned int m_wHeight;
  std::string m_fontFile;
  int m_fontSize;
  int m_fontRGB[3];
  std::vector<MyRectangle> recs;
  std::vector<MyCircle> circs;
  sf::RenderWindow *m_window;
  sf::Font m_font;

 public:
  Game();
  ~Game();

 private:
  void print_members() const;
  void drawShapes();
  bool loadConfig(std::string filename);
};
