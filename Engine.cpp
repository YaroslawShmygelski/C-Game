//
// Created by yaros on 10.03.2024.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Engine.h"

using namespace std;


// Konstruktor tworzacy nasza tablice gry
Engine::Engine() {

    GetConfig(&row, &col, &alive_units);

    //Tworzenie tablice o zadanym w pliku rozmiaru (pierwsze 2 liczby)
    arr = new int *[row];
    temp_arr = new int *[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
        temp_arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            arr[i][j] = 0;
            temp_arr[i][j] = 0;
        }
    }

//Generacja podanej licby jedynek w pliku (3 licba)
    for (int i = 0; i < alive_units; ++i) {
        int randomRow, randomCol;
        do {
            randomRow = rand() % row;
            randomCol = rand() % col;
        } while (arr[randomRow][randomCol] != 0);
        arr[randomRow][randomCol] = 1;
    }
}


//Otrzymanie Konfiguracyjnych liczb
void Engine::GetConfig(int *width, int *height, int *alive) {
    ifstream file("D:\\JZO\\LifeGame\\config.txt");  //UWAGA!!! Tu muszi byc prawdilowy PATH
    // Mozna zmieniac configuracje Gry w pliku config.txt 1 szer. 2 wysot. 3 licba zywych elementow

    if (!file.is_open()) {
        cerr << "Open file Eror!" << endl;
    }

    int inp_width;
    int inp_height;
    int inp_alive;

    string firstLine;
    if (getline(file, firstLine)) {
        istringstream iss(firstLine);
        if (!(iss >> inp_width >> inp_height >> inp_alive)) {
            cerr << "Reading eror!" << endl;
        }
    } else {
        cerr << "File is empty" << endl;
    }

    *width = inp_width;
    *height = inp_height;
    *alive = inp_alive;


    cout << "Width: " << *width << ", Height: " << *height << ", Random Alive units: " << *alive << endl << endl;


    file.close();


}

// Otrzymanie Sumy sasiadow elementow
int Engine::Neighbours_Sum(int element_r, int element_c) {
    int sum = 0;
    for (int i = element_r - 1; i <= element_r + 1; i++) {
        for (int j = element_c - 1; j <= element_c + 1; j++) {
            if (i == element_r && j == element_c) {
                continue;
            }
            if (i >= 0 && i < row && j >= 0 && j < col) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}


// Zamiana elementow zgodnie z Logika gry
void Engine::Logic_Changes() {
    cout << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == 1 &&
                (Neighbours_Sum(i, j) == 2
                 || Neighbours_Sum(i, j) == 3)) {
                temp_arr[i][j] = 1;
            } else if (arr[i][j] == 0 && Neighbours_Sum(i, j) == 3) {
                temp_arr[i][j] = 1;

            } else {
                temp_arr[i][j] = 0;
            }
        }
    }


    arr = temp_arr;
}

//Oczywiszcie Destruktor
Engine::~Engine() {
    if (arr && temp_arr) {
        for (int i = 0; i < row; i++) {
            delete[]arr[i];
            delete[]temp_arr[i];
        }

        delete[]arr;
        delete[]temp_arr;
    }
    arr = 0;
    temp_arr = 0;

}