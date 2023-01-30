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
Current_time_2(uint16_t& hour, uint16_t& min, uint16_t& sec, uint16_t& millisec, uint16_t& microsec)
{
  std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds>(
    std::chrono::system_clock::now().time_since_epoch());
  microsec = ms.count() % 1000;
  millisec = ((ms.count() - microsec) / uint64_t(1000)) % 1000;
  sec =
    ((ms.count() - microsec - millisec * uint64_t(1000)) / (uint64_t(1000) * uint64_t(1000))) % 60;
  min = ((ms.count() - microsec - millisec * uint64_t(1000) - sec * uint64_t(1000000)) /
         (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) %
        60;
  hour = ((ms.count() - microsec - millisec * uint64_t(1000) - sec * uint64_t(1000000) -
           min * (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) /
          (uint64_t(1000) * uint64_t(1000) * uint64_t(60) * uint64_t(60))) %
         24;
}

void
Current_time_3(uint16_t& hour,
               uint16_t& min,
               uint16_t& sec,
               uint16_t& millisec,
               uint16_t& microsec,
               uint16_t timeZone)
{
  std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds>(
    std::chrono::system_clock::now().time_since_epoch());
  microsec = ms.count() % 1000;
  millisec = ((ms.count() - microsec) / uint64_t(1000)) % 1000;
  sec =
    ((ms.count() - microsec - millisec * uint64_t(1000)) / (uint64_t(1000) * uint64_t(1000))) % 60;
  min = ((ms.count() - microsec - millisec * uint64_t(1000) - sec * uint64_t(1000000)) /
         (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) %
        60;
  hour = ((ms.count() - microsec - millisec * uint64_t(1000) - sec * uint64_t(1000000) -
           min * (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) /
          (uint64_t(1000) * uint64_t(1000) * uint64_t(60) * uint64_t(60))) %
         24;
  hour = (hour + timeZone >= 24 ? hour + timeZone - 24
                                : (hour + timeZone < 0 ? hour + timeZone + 24 : hour + timeZone));
}

void
Current_time_4(uint16_t& hour,
               uint16_t& min,
               uint16_t& sec,
               uint16_t& millisec,
               uint16_t& microsec,
               uint16_t timeZone)
{
  auto now = std::chrono::system_clock::now();
  auto time_global =
    (std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch())).count();

  microsec = time_global % 1000;
  time_global = (time_global - microsec) / 1000;
  millisec = time_global % 1000;
  time_global = (time_global - millisec) / 1000;
  sec = time_global % 60;
  time_global = (time_global - sec) / 60;
  min = time_global % 60;
  time_global = (time_global - min) / 60;
  hour = time_global % 24;

  hour = (hour + timeZone >= 24 ? hour + timeZone - 24
                                : (hour + timeZone < 0 ? hour + timeZone + 24 : hour + timeZone));
}