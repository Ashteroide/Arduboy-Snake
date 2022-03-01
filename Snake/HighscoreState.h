#pragma once

struct HighscoreState
{
    void update()
    {
        if(arduboy.justPressed(A_BUTTON))
            gameState = GameState::Menu;
    }

    void draw()
    {
        arduboy.print(F("Highscore"));
    }
};