/*
Name:Zhen Xun Li
Student ID:403410035
Dept:Computer Science and Information engineering
Year:2
*/
#include <iostream>
#include <cstdbool>
#include <ctime>
#include <cstdlib>
#include <string>
#include <unistd.h>
using namespace std;

class GameOfLIFE
{
public:
    GameOfLIFE(int wValue , int hValue);
    GameOfLIFE();
    void initailize(int p);
    void proceed(int t);
    void display();
    void clearScreen();

private:
    int width;
    int high;
    bool state[256][256];
};

int main()
{
    srand(time(NULL));
    //test pattern 1
    GameOfLIFE case1; //defult size
    case1.initailize(1);
    case1.display();
    case1.clearScreen();
    case1.proceed(100);
    /******************************/
    //test pattern 2
    GameOfLIFE case2; //defult size
    case2.initailize(2);
    case2.display();
    case2.clearScreen();
    case2.proceed(100);
    /******************************/
    //test pattern 3
    GameOfLIFE case3; //defult size
    case3.initailize(3);
    case3.display();
    case3.clearScreen();
    case3.proceed(100);
    /******************************/
    //test pattern 4
    GameOfLIFE case4; //defult size
    int percent=4+rand()%97;
    case4.initailize(percent);
    case4.display();
    case4.clearScreen();
    case4.proceed(100);

    return 0;
}

GameOfLIFE::GameOfLIFE(int wValue , int hValue)
{
    width=hValue;
    high=wValue;
    for(int i=0; i<width; i++) {
        for(int j=0; j<high; j++) {
            state[i][j]=false;
        }
    }
}

GameOfLIFE::GameOfLIFE()
{
    width=23;
    high=80;
    for(int i=0; i<width; i++) {
        for(int j=0; j<high; j++) {
            state[i][j]=false;
        }
    }
}

void GameOfLIFE::initailize (int p)
{
    int wCenter=width/2, hCenter=high/2;
    if(p==1) {
        state[wCenter-1][hCenter-1]=true;
        state[wCenter-1][hCenter]=true;
        state[wCenter-1][hCenter+1]=true;
        state[wCenter][hCenter-1]=true;
        state[wCenter+1][hCenter]=true;
    }// pattern 1 glider
    else if(p==2) {
        state[wCenter-2][hCenter-1]=true;
        state[wCenter-2][hCenter+2]=true;
        state[wCenter-1][hCenter-2]=true;
        state[wCenter][hCenter-2]=true;
        state[wCenter][hCenter+2]=true;
        state[wCenter+1][hCenter-2]=true;
        state[wCenter+1][hCenter-1]=true;
        state[wCenter+1][hCenter]=true;
        state[wCenter+1][hCenter+1]=true;
    } // pattern 2 lightweight spaceship
    else if(p==3) {
        state[wCenter-6][hCenter-4]=true;
        state[wCenter-6][hCenter-3]=true;
        state[wCenter-6][hCenter+3]=true;
        state[wCenter-6][hCenter+4]=true;
        state[wCenter-5][hCenter-3]=true;
        state[wCenter-5][hCenter-2]=true;
        state[wCenter-5][hCenter+2]=true;
        state[wCenter-5][hCenter+3]=true;
        state[wCenter-4][hCenter-6]=true;
        state[wCenter-4][hCenter-3]=true;
        state[wCenter-4][hCenter-1]=true;
        state[wCenter-4][hCenter+1]=true;
        state[wCenter-4][hCenter+3]=true;
        state[wCenter-4][hCenter+6]=true;
        state[wCenter-3][hCenter-6]=true;
        state[wCenter-3][hCenter-5]=true;
        state[wCenter-3][hCenter-4]=true;
        state[wCenter-3][hCenter-2]=true;
        state[wCenter-3][hCenter-1]=true;
        state[wCenter-3][hCenter+1]=true;
        state[wCenter-3][hCenter+2]=true;
        state[wCenter-3][hCenter+4]=true;
        state[wCenter-3][hCenter+5]=true;
        state[wCenter-3][hCenter+6]=true;
        state[wCenter-2][hCenter-5]=true;
        state[wCenter-2][hCenter-3]=true;
        state[wCenter-2][hCenter-1]=true;
        state[wCenter-2][hCenter+1]=true;
        state[wCenter-2][hCenter+3]=true;
        state[wCenter-2][hCenter+5]=true;
        state[wCenter-1][hCenter-4]=true;
        state[wCenter-1][hCenter-3]=true;
        state[wCenter-1][hCenter-2]=true;
        state[wCenter-1][hCenter+2]=true;
        state[wCenter-1][hCenter+3]=true;
        state[wCenter-1][hCenter+4]=true;
        state[wCenter+1][hCenter-4]=true;
        state[wCenter+1][hCenter-3]=true;
        state[wCenter+1][hCenter-2]=true;
        state[wCenter+1][hCenter+2]=true;
        state[wCenter+1][hCenter+3]=true;
        state[wCenter+1][hCenter+4]=true;
        state[wCenter+2][hCenter-5]=true;
        state[wCenter+2][hCenter-3]=true;
        state[wCenter+2][hCenter-1]=true;
        state[wCenter+2][hCenter+1]=true;
        state[wCenter+2][hCenter+3]=true;
        state[wCenter+2][hCenter+5]=true;
        state[wCenter+3][hCenter-6]=true;
        state[wCenter+3][hCenter-5]=true;
        state[wCenter+3][hCenter-4]=true;
        state[wCenter+3][hCenter-2]=true;
        state[wCenter+3][hCenter-1]=true;
        state[wCenter+3][hCenter+1]=true;
        state[wCenter+3][hCenter+2]=true;
        state[wCenter+3][hCenter+4]=true;
        state[wCenter+3][hCenter+5]=true;
        state[wCenter+3][hCenter+6]=true;
        state[wCenter+4][hCenter-6]=true;
        state[wCenter+4][hCenter-3]=true;
        state[wCenter+4][hCenter-1]=true;
        state[wCenter+4][hCenter+1]=true;
        state[wCenter+4][hCenter+3]=true;
        state[wCenter+4][hCenter+6]=true;
        state[wCenter+5][hCenter-3]=true;
        state[wCenter+5][hCenter-2]=true;
        state[wCenter+5][hCenter+2]=true;
        state[wCenter+5][hCenter+3]=true;
        state[wCenter+6][hCenter-4]=true;
        state[wCenter+6][hCenter-3]=true;
        state[wCenter+6][hCenter+3]=true;
        state[wCenter+6][hCenter+4]=true;

    } // pattern 3 pulsar0
    else {
        int lives=p*width*high/100,cnt=0;
        while(1) {
            if(cnt==lives)break;
            int x=rand()%width,y=rand()%high;
            if(state[x][y]==true) {
                continue;
            } else {
                state[x][y]=true;
                cnt++;
            }
        }
    }
}

