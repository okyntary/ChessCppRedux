// ChessCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "View.h"
#include "Model.h"
#include "Controller.h"
#include "ChessPiece.h"

int main()
{
    Model model;
    View view{ &model };
    model.setView(&view);
    Controller controller(&model, &view);

    bool isExit = false;
    while (!isExit)
    {
        isExit = controller.readInput();
    }

    return EXIT_SUCCESS;
}
