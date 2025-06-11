#ifndef FRIENDS_GROUP_H
#define FRIENDS_GROUP_H

#include <functional>
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

        bool leftLessThanRight = false;

        // Compare years first
        if (lhs.year < rhs.year)
        {
            leftLessThanRight = true;
        }
        else if (lhs.year == rhs.year)
        {
            // If years are equal, compare months
            if (lhs.month < rhs.month)
            {
                leftLessThanRight = true;
            }
            // If months are also equal, compare days
            else if (lhs.month == rhs.month)
            {
                if (lhs.day < rhs.day)
                {
                    leftLessThanRight = true;
                }
            }
        }

        return leftLessThanRight;
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
                std::cout << "Date: " << pair.first.day << "/" << pair.first.month << "/"
                          << pair.first.year << "\nNames:\n";
                for (const auto& name : pair.second)
                {
                    std::cout << "  - " << name << "\n";
                }
                std::cout << std::endl;
            }
        }
    }

    // funcion lambda para imprimir los cumpleaños de aquellas fechas con 2 o más personas
    std::function<void()> show2 = [this]()
    {
        for (const auto& pair : birthdays)
        {
            if (pair.second.size() > 1)
            {
                std::cout << "Date: " << pair.first.day << "/" << pair.first.month << "/"
                          << pair.first.year << "\nNames:\n";
                for (const auto& name : pair.second)
                {
                    std::cout << "  - " << name << "\n";
                }
                std::cout << std::endl;
            }
        }
    };
};

#endif // FRIENDS_GROUP_H