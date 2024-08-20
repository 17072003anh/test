#include "Friend.h"
#include <iostream>
#include <iomanip>

using namespace std;

Friend::Friend(string name, int age) : name(name), age(age) {}

BestFriend::BestFriend(string name, int age, string phone) : Friend(name, age), phone(phone) {}

double BestFriend::calculateTime(int totalFriends) {
    return 5.0;
}

void BestFriend::printInfo() {
    cout << "Ten: " << name << ", tuoi: " << age << ", so dien thoai: " << phone << endl;
}

BoyFriend::BoyFriend(string name, int age, double income) : Friend(name, age), income(income) {}

double BoyFriend::calculateTime(int totalFriends) {
    return 5.0 * income / 10000000.0;
}

void BoyFriend::printInfo() {
    cout << "Ten: " << name << ", tuoi: " << age << ", thu nhap: " << fixed << setprecision(0) << income << "d" << endl;
}

OtherBoy::OtherBoy(string name, int age, double attractiveness) : Friend(name, age), attractiveness(attractiveness) {}

double OtherBoy::calculateTime(int totalFriends) {
    return attractiveness * 20.0 / totalFriends;
}

void OtherBoy::printInfo() {
    cout << "Ten: " << name << ", tuoi: " << age << ", do thu hut: ";
    if (attractiveness >= 0.7)
        cout << "cao";
    else if (attractiveness >= 0.4)
        cout << "trung binh";
    else
        cout << "thap";
    cout << endl;
}

PhanLoai::PhanLoai(int capacity) : capacity(capacity), count(0) {
    friends = new Friend*[capacity];
}

void PhanLoai::addFriend(Friend* newFriend) {
    if (count < capacity) {
        friends[count++] = newFriend;
    } else {
        cout << "Khong the them ban moi, da dat gioi han." << endl;
    }
}

void PhanLoai::inputFriends(int n) {
    for (int i = 0; i < n; ++i) {
        int type;
        string name;
        int age;
        cin >> type >> name >> age;

        if (type == 1) {
            string phone;
            cin >> phone;
            addFriend(new BestFriend(name, age, phone));
        } else if (type == 2) {
            double income;
            cin >> income;
            addFriend(new BoyFriend(name, age, income));
        } else if (type == 3) {
            double attractiveness;
            cin >> attractiveness;
            addFriend(new OtherBoy(name, age, attractiveness));
        }
    }
}

void PhanLoai::displayStatistics() {
    double timeForBestFriend = 0.0, timeForBoyFriend = 0.0, timeForOtherBoy = 0.0;

    for (int i = 0; i < count; ++i) {
        if (dynamic_cast<BestFriend*>(friends[i])) {
            timeForBestFriend += friends[i]->calculateTime(count);
        } else if (dynamic_cast<BoyFriend*>(friends[i])) {
            timeForBoyFriend += friends[i]->calculateTime(count);
        } else if (dynamic_cast<OtherBoy*>(friends[i])) {
            timeForOtherBoy += friends[i]->calculateTime(count);
        }
    }

    cout << "Thong ke:" << endl;
    if (timeForBestFriend > 0) {
        cout << "- Thoi gian cho ban than: " << timeForBestFriend << " h" << endl;
    }
    if (timeForBoyFriend > 0) {
        cout << "- Thoi gian cho ban trai: " << timeForBoyFriend << " h" << endl;
    }
    if (timeForOtherBoy > 0) {
        cout << "- Thoi gian cho ban trai khac: " << timeForOtherBoy << " h" << endl;
    }
}

void PhanLoai::displayMostImportantFriends() {
    double maxTime = 0.0;
    Friend** importantFriends = new Friend*[capacity]; 
    int importantCount = 0;

    for (int i = 0; i < count; ++i) {
        double time = friends[i]->calculateTime(count);
        if (time > maxTime) {
            importantCount = 0;
            importantFriends[importantCount++] = friends[i];
            maxTime = time;
        } else if (time == maxTime) {
            importantFriends[importantCount++] = friends[i];
        }
    }

    cout << "Nguoi ban quan trong nhat:" << endl;
    for (int i = 0; i < importantCount; ++i) {
        importantFriends[i]->printInfo();
    }

    delete[] importantFriends;  
}


PhanLoai::~PhanLoai() {
    for (int i = 0; i < count; ++i) {
        delete friends[i];
    }
    delete[] friends;
}
