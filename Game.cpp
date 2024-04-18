//
// Created by yaros on 13.03.2024.
//

#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <synchapi.h>


using namespace std;


Game::Game() : Engine() {
}

Game::~Game() {
    delete []arr;
    cout<<"Destructor Game";
}


// Zapusk gry z interwalem 2 sekundy
void Game::Run() {
    while (TRUE) {
        View();
        Logic_Changes();
        Sleep(2000);
    }
}


// Wyswietlianie naszej tablicy
void Game::Show() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (arr[i][j]==1) {
                cout << "X" << " ";
            } else {
                cout << "O" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


