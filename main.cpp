#include <iostream>
#include <sstream>
#include <chrono>

int calculateDayOfWeek(int q, int m, int k, int j) {
    int h;

    h = (q + ((m + 1) * 26) / 10 + k + k / 4 + j / 4 - 2 * j) % 7;

    return h;
}

std::string getDayOfWeek(int h) {
    std::string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    return daysOfWeek[h];
}

int main() {
    // Get date input from the user
    std::string date;
    std::cout << "Enter the date (day month year): ";
    std::getline(std::cin, date);

    int day, month, year;
    std::stringstream(date) >> day >> month >> year;

    // Get current date
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t now_time = std::chrono::system_clock::to_time_t(now);
    struct tm* now_tm = std::localtime(&now_time);

    // Get the target date
    struct tm target_tm;
    target_tm.tm_year = year - 1900;
    target_tm.tm_mon = month - 1;
    target_tm.tm_mday = day;
    target_tm.tm_hour = 0;
    target_tm.tm_min = 0;
    target_tm.tm_sec = 0;

    // Calculate the difference in days between the two dates
    time_t target_time = std::mktime(&target_tm);
    double diff_seconds = std::difftime(now_time, target_time);
    int diff_days = diff_seconds / (60 * 60 * 24);

    // Calculate the day of the week for the target date
    int dayOfWeek = calculateDayOfWeek(day, month, year % 100, year / 100);
    std::string dayName = getDayOfWeek(dayOfWeek);

    std::cout << "The entered date falls on a " << dayName << "." << std::endl;
    std::cout << "Number of days elapsed since today: " << diff_days << std::endl;

    return 0;
}
