#include <Windows.h>	//Win32API
#include <iostream>		//Input/Output
#include "Clicker.h"	//Header File


//Constructors / Destructors

Clicker::Clicker() {}					//Default Constructor

Clicker::~Clicker() {}					//Destructor

Clicker::Clicker(int delay) {				//Overloaded Constructor
	Clicker::cDelay = delay;
	Clicker::isRunning = false;
}


//Function Definitions / Implementation

void Clicker::startClick() {
	POINT p;
	isRunning = true;

	//Error Handling -  If GetCursorPos() returns true (function completes successfully - refer to msdn)
	if (GetCursorPos(&p)) {				//GetCursorPos stores coordinates in our pointer variable 
		//Simulate Click
		while (isRunning) {
		mouse_event(MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, p.x, p.y, 0, 0);
		Sleep(cDelay);
			
		if (GetAsyncKeyState(VK_F4) & 0x01) {
			stopClick();
		}
		}
	}

	else {
		std::cout << "Start Click Function Failed - Could Not Get Cursor Position" << std::endl;
	}
}


void Clicker::stopClick() {
	isRunning = false;
}


void Clicker::setDelay() {
	std::cout << "Please enter the delay to set in milliseconds: " << std::endl;
	int delayInput;
	std::cin >> delayInput;

	//set delay
	cDelay = delayInput;
	std::cout << "Delay set to " << cDelay << " ms" << std::endl;
}


