#pragma once

struct EndState
{
    void update()
    {
        if(arduboy.justPressed(A_BUTTON))
            gameState = GameState::Highscore;
    }

    void draw()
    {
        arduboy.print(F("End"));
    }
};