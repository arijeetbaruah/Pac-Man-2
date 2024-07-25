#pragma once

#include <SFML/Graphics.hpp>

class LoadFromResource
{
public:
	static sf::Texture loadTextureFromResource(const std::string& resourceId);
	static std::string loadTxtFromResource(const std::string& resourceId);
};

