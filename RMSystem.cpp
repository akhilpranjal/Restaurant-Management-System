#include <iostream>
#include <vector>
#include <string>
using namespace std;


class MenuItem
{
public:
    string name;
    double price;

    MenuItem(string itemName, double itemPrice)
    {
        name=itemName;
        price=itemPrice;
    }

    void displayItem()
    {
        cout << name << " - Rs." << price << endl;
    }
};


class OrderItem : public MenuItem
{
public:
    int quantity;

    OrderItem(string itemName, double itemPrice, int itemQuantity) : MenuItem(itemName, itemPrice)
    {
        quantity = itemQuantity;
    }

    double calculatePrice()
    {
        return price * quantity;
    }

    void displayOrderItem()
    {
        cout << name << " x" << quantity << " - Rs." << calculatePrice() << endl;
    }
};


class Restaurant
{
private:
    vector<MenuItem> menu;
    vector<OrderItem> orders;

public:
    // Here we are adding menu items.
    void addMenuItem(string name, double price)
    {
        menu.push_back(MenuItem(name, price));
    }

    // Displaying the menu.
    void displayMenu()
    {
        cout << "Menu:\n";
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". ";
            menu[i].displayItem();
        }
    }

    // Placing an order.
    void placeOrder(int menuIndex, int quantity)
    {
        if (menuIndex < 1 || menuIndex > menu.size())
        {
            cout << "Invalid menu item selection.\n";
            return;
        }

        MenuItem& selectedItem = menu[menuIndex - 1];
        orders.push_back(OrderItem(selectedItem.name, selectedItem.price, quantity));
        cout << "Order placed: " << selectedItem.name << " x" << quantity << endl;
    }

    // Displaying all the orders.
    void displayOrders()
    {
        cout << "\nOrders:\n";
        double total = 0.0;
        for (auto& order : orders)
        {
            order.displayOrderItem();
            total += order.calculatePrice();
        }
        cout << "Total Amount: Rs." << total << endl;
    }
};

int main() {
    Restaurant restaurant;

    // Adding menu items.
    restaurant.addMenuItem("Chole-Bhature", 200);
    restaurant.addMenuItem("Dahi-Jalebi", 100);
    restaurant.addMenuItem("Idli-Sambhar", 150);

    int choice, quantity;

    // Displaying menu and taking orders.
    do {
        cout << "\nWelcome to our Restaurant!\n";
        restaurant.displayMenu();
        cout << "Enter the menu item number to order (0 to finish): ";
        cin >> choice;

        if (choice == 0) break;

        cout << "Enter quantity: ";
        cin >> quantity;

        restaurant.placeOrder(choice, quantity);
    } while (choice != 0);

    // Displaying all orders.
    restaurant.displayOrders();

    return 0;
}
