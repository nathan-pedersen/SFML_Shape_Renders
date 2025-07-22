#include "Game.hpp"

Game::Game() {
    if (!loadConfig("text.txt")) return;

    print_members();

    if (!m_font.loadFromFile(m_fontFile)) {
      std::println("Font file not found");
      return;
    }

    m_window = new sf::RenderWindow({m_wWidth, m_wHeight}, "SFML Window");
    m_window->setFramerateLimit(1000);

    // Main loop: runs until window is closed
    while (m_window->isOpen()) {
      sf::Event event;
      // Process all pending events
      while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) m_window->close();
      }

      m_window->clear();  // prepare for drawing
                          // … draw your things here …
      drawShapes();

      for (auto &rec : recs) {
        rec.Update();
      }
      for (auto &circ : circs) {
        circ.Update();
      }
      m_window->display();  // show what was drawn this frame
    }
    std::println("Window Closed.");
  }
Game::~Game() {}

  void Game::print_members() const {
    std::println("width {}, height {}, fontFile {}, fontSize {}, rgb {}{}{}",
                 m_wWidth, m_wHeight, m_fontFile, m_fontSize, m_fontRGB[0],
                 m_fontRGB[1], m_fontRGB[2]);
    for (auto &rec : recs) {
      rec.Print();
    }
    for (auto &circ : circs) {
      circ.Print();
    }
  }

  void Game::drawShapes() {
    for (auto &rec : recs) {
      m_window->draw(rec.getSfRec());
      m_window->draw(rec.getText());
    }
    for (auto &circ : circs) {
      m_window->draw(circ.getSfCir());
      m_window->draw(circ.getText());
    }
  }

  bool Game::loadConfig(std::string filename) {
    // load window width,height,font and shapes from file
    std::fstream fin(filename);
    std::string line;
    std::string first_token;

    while (std::getline(fin, line)) {
      std::istringstream iss(line);

      iss >> first_token;
      if (first_token == "Window") {
        iss >> m_wWidth >> m_wHeight;
      } else if (first_token == "Fonts") {
        iss >> m_fontFile >> m_fontSize >> m_fontRGB[0] >> m_fontRGB[1] >>
            m_fontRGB[2];
      } else if (first_token == "Rectangle") {
        MyRectangle rec = MyRectangle(iss, m_wWidth, m_wHeight, m_font);
        recs.push_back(rec);
      } else if (first_token == "Circle") {
        MyCircle circ = MyCircle(iss, m_wWidth, m_wHeight, m_font);
        circs.push_back(circ);
      }
    }
    return true;
  }
