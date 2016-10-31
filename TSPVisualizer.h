#pragma once
#include <SFML\Graphics.hpp>
class TSPVisualizer
{
public:

	sf::RenderWindow * window;
	sf::Font font;

	std::vector<std::pair<float, float>> drawV;
	std::vector<int16_t> drawT;

	int16_t N;

	TSPVisualizer(int windowsHeight, int windowsWidth, int16_t nodes, std::vector<std::pair<float, float>> V, std::vector<int16_t> T);
	~TSPVisualizer();

	void drawTour();
	void drawNodes();
	void draw();
	void drawPrint(); 
};
