#include "TSPVisualizer.h"
#include <iostream>

TSPVisualizer::TSPVisualizer(int windowsHeight, int windowsWidth, int16_t nodes, std::vector<std::pair<float, float>> V, std::vector<int16_t> T)
{
	window = new sf::RenderWindow(sf::VideoMode(windowsWidth, windowsHeight), "TSP Visualizer");
	if (!font.loadFromFile("COURIER.ttf"))
	{
		std::cout << "ERROR: font" << std::endl;
	}
	N = nodes; 
	drawV = V; 
	drawT = T; 
}

TSPVisualizer::~TSPVisualizer()
{
	delete window; 
}

/*
* Draws the nodes and indexes that are in the TSP
*/
void TSPVisualizer::drawNodes() {
	int radius = 1; //used for centering
	for (int i = 0; i < N; i++) {
		//Labelling 
		sf::Text text;
		text.setFont(font);
		text.setString(std::to_string(i)); //" - " + std::to_string((V[i].first)) + ", " + std::to_string((V[i].second))
		text.setCharacterSize(9);
		text.setPosition(drawV[i].first - radius, drawV[i].second - 35);
		text.setColor(sf::Color::Green);
		//window->draw(text);
		//Cirle
		sf::CircleShape circle(radius, 150);
		circle.setOrigin(radius, radius);
		circle.setFillColor(sf::Color::White);
		circle.setPosition(drawV[i].first, drawV[i].second);
		window->draw(circle);
	}
}

/*
* Draws the tour that is stored in vector T
*/
void TSPVisualizer::drawTour() {
	sf::VertexArray tour(sf::LinesStrip, N);

	int16_t i = 0;
	do {
		tour.append(sf::Vertex(sf::Vector2f(drawV[drawT[i]].first, drawV[drawT[i]].second)));
		i = drawT[i];
	} while (i != 0);

	window->draw(tour);
}

void TSPVisualizer::draw() {
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		//Draw stuff here: 
		drawNodes();
		drawTour();
		window->display();
	}
}

void TSPVisualizer::drawPrint() {
	std::cout << "Inside Visualizer" << std::endl; 
	for (int i = 0; i < N; i++) {
		std::cout << i << std::endl; 
		//std::cout << drawV[i].first << ", " << drawV[i].second << std::endl; 
	}
}
