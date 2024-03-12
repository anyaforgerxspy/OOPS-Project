#include <iostream>
#include <string>

class User {
private:
    std::string name;
    int birth_year;
    int birth_day;
    int birth_month;
    double salary;

public:
    User(std::string n, int by, int bd, int bm, double s) 
        : name(n), birth_year(by), birth_day(bd), birth_month(bm), salary(s) {}

    bool operator==(const User& other) const {
        return (birth_year == other.birth_year) && 
               (birth_month == other.birth_month) && 
               (birth_day == other.birth_day);
    }

    bool operator>(const User& other) const {
        if (birth_year != other.birth_year)
            return birth_year > other.birth_year;
        if (birth_month != other.birth_month)
            return birth_month > other.birth_month;
        return birth_day > other.birth_day;
    }

    bool operator<(const User& other) const {
        if (birth_year != other.birth_year)
            return birth_year < other.birth_year;
        if (birth_month != other.birth_month)
            return birth_month < other.birth_month;
        return birth_day < other.birth_day;
    }

    int compareAge(const User& other) const {
        if (*this == other) return 0;
        return (*this > other) ? 1 : -1;
    }

    double operator+(const User& other) const {
        return (salary + other.salary) / 2.0;
    }

    User operator+(int percentage) const {
        double increment = salary * percentage / 100.0;
        return User(name, birth_year, birth_day, birth_month, salary + increment);
    }

    void displayDetails() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Birth Year: " << birth_year << std::endl;
        std::cout << "Birth Day: " << birth_day << std::endl;
        std::cout << "Birth Month: " << birth_month << std::endl;
        std::cout << "Salary: " << salary << std::endl;
    }
};

int main() {
    User user1("Alice", 1990, 15, 3, 50000.0);
    User user2("Bob", 1995, 10, 5, 60000.0);

    int result = user1.compareAge(user2);
    double average_sal = user1 + user2;

    std::cout << "Comparison result: " << result << std::endl;
    std::cout << "Average Salary: " << average_sal << std::endl;

    user1.displayDetails();
    user2.displayDetails();

    return 0;
}