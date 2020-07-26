#include "game.h"


using namespace std;
std::string p[11]={"Manish Pandey",\
"Prithvi Shaw   ",\
"Shikhar Dhawan ",\
"Shreyas Iyer   ",\
"Virat Kohli    ",\
"Hardik Pandya  ",\
"Ravindra Jadeja",\
"KL Rahul       ",\
"Rishabh Pant   ",\
"Bhuvneshwar Kumar",\
"Jasprit Bumrah "};

/*
int t;
int main() {

	while(!(cin>>t) )
    {
    cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<" ========= "<<t<<endl;
    }
	return 0;
}
*/



void welcome(game* g)
{
 cout<<"***************************** CRIC-IN *********************************\n\n";
 cout<<"*****************   WELCOME TO VIRTUAL CRICKET GAME  ******************\n\n"<<endl<<endl;
 cout<<"*************************     INSTRUCTIONS     *************************\n\n";
 cout<<"1) Select 2 teams with 4 players each from pool of 11 players "<<endl;
 cout<<"2) Lead the toss and decide the choice of play and 1st chance to select players from pool"<<endl;
 cout<<"3) Each inning will be of 6 balls. "<<endl;
 usleep(1500000);

    cout<<"please Enter to continue";
    //char ch;


    //cin>>ch;
std2 :: buff_clear();
        //if(ch=='\n')break;
        g->show();

}

using namespace std;

int main()
{
    game *g=new game(p);
    welcome(g);
    g->t1->~team();
    g->t2->~team();
    g->~game();
    delete g;
    cout << "!!!!=================  END OF  GAME ==================!!!!" << endl;
    usleep(2000);
    return 0;
}


