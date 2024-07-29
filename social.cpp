#include <iostream>
#include <vector>
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
        this->friends.push_back(friendName);
    }

    void displayProfile() {
        cout << "Name: " << this->name << "\nEmail: " << this->email << "\nFriends: ";
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
        this->likes++;
    }

    void displayPost() {
        cout << "User: " << this->user << "\nContent: " << this->content << "\nLikes: " << this->likes << "\n";
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
        cout << "From: " << this->sender << "\nTo: " << this->receiver << "\nMessage: " << this->content << "\n";
    }
    
    void editMessage(const string& newContent) {
        this->content = newContent;
    }
};

int main() {
    // Create an array of User objects
    vector<User> users = {
        User("Alice", "alice@example.com"),
        User("Bob", "bob@example.com")
    };

    // Add friends
    users[0].addFriend("Bob");
    users[1].addFriend("Alice");

    // Display profiles
    for (auto& user : users) {
        user.displayProfile();
    }

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
