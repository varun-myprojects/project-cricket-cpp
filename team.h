#include "player.h"
class team
{
    public:
std::string team_name;
player  *p[4];
int total_runs,   wickets_lost,   balls_bowled;

void play(team* t2);
void update(team*);
team(std::string);
~team();
};

