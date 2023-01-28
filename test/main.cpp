#include <iostream>
#include "../include/current_time.h"


int main()
{
    for (int i = 0; i < 5000; ++i) {
        CurrentTime time;
        Current_time(time);
        std::cout << "Curent UTC time: " << time.hour << " : " << time.min << " : " << time.sec << " : " << time.msec <<  " : " << time.mksek << std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(50));
        
    }
}