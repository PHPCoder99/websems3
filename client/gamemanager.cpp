//-----------------------------------------
#include "gamemanager.h"

#include <string>
#include <iostream>

#include "game.h"

#include "simpleboard.h"
#include "consoleplayer.h"
#include "consolegame.h"

//============================================
IGame* GameManager::createGame(const std::string& name, int boardSize) const
{
    IGame* game = nullptr;
    // так как N должен быть во время компилации, тут невозможно задать.
    IBoard* board = new SimpleBoard<5>();
    game = static_cast<IGame*>(new ConsoleGame(name, board, boardSize));

    return game;
}
