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
    float price;
    int quantity;
    string supplierName;

public:

    void addProduct()
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

        ofstream fout("stock.txt", ios::app);

        fout << productID << " "
             << productName << " "
             << category << " "
             << price << " "
             << quantity << " "
             << supplierName << endl;

        fout.close();

        cout << "\nProduct added successfully.";
    }

    void displayProduct()
    {
        cout << "\nProduct ID    : " << productID;
        cout << "\nProduct Name  : " << productName;
        cout << "\nCategory      : " << category;
        cout << "\nPrice         : " << price;
        cout << "\nQuantity      : " << quantity;
        cout << "\nSupplier Name : " << supplierName;
        cout << "\n-----------------------------";
    }

    void displayAll()
    {
        ifstream fin("stock.txt");

        if(!fin)
        {
            cout << "\nNo stock file found.";
            return;
        }

        while(fin >> productID
                  >> productName
                  >> category
                  >> price
                  >> quantity
                  >> supplierName)
        {
            displayProduct();
        }

        fin.close();
    }

    void searchProduct()
    {
        int id;
        bool found = false;

        cout << "\nEnter Product ID to search: ";
        cin >> id;

        ifstream fin("stock.txt");

        while(fin >> productID
                  >> productName
                  >> category
                  >> price
                  >> quantity
                  >> supplierName)
        {
            if(productID == id)
            {
                cout << "\nProduct Found";
                displayProduct();
                found = true;
                break;
            }
        }

        fin.close();

        if(!found)
        {
            cout << "\nProduct not found.";
        }
    }

    void updateProduct()
    {
        int id;
        bool found = false;

        cout << "\nEnter Product ID to update: ";
        cin >> id;

        ifstream fin("stock.txt");
        ofstream fout("temp.txt");

        while(fin >> productID
                  >> productName
                  >> category
                  >> price
                  >> quantity
                  >> supplierName)
        {
            if(productID == id)
            {
                found = true;

                cout << "\nEnter New Product Name: ";
                cin >> productName;

                cout << "Enter New Category: ";
                cin >> category;

                cout << "Enter New Price: ";
                cin >> price;

                cout << "Enter New Quantity: ";
                cin >> quantity;

                cout << "Enter New Supplier Name: ";
                cin >> supplierName;
            }

            fout << productID << " "
                 << productName << " "
                 << category << " "
                 << price << " "
                 << quantity << " "
                 << supplierName << endl;
        }

        fin.close();
        fout.close();

        remove("stock.txt");
        rename("temp.txt", "stock.txt");

        if(found)
            cout << "\nProduct updated successfully.";
        else
            cout << "\nProduct not found.";
    }

    void deleteProduct()
    {
        int id;
        bool found = false;

        cout << "\nEnter Product ID to delete: ";
        cin >> id;

        ifstream fin("stock.txt");
        ofstream fout("temp.txt");

        while(fin >> productID
                  >> productName
                  >> category
                  >> price
                  >> quantity
                  >> supplierName)
        {
            if(productID == id)
            {
                found = true;
                continue;
            }

            fout << productID << " "
                 << productName << " "
                 << category << " "
                 << price << " "
                 << quantity << " "
                 << supplierName << endl;
        }

        fin.close();
        fout.close();

        remove("stock.txt");
        rename("temp.txt", "stock.txt");

        if(found)
            cout << "\nProduct deleted successfully.";
        else
            cout << "\nProduct not found.";
    }

    void purchaseStock()
    {
        int id, amount;
        bool found = false;

        cout << "\nEnter Product ID: ";
        cin >> id;

        cout << "Enter quantity to purchase: ";
        cin >> amount;

        ifstream fin("stock.txt");
        ofstream fout("temp.txt");

        while(fin >> productID
                  >> productName
                  >> category
                  >> price
                  >> quantity
                  >> supplierName)
        {
            if(productID == id)
            {
                quantity += amount;
                found = true;
            }

            fout << productID << " "
                 << productName << " "
                 << category << " "
                 << price << " "
                 << quantity << " "
                 << supplierName << endl;
        }

        fin.close();
        fout.close();

        remove("stock.txt");
        rename("temp.txt", "stock.txt");

        if(found)
            cout << "\nStock purchased successfully.";
        else
            cout << "\nProduct not found.";
    }

    void sellStock()
    {
        int id, amount;
        bool found = false;

        cout << "\nEnter Product ID: ";
        cin >> id;

        cout << "Enter quantity to sell: ";
        cin >> amount;

        ifstream fin("stock.txt");
        ofstream fout("temp.txt");

        while(fin >> productID
                  >> productName
                  >> category
                  >> price
                  >> quantity
                  >> supplierName)
        {
            if(productID == id)
            {
                found = true;

                if(amount <= quantity)
                {
                    quantity -= amount;
                    cout << "\nStock sold successfully.";
                }
                else
                {
                    cout << "\nInsufficient stock.";
                }
            }

            fout << productID << " "
                 << productName << " "
                 << category << " "
                 << price << " "
                 << quantity << " "
                 << supplierName << endl;
        }

        fin.close();
        fout.close();

        remove("stock.txt");
        rename("temp.txt", "stock.txt");

        if(!found)
            cout << "\nProduct not found.";
    }

    void calculateStockValue()
    {
        float total = 0;

        ifstream fin("stock.txt");

        while(fin >> productID
                  >> productName
                  >> category
                  >> price
                  >> quantity
                  >> supplierName)
        {
            total = total + (price * quantity);
        }

        fin.close();

        cout << "\nTotal Stock Value = " << total;
    }
};

int main()
{
    Stock s;
    int choice;

    do
    {
        cout << "\n\n===== STOCK MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Product";
        cout << "\n2. Display All Products";
        cout << "\n3. Search Product";
        cout << "\n4. Update Product";
        cout << "\n5. Delete Product";
        cout << "\n6. Purchase Stock";
        cout << "\n7. Sell Stock";
        cout << "\n8. Calculate Stock Value";
        cout << "\n9. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                s.addProduct();
                break;

            case 2:
                s.displayAll();
                break;

            case 3:
                s.searchProduct();
                break;

            case 4:
                s.updateProduct();
                break;

            case 5:
                s.deleteProduct();
                break;

            case 6:
                s.purchaseStock();
                break;

            case 7:
                s.sellStock();
                break;

            case 8:
                s.calculateStockValue();
                break;

            case 9:
                cout << "\nProgram Exited.";
                break;

            default:
                cout << "\nInvalid choice.";
        }

    } while(choice != 9);

    return 0;
}