// D: Dependency Inversion Principle

#include<iostream>
using namespace std;

class DataBase {
public:
    virtual void save(string data) = 0;
};

class MySQLDataBase : public DataBase {
public:
    void save(string data) {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

class MongoDataBase : public DataBase {
public:
    void save(string data) {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
    }
};

class User {
    DataBase* db;
public:
    User(DataBase* db) {
        this->db = db;
    }

    void storeUser(string user) {
        db->save(user);
    }
};

int main() {
    int choice;
    string username;

    cout << "Enter user name: ";
    getline(cin, username);

    cout << "Choose Database:\n";
    cout << "1. MySQL\n";
    cout << "2. MongoDB\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    DataBase* db = nullptr;

    if (choice == 1) {
        db = new MySQLDataBase();
    } 
    else if (choice == 2) {
        db = new MongoDataBase();
    } 
    else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    User service(db);
    service.storeUser(username);


    return 0;
}
