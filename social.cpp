#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User {
private:
    string name;
    string email;
    vector<string> friends;

    // Static variable to keep track of the total number of users
    static int userCount;

public:
    User(const string& n, const string& e) : name(n), email(e) {
        userCount++; // Increment the user count when a new user is created
    }

    ~User() {
        userCount--; // Decrement the user count when a user is deleted
    }

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

    // Static method to get the total number of users
    static int getUserCount() {
        return userCount;
    }
};

// Initialize static variable
int User::userCount = 0;

class Post {
private:
    string user;
    string content;
    int likes;

    // Static variable to track the total number of posts
    static int postCount;

public:
    Post(const string& u, const string& c) : user(u), content(c), likes(0) {
        postCount++; // Increment the post count when a new post is created
    }

    ~Post() {
        postCount--; // Decrement the post count when a post is deleted
    }

    void likePost() {
        this->likes++;
    }

    void displayPost() {
        cout << "User: " << this->user << "\nContent: " << this->content << "\nLikes: " << this->likes << "\n";
    }

    // Static method to get the total number of posts
    static int getPostCount() {
        return postCount;
    }
};

// Initialize static variable
int Post::postCount = 0;

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
    // Create an array of User objects using dynamic memory allocation
    vector<User*> users = {
        new User("Alice", "alice@example.com"),
        new User("Bob", "bob@example.com")
    };

    // Add friends
    users[0]->addFriend("Bob");
    users[1]->addFriend("Alice");

    // Display profiles
    for (auto user : users) {
        user->displayProfile();
    }

    // Display the total number of users
    cout << "Total Users: " << User::getUserCount() << "\n";

    // Create a post using dynamic memory allocation
    Post* post1 = new Post("Alice", "Hello, world!");
    post1->likePost();

    // Display post
    post1->displayPost();

    // Display the total number of posts
    cout << "Total Posts: " << Post::getPostCount() << "\n";

    // Send a message using dynamic memory allocation
    Message* msg1 = new Message("Alice", "Bob", "Hi Bob!");
    msg1->displayMessage();

    // Edit and display the message
    msg1->editMessage("Hello Bob!");
    msg1->displayMessage();

    // Cleanup: delete dynamically allocated objects
    for (auto user : users) {
        delete user;
    }
    delete post1;
    delete msg1;

    // After deletion, display the total number of users and posts again
    cout << "Total Users after deletion: " << User::getUserCount() << "\n";
    cout << "Total Posts after deletion: " << Post::getPostCount() << "\n";

    return 0;
}
