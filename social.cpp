#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class User {
private:
    string name;
    string email;
    vector<string> friends;

public:
    User(const string& n, const string& e) : name(n), email(e) {}

    void addFriend(const string& friendName) {
        friends.push_back(friendName);
    }

    void displayProfile() {
        cout << "Name: " << name << "\nEmail: " << email << "\nFriends: ";
        for (const auto& f : friends) {
            cout << f << " ";
        }
        cout << "\n";
    }
};

class Post {
private:
    string user;
    string content;
    int likes;

public:
    Post(const string& u, const string& c) : user(u), content(c), likes(0) {}

    void likePost() {
        likes++;
    }

    void displayPost() {
        cout << "User: " << user << "\nContent: " << content << "\nLikes: " << likes << "\n";
    }
};

class Message {
private:
    string sender;
    string receiver;
    string content;

public:
    Message(const string& s, const string& r, const string& c) : sender(s), receiver(r), content(c) {}

    void displayMessage() {
        cout << "From: " << sender << "\nTo: " << receiver << "\nMessage: " << content << "\n";
    }
    
    void editMessage(const string& newContent) {
        content = newContent;
    }
};

int main() {
    // Create users
    User user1("Alice", "alice@example.com");
    User user2("Bob", "bob@example.com");

    // Add friends
    user1.addFriend("Bob");
    user2.addFriend("Alice");

    // Display profiles
    user1.displayProfile();
    user2.displayProfile();

    // Create a post
    Post post1("Alice", "Hello, world!");
    post1.likePost();

    // Display post
    post1.displayPost();

    // Send a message
    Message msg1("Alice", "Bob", "Hi Bob!");
    msg1.displayMessage();

    // Edit and display the message
    msg1.editMessage("Hello Bob!");
    msg1.displayMessage();

    return 0;
}
