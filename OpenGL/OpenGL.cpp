#include "GameController.h"

int main(void)
{
    srand(static_cast<unsigned>(time(0)));

    GameController::GetInstance().Initialize();
    GameController::GetInstance().RunGame();

    return 0;
}
