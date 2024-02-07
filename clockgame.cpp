#include <iostream>
#include <list>
using namespace std;

int findWinner(int n, int k) {
    list<int> friends;

    // Create a circular linked list representing friends
    for (int i = 1; i <= n; ++i) {
        friends.push_back(i);
    }

    auto currentFriend = friends.begin();

    while (friends.size() > 1) {
        int count = 1;

        while (count < k) {
            currentFriend++;
            if (currentFriend == friends.end()) {
                currentFriend = friends.begin();
            }
            count++;
        }

        auto nextFriend = ++currentFriend;
        if (nextFriend == friends.end()) {
            nextFriend = friends.begin();
        }
        --currentFriend;

        friends.erase(currentFriend);

        currentFriend = nextFriend;
    }

    return friends.front();
}

int main() {
    int n = 5; // Number of friends
    int k = 3; // Counting interval

    int winner = findWinner(n, k);
    cout << "The winner is Friend " << winner << endl;

    return 0;
}

