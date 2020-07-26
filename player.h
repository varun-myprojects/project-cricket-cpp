#include<iostream>
#include<string>

#include <limits>
#include<cstdlib>
#include <unistd.h>

namespace std2
{
inline void buff_clear()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
};
//int uu=56;


class player
{public:
    std::string name;
    int uid, runs_scored, balls_played, balls_bowled, runs_given,wickets_taken;

    player(std::string s,int id);
    //inline void buff_clear();
};



