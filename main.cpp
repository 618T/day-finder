#include <iostream>

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
    int q, m, y;

    std::cout << "Enter the date:\n";
    std::cout << "Day: ";
    std::cin >> q;
    std::cout << "Month: ";
    std::cin >> m;
    std::cout << "Year: ";
    std::cin >> y;

    int k = y % 100; 
    int j = y / 100; 

    int dayOfWeek = calculateDayOfWeek(q, m, k, j);
    std::string dayName = getDayOfWeek(dayOfWeek);

    std::cout << "The date entered falls on " << dayName << std::endl;

    return 0;
}
