#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Scene.hpp"
#include "Background.hpp"
#include "Menu.hpp"
#include "Singleplayer.hpp"
#include "Multiplayer.hpp"
#include "GameSettings.hpp"

#include "path.hpp"
#include "definitions.hpp"

#include <stdlib.h>
#include <time.h>

using namespace sf;

#ifdef _DEBUG 
unsigned const
FULLSCREEN_MODE_ID = 3,
SCREEN_STYLE = Style::Titlebar | Style::Close;
#else 
unsigned const
FULLSCREEN_MODE_ID = 0,
SCREEN_STYLE = Style::Titlebar | Style::Close | Style::Fullscreen;
#endif 

const auto ROOT = get_current_path();
const auto MEDIA_PATH = combine_paths(ROOT, MEDIA_FOLDER);

int main()
{
	srand(time(NULL));

	VideoMode fullscreen_mode = VideoMode::getFullscreenModes()[FULLSCREEN_MODE_ID];

	if (fullscreen_mode.isValid()) {
		Game::window = new RenderWindow(fullscreen_mode, "Floppy Cats Online", SCREEN_STYLE);

#ifdef NDEBUG 
		Game::window->setMouseCursorVisible(false);
#endif 

		auto icon = Image();
		if (icon.loadFromFile(combine_paths(MEDIA_PATH, ICON_FILE))) {
			Game::window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
		}

		Texture texture;
		if (!texture.loadFromFile(combine_paths(MEDIA_PATH, SPRITE_LIST_FILE))) {
			return 1;
		} 

		Game::width = fullscreen_mode.width;
		Game::height = fullscreen_mode.height;
		Game::backgroundColor = Color(GAME_BACKGROUND_COLOR);
		Game::setSpriteList(texture);

		Scene* backgroundScene = new Scene();
		backgroundScene->gameObjects.push_back(new Background());

		Game::loadStaticScene(backgroundScene);

#if MODE == DEPLOY
		Game::loadScene(new Menu());
#endif
#if MODE == MENU
		Game::loadScene(new Menu());
#endif
#if MODE == SINGLEPLAYER
		Game::loadScene(new Singleplayer());
#endif
#if MODE == MULTIPLAYER
		Game::loadScene(new Multiplayer());
#endif
#if MODE == GAME_SETTINGS
		Game::loadScene(new GameSettings());
#endif

		Game::run();

		return 0;
	}

	return 1;
}