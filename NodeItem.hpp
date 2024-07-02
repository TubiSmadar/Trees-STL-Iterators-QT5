// Tuvia Smadar
// gunslokij@gmail.com

#ifndef NODEITEM_HPP
#define NODEITEM_HPP

#include <SFML/Graphics.hpp>
#include <string>

// NodeItem class inheriting from sf::CircleShape
class NodeItem : public sf::CircleShape {
public:
    // Constructor to initialize NodeItem with radius, text, and font
    NodeItem(float nodeRadius, const std::string& nodeText, const sf::Font& nodeFont);

    // Function to draw the NodeItem on the given window
    void draw(sf::RenderWindow& window);

private:
    sf::Text label; // Text label for the node
};

#endif // NODEITEM_HPP
