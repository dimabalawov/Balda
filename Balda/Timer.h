#include <iostream>
#include <chrono>
using namespace std;

class Time {
    int hours;
    int minutes;
    int seconds;
public:

    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void display()
    {
        cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }
};

class Timer
{
    chrono::time_point<chrono::steady_clock> start_time;
    bool isRunning;
public:
    Timer() : isRunning(false) {}
    void start()
    {
        start_time = chrono::steady_clock::now();
        isRunning = true;
    }
    Time stop()
    {
        auto end_time = chrono::steady_clock::now();
        size_t elapsed_time = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();
        int hours = elapsed_time / 3600;
        int minutes = (elapsed_time % 3600) / 60;
        int seconds = elapsed_time % 60;
        Time elapsed(hours, minutes, seconds);
        isRunning = false;
        return elapsed;
    }
};
