#include "SplashScreen.h"
#include "MainMenu.h"

#include <iostream>
#include <memory>

#include "Window.h"
#include "SceneManager.h"
#include "AudioManager.h"


SplashScreen::SplashScreen(SharedObject& obj, bool replace) :BaseScene(obj, replace), alphaMask(255, 255, 255, 255)
{
#ifdef _DEBUG
	std::cout << "SplashScreen Created" << std::endl;
#endif
	//Background
	background.setSize(sf::Vector2f(mWindow.GetWindowSize().x, mWindow.GetWindowSize().y));
	background.setFillColor(sf::Color::White);
	//Mask fader
	rectMask.setFillColor(alphaMask);
	rectMask.setSize(sf::Vector2f(mWindow.GetWindowSize().x, mWindow.GetWindowSize().y));
	//Logo ITS
	rectLogoITS.setSize(sf::Vector2f(500, 500));
	logoITS.loadFromFile("Assets/Texture/GUI/splash_logoits.png");
	logoITS.setSmooth(true);
	rectLogoITS.setTexture(&logoITS);
	rectLogoITS.setOrigin(rectLogoITS.getSize().x / 2, rectLogoITS.getSize().y / 2);
	rectLogoITS.setPosition(static_cast<float>(mWindow.GetWindowSize().x) / 2, static_cast<float>(mWindow.GetWindowSize().y) / 2);
	//Logo Game
	rectLogoGame.setSize(sf::Vector2f(500, 500));
	logoGame.loadFromFile("Assets/Texture/GUI/splash_logogame.png");
	rectLogoGame.setTexture(&logoGame);
	rectLogoGame.setOrigin(rectLogoGame.getSize().x / 2, rectLogoGame.getSize().y / 2);
	rectLogoGame.setPosition(static_cast<float>(mWindow.GetWindowSize().x) / 2, static_cast<float>(mWindow.GetWindowSize().y) / 2);
	mAudio.play("Loading");
}


void SplashScreen::Pause()
{
	std::cout << "SplashScreen Paused" << std::endl;
}

void SplashScreen::Resume()
{
	std::cout << "SplashScreen Resume" << std::endl;
}

void SplashScreen::Update(float deltaTime)
{
	for (auto event = sf::Event{}; mWindow.GetRenderWindow()->pollEvent(event);)
	{
		switch (event.type)
		{
		case sf::Event::Closed: mWindow.Destroy(); break;
#ifdef _DEBUG
		case sf::Event::KeyPressed:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Space:
				mNext = SceneManager::build<MainMenu>(mObj, false);
				break;
			case sf::Keyboard::Escape: mWindow.Destroy(); break;
			case sf::Keyboard::M: mAudio.toggleMute(); break;
			default: break;
			}
			break;
		}
#endif
		default: break;
		}
	}

	if (alphaMask.a != 0 && (logoFlag == 1 || logoFlag == 3))
		alphaMask.a -= 1;
	else
		alphaMask.a += 1;

	if (logoFlag == 3 && alphaMask.a == 0)
		mNext = SceneManager::build<MainMenu>(mObj, true);

	if (alphaMask.a == 0 || (alphaMask.a == 255 && logoFlag == 2))
		logoFlag++;



	rectMask.setFillColor(alphaMask);

}

void SplashScreen::Draw()
{
	mWindow.BeginDraw();

	mWindow.Draw(background);

	if (logoFlag == 1 || logoFlag == 2)
		mWindow.Draw(rectLogoITS);
	else
		mWindow.Draw(rectLogoGame);

	if (alphaMask.a != 0)
	{
		mWindow.Draw(rectMask);
	}

	mWindow.EndDraw();
}


