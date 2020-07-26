#include "game.h"
#include <stdlib.h>
#include<time.h>
#include<limits>

using namespace std;

game::~game()
{
    delete t1;
    delete t2;
}

void game::game_result()
{
    int r=t1->total_runs    -   t2->total_runs;
    if(r>0)
        cout<<endl<<"Team1 won the match by "<<r<<" runs!!!"<<endl;
    else if(r<0)
        cout<<endl<<"Team2 won the match by "<<(-1*r)<<" runs!!!"<<endl;
    else
         cout<<endl<<"Its a Tie!!!"<<endl;
         cout<<"==============      MATCH ENDS      ================"<<endl;
         usleep(1500000);
         cout<<"==============      SCORE BOARD      ================"<<endl;
}

void game::details(int ch)
{
    cout<<endl<<endl;
    team* t;
    if(ch==1)t=t1;
    else t=t2;

    cout<<t->team_name<<" "<<t->total_runs<<"-"<<t->wickets_lost<<" (6)"<<endl;
    cout<<"PLAYER \t\t\t\t BATTING \t\t BOWLING"<<endl;
    for(int i=1,j=0;i<=4;i++)
    {j=i-1;
        cout<<"["<<i<<"] "<<t->p[j]->name<<" \t\t "<<t->p[j]->runs_scored<<"("<<t->p[j]->balls_played<<") \t\t\t ";
        cout<<t->p[j]->balls_bowled<<"-"<<t->p[j]->runs_given<<"-"<<t->p[j]->wickets_taken<<endl;
    }
}

game::game(string players[11])
{
    for(int i=0;i<11;i++)
       {
           available[i] =   1;
        name[i]    =   players[i];
       }
}

void showp(team* t)
{
    cout<<"------------- "<< t->team_name <<" Selected Players -------------------"<<endl;
    for(int i=0;i<4;i++)
        cout<<i+1  <<  ") " <<  t->p[i]->name<<endl;
}

void game::game_start(int inning, int choice)
{
    cout<<"\n\n*****************************************"<<endl;
    cout<<"   |||"<<"INNING"<<inning<<" Starts.|||\n\n"<<endl;

    switch(choice)
				{
					case 1:
					t1->play(t2);//t1 will bat
					break;

					case 0:
					t2->play(t1);//t2 will bat
					break;
				}

    cout<<endl<<"   |||"<<"INNING"<<inning<<" Ends.|||"<<endl;
    cout<<"*****************************************\n\n\n"<<endl<<endl;
    if(inning==1)
    {
    if(choice==1)
    {
        cout<<"Team1 "<<t1->total_runs<<" - "<<t1->wickets_lost<<" (6)"<<endl;
		cout<<"Team2 needs " << t1->total_runs+1 << "runs to win the match"<<endl;
    }
    else
    {
        cout<<"Team2 "<<t2->total_runs<<" - "<<t2->wickets_lost<<" (6)"<<endl;
        cout<<"Team1 needs " << t2->total_runs+1 << "runs to win the match"<<endl;
    }
    }
}

void game::show()
{
    cout<<endl<<endl<<"************************ POOL OF PLAYERS ************************" <<endl<<endl;
    for(int i=0;i<11;i++)
        cout<<"["<<i+1<<"]  "<<name[i]<<endl;

        cout<<endl<<endl;

    t1=new team("Team1");
    t2=new team("Team2");

    cout<<"please Enter to continue";
    //char ch;
    //cin>>ch;
//    cout<<uu;
    std2::buff_clear();
        //if(ch=='\n')
        game::select();

}

int check(game* g)
{
    int id;
    while ( !(cin>> id) || id<1 || id>11 || !g->available[id] )
    {
        if(!g->available[id])
        cout<<"Player already selected. Please select id from the available player in the pool."<<endl;
        else
            cout<<"Invalid option entered. Please select a valid id."<<endl;
            std2::buff_clear();
    }
    std2::buff_clear();
            return id;
}

void game::select()
{int id;
    cout<<"select your 4 players for your team from the available players in pool by their id shown"<<endl<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<endl<<"Select player for team1"<<endl;
        id=check(this);
         t1->p[i]=new player(name[id],id);
            available[id]=0;

        cout<<endl<<"Select player for team2"<<endl;
        id=check(this);
         t2->p[i]=new player(name[id],id);
         available[id]=0;
    }

    cout<<endl<<"Players of Team 1"<<endl;
    showp(t1);
    cout<<endl<<endl;

    cout<<"Players of Team 2"<<endl;
    showp(t2);
    cout<<endl<<endl;

    cout<<" Please press enter to continue... ";

    toss();
}


void game::toss()
{
int toss_ch,tos,batbowl_ch;

    std2 ::buff_clear();
		do
        {

		cout<<"\t\t\t!!!!!! TOSS !!!!!!!\n"<<endl;
		cout<<"1. Heads"<<endl;
		cout<<"2. Tails"<<endl;
		cout<<"Enter your choice "<< t1->team_name  <<endl;

		cin>>toss_ch;
		std2::buff_clear();
		cout<<endl;
		if(!(toss_ch==1||toss_ch==2))
		{
		    cout<<"Invalid option entered. Please select from given options"<<endl;
		    continue;
        }

            srand(time(0));
			tos=rand();
            toss_ch%=2;
			if(tos&1)tos=1;
			else tos=0;//0 represents for 2


			if(toss_ch==tos)
			{
				cout<<"Congrats!!! "<<t1->team_name<<" have won the toss. Its a ";

				if(tos)cout<<"Heads!"<<endl;
				else cout<<"Tails!"<<endl;

				cout<<t1->team_name<<"! Select your option."<<endl;
			}
			else if(toss_ch==(1-tos))
            {
                cout<<"Congrats!!! "<<t2->team_name<<" have won the toss. Its a";

				if(tos)cout<<"Heads!"<<endl;
				else cout<<"Tails!"<<endl;

				cout<<t2->team_name<<"! Select your option."<<endl;
            }


                while(1)
                {
				cout<<"1.Bat"<<endl;
				cout<<"2.Bowl"<<endl;
				cin>>batbowl_ch;
				std2::buff_clear();

				if(batbowl_ch==1 || batbowl_ch==2)break;
				else
                cout<<"Invalid option entered. Please select from given options i.e. 1 or 2"<<endl;
                }

                batbowl_ch%=2;// 0 is bowl now
                if(batbowl_ch)cout<<" You chosed to Bat first. Lets start the GAME!!!"<<endl;
                else cout<<" You chosed to Bowl first. Lets start the GAME!!!"<<endl;

                if(toss_ch==(1-tos))
                    batbowl_ch=1-batbowl_ch;//now its the choice of team1

                cout<<endl<<endl;
                game_start(1,batbowl_ch);

                batbowl_ch=1-batbowl_ch;

                game_start(2,batbowl_ch);

                game_result();
                details(1);
                details(2);
		 break;

	}
	while(1);

}
