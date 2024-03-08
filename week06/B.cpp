#include <iostream>

struct Time { int hours = 0, minutes = 0, seconds = 0; };

Time time_add(Time start, Time interval) {
  Time end;
  end.seconds = (start.seconds + interval.seconds) % 60;
  end.minutes = (start.minutes + interval.minutes + (start.seconds + interval.seconds) / 60) % 60;
  end.hours = (start.hours + interval.hours + (start.minutes + interval.minutes + (start.seconds + interval.seconds) / 60) / 60) % 24;
  return end;
}
  
int main() {
  Time start, interval;
  std::cin >> start.hours >> start.minutes >> start.seconds >> interval.hours >> interval.minutes >> interval.seconds;
  Time end = time_add(start, interval);
  std::cout << end.hours << ' ' << end.minutes << ' ' << end.seconds << std::endl;
  return 0;
}