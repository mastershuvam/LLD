//Oppen Closed Principle (OCP)

#include<iostream>
using namespace std;

class Product{
    public:
    string name;
    double price;

    //constractor
    public:
    Product(string name,double price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart{
    //create a array for store data
    vector<Product*>products;

    public:
    //add product
    void addProduct(Product*p){
        products.push_back(p);
    }

    //get product
    const vector<Product*> & getProducts(){
        return products;
    }

    //calculate price
    double calculatePrice(){
        double total = 0;

        for(auto p:products){
            total+=p->price;
        }

        return total;
    }
};

class ShoppingCartPrinter {
    ShoppingCart * cart;

    public:
    ShoppingCartPrinter(ShoppingCart * cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout << "Shopping Cart Invoice:\n";

        for(auto p: cart->getProducts()){
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout<<"Total: Rs "<<cart->calculatePrice()<<endl;
    }
};

class saveToDatabase{
    ShoppingCart*cart;

    public:
    virtual void save(ShoppingCart*cart) = 0;
};

class saveSQL:public saveToDatabase{
    public:
    void save(ShoppingCart*cart){
         cout << "Saving shopping cart to SQL DB..." << endl;
    }
};

class mongoDb: public saveToDatabase{
public:
    void save(ShoppingCart*cart){
        cout << "Saving shopping cart to MongoDB..." << endl;
    }
};

class FileXL:public saveToDatabase{
    public:
    void save(ShoppingCart*cart){
        cout<< "Saving shopping cart to File XL..."<<endl;
    }
};


#include<iostream>
#include<vector>
using namespace std;

int main(){
    ShoppingCart* cart = new ShoppingCart();

    int n;
    cout << "Enter number of products to add: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        string name;
        double price;

        cout << "Enter name of product " << i+1 << ": ";
        cin >> ws; // consume any leftover newline
        getline(cin, name);

        cout << "Enter price of product " << i+1 << ": ";
        cin >> price;

        cart->addProduct(new Product(name, price));
    }

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    saveToDatabase* sql = new saveSQL();
    saveToDatabase* mongoDbVar = new mongoDb();
    saveToDatabase* fileXL = new FileXL();

    sql->save(cart);
    mongoDbVar->save(cart);
    fileXL->save(cart);

    return 0;
}
