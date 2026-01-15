#include <iostream>
using namespace std;
class Account // i can use struct and remove public:
// Class data and function members are private by default
// we should not make data members private  cuz it shields the very purpose of OOP wc is data hiding.
// so we will add another public member function to access the provate data member
{
private:
    int num;
    double balance;

public:
    Account()
    {
        num = 0;
        balance = 0.0;
    }
    Account(int n, double b)
    {
        num = n;
        balance = b;
    }
    void setdata(int n, double b)
    {
        num = n;
        balance = b;
    }

    void display()
    {
        cout << "Account N0.: " << num;
        cout << "\nBalance: " << balance;
    }
    void wealth();
};

void Account::wealth()
{
    if (balance > 1000000)
        cout << "\nyou're rich";
    else
        cout << "\nYOUR LUCKY TO BE HEALTHY.";
};

class Rectangle
{
private:
    double width;
    double length;

public:
    // mutators (setters)
    void setWidth(double w)
    {
        width = w;
    }

    void setLength(double l)
    {
        length = l;
    }

    // accessors (getters)
    double getWidth() const
    {
        return width;
    }

    double getLength() const
    {
        return length;
    }

    double getArea() const
    {
        return width * length; // area = width × length
    }
};

int main()
{
    Account saving(12345, 1500);
    saving.wealth();
    saving.display(); // accessing private data members using public member function
    int n;
    cout << "Enter acc no: ";
    cin >> n;
    saving.setdata(n, 2000);
    saving.wealth();
    saving.display(); // updating data members using member function

    Rectangle r; // create object

    double w, l;
    cout << "\nEnter width: ";
    cin >> w;
    cout << "Enter length: ";
    cin >> l;

    // set the data in the object
    r.setWidth(w);
    r.setLength(l);

    // use accessor functions
    cout << "\nWidth  = " << r.getWidth();
    cout << "\nLength = " << r.getLength();
    cout << "\nArea   = " << r.getArea() << endl;

    return 0;
}