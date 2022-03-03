#include <Arduboy2.h>
#include <ArduboyTones.h>

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

enum class GameState : uint8_t
{
    Menu,
    Gameplay,
    End,
    Highscore
};
GameState gameState = GameState::Menu;

#include "Player.h"
Player snake = { 0, 20, 20, 10, true };

#include "MenuState.h"
MenuState menuState;

#include "GamePlayState.h"
GameplayState gameplayState;

#include "EndState.h"
EndState endState;

#include "HighscoreState.h"
HighscoreState highscoreState;

void setup()
{
    arduboy.begin();
    arduboy.initRandomSeed();
}

void loop()
{
    if(!arduboy.nextFrame())
        return;

    arduboy.pollButtons();

    arduboy.clear();

    switch(gameState)
    {
        case GameState::Menu:
            menuState.update();
            menuState.draw();
            break;
        case GameState::Gameplay:
            gameplayState.update();
            gameplayState.draw();
            break;
        case GameState::End:
            endState.update();
            endState.draw();
            break;

        case GameState::Highscore:
            highscoreState.update();
            highscoreState.draw();
            break;
    }

    arduboy.display();
}