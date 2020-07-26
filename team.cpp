#include "team.h"
#include <stdlib.h>
#include<time.h>

using namespace std;

int run(int t)
{
    int x;
    srand(t+time(0));

    x=rand();
    x%=7;
    return x;
}

team::team(string n):team_name(n)
{
    total_runs=0;
    wickets_lost=0;
    balls_bowled=0;
}

team::~team()
{
    for(int i=0;i<4;i++)
       //delete this->p[i];
        delete[] p;
}
void team::update(team* t)
{
    //cout<<uu<<"==========uu"<<endl;
    int c=this->wickets_lost;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<this->team_name  <<"  "<<this->total_runs<<" "<<c<<" ("<<t->balls_bowled<<")  |  ";
    cout<<this->p[c]->name<<"  "<< this->p[c]->runs_scored << "  (" << this->p[c]->balls_played <<")    ";
    cout<<"  "<< t->p[0]->name <<"  "<< t->p[0]->balls_bowled <<" - " <<t->p[0]->runs_given<<" - "<<t->p[0]->wickets_taken<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
}


void team::play(team* t)
{int curr=0,out=1,r;

    for(int i=0;i<6;i++)
    {

    if(out)
    {
    out=0;
    cout<<t->team_name<<" - "<< t->p[0]->name    <<"is bowling"<<endl;
    cout<<this->team_name<<" - "<< this->p[curr]->name    <<"is batting"<<endl;
    }

    cout<<endl<<endl<<"Press Enter to bowl....";
    //cin>>ch;
    std2::buff_clear();
    usleep(1000000);
    cout<<endl<<"Bowling .... "<<endl<<endl;

    r=run(i);
    cout<<t->p[0]->name<<"  to  "<<this->p[curr]->name ;
    if(r==0)
    {
        cout<<"  OUT!"<<endl;
        if(curr==3)return;//all out
        out=1;
    }
    else
        cout<<"  "<<r<<" runs!"<<endl;


    this->wickets_lost = t->p[0]->wickets_taken = curr;
    this->total_runs+=r;
    t->balls_bowled = t->p[0]->balls_bowled = i+1;

    this->p[curr]->runs_scored =this->p[curr]->runs_scored + r;
    this->p[curr]->balls_played++;

    t->p[0]->runs_given+=r;

    if(out)curr++;
    team::update(t);

    }
}
