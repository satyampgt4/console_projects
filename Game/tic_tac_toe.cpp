#include <bits/stdc++.h>
using namespace std;
char board[9];
int n=0,level =0;
void show();
int check();
void clear();
int move();
void ini();
void single_player();
void multi_player();
void player();

int main()
{
    int answer;

    do
    {
        clear();
        system("Color 0F");
        player();
        system("cls");

        show();
        cout<<"                 ";
        check();
        cout<<"\n\n          PRESS 1 TO RESTART THE GAME ELSE PRESS ENTER::" ;
        string p;
        cin.ignore();
        getline(cin,p);
        answer = p[0]-'0';

    }
    while (answer==1);

    return 0;

}

int win(char g ,char h);
 void clear(){
     for(int i =0; i<9; i++)
     {
         board[i] = '_';
     }
     n =0;
     level=0;
 }
 int check(){

     int flag=0;
     char winner;
     for(int i=0; i<3;i++)
     {
         if((board[0+(i*3)]!='_')
         &&(board[0+(i*3)]==board[1+(i*3)])&&(board[0+(i*3)]==board[2+(i*3)]))
         {winner= board[0+(i*3)];
          flag=1;
         }

         else if((board[0+i]!='_')
         &&(board[0+i]==board[3+i])&&(board[0+i]==board[6+i]))
         {winner = board[0+i];
         flag=1;
         }
     }

    if((board[0]!='_')
         &&(board[0]==board[8])&&(board[4]==board[8]))
         {winner= board[0];
         flag=1;
         }
    else if((board[2]!='_')
         &&(board[02]==board[4])&&(board[4]==board[6]))
         {winner=board[2];
         flag=1;
         }
    if(flag==1)
    {
        system("Color 0C");
        if(winner=='X')
        {
            system("Color 0A");
        }
        cout<<winner<<"  WON THE GAME";
        return 1;
    }

    if(n==9)
    {
        system("Color 0E");
        cout<<"       THE GAME IS DRAWN";
        return 1;
    }

    return 0;

 }
 int move(){


        if(win('O','O'))
            {    n++;
                return 0;
            }
        if(level>1)
        {
            if(win('X','X'))
                {
                    n++;
                    return 0;
                }
        }
        if(level>2)
        {
            if(win('O','_'))
                {
                    n++;
                    return 0;
                }
        }


     unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    minstd_rand0 generator (seed);

     int x =generator()%9;
     while(board[x]!='_')
     {
         x =generator()%9;
     }
     board[x]='O';
     n ++;
     return 0;

 }
 void show(){
     cout<<"\n\n                           "<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<"\n\n";
     cout<<"                           "<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<"\n\n";
     cout<<"                           "<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<"\n\n\n";
 }
int win(char g,char h){
for(int i=0; i<3;i++){
         for(int j=0;j<3;j++){
          if((board[(j%3)+(i*3)]== g&& board[((1+j)%3)+(i*3)]== h&& board[((2+j)%3)+(i*3)]=='_'))
          {
             board[((2+j)%3)+(i*3)] ='O';
             return 1;
          }
         }

        for(int j=0; j<9;j=j+3){
         if((board[(j%9)+i]==g && board[((j+3)%9)+i]==h&& board[((j+6)%9)+i]=='_'))
         {
            board[((j+6)%9)+i]='O';
            return 1;
         }
        }
     }
for(int j=0; j<12;j=j+4){
    if((board[(0+j)%12]==g &&board[(4+j)%12]==h &&board[(8+j)%12]=='_'))
         {board[(8+j)%12]='O';
         return 1;
         }
}
    if((board[(2)]==g &&board[(4)]== h&&board[(6)]=='_'))
         {board[(6)]='O';
         return 1;
         }
    if((board[(6)]==g &&board[(2)]==h &&board[(4)]=='_'))
         {board[(4)]='O';
         return 1;
         }
    if((board[(4)]==g &&board[(6)]==h &&board[(2)]=='_'))
         {board[(2)]='O';
         return 1;
         }



    return 0;
}

void ini(){
    system("cls");
    cout<<"\n\n..................CHOOSE THE LEVEL............................\n\n\n\n";
    cout<<"                   1. BEGINNER\n\n";
    cout<<"                   2. INTERMEDIATE\n\n";
    cout<<"                   3. PROFESSIONAL\n\n";
    cout<<"                   ENTER YOUR CHOICE (1-3):";
    string s;
    cin>>s;
    while(s[0]!='1'&&s[0]!='2'&&s[0]!='3')
    {
        cout<<"Invalid Input Try Again :";
        cin>>s;
    }
    level = s[0]-'0';
    //cin>>level;
}
void single_player(){

     ini();
     system("cls");
    if(level>2)
            move();
        while(!check()){
        system("cls");
        show();
        cout<<"             ENTER YOUR MOVE :  ";
        int mov;

        string g;
        cin>>g;
        mov = g[0] - '0';
        while((mov>9||mov<1)||(board[mov-1]!='_'))
        {
            cout<<"\n\n             INVALID MOVE PLEASE ENTER DIGIT 0 TO 9 WHICH IS UNOCCUPIED \n\n ";
            cout<<"           ENTER YOUR MOVE :  ";

        cin>>g;
        mov = g[0] - '0';
        }
        board[mov-1] = 'X';
        n++;
        if(check())
        break;
        move();
        }
}
void multi_player()
{
        while(!check()){
        system("cls");
        show();
        if(n%2==0)
        cout<<" PLAYER 1 (\" X \")ENTER YOUR MOVE :  ";
        else
        cout<<" PLAYER 2 (\" O \")ENTER YOUR MOVE :  ";
        int mov;
        string g;
        cin>>g;
        mov = g[0] - '0';
        while((mov>9||mov<1)||(board[mov-1]!='_'))
        {

             cout<<"\n\n             INVALID MOVE PLEASE ENTER DIGIT 0 TO 9 WHICH IS UNOCCUPIED \n\n ";

             if(n%2==0)
             cout<<" PLAYER 1 (\" X \")ENTER YOUR MOVE :  ";
             else
             cout<<" PLAYER 2 (\" O \")ENTER YOUR MOVE :  ";
             cin>>g;
             mov = g[0] - '0';
        }
        if(n%2==0)
        board[mov-1] = 'X';
        else
        board[mov-1] = 'O';
        n++;

        }
}
void player(){
    system("cls");
    int x;
    cout<<"\n\n..................CHOOSE NUMBER............................\n\n\n\n";
    cout<<"                   1. SINGLE PLAYER\n\n";
    cout<<" \n";
    cout<<"                   2. MULTI PLAYER\n\n";
    cout<<"\n                   ENTER YOUR CHOICE (1 or 2): ";
    string s;
    cin>>s;
    while(s[0]!='1'&&s[0]!='2')
    {
        cout<<"Invalid Input Try Again :";
        cin>>s;
    }
    x = s[0]-'0';
    system("cls");

    if(x==1)
    {
     single_player();

    }
    else
    {
        multi_player();
    }
}
