//
//  main.cpp
//  homework6-1
//
//  Created by Teng on 5/5/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;



class User {
public:
    User() {
        name = "guest";
        rank = "beginner";
    }
    
    static User *getUser();
    static User *getUser(string name);
    
    string getName() {
        return name;
    }
    
    void login() {
        if (!online) {
            online = true;
            loginTimes++;
        }
    }
    
    void logout() {
        online = false;
    }
    
    bool isOnline() {
        return online;
    }
    
    int getLoginTimes() {
        return loginTimes;
    }
    
    int getPlayedMatches() {
        return playedMatches;
    }
    
    int getWonMatches() {
        return wonMatched;
    }
    
    double getWonRatio() {
        if (playedMatches == 0) {
            return 0;
        } else {
            ratio = (double)wonMatched/playedMatches;
            return ratio;
        }
    }
    
    string getRank() {
        return rank;
    }
    
    void setRank(string newRank) {
        rank = newRank;
    }
    
    void setName(string newName) {
        name = newName;
    }
    
    void playWith(User *anotherUser, bool win);
private:
    static map<string, User*> userMap;
    string name;
    bool online = false;
    int loginTimes = 0;
    int playedMatches = 0;
    int wonMatched = 0;
    double ratio = 0;
    string rank;
};


map<string, User*> User::userMap = *new map<string, User*>();

User *User::getUser() {
    User *newUser = new User();
    string key = "guest" + to_string(userMap.size());
    userMap.insert(pair<string, User*>(key, newUser));
    
    return newUser;
}

User *User::getUser(string name) {
    map<string, User*>::iterator iter;
    
    iter = userMap.find(name);
    if (iter != userMap.end()) {
        return userMap[name];
    } else {
        User *newUser = new User();
        newUser->setName(name);
        userMap.insert(pair<string, User*>(name, newUser));
        
        return newUser;
    }
}

void calcuRank(User* current) {
    if (current->getWonRatio() >= 0.8 && current->getPlayedMatches() >= 100) {
        current->setRank("expert");
    } else if (current->getWonRatio() >= 0.7 && current->getPlayedMatches() >= 50) {
        current->setRank("professional");
    }
}

void User::playWith(User *anotherUser, bool win) {
    if (online) {
        playedMatches++;
        anotherUser->playedMatches++;
        if (win) {
            wonMatched++;
            
        } else {
            
            anotherUser->wonMatched++;
        }
        
        calcuRank(anotherUser);
        calcuRank(this);
    }
}

//int main(int argc, const char * argv[]) {
//    
//    User *guest0 = User::getUser();
//    User *guest1 = User::getUser();
//    guest0->login();
//    cout << guest0->isOnline() <<endl; // true
//    guest0->logout();
//    cout << guest0->isOnline() <<endl; // false
//    cout << guest1->getLoginTimes() <<endl; // 0
//    User *maoge = User::getUser("Maoge");
//    cout << maoge->getName() <<endl; // Maoge
//    maoge->login();
//    maoge->logout();
//    maoge->login();
//    maoge->login();
//    cout << maoge->getLoginTimes() <<endl; // 2
//    User *maogeCopy = User::getUser("Maoge");
//    User *kuanye = User::getUser("Kuanye");
//    kuanye->playWith(maoge, true);
//    cout << kuanye->getWonMatches() <<endl; // 0
//    kuanye->login();
//    kuanye->playWith(maoge, true);
//    cout << kuanye->getWonMatches() <<endl; // 1
//    cout << maogeCopy->getPlayedMatches() <<endl; // 1
//    
//    return 0;
//}
