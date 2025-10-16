//Single Responsibility Principle (SRP)


#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
    string name;
    double price;

public:
    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};

// 1️ ShoppingCart: manages products
class ShoppingCart {
    vector<Product*> products;

public:
    void addProduct(Product* p) {
        products.push_back(p);
    }

    const vector<Product*>& getProducts() const {
        return products;
    }

    double calculateTotal() const {
        double total = 0;
        for (auto p : products) {
            total += p->getPrice();
        }
        return total;
    }
};

// 2️ ShoppingCartPrinter: prints invoice
class ShoppingCartPrinter {
    ShoppingCart* cart;

public:
    ShoppingCartPrinter(ShoppingCart* cart) {
        this->cart = cart;
    }

    void printInvoice() {
        cout << "\n====== Shopping Cart Invoice ======\n";
        for (auto p : cart->getProducts()) {
            cout << p->getName() << " - Rs " << p->getPrice() << endl;
        }
        cout << "-----------------------------------\n";
        cout << "Total: Rs " << cart->calculateTotal() << endl;
        cout << "===================================\n";
    }
};

// 3️ ShoppingCartStorage: saves to DB
class ShoppingCartStorage {
    ShoppingCart* cart;

public:
    ShoppingCartStorage(ShoppingCart* cart) {
        this->cart = cart;
    }

    void saveToDatabase() {
        cout << "\nSaving shopping cart to database..." << endl;
    }
};

// 🧠 main function with user input
int main() {
    ShoppingCart* cart = new ShoppingCart();

    int n;
    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        double price;

        cout << "\nEnter name of product " << i + 1 << ": ";
        cin >> ws; // whitespace clear
        getline(cin, name);

        cout << "Enter price of " << name << ": Rs ";
        cin >> price;

        cart->addProduct(new Product(name, price));
    }

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* storage = new ShoppingCartStorage(cart);
    storage->saveToDatabase();

    // clean up memory
    delete printer;
    delete storage;
    delete cart;

    return 0;
}
