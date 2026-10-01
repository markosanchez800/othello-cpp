#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <utility>
#include <set>
using namespace std;

random_device rD;
mt19937 gen(rD());
uniform_int_distribution<int> from(0,1);
vector<pair<int,int>> movesToMake;
int playerColor = from(gen);
int whites = 0;
int blacks = 0;
static char unplayed = '.';
static char black = 'X';
static char white = 'O';
static char potential = '#';
bool isDone = false;
char activePlayer = black;
char gameBoard [8][8] = 
{
    unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,
    unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,
    unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,
    unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,
    unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,
    unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,
    unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,
    unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed,unplayed
};

vector<pair<int,int>> checkMoves(char activePlayer) {
    int vert, horiz = 0;
    vector<pair<int,int>> possibleMoves;
    for (int i = 0; i < 8;  i++){
        for (int j = 0; j < 8; j++){
            if (gameBoard[i][j] == activePlayer){
                if (gameBoard[i - 1][j - 1] != unplayed && gameBoard[i - 1][j - 1] != activePlayer){
                    vert = i - 1;
                    horiz = j - 1;
                    while (vert >= 0 && horiz >= 0){
                        if (gameBoard[vert][horiz] != activePlayer && gameBoard[vert][horiz] != unplayed){
                            vert--;
                            horiz--;
                        } else if (gameBoard[vert][horiz] == unplayed){
                          possibleMoves.push_back((make_tuple(vert,horiz)));
                          vert = -1;
                          horiz = -1;
                          break;
                        } else {
                            vert = -1;
                            horiz = -1;
                            break;
                        }
                    }
                }
                if (gameBoard[i - 1][j] != unplayed && gameBoard[i - 1][j] != activePlayer){
                    vert = i - 1;
                    while (vert >= 0){
                        if (gameBoard[vert][j] != activePlayer && gameBoard[vert][j] != unplayed){
                            vert--;
                        } else if (gameBoard[vert][j] == unplayed){
                          possibleMoves.push_back((make_tuple(vert,j)));
                          vert = -1;
                          break;
                        } else {
                            vert = -1;
                            break;
                        }
                    }
                }
                if (gameBoard[i - 1][j + 1] != unplayed && gameBoard[i - 1][j + 1] != activePlayer){
                    vert = i - 1;
                    horiz = j + 1;
                    while (vert >= 0 && horiz <= 7){
                        if (gameBoard[vert][horiz] != activePlayer && gameBoard[vert][horiz] != unplayed){
                            vert--;
                            horiz++;
                        } else if (gameBoard[vert][horiz] == unplayed){
                          possibleMoves.push_back((make_tuple(vert,horiz)));
                          vert = -1;
                          horiz = 9;
                          break;
                        } else {
                            vert = -1;
                            horiz = 9;
                            break;
                        }
                    }
                }
                if (gameBoard[i][j - 1] != unplayed && gameBoard[i][j - 1] != activePlayer){
                    horiz = j - 1;
                    while (horiz >= 0){
                        if (gameBoard[i][horiz] != activePlayer && gameBoard[i][horiz] != unplayed){
                            horiz--;
                        } else if (gameBoard[i][horiz] == unplayed){
                          possibleMoves.push_back((make_tuple(i,horiz)));
                          horiz = -1;
                          break;
                        } else {
                            horiz = -1;
                            break;
                        }
                    }
                }
                if (gameBoard[i][j + 1] != unplayed && gameBoard[i][j + 1] != activePlayer){
                    horiz = j + 1;
                    while (horiz <= 7){
                        if (gameBoard[i][horiz] != activePlayer && gameBoard[i][horiz] != unplayed){
                            horiz++;
                        } else if (gameBoard[i][horiz] == unplayed){
                          possibleMoves.push_back((make_tuple(i,horiz)));
                          horiz = 9;
                          break;
                        } else {
                            horiz = 9;
                            break;
                        }
                    }
                }
                if (gameBoard[i + 1][j - 1] != unplayed && gameBoard[i + 1][j - 1] != activePlayer){
                    vert = i + 1;
                    horiz = j - 1;
                    while (vert <= 7 && horiz >= 0){
                        if (gameBoard[vert][horiz] != activePlayer && gameBoard[vert][horiz] != unplayed){
                            vert++;
                            horiz--;
                        } else if (gameBoard[vert][horiz] == unplayed){
                          possibleMoves.push_back((make_tuple(vert,horiz)));
                          vert = 9;
                          horiz = -1;
                          break;
                        } else {
                            vert = 9;
                            horiz = -1;
                            break;
                        }
                    }
                }
                if (gameBoard[i + 1][j] != unplayed && gameBoard[i + 1][j] != activePlayer){
                    vert = i + 1;
                    while (vert <= 7){
                        if (gameBoard[vert][j] != activePlayer && gameBoard[vert][j] != unplayed){
                            vert++;
                        } else if (gameBoard[vert][j] == unplayed){
                          possibleMoves.push_back((make_tuple(vert,j)));
                          break;
                        } else {
                            vert = 9;
                            break;
                        }
                    }
                }
                if (gameBoard[i + 1][j + 1] != unplayed && gameBoard[i + 1][j + 1] != activePlayer){
                    vert = i + 1;
                    horiz = j + 1;
                    while (vert <= 7 && horiz <= 7){
                        if (gameBoard[vert][horiz] != activePlayer && gameBoard[vert][horiz] != unplayed){
                            vert++;
                            horiz++;
                        } else if (gameBoard[vert][horiz] == unplayed){
                          possibleMoves.push_back((make_tuple(vert,horiz)));
                          vert = 9;
                          horiz = 9;
                          break;
                        } else {
                            vert = 9;
                            horiz = 9;
                            break;
                        }
                    }
                }
            }
            }
        }
        return possibleMoves;
}

