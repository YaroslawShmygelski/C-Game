//
// Created by yaros on 10.03.2024.
//

#ifndef LIFEGAME_ENGINE_H
#define LIFEGAME_ENGINE_H


class Engine {
public:
    int col;
    int **arr;
protected:
    int alive_units;
    int **temp_arr;
    int row;
protected:
    Engine();


    ~Engine();

    int Neighbours_Sum(int element_r, int element_c);
    void GetConfig(int* width, int* height, int* alive);
    void Logic_Changes();




};


#endif LIFEGAME_ENGINE_H
