#include "../include/current_time.h"

void
Current_time_1(CurrentTime& currentTime)
{
  std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds>(
    std::chrono::system_clock::now().time_since_epoch());
  currentTime.mksec = ms.count() % 1000;
  currentTime.msec = ((ms.count() - currentTime.mksec) / uint64_t(1000)) % 1000;
  currentTime.sec = ((ms.count() - currentTime.mksec - currentTime.msec * uint64_t(1000)) /
                     (uint64_t(1000) * uint64_t(1000))) %
                    60;
  currentTime.min = ((ms.count() - currentTime.mksec - currentTime.msec * uint64_t(1000) -
                      currentTime.sec * uint64_t(1000000)) /
                     (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) %
                    60;
  currentTime.hour = ((ms.count() - currentTime.mksec - currentTime.msec * uint64_t(1000) -
                       currentTime.sec * uint64_t(1000000) -
                       currentTime.min * (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) /
                      (uint64_t(1000) * uint64_t(1000) * uint64_t(60) * uint64_t(60))) %
                     24;
}

void
Current_time_2(uint16_t& hour, uint16_t& min, uint16_t& sec, uint16_t& minisec, uint16_t& microsec)
{
  std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds>(
    std::chrono::system_clock::now().time_since_epoch());
  microsec = ms.count() % 1000;
  minisec = ((ms.count() - microsec) / uint64_t(1000)) % 1000;
  sec =
    ((ms.count() - microsec - minisec * uint64_t(1000)) / (uint64_t(1000) * uint64_t(1000))) % 60;
  min = ((ms.count() - microsec - minisec * uint64_t(1000) - sec * uint64_t(1000000)) /
         (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) %
        60;
  hour = ((ms.count() - microsec - minisec * uint64_t(1000) - sec * uint64_t(1000000) -
           min * (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) /
          (uint64_t(1000) * uint64_t(1000) * uint64_t(60) * uint64_t(60))) %
         24;
}

void
Current_time_3(uint16_t& hour, uint16_t& min, uint16_t& sec, uint16_t& minisec, uint16_t& microsec, uint16_t timeZone)
{
  std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds>(
    std::chrono::system_clock::now().time_since_epoch());
  microsec = ms.count() % 1000;
  minisec = ((ms.count() - microsec) / uint64_t(1000)) % 1000;
  sec =
    ((ms.count() - microsec - minisec * uint64_t(1000)) / (uint64_t(1000) * uint64_t(1000))) % 60;
  min = ((ms.count() - microsec - minisec * uint64_t(1000) - sec * uint64_t(1000000)) /
         (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) %
        60;
  hour = ((ms.count() - microsec - minisec * uint64_t(1000) - sec * uint64_t(1000000) -
           min * (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) /
          (uint64_t(1000) * uint64_t(1000) * uint64_t(60) * uint64_t(60))) %
         24;
    hour = (hour + timeZone >= 24 ? hour + timeZone - 24:(hour + timeZone < 0 ? hour + timeZone + 24 : hour + timeZone) );
}