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

    void setFont(std::string path);

    void setText(std::string name = "Button");

    bool buttonPressed(sf::Vector2f pos);

    void buttonReleased();

  private:

    sf::Font m_font;
    sf::Text m_text;
  };
}