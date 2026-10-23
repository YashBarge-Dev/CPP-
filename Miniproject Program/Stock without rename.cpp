#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Stock
{
private:
    int productID;
    string productName;
    string category;
    double price;
    int quantity;
    string supplierName;

public:

    // Accept product details
    void accept()
    {
        cout << "\nEnter Product ID: ";
        cin >> productID;

        cout << "Enter Product Name: ";
        cin >> productName;

        cout << "Enter Category: ";
        cin >> category;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Supplier Name: ";
        cin >> supplierName;
    }

    // Display product details
    void display()
    {
        cout << "\n----------------------------------------";
        cout << "\nProduct ID     : " << productID;
        cout << "\nProduct Name   : " << productName;
        cout << "\nCategory       : " << category;
        cout << "\nPrice          : " << price;
        cout << "\nQuantity       : " << quantity;
        cout << "\nSupplier Name  : " << supplierName;
        cout << "\n----------------------------------------";
    }

    // Write object to file
    void writeToFile(ofstream &fout)
    {
        fout << productID << " "
             << productName << " "
             << category << " "
             << price << " "
             << quantity << " "
             << supplierName << endl;
    }

    // Read object from file
    bool readFromFile(ifstream &fin)
    {
        if (fin >> productID
                >> productName
                >> category
                >> price
                >> quantity
                >> supplierName)
        {
            return true;
        }

        return false;
    }

    int getProductID()
    {
        return productID;
    }

    int getQuantity()
    {
        return quantity;
    }

    double getPrice()
    {
        return price;
    }

    // Purchase stock
    void purchase(int qty)
    {
        quantity = quantity + qty;
    }

    // Sell stock
    bool sell(int qty)
    {
        if (qty <= quantity)
        {
            quantity = quantity - qty;
            return true;
        }

        return false;
    }
};


// 1. ADD PRODUCT
void addProduct()
{
    Stock s;

    s.accept();

    ofstream fout("stock.txt", ios::app);

    if (!fout)
    {
        cout << "\nError opening file!";
        return;
    }

    s.writeToFile(fout);

    fout.close();

    cout << "\nProduct added successfully!";
}


// 2. DISPLAY ALL PRODUCTS
void displayProducts()
{
    Stock s;
    ifstream fin("stock.txt");

    if (!fin)
    {
        cout << "\nNo stock records found!";
        return;
    }

    bool found = false;

    cout << "\n\n========== ALL PRODUCTS ==========";

    while (s.readFromFile(fin))
    {
        s.display();
        found = true;
    }

    fin.close();

    if (!found)
    {
        cout << "\nNo products available!";
    }
}


// 3. SEARCH PRODUCT
void searchProduct()
{
    int id;
    bool found = false;

    cout << "\nEnter Product ID to search: ";
    cin >> id;

    ifstream fin("stock.txt");

    if (!fin)
    {
        cout << "\nFile could not be opened!";
        return;
    }

    Stock s;

    while (s.readFromFile(fin))
    {
        if (s.getProductID() == id)
        {
            cout << "\nProduct Found!";
            s.display();
            found = true;
            break;
        }
    }

    fin.close();

    if (!found)
    {
        cout << "\nProduct not found!";
    }
}


// 4. UPDATE PRODUCT
void updateProduct()
{
    int id;
    bool found = false;

    cout << "\nEnter Product ID to update: ";
    cin >> id;

    ifstream fin("stock.txt");
    ofstream fout("temp.txt");

    if (!fin)
    {
        cout << "\nFile could not be opened!";
        return;
    }

    Stock s;

    while (s.readFromFile(fin))
    {
        if (s.getProductID() == id)
        {
            cout << "\nEnter new details:\n";
            s.accept();
            found = true;
        }

        s.writeToFile(fout);
    }

    fin.close();
    fout.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    if (found)
        cout << "\nProduct updated successfully!";
    else
        cout << "\nProduct not found!";
}


// 5. DELETE PRODUCT
void deleteProduct()
{
    int id;
    bool found = false;

    cout << "\nEnter Product ID to delete: ";
    cin >> id;

    ifstream fin("stock.txt");
    ofstream fout("temp.txt");

    if (!fin)
    {
        cout << "\nFile could not be opened!";
        return;
    }

    Stock s;

    while (s.readFromFile(fin))
    {
        if (s.getProductID() == id)
        {
            found = true;
            continue;
        }

        s.writeToFile(fout);
    }

    fin.close();
    fout.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    if (found)
        cout << "\nProduct deleted successfully!";
    else
        cout << "\nProduct not found!";
}


// 6. PURCHASE STOCK
void purchaseStock()
{
    int id;
    int qty;
    bool found = false;

    cout << "\nEnter Product ID: ";
    cin >> id;

    cout << "Enter quantity to purchase: ";
    cin >> qty;

    ifstream fin("stock.txt");
    ofstream fout("temp.txt");

    if (!fin)
    {
        cout << "\nFile could not be opened!";
        return;
    }

    Stock s;

    while (s.readFromFile(fin))
    {
        if (s.getProductID() == id)
        {
            s.purchase(qty);
            found = true;
        }

        s.writeToFile(fout);
    }

    fin.close();
    fout.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    if (found)
        cout << "\nStock purchased successfully!";
    else
        cout << "\nProduct not found!";
}


// 7. SELL STOCK
void sellStock()
{
    int id;
    int qty;
    bool found = false;
    bool sold = false;

    cout << "\nEnter Product ID: ";
    cin >> id;

    cout << "Enter quantity to sell: ";
    cin >> qty;

    ifstream fin("stock.txt");
    ofstream fout("temp.txt");

    if (!fin)
    {
        cout << "\nFile could not be opened!";
        return;
    }

    Stock s;

    while (s.readFromFile(fin))
    {
        if (s.getProductID() == id)
        {
            found = true;

            if (s.sell(qty))
            {
                sold = true;
            }
        }

        s.writeToFile(fout);
    }

    fin.close();
    fout.close();

    remove("stock.txt");
  //  rename("temp.txt", "stock.txt");

    if (!found)
    {
        cout << "\nProduct not found!";
    }
    else if (sold)
    {
        cout << "\nStock sold successfully!";
    }
    else
    {
        cout << "\nInsufficient stock!";
    }
}


// 8. CALCULATE STOCK VALUE
void calculateStockValue()
{
    ifstream fin("stock.txt");

    if (!fin)
    {
        cout << "\nFile could not be opened!";
        return;
    }

    Stock s;
    double totalValue = 0;

    while (s.readFromFile(fin))
    {
        totalValue = totalValue +
                     (s.getPrice() * s.getQuantity());
    }

    fin.close();

    cout << "\nTotal Stock Value = " << totalValue;
}


// MAIN FUNCTION
int main()
{
    int choice;

    do
    {
        cout << "\n\n========== STOCK MANAGEMENT SYSTEM ==========";
        cout << "\n1. Add Product";
        cout << "\n2. Display All Products";
        cout << "\n3. Search Product";
        cout << "\n4. Update Product";
        cout << "\n5. Delete Product";
        cout << "\n6. Purchase Stock";
        cout << "\n7. Sell Stock";
        cout << "\n8. Calculate Stock Value";
        cout << "\n9. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addProduct();
            break;

        case 2:
            displayProducts();
            break;

        case 3:
            searchProduct();
            break;

        case 4:
            updateProduct();
            break;

        case 5:
            deleteProduct();
            break;

        case 6:
            purchaseStock();
            break;

        case 7:
            sellStock();
            break;

        case 8:
            calculateStockValue();
            break;

        case 9:
            cout << "\nExiting program...";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while (choice != 9);

    return 0;
}