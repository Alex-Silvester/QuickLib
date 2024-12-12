
#include "QuickLib.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(540, 360), "window");

	sf::Sprite spr;

	ql::Button button;

	sf::Texture texture;

	if (!texture.loadFromFile("C:/Users/alexs/various cpp/QuickLib/QuickLib/Data/button.png"))
		printf("oops..\n");
	button.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;

		auto mouse_pos = sf::Mouse::getPosition(window);
		sf::Vector2f mouse_pos_f = static_cast<sf::Vector2f>(mouse_pos);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 0;
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				button.buttonPressed(mouse_pos_f);
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				button.buttonReleased();
			}
		}

		window.clear(sf::Color::Black);

		window.draw(button);

		window.display();
	}
	return 0;
}