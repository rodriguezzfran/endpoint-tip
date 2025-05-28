#ifndef FRIENDS_GROUP_H
#define FRIENDS_GROUP_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Date
{
    int day;
    int month;
    int year;

    // this is a comparison operator to sort the dates
    // it is used to compare two dates and return true if the left date is less than the right date
    friend bool operator<(const Date& lhs, const Date& rhs)
    {
        if (lhs.year != rhs.year)
            return lhs.year < rhs.year;
        if (lhs.month != rhs.month)
            return lhs.month < rhs.month;
        return lhs.day < rhs.day;
    }
};


class FriendsGroup
{
private:
    std::map<Date, std::vector<std::string>> birthdays;

public:
    // add a birthday to the group using the date as key and the name as value
    void addBirthday(const Date& date, const std::string& name)
    {
        birthdays[date].push_back(name);
    }

    // print all birthdays in the group if the date has more than one birthday
    void show() const
    {
        for (const auto& pair : birthdays)
        {
            if (pair.second.size() > 1)
            {
                std::cout << "Date: " << pair.first.day << "/" << pair.first.month << "/" << pair.first.year
                          << "\nNames:\n";
                for (const auto& name : pair.second)
                {
                    std::cout << "  - " << name << "\n";
                }
                std::cout << std::endl;
            }
        }
    }

    // Imprime las fechas que tienen MÁS de 2 personas, usando una lambda
    void show2() const
    {
        for (const auto& pair : birthdays)
        {
            if (pair.second.size() > 1)
            {
                std::cout << "Date: " << pair.first.day << "/" << pair.first.month << "/" << pair.first.year
                          << "\nNames:\n";
                for (const auto& name : pair.second)
                {
                    std::cout << "  - " << name << "\n";
                }
                std::cout << std::endl;
            }
        }
    }
};

#endif // FRIENDS_GROUP_H