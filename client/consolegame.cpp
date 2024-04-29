//--------------------------------
#include <string>
#include <iostream>
#include "simpleboard.h"
#include "consoleplayer.h"

#include "consolegame.h"

//================================
ConsoleGame::ConsoleGame(const std::string& name, IBoard* board, int boardSize)
:m_name(name), m_boardSize(boardSize)
{
    setup(board);
}

bool ConsoleGame::setup(IBoard* board)
{
    if(m_players.empty())
        m_board.reset(board);
    return true;
}

bool ConsoleGame::waitForPlayers(uint64_t /*timeout*/)
{
    while(m_players.size() < 2)
    {
        std::cout << "Enter name of players "<<std::to_string(m_players.size()+1)<<std::endl;

        std::string name;
        std::cin>>name;
        if(name.empty())
            continue;

        m_players.emplace_back(new ConsolePlayer(name) );
    }

    return true;
}

void ConsoleGame::renderBoard() const
{
    auto dimension = m_board->dimention();
    const auto& xmin = dimension.first.x;
    const auto& ymin = dimension.first.y;
    const auto& xmax = dimension.second.x;
    const auto& ymax = dimension.second.y;

    IBoard::PositionType pos;
    for( auto y = ymin; y < ymax; y++)
    {
        pos.y = y;
        for (auto x = xmin; x < xmax; x++)
        {
            pos.x = x;
            auto mark = m_board->mark(pos);
            std::string outSymbol = "_";
            switch(mark)
            {
                case IBoard::MARK_O: outSymbol = "O"; break;
                case IBoard::MARK_X: outSymbol = "X"; break;
                default: break;
            }
            std::cout<<"|" << outSymbol<<"|";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

int  ConsoleGame::calculateVictory()
{
    return false;//rand()%2;
}

int  ConsoleGame::exec(/*add parameters*/)
{
    if (m_name == "console_game"){
        int iplayer = 0;
        while(true)
        {
            renderBoard();
            auto& player = m_players[iplayer];
            bool moveAssepted = false;
            while(!moveAssepted)
            {
                auto move = player->getMove();
                if( !move )
                    return -1;

                auto currentMark = m_board->mark(move.value());
                if(currentMark == IBoard::MARK_EMPTY)
                    moveAssepted = m_board->setMark(move.value(), iplayer == 0 ? IBoard::MARK_X : IBoard::MARK_O);
            }
            //calculate wictory function
            if( calculateVictory() > 0){
                std::cout << "player "<<std::to_string(iplayer+1)<<" win! Congratulations!"<<std::endl;
                return iplayer;
            }

            iplayer = (iplayer + 1) % 2;
        }
        return -1;
    } else if (m_name == "bot_game"){
        bool isbotmove = 0;
        while(true)
        {
            renderBoard();
            auto& player = m_players[0];
            auto& bot = new ConsolePlayer("[bot]");
            if (!isbotmove) {
                bool moveAssepted = false;
                while(!moveAssepted)
                {
                    auto move = player->getMove();
                    if( !move )
                        return -1;
                    
                    auto currentMark = m_board->mark(move.value());
                    if(currentMark == IBoard::MARK_EMPTY)
                        moveAssepted = m_board->setMark(move.value(), IBoard::MARK_X);
                }
            } else {
                bool moveAssepted = false;

                while(!moveAssepted)
                {
                    auto move = bot->randMove(m_boardSize);
                    if( !move )
                        return -1;
                    
                    auto currentMark = m_board->mark(move.value());
                    if(currentMark == IBoard::MARK_EMPTY)
                        moveAssepted = m_board->setMark(move.value(), IBoard::MARK_X);
                }
            }

            if( calculateVictory() > 0){
                if (isbotmove) {
                    std::cout << "bot wins!";
                } else {
                    std::cout << "you win!";
                }
                return isbotmove;
            }
        }
    }
}
//[7]

// just random moves for the bot idk