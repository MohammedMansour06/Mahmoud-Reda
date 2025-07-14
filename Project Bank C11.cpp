#include <iostream>
#include"clsLoginScreen.h"




int main()

{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginnScreen())
        {
            break;
        }

    }

    return 0;
}

