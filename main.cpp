#include <ctime>
#include "Game.h"

int main() {
    setcursor(0, 0);
    srand((unsigned)time(NULL));
    menu();
    return 0;
}
