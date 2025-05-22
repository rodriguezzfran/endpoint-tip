#ifndef FRIENDS_GROUP_HPP
#define FRIENDS_GROUP_HPP

#include <iostream>
#include <map>
#include <vector>
#include <string>

class FriendsGroup {
    private:
        std::map<std::string, std::vector<std::string>> birthdays;
    public:
        
        // add a birthday to the group using the date as key and the name as value
        void addBirthday(const std::string& date, const std::string& name) {
            birthdays[date].push_back(name);
        }

        // print all birthdays in the group if the date has more than one birthday
        void show() const {
            for (const auto& pair : birthdays) {
                if (pair.second.size() > 1) {
                    std::cout << "Date: " << pair.first << "\nNames: ";
                    bool first = true;
                    for (const auto& name : pair.second) {
                        if (first) {
                            std::cout << name;
                            first = false;
                        } else {
                            std::cout <<"       " << name << "\n";
                        }
                        std::cout << "\n";
                    }
                }
            }
        }

};

#endif