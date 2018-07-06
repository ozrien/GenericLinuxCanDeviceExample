#include "ctre/Phoenix.h"

#include <unistd.h>
#include <iostream>
#include <chrono>
#include <ctre/phoenix/Platform/SysWatchdog.h>
#include <dlfcn.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <map>
#include <iostream>
#include <vector>

#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>


// SDL code from https://gist.github.com/fabiocolacio/423169234b8daf876d8eb75d8a5f2e95

using namespace ctre::phoenix;
using namespace ctre::phoenix::platform;
using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;

int main() {

    bool success;
    TalonSRX * talon = new TalonSRX(1);
    
    // Initialize the joystick subsystem
//    SDL_Init(SDL_INIT_JOYSTICK);
//
//    // If there are no joysticks connected, quit the program
//    if (SDL_NumJoysticks() <= 0) {
//        printf("There are no joysticks connected. Quitting now...\n");
//        SDL_Quit();
//        return -1;
//    }
   
    // Open the joystick for reading and store its handle in the joy variable
//    SDL_Joystick *joy = SDL_JoystickOpen(0);
// 
//    // If the joy variable is NULL, there was an error opening it.
//    if (joy != NULL) {
//        // Get information about the joystick
//        const char *name = SDL_JoystickName(joy);
//        const int num_axes = SDL_JoystickNumAxes(joy);
//        const int num_buttons = SDL_JoystickNumButtons(joy);
//        const int num_hats = SDL_JoystickNumHats(joy);
//
//        printf("Now reading from joystick '%s' with:\n"
//               "%d axes\n"
//               "%d buttons\n"
//               "%d hats\n\n",
//               name,
//               num_axes,
//               num_buttons,
//               num_hats);
//
//        int quit = 0;
//
//        // Keep reading the state of the joystick in a loop
//        while (quit == 0) {
//            if (SDL_QuitRequested()) {
//                quit = 1;
//            }
        while(1) {           
            //std::cout << SDL_JoystickGetAxis(joy, 1) << std::endl; 
            talon->Set(ControlMode::PercentOutput, 0.3);//((double) SDL_JoystickGetAxis(joy, 1)) / 32767.0);
            
            SysWatchdog::GetInstance().Feed(100);
            usleep(20000);
        }
//        SDL_JoystickClose(joy);
//    } else {
//        printf("Couldn't open the joystick. Quitting now...\n");
//    }
//
//    SDL_Quit();
    return 0;
}



