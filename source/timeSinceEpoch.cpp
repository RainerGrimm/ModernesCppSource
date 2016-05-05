// timeSinceEpoch.cpp

#include <chrono>
#include <iostream>

int main(){

  std::cout << std::fixed << std::endl;
  
  std::cout << "Time since 1.1.1970:\n" << std::endl;

  auto timeNow= std::chrono::system_clock::now();
  auto duration= timeNow.time_since_epoch();
  std::cout << duration.count() << " nanoseconds " << std::endl;

  typedef std::chrono::duration<long double,std::ratio<1,1000000>> MyMicroSecondTick;
  MyMicroSecondTick micro(duration);
  std::cout << micro.count() << " microseconds" << std::endl;
  
  typedef std::chrono::duration<long double,std::ratio<1,1000>> MyMilliSecondTick;
  MyMilliSecondTick milli(duration);
  std::cout << milli.count() << " milliseconds" << std::endl;
  
  typedef std::chrono::duration<long double> MySecondTick;
  MySecondTick sec(duration);
  std::cout << sec.count() << " seconds " << std::endl;
  
  typedef std::chrono::duration<double, std::ratio<60>> MyMinuteTick;
  MyMinuteTick myMinute(duration);
  std::cout << myMinute.count() << " minutes" << std::endl;

  typedef std::chrono::duration<double, std::ratio<60*60>> MyHourTick;
  MyHourTick myHour(duration);
  std::cout << myHour.count() << " hours" << std::endl;
  
  typedef std::chrono::duration<double, std::ratio<60*60*24*365>> MyYearTick;
  MyYearTick myYear(duration);
  std::cout << myYear.count() << " years" << std::endl;

  typedef std::chrono::duration<double, std::ratio<60*45>> MyLessonTick;
  MyLessonTick myLesson(duration);
  std::cout << myLesson.count() << " lessons" << std::endl;

  std::cout << std::endl;

}