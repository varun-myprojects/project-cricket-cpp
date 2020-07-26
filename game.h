#include "team.h"

class game
{
    public:
    team *t1,*t2;
std::string name[11];
int available[11];
//team A and team B
//details, players per team, maximum deliveries allowed in each innings, names of
//all the 11 given players, and a variable to check which innings is going on.
game(std::string players[11]);
void show();
void select();
void toss();
void game_start(int a,int b);
void game_result();
void details(int);
~game();
};
