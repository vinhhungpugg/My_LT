#include <iostream>
#include <string>

using namespace std;

class Time 
{
private:
    int hour, minute, second;

public:
    Time() : hour(0), minute(0), second(0) {}
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    int getHour() 
    {
        return hour;
    }

    int getMinute() 
    {
        return minute;
    }

    void setHour(int h) 
    {
        hour = h;
    }

    void setMinute(int m) 
    {
        minute = m;
    }

    bool isValidTime(int h, int m) 
    {
        return (h >= 0 && h <= 23) && (m >= 0 && m <= 59);
    }

    string getAMPM(int h) 
    {
        return (h >= 0 && h <= 11) ? "AM" : "PM";
    }

    static Time gio(long mili)
    {
        Time time;
        long seconds = mili/1000;
        time.hour = seconds / 3600;
        time.minute = (seconds % 3600) / 60;
        time.second = seconds % 60;
        return time;
    }
};

int main() {
    Time time;
    int inputHour, inputMinute;

    cout << "Enter hour: ";
    cin >> inputHour;

    cout << "Enter minute: ";
    cin >> inputMinute;


    if (time.isValidTime(inputHour, inputMinute)) {
        cout << "Valid time entered." << endl;
    } else {
        cout << "Invalid time entered. Please enter again." << endl;
        return 1;
    }

    time.setHour(inputHour);
    time.setMinute(inputMinute);

    cout << "Time entered belongs to: " << time.getAMPM(inputHour) << endl;


    cout << "Enter miliseconds: ";
    long inputMili;
    cin >> inputMili;
    Time timemili=Time::gio(inputMili);
    cout << "Time: "<<timemili.getHour()<<":"<<timemili.getMinute()<<'\n';
    return 0;
}
