// Tuvia Smadar
// gunslokij@gmail.com
#include "NodeItem.hpp"

// Constructor for NodeItem: initializes a circle shape with a label
NodeItem::NodeItem(float nodeRadius, const std::string& nodeText, const sf::Font& nodeFont)
    : sf::CircleShape(nodeRadius), label(nodeText, nodeFont, nodeRadius / 2) {
    // Center the circle at the origin
    setOrigin(nodeRadius, nodeRadius);
    setOutlineColor(sf::Color::Black); // Set the outline color of the circle
    setOutlineThickness(2); // Set the outline thickness of the circle
    label.setFillColor(sf::Color::Black); // Set the color of the text label
    // Center the label within the circle
    label.setOrigin(label.getLocalBounds().width / 2, label.getLocalBounds().height / 2);
}

// Function to draw the NodeItem on the given window
void NodeItem::draw(sf::RenderWindow& window) {
    window.draw(*this); // Draw the circle
    // Position the label at the center of the circle
    label.setPosition(getPosition().x - label.getLocalBounds().width / 2, getPosition().y - label.getLocalBounds().height / 2);
    window.draw(label); // Draw the label
}
