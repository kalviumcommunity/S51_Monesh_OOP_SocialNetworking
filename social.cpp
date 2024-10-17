#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract class User with a virtual function
class User {
protected:
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

    // Virtual destructor (important for abstract base classes)
    virtual ~User() {
        userCount--; // Decrement the user count when a user is deleted
    }

    void addFriend(const string& friendName) {
        this->friends.push_back(friendName);
    }

    // Pure virtual function (this makes the User class abstract)
    virtual void displayProfile() const = 0;

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

    // Override the virtual function from the User class
    void displayProfile() const override {
        cout << "Admin Profile\n";
        cout << "Name: " << name << "\nEmail: " << email << "\nRole: " << adminRole << "\n";
        cout << "Friends: ";
        for (const auto& f : friends) {
            cout << f << " ";
        }
        cout << "\n";
    }

    void displayAdminProfile() const {
        displayProfile(); // Calls the overridden method
    }
};

// RegularUser class inherits from User and implements the displayProfile method
class RegularUser : public User {
public:
    RegularUser(const string& n, const string& e) : User(n, e) {}

    // Override the virtual function from the User class
    void displayProfile() const override {
        cout << "Regular User Profile\n";
        cout << "Name: " << name << "\nEmail: " << email << "\nFriends: ";
        for (const auto& f : friends) {
            cout << f << " ";
        }
        cout << "\n";
    }
};

// Post class
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

int main() {
    // Create RegularUser and AdminUser objects
    RegularUser* user1 = new RegularUser("Alice", "alice@example.com");
    AdminUser* admin1 = new AdminUser("Bob", "bob@admin.com", "Super Admin");

    // Add friends
    user1->addFriend("Charlie");
    admin1->addFriend("Alice");

    // Display profiles
    user1->displayProfile(); // Calls the overridden displayProfile for RegularUser
    admin1->displayProfile(); // Calls the overridden displayProfile for AdminUser

    // Display the total number of users
    cout << "Total Users: " << User::getUserCount() << "\n";

    // Create Post objects
    Post* post1 = new Post("Alice", "Hello, world!");
    Post* post2 = new Post("Bob", "Admin post here!");

    // Like and display posts
    post1->likePost();
    post1->displayPost();
    post2->displayPost();

    // Display the total number of posts
    cout << "Total Posts: " << Post::getPostCount() << "\n";

    // Cleanup
    delete user1;
    delete admin1;
    delete post1;
    delete post2;

    // After deletion, display the total number of users and posts again
    cout << "Total Users after deletion: " << User::getUserCount() << "\n";
    cout << "Total Posts after deletion: " << Post::getPostCount() << "\n";

    return 0;
}
