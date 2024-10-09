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
    // Default constructor
    User() : name("Unknown"), email("unknown@example.com") {
        userCount++;
    }

    // Parameterized constructor
    User(const string& n, const string& e) : name(n), email(e) {
        userCount++;
    }

    ~User() {
        userCount--; // Decrement the user count when a user is deleted
    }

    void addFriend(const string& friendName) {
        this->friends.push_back(friendName);
    }

    // Overloaded function to display profile
    void displayProfile() const {
        cout << "Name: " << this->name << "\nEmail: " << this->email << "\nFriends: ";
        for (const auto& f : friends) {
            cout << f << " ";
        }
        cout << "\n";
    }

    // Overloaded function with one argument to display specific friend details
    void displayProfile(const string& friendName) const {
        cout << "User: " << this->name << " has friend: " << friendName << "\n";
    }

    // Static method to get the total number of users
    static int getUserCount() {
        return userCount;
    }

    // Getter for name (used in AdminUser)
    string getName() const {
        return name;
    }
};

// Initialize static variable
int User::userCount = 0;

// Single Inheritance: AdminUser class inherits from User class
class AdminUser : public User {
private:
    string adminRole;

public:
    AdminUser(const string& n, const string& e, const string& role) : User(n, e), adminRole(role) {}

    void displayAdminProfile() const {
        // Call base class method to display the common user profile details
        displayProfile();
        // Add admin-specific details
        cout << "Role: " << adminRole << "\n";
    }
};

class Post {
private:
    string user;
    string content;
    int likes;

    // Static variable to track the total number of posts
    static int postCount;

public:
    // Default constructor
    Post() : user("Anonymous"), content("No Content"), likes(0) {
        postCount++;
    }

    // Parameterized constructor
    Post(const string& u, const string& c) : user(u), content(c), likes(0) {
        postCount++;
    }

    ~Post() {
        postCount--; // Decrement the post count when a post is deleted
    }

    void likePost() {
        this->likes++;
    }

    void displayPost() const {
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
    // Parameterized constructor
    Message(const string& s, const string& r, const string& c) : sender(s), receiver(r), content(c) {}

    void displayMessage() const {
        cout << "From: " << this->sender << "\nTo: " << this->receiver << "\nMessage: " << this->content << "\n";
    }
    
    void editMessage(const string& newContent) {
        this->content = newContent;
    }
};

// Multiple Inheritance: Comment class inherits from both Post and Message
class Comment : public Post, public Message {
public:
    // Constructor to initialize both base classes
    Comment(const string& u, const string& c, const string& s, const string& r, const string& m)
        : Post(u, c), Message(s, r, m) {}

    // Display details of both post and message
    void displayComment() const {
        displayPost();      // Call Post's display method
        displayMessage();   // Call Message's display method
    }
};

int main() {
    // Create User objects using both default and parameterized constructors
    vector<User*> users = {
        new User(),                    // Default constructor
        new User("Alice", "alice@example.com")  // Parameterized constructor
    };

    // Add friends
    users[0]->addFriend("Bob");
    users[1]->addFriend("Charlie");

    // Display profiles
    for (auto user : users) {
        user->displayProfile(); // Calls the regular displayProfile()
    }

    // Using the overloaded displayProfile() function
    users[1]->displayProfile("Charlie"); // Calls the overloaded displayProfile() with a friend name

    // Display the total number of users
    cout << "Total Users: " << User::getUserCount() << "\n";

    // Create AdminUser
    AdminUser* admin = new AdminUser("Charlie", "charlie@admin.com", "Super Admin");
    admin->displayAdminProfile();

    // Create Post objects using both default and parameterized constructors
    Post* post1 = new Post();                 // Default constructor
    Post* post2 = new Post("Alice", "Hello, world!"); // Parameterized constructor
    post2->likePost();

    // Display posts
    post1->displayPost();
    post2->displayPost();

    // Display the total number of posts
    cout << "Total Posts: " << Post::getPostCount() << "\n";

    // Send a message using dynamic memory allocation
    Message* msg1 = new Message("Alice", "Bob", "Hi Bob!");
    msg1->displayMessage();

    // Create a comment (Multiple Inheritance: Post + Message)
    Comment* comment = new Comment("Alice", "Great post!", "Bob", "Alice", "Thanks, Alice!");
    comment->displayComment();

    // Cleanup: delete dynamically allocated objects
    for (auto user : users) {
        delete user;
    }
    delete admin;
    delete post1;
    delete post2;
    delete msg1;
    delete comment;

    // After deletion, display the total number of users and posts again
    cout << "Total Users after deletion: " << User::getUserCount() << "\n";
    cout << "Total Posts after deletion: " << Post::getPostCount() << "\n";

    return 0;
}
