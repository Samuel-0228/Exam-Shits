#include <iostream>
using namespace std;

class Account
{
private:
    int num;
    double balance;

public:
    // default constructor
    Account()
    {
        num = 0;
        balance = 0.0;
    }

    // constructor with parameters
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
        cout << "Account No.: " << num;
        cout << "\nBalance: " << balance;
    }

    void wealth();
};

void Account::wealth()
{
    if (balance > 1000000)
        cout << "\nyou're rich";
    else
        cout << "\nYOU'RE LUCKY TO BE HEALTHY.";
}

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
    Account saving(12345, 1500); // initial values (will be overwritten)

    int n;
    cout << "Enter acc no: ";
    cin >> n;

    // update account with user input and fixed balance 2000
    saving.setdata(n, 2000);

    // now both wealth() and display() use the updated data
    saving.wealth();
    saving.display();

    Rectangle r; // create object

    double w, l;
    cout << "\n\nEnter width: ";
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
