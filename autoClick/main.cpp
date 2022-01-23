#include <Windows.h>
#include <iostream>
#include <thread> 
#include "Clicker.h"

int main()
{

    SetConsoleTitleW(L"Stacks Auto Clicker");
    std::cout << "F3. Start" << std::endl;
    std::cout << "F4. Stop" << std::endl;
    std::cout << "F5. Set Delay (milliseconds)\n" << std::endl;
    std::cout << "F8. Exit" << std::endl;

    Clicker clicker(50);

    while (!GetAsyncKeyState(VK_F8) & 0x01) {               //Main Loop

                                              //create clicker object, parse 50ms argument to our constructor to initialize our cDelay property.

        if (GetAsyncKeyState(VK_F3) & 0x01) {               //Start
            clicker.startClick();

        }

        else if (GetAsyncKeyState(VK_F4) & 0x01) {          //Stop
            clicker.stopClick();
        }
        
        else if (GetAsyncKeyState(VK_F5) & 0x01) {          //Set Delay
            clicker.setDelay();
        }

        else {
        //do nothing
        }


    }

}
