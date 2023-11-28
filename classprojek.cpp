#include <iostream>
using namespace std;

struct Product
{
    string productName;
    string productBrand;
    string productCategory;
    double productPrice;
    int productID;
};

const int maxProduct = 50;
int productCount = 0;
Product productList[maxProduct];
Product productChosen;
bool productIsChosen = false;


void predefinedProduct()
{
    productList[productCount++] = {"ASUS TUF F15 FX506HC", "ASUS", "Laptop", 1199.99, 115};
    productList[productCount++] = {"Lenovo LOQ 15 IRH-8", "LENOVO", "Laptop", 1399.90, 105};
    productList[productCount++] = {"Nokia 106 Dual Sim", "NOKIA", "Handphone", 399.90, 201};
    productList[productCount++] = {"HUAWEI Band 8", "HUAWEI", "Smartwatch", 599.90, 345};
    productList[productCount++] = {"Kingston SSD A400 480GB", "KINGSTON", "SSD", 499.90, 401};
    productList[productCount++] = {"Resistor 1k", "RESISTOR", "Komponen", 500.00, 115};
    //...
}

void displayProducts()
{
    cout << "Available products : " << endl;
    for (int i = 0; i < productCount; i++)
    {
        cout << "Name : " << productList[i].productName;
        cout << ", Brand : " << productList[i].productBrand;
        cout << ", category : " << productList[i].productCategory;
        cout << ", price : $" << productList[i].productPrice;
        cout << ", ID : " << productList[i].productID << endl;
    }
    cout << endl;
}

void displayByCategory(int typeCategory)
{
    if(typeCategory>0 && typeCategory<=5)
    {
        cout << "Products in the selected category : " << endl;
        for (int i = 0; i < productCount; i++)
        {
            if (typeCategory == 1 && productList[i].productCategory == "Laptop")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
            else if (typeCategory == 2 && productList[i].productCategory == "Handphone")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
            else if (typeCategory == 3 && productList[i].productCategory == "Smartwatch")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
            else if (typeCategory == 4 && productList[i].productCategory == "SSD")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
            else if (typeCategory == 5 && productList[i].productCategory == "Komponen")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
            
        }
    }
     else
    {
            cout<<"ENTER THE AVAILABLE CATEGORIES!!!!!!!!!";
    }
    cout << endl;
}

void displayByBrand(string brand)
{
    cout << "Products by the selected brand : " << endl;
    for (int i = 0; i < productCount; i++)
    {
        if (productList[i].productBrand == brand)
        {
            cout << "Name : " << productList[i].productName;
            cout << ", Brand : " << productList[i].productBrand;
            cout << ", Category : " << productList[i].productCategory;
            cout << ", Price : $" << productList[i].productPrice;
            cout << ", ID : " << productList[i].productID << endl;
        }
    }
    cout << endl;
}

void displayByPrice() {
    // Copying productList to tempProductList to not tampering with displayProduct index
    Product tempProductList[productCount];
    Product tempKey;
    for (int i = 0; i < productCount; i++) {
        tempProductList[i] = productList[i];
    }

    int key, j = productCount;
    for (int i = 1; i < productCount; i++) {
        key = tempProductList[i].productPrice;
        tempKey = tempProductList[i];
        j = i - 1;

        while (j >= 0 && tempProductList[j].productPrice > key) {
            tempProductList[j + 1] = tempProductList[j];
            j = j - 1;
        }
        tempProductList[j + 1] = tempKey;
    }

    cout << "Available products : " << endl;
    for (int i = 0; i < productCount; i++)
    {
        cout << "Name : " << tempProductList[i].productName;
        cout << ", Brand : " << tempProductList[i].productBrand;
        cout << ", category : " << tempProductList[i].productCategory;
        cout << ", price : $" << tempProductList[i].productPrice;
        cout << ", ID : " << tempProductList[i].productID << endl;
    }
    cout << endl;
}


struct User
{
    string userName, userPass;
};

User singleUser = {"user1", "awikwok1"};

bool userAuthentication(string userName, string userPass)
{
    if (singleUser.userName == userName && singleUser.userPass == userPass)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    predefinedProduct();
    string username, password;

    cout << "=== Welcome to TronHUB ===" << endl;
    do
    {
        cout << "Enter your username : ";
        cin >> username;
        cout << "Enter your password : ";
        cin >> password;

        if (!userAuthentication(username, password))
        {
            cout << "Invalid username or password" << endl;
        }
    } while (!userAuthentication(username, password));
    cout << "login successful!" << endl;
    int option;
    do
    {
        cout << "Home Page" << endl;
        cout << "1. Display all available Products" << endl;
        cout << "2. Display Products by category" << endl;
        cout << "3. Display Products by brand" << endl;
        cout << "4. Display Product by Price" << endl;
        cout << "5. Add products to cart" << endl;
        cout << "6. Buy products from the cart" << endl;
        cout << "7. Exit" << endl;
        cout << "please select your choice = ";
        cin >> option;

        switch (option)
        {
        case 1:
            displayProducts();
            break;
        case 2:
        {
        int categoryOption;
        cout << "Enter category option: " << endl;
        cout << "1. Laptop\n2. Handphone\n3. Smartwatch\n4. SSD\n5. Komponen" << endl; 
        cin >> categoryOption;
        displayByCategory(categoryOption);
        break;
        }
      case 3:
        {
        string brand;
        cout << "Enter brand: ";
        cin >> brand;
        displayByBrand(brand);
        break;
        }
        case 4:
            displayByPrice();
            break;
        case 7:
            cout << "exiting the program, goodbye";
            break;
        }
    } while (option != 7);
} //program is still yet to finish
