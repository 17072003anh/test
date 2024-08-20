// Friend.h
#ifndef FRIEND_H
#define FRIEND_H

#include <string>
using namespace std;

// Lớp cơ bản Friend
class Friend {
protected:
    string name;
    int age;

public:
    Friend(string name, int age);
    virtual double calculateTime(int totalFriends) = 0;
    virtual void printInfo() = 0;
    virtual ~Friend() {}
};

class BestFriend : public Friend {
private:
    string phone;

public:
    BestFriend(string name, int age, string phone);
    double calculateTime(int totalFriends);
    void printInfo();
};

class BoyFriend : public Friend {
private:
    double income;

public:
    BoyFriend(string name, int age, double income);
    double calculateTime(int totalFriends);
    void printInfo();
};


class OtherBoy : public Friend {
private:
    double attractiveness;

public:
    OtherBoy(string name, int age, double attractiveness);
    double calculateTime(int totalFriends);
    void printInfo();
};

class PhanLoai {
private:
    Friend** friends;  
    int capacity;      
    int count;         

public:
    PhanLoai(int capacity);
    void addFriend(Friend* newFriend);
    void inputFriends(int n);
    void displayStatistics();
    void displayMostImportantFriends();
    ~PhanLoai();
};

#endif
