#include <iostream>
using namespace std;

class Menu {
    string food_names[6];
    float prices[6];
public:
    Menu() {}
    Menu(string names[], float prices[]) {
        for (int i = 0; i < 6; i++) {
            food_names[i] = names[i];
            prices[i] = prices[i];
        }
    }
    float get_price(int n) {
        return prices[n - 1];
    }
    void set_names(string names[]) {
        for (int i = 0; i < 6; i++) {
            food_names[i] = names[i];
        }
    }
    void set_prices(float prices[]) {
        for (int i = 0; i < 6; i++) {
            this-> prices[i] = prices[i];
        }
    }
    void display_menu() {
        cout << "--> Menu:" << endl;
        for (int i = 0; i < 6; i++) {
            cout << "     " << i + 1 << ") Dish Name: " << food_names[i] << "\n        Price: " << prices[i] << endl;
        }
    }
};

class Payments {
    float total;
public:
    Payments() { total = 0; }
    void update_total(float p) {
        total += p;
    }
    float get_total() { return total; }
};

class Orders {
    Menu menu;
    Payments payment;
public:
    Orders() {}
    void place_order(Menu m) {
        menu = m;
        cout << "Menu: " << endl;
        menu.display_menu();
        string choice;
        cout << "\nDo you want to order anything? ";
        cin >> choice;
        if (choice == "yes") {
            int c;
            int qty;
            cout << "\nEnter the number of dishes you want to order: ";
            cin >> qty;
            for (int i = 0; i < qty; i++) {
                cout << "\nEnter the number of the dish in the menu: ";
                cin >> c;
                if (c >= 1 && c <= 6) {
                    payment.update_total(menu.get_price(c));
                } else {
                    cout << "Enter a valid number of dish." << endl;
                    i--;
                    continue;
                }
            }
        }
    }
    void bill() {
        cout << "Total Bill Amount = " << payment.get_total() << endl;
    }
};

class RestaurantSystem {
    Menu menu;
    Orders orders;
public:
    RestaurantSystem() {}
    void add_items(string names[]) {
        menu.set_names(names);
    }
    void set_prices(float prices[]) {
        menu.set_prices(prices);
    }
    void display_menu() {
        menu.display_menu();
    }
    void take_order() {
        orders.place_order(menu);
    }
    void total() {
        orders.bill();
    }
};

int main() {
    cout << "Name: Your Name Here\nRoll no: Your Roll Number Here" << endl;

    string menu_items[6] = { "Shawarma ", "Friend Chicken", "steak", "Ice cream", "Soda", "Water"};
    float prices[6] = { 150, 300, 1200, 150, 40,50 };

    RestaurantSystem system;

    system.set_prices(prices);
    system.add_items(menu_items);
    cout << endl;
    system.display_menu();
    cout << endl;
    system.take_order();
    cout << endl;
    system.total();

    return 0;
}
