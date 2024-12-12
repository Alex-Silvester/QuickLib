#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <functional>

namespace ql
{
  class Button : public sf::Sprite
  {
  public:
    Button() = default;
    ~Button() {};

    void setFont(std::string path)
    {
      if (!m_font.loadFromFile(path))
      {
        printf("Button: Unable to load font...\n");
        std::cout << "Font path " << path << std::endl;
      }
    }

    void setText(std::string name = "Button")
    {
      this->m_text.setString(name);
      this->m_text.setPosition(getGlobalBounds().getSize() / 2.f - this->m_text.getGlobalBounds().getSize() / 2.f - sf::Vector2f(this->m_text.getLetterSpacing(), 8 * this->m_text.getLineSpacing()));
    }

    bool buttonPressed(sf::Vector2f pos)
    {

      if (getGlobalBounds().contains(pos))
      {
        setColor(sf::Color(210, 210, 210));
        return true;
      }
      return false;
    }

    void buttonReleased() { setColor(sf::Color::White); }

  private:

    sf::Font m_font;
    sf::Text m_text;
  };
}