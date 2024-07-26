#pragma once

#include <SFML/Graphics.hpp>

class LoadFromResource
{
public:
	static sf::Texture loadTextureFromResource(const std::string& resourceId);
};

