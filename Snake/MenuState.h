#pragma once

struct MenuState
{
    void update()
    {
        if(arduboy.justPressed(A_BUTTON))
            gameState = GameState::Gameplay;
    }

    void draw()
    {
        arduboy.print(F("Menu"));
    }
};
