#include <iostream>
#include "../include/current_time.h"


int main()
{
    for (int i = 0; i < 16; ++i) {
        CurrentTime time;
        Current_time_1(time);
        std::cout << "TEST#1 Curent UTC time:\t" << time.hour << " : " << time.min << " : " << time.sec << " : " << time.msec <<  " : " << time.mksec << std::endl;
        uint16_t    hour,
                    min,
                    sec,
                    msec,
                    mksec;
        Current_time_2(hour, min, sec, msec, mksec);
        std::cout << "TEST#2 Curent UTC time:\t" << hour << " : " << min << " : " << sec << " : " << msec <<  " : " << mksec << std::endl;
        uint16_t    timeZone = 3;
        Current_time_3(hour, min, sec, msec, mksec, timeZone);
        std::cout << "TEST#3 Curent UTC time:\t" << hour << " : " << min << " : " << sec << " : " << msec <<  " : " << mksec << " (TimeZoned)" <<std::endl;
        //std::this_thread::sleep_for(std::chrono::nanoseconds(50));
        std::cout << "*******" << std::endl;
    }
}