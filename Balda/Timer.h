#include <iostream>
#include <chrono>


class Time {
public:
    int hours;
    int minutes;
    int seconds;

    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void display()
    {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }
};

class Timer {
private:
    std::chrono::time_point<std::chrono::steady_clock> start_time;
    bool is_running;
public:
    Timer() : is_running(false) {}
    void start()
    {
        start_time = std::chrono::steady_clock::now();
        is_running = true;
    }
    Time stop()
    {
        auto end_time = std::chrono::steady_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();
        int hours = elapsed_time / 3600;
        int minutes = (elapsed_time % 3600) / 60;
        int seconds = elapsed_time % 60;
        Time elapsed(hours, minutes, seconds);
        is_running = false;
        return elapsed;
    }
};
