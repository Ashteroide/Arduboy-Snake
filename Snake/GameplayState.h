struct GameplayState
{
    void update()
    {
        if(arduboy.justPressed(A_BUTTON))
            gameState = GameState::End;
    }

    void draw()
    {
        arduboy.print(F("Gameplay"));
    }
};