#include <iostream>
#include <vector>
#include "fns.hpp"


int main()
{
while(is_game_over() && count() <=9)
{
display_board();
player_turn();
}
display_board();
display_winner();
}
