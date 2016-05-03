//
//  main.cpp
//  homework5-3
//
//  Created by Teng on 5/3/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Coordination {
    int x;
    int y;
};

int row, col, num;
char **square;
int **routeSqure;
bool thereIsCircle = false;
vector<Coordination> route;

void setX(int startX, int startY) {
    routeSqure[startX][startY] = 1;
    Coordination first;
    first.x = startX;
    first.y = startY;
    
    route.push_back(first);
    
    int currentX = 0;
    
    while (currentX < num) {
        Coordination current = route[route.size()-1];
        
        if (current.y > 0 && routeSqure[current.x][current.y-1] == -1) {
            if (square[current.x][current.y-1] == '.') {
                Coordination newPosition;
                newPosition.x = current.x;
                newPosition.y = current.y-1;
                routeSqure[newPosition.x][newPosition.y] = 1;
                route.push_back(newPosition);
                continue;
            }
        }
        if (current.x < row-1 && routeSqure[current.x+1][current.y] == -1) {
            if (square[current.x+1][current.y] == '.') {
                Coordination newPosition;
                newPosition.x = current.x+1;
                newPosition.y = current.y;
                routeSqure[newPosition.x][newPosition.y] = 1;
                route.push_back(newPosition);
                continue;
            }
        }
        if (current.y < col-1 && routeSqure[current.x][current.y+1] == -1) {
            if (square[current.x][current.y+1] == '.') {
                Coordination newPosition;
                newPosition.x = current.x;
                newPosition.y = current.y+1;
                routeSqure[newPosition.x][newPosition.y] = 1;
                route.push_back(newPosition);
                continue;
            }
        }
        if (current.x > 0 && routeSqure[current.x-1][current.y] == -1) {
            if (square[current.x-1][current.y] == '.') {
                Coordination newPosition;
                newPosition.x = current.x-1;
                newPosition.y = current.y;
                routeSqure[newPosition.x][newPosition.y] = 1;
                route.push_back(newPosition);
                continue;
            }
        }
        
        // 如果走不通，填X
//        if (route.size() > 3) {
//            Coordination now = route[route.size()-1];
//            Coordination last = route[route.size()-2];
//            if (now.y > 0 && (now.x != last.x && now.y-1 != last.y)) {
//                if (hasCircle(now.x, now.y-1)) {
//                    thereIsCircle = true;
//                    return;
//                }
//            }
//            if (now.x < row-1 && (now.x+1 != last.x && now.y != last.y)) {
//                if (hasCircle(now.x+1, now.y)) {
//                    thereIsCircle = true;
//                    return;
//                }
//            }
//            if (now.y < col-1 && (now.x != last.x && now.y+1 != last.y)) {
//                if (hasCircle(now.x, now.y+1)) {
//                    thereIsCircle = true;
//                    return;
//                }
//            }
//            if (now.x > 0 && (now.x-1 != last.x && now.y != last.y)) {
//                if (hasCircle(now.x-1, now.y)) {
//                    thereIsCircle = true;
//                    return;
//                }
//            }
//            route.pop_back();
//            continue;
//        } else {
//            route.pop_back();
//            continue;
//        }
        Coordination last = route[route.size()-1];
        route.pop_back();
        square[last.x][last.y] = 'X';
        currentX++;
    }
}



Coordination findStart() {
    Coordination find;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (square[i][j] == '.') {
                find.x = i;
                find.y = j;
                break;
            }
        }
    }
    return find;
}

int main() {
    
    cin >> row >> col >> num;
    
    square = new char*[row];
    routeSqure = new int*[row];
    
    for (int i = 0; i < row; ++i) {
        square[i] = new char[col];
        routeSqure[i] = new int[col];
        
        for (int j = 0; j < col; ++j) {
            cin >> square[i][j];
            routeSqure[i][j] = -1;
        }
    }
    
    Coordination start = findStart();
    setX(start.x, start.y);
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << square[i][j];
        }
        cout <<endl;
    }
    
    return 0;
}



