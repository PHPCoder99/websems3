//----------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <utility>
#include <memory>
#include <vector>

#include "board.h"
#include "player.h"
#include "game.h"

#include "gamemanager.h"

//[5]============================================================================
int main(int argv, char* argc[])
{
    GameManager gameManager;
    while(true){
        std::unique_ptr<IGame> game;
        std::cout<<"Enter game type:"<<std::endl;
        std::cout<<"1. Console game"<<std::endl;
        std::cout<<"2. Bot game"<<std::endl;

        int answer = 0;
        std::cin >> answer;
        switch(answer)
        {
            case 1:
            {
                std::cout<<"Creating game"<<std::endl;
                game.reset(gameManager.createGame("console_game", 5));
            }
                break;
            case 2:
            {
                std::cout<<"Creating game"<<std::endl;
                game.reset(gameManager.createGame("bot_game", 5));
            }
                break;
            default: return 0;
        }

        if(game)
        {
            std::cout<<"Game created"<<std::endl;
            if( game->waitForPlayers(30000) )
                game->exec();
        }
        else
            std::cout<<"Game NOT created"<<std::endl;
    }
    return 0;
}

//[6]================================================================

