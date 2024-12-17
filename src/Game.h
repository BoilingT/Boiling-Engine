#pragma once
#include "Engine.h"
#include "Console.h"

#include <iostream>

class Game : public Engine
{
  private:
  public:
    Game();

    void start();
    void update();
    void render();
};