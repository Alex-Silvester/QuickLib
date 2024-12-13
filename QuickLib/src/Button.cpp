#include "Button.h"

namespace ql 
{
  void Button::setFont(std::string path)
  {
    if (!m_font.loadFromFile(path))
    {
      printf("Button: Unable to load font...\n");
      std::cout << "Font path " << path << std::endl;
    }
  }

  void Button::setText(std::string name)
  {
    this->m_text.setString(name);
    this->m_text.setPosition
    (
      getGlobalBounds().getSize() / 2.f - this->m_text.getGlobalBounds().getSize() / 2.f - sf::Vector2f(this->m_text.getLetterSpacing(), 
        8 * this->m_text.getLineSpacing())
    );
  }

  bool Button::buttonPressed(sf::Vector2f pos)
  {

    if (getGlobalBounds().contains(pos))
    {
      setColor(sf::Color(210, 210, 210));
      return true;
    }
    return false;
  }

	void Button::buttonReleased() 
	{ 
		setColor(sf::Color::White); 
	}
}