void GameOfLIFE::proceed(int t)
{
    while(t--) {
        bool stateTemp[width][high];
        for(int i=0; i<width; i++) {
            for(int j=0; j<high; j++) {
                stateTemp[i][j]=false;
            }
        }
        // counting for neighbors
        for(int i=0; i<width; i++) {
            for(int j=0; j<high; j++) {
                int neighborCnt=0;
                if((i>=0 && i<width) && (j+1>=0 && j+1<high) && state[i][j+1]==true) {
                    neighborCnt++;
                }
                if((i-1>=0 && i-1<width) && (j+1>=0 && j+1<high) && state[i-1][j+1]==true) {
                    neighborCnt++;
                }
                if((i-1>=0 && i-1<width) && (j>=0 && j<high) && state[i-1][j]==true) {
                    neighborCnt++;
                }
                if((i-1>=0 && i-1<width) && (j-1>=0 && j-1<high) && state[i-1][j-1]==true) {
                    neighborCnt++;
                }
                if((i>=0 && i<width) && (j-1>=0 && j-1<high) && state[i][j-1]==true) {
                    neighborCnt++;
                }
                if((i+1>=0 && i+1<width) && (j-1>=0 && j-1<high) && state[i+1][j-1]==true) {
                    neighborCnt++;
                }
                if((i+1>=0 && i+1<width) && (j>=0 && j<high) && state[i+1][j]==true) {
                    neighborCnt++;
                }
                if((i+1>=0 && i+1<width) && (j+1>=0 && j+1<high) && state[i+1][j+1]==true) {
                    neighborCnt++;
                }
                // judge live or die
                //cout<<"neighborCnt="<<neighborCnt<<endl;
                if((state[i][j])==true) {
                    if(neighborCnt<=1 || neighborCnt>=4) {
                        stateTemp[i][j]=false;
                    }
                    if(neighborCnt==2||neighborCnt==3) {
                        stateTemp[i][j]=true;
                    }
                }
                if((state[i][j])==false) {
                    if(neighborCnt==3) {
                        stateTemp[i][j]=true;
                    }
                }
            }
        }

        //update status
        for(int i=0; i<width; i++) {
            for(int j=0; j<high; j++) {
                state[i][j]=stateTemp[i][j];
            }
        }
        clearScreen();
        display();
        sleep(1);
    }
}

void GameOfLIFE::display()
{
    for(int i=0; i<width; i++) {
        for(int j=0; j<high; j++) {
            state[i][j]==true?(cout<<'O'):(cout<<' ');
        }
        cout<<endl;
    }
}

void GameOfLIFE::clearScreen()
{
    cout<<string(100,'\n');
}