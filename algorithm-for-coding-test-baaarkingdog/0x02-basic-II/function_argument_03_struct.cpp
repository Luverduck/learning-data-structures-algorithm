#include <bits/stdc++.h>

using namespace std;

struct Position
{
    int x, y;
};

void func(Position pos)
{
    pos.x = 100;
}

int main()
{
    Position pos = {0, 0};
    func(pos);
    cout << pos.x;
}