void countSpots() {
    whites = 0;
    blacks = 0;
    for (int i = 0; i < 8;  i++){
        for (int j = 0; j < 8; j++){
            if (gameBoard[i][j] == black){
                blacks++;
            } else if (gameBoard[i][j] == white){
                whites++;
            }
            }
        }
}

void displayBoard() {
    countSpots();
    cout << string(15,'-') << endl;
    for (int i = 0; i < 8;  i++){
        for (int j = 0; j < 8; j++){
            cout << gameBoard[i][j] << " ";
            if (j == 7){
                cout << endl;
            }
        }
    }
    cout << string(15,'-') << endl;
    cout << "WHITE: " << whites << "     BLACK: " << blacks << endl;
    movesToMake = checkMoves(activePlayer);
    set<pair<int,int>> noDupeMoves(movesToMake.begin(), movesToMake.end());
    cout << "Possible Moves: " << endl;
    for (const auto& elem : noDupeMoves){
        cout << "(" << elem.first << "," << elem.second << ")";
    }
    cout << endl;
}

void makeMove(){
    int x;
    int y;
    vector<pair<int,int>> piecesToFlip;
    vector<pair<int,int>> potentialFlips;
    if (movesToMake.empty()){
        cout << "No moves to make! Previous player goes again" << endl;
        return;
    }
    cout << "Enter row (x):";
    cin >> x;
    cout << "Enter column (y):";
    cin >> y;
    pair<int,int> move_tuple = make_tuple(x,y);
    if (!(find(movesToMake.begin(),movesToMake.end(), move_tuple) != movesToMake.end())){
        cout << "Invalid move, please try again" << endl;
        makeMove();
    }
    gameBoard[x][y] = activePlayer;
    int vert;
    int horiz;
    //up and back
    if (gameBoard[x - 1][y - 1] != unplayed && gameBoard[x - 1][y - 1] != activePlayer){
        vert = x - 1;
        horiz = y - 1;
        while (vert >= 0 && horiz >= 0){
            if (vert == 0 && horiz == 0){
            vert = -1;
            horiz = -1;
            potentialFlips.clear();
            break;
            }
            if (gameBoard[vert][horiz] != activePlayer && gameBoard[vert][horiz] != unplayed){
                potentialFlips.push_back((make_tuple(vert,horiz)));
                vert--;
                horiz--;
                } else if (gameBoard[vert][horiz] == unplayed){
                    vert = -1;
                    horiz = -1;
                    potentialFlips.clear();
                    break;
                } else if (gameBoard[vert][horiz] == activePlayer){
                    vert = -1;
                    horiz = -1;
                    piecesToFlip.reserve(piecesToFlip.size() + potentialFlips.size());
                    move(potentialFlips.begin(),potentialFlips.end(), back_inserter(piecesToFlip));
                    potentialFlips.clear();
                    break;
                }
            }
        }
    //up and straight
    if (gameBoard[x - 1][y] != unplayed && gameBoard[x - 1][y] != activePlayer){
        vert = x - 1;
        while (vert >= 0){
            if (vert == 0){
            vert = -1;
            potentialFlips.clear();
            break;
            }
            if (gameBoard[vert][y] != activePlayer && gameBoard[vert][y] != unplayed){
                potentialFlips.push_back((make_tuple(vert,y)));
                vert--;
            } else if (gameBoard[vert][y] == unplayed){
                vert = -1;
                potentialFlips.clear();
                break;
            } else if (gameBoard[vert][y] == activePlayer){
                vert = -1;
                piecesToFlip.reserve(piecesToFlip.size() + potentialFlips.size());
                move(potentialFlips.begin(),potentialFlips.end(), back_inserter(piecesToFlip));
                potentialFlips.clear();
                break;
            }
        }
    }
    //up and forward
    if (gameBoard[x-1][y+1] != activePlayer && gameBoard[x-1][y+1] != unplayed){
        vert = x - 1;
        horiz = y + 1;
        while (vert >= 0 && horiz <= 7){
            if (vert == 0 && horiz == 7){
            vert = -1;
            horiz = 8;
            potentialFlips.clear();
            break;
            }
            if (gameBoard[vert][horiz] != activePlayer && gameBoard[vert][horiz] != unplayed){
                potentialFlips.push_back((make_tuple(vert,horiz)));
                vert--;
                horiz++;
            } else if (gameBoard[vert][horiz] == unplayed){
                vert = -1;
                horiz = 8;
                potentialFlips.clear();
                break;
            } else if (gameBoard[vert][horiz] == activePlayer){
                vert = -1;
                horiz = 8;
                piecesToFlip.reserve(piecesToFlip.size() + potentialFlips.size());
                move(potentialFlips.begin(),potentialFlips.end(), back_inserter(piecesToFlip));
                potentialFlips.clear();
                break;
            }
        }
    }
    //back and straight
    if (gameBoard[x][y-1] != activePlayer && gameBoard[x][y-1] != unplayed){
        horiz = y - 1;
        while(horiz >= 0){
            if ((horiz == 0 && x == 0) || (horiz == 0 && x == 7)){
                horiz = -1;
                potentialFlips.clear();
                break;
            }
            if (gameBoard[x][horiz] != activePlayer && gameBoard[x][horiz] != unplayed){
                potentialFlips.push_back((make_tuple(x,horiz)));
                horiz--;
            } else if (gameBoard[x][horiz] == unplayed){
                horiz = -1;
                potentialFlips.clear();
                break;
            } else if (gameBoard[x][horiz] == activePlayer){
                horiz = -1;
                piecesToFlip.reserve(piecesToFlip.size() + potentialFlips.size());
                move(potentialFlips.begin(),potentialFlips.end(), back_inserter(piecesToFlip));
                potentialFlips.clear();
                break;
            }
        }
    }
    //forward and straight
    if (gameBoard[x][y+1] != activePlayer && gameBoard[x][y+1] != unplayed){
        horiz = y + 1;
        while(horiz <= 7){
            if ((x == 0 && horiz == 7) || (x == 7 && horiz == 7)){
                horiz = 8;
                potentialFlips.clear();
                break;
            }
            if (gameBoard[x][horiz] != activePlayer && gameBoard[x][horiz] != unplayed){
                potentialFlips.push_back((make_tuple(x,horiz)));
                horiz++;
            } else if (gameBoard[x][horiz] == unplayed){
                horiz = -1;
                potentialFlips.clear();
                break;
            } else if (gameBoard[x][horiz] == activePlayer){
                horiz = -1;
                piecesToFlip.reserve(piecesToFlip.size() + potentialFlips.size());
                move(potentialFlips.begin(),potentialFlips.end(), back_inserter(piecesToFlip));
                potentialFlips.clear();
                break;
            }
        }
    }
    //down and back
    if (gameBoard[x+1][y-1] != activePlayer && gameBoard[x+1][y-1] != unplayed){
        vert = x + 1;
        horiz = y - 1;
        while(vert <= 7 && horiz >= 0){
            if (vert == 7 && horiz == 0){
            vert = 8;
            horiz = -1;
            potentialFlips.clear();
            break;
            }
            if (gameBoard[vert][horiz] != activePlayer && gameBoard[vert][horiz] != unplayed){
                potentialFlips.push_back((make_tuple(vert,horiz)));
                vert++;
                horiz--;
            } else if (gameBoard[vert][horiz] == unplayed){
                vert = 8;
                horiz = -1;
                potentialFlips.clear();
                break;
            } else if (gameBoard[vert][horiz] == activePlayer){
                vert = 8;
                horiz = -1;
                piecesToFlip.reserve(piecesToFlip.size() + potentialFlips.size());
                move(potentialFlips.begin(),potentialFlips.end(), back_inserter(piecesToFlip));
                potentialFlips.clear();
                break;
            }
        }
    }
    //down and straight
    if (gameBoard[x+1][y] != activePlayer && gameBoard[x+1][y] != unplayed){
        vert = x + 1;
        while(vert <= 7){
            if ((vert == 7 && y == 0) || (vert == 7 && y == 7)){
            vert = 8;
            potentialFlips.clear();
            break;
            }
            if (gameBoard[vert][y] != activePlayer && gameBoard[vert][y] != unplayed){
                potentialFlips.push_back((make_tuple(vert,y)));
                vert++;
            } else if (gameBoard[vert][y] == unplayed){
                vert = 8;
                potentialFlips.clear();
                break;
            } else if (gameBoard[vert][y] == activePlayer){
                vert = 8;
                piecesToFlip.reserve(piecesToFlip.size() + potentialFlips.size());
                move(potentialFlips.begin(),potentialFlips.end(), back_inserter(piecesToFlip));
                potentialFlips.clear();
                break;
            }
        }
    }
    //down and forward
    if (gameBoard[x+1][y+1] != activePlayer && gameBoard[x+1][y+1] != unplayed){
        vert = x + 1;
        horiz = y + 1;
        while(vert <= 7 && horiz <= 7){
            if (vert == 7 && horiz == 7){
            vert = 8;
            horiz = 8;
            potentialFlips.clear();
            break;
            }
            if (gameBoard[vert][horiz] != activePlayer && gameBoard[vert][horiz] != unplayed){
                potentialFlips.push_back((make_tuple(vert,horiz)));
                vert++;
                horiz++;
            } else if (gameBoard[vert][horiz] == unplayed){
                vert = 8;
                horiz = 8;
                potentialFlips.clear();
                break;
            } else if (gameBoard[vert][horiz] == activePlayer){
                vert = 8;
                horiz = 8;
                piecesToFlip.reserve(piecesToFlip.size() + potentialFlips.size());
                move(potentialFlips.begin(),potentialFlips.end(), back_inserter(piecesToFlip));
                potentialFlips.clear();
                break;
            }
        }
    }
    //changes all necessary pieces to the active player color
    for (pair<int,int> moveCoord : piecesToFlip){
        gameBoard[moveCoord.first][moveCoord.second] = activePlayer;
    }
    piecesToFlip.clear();
}

void play() {
    while(!isDone){
        if (whites + blacks == 64){
            isDone = true;
            break;
        }
    displayBoard();
    makeMove();
    if (activePlayer == black){
        activePlayer = white;
    } else {
        activePlayer = black;
    }
    }
}

void startBoard() {
    gameBoard[3][3] = white;
    gameBoard[3][4] = black;
    gameBoard[4][3] = black;
    gameBoard[4][4] = white;
    play();
}

int main() {
    while(!isDone){
        startBoard();
    }
    if (whites > blacks){
        cout << "White wins!" << endl;
    } else {
        cout << "Black wins!" << endl;
    }
}