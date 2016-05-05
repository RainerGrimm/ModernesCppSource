// now.cpp

#include <chrono>
#include <iomanip>
#include <iostream>

template <typename T>
void durationSinceEpoch(T dur){
    std::cout << "     Counts since epoch:  " << dur.count() << std::endl;
    typedef std::chrono::duration<double, std::ratio<60>> MyMinuteTick;
    MyMinuteTick myMinute(dur);
    std::cout << std::fixed;
    std::cout << "     Minutes since epoch: "<< myMinute.count() << std::endl;
    typedef std::chrono::duration<double, std::ratio<60*60*24*365>> MyYearTick;
    MyYearTick myYear(dur);
    std::cout << "     Years since epoch:   " << myYear.count() << std::endl;
}
    
int main(){
    
    std::cout << std::endl;
    
    std::chrono::system_clock::time_point timeNowSysClock = std::chrono::system_clock::now(); 
    std::chrono::system_clock::duration timeDurSysClock= timeNowSysClock.time_since_epoch();
    std::cout << "std::chrono::system_clock: " << std::endl;
    durationSinceEpoch(timeDurSysClock);
    
    std::cout << std::endl;
     
    auto timeNowStClock = std::chrono::steady_clock::now(); 
    auto timeDurStClock= timeNowStClock.time_since_epoch();
    std::cout << "std::chrono::steady_clock: " << std::endl;
    durationSinceEpoch(timeDurStClock);
    
    std::cout << std::endl;
    
    auto timeNowHiRes = std::chrono::high_resolution_clock::now(); 
    auto timeDurHiResClock= timeNowHiRes.time_since_epoch();
    std::cout << "std::chrono::high_resolution_clock: " << std::endl;
    durationSinceEpoch(timeDurHiResClock);
    
    std::cout << std::endl;

}