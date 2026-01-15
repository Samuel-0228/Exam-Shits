#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    string interest, playagain;
    int guess;
    srand(time(0));
    cout << "I have numers from 1 to 1000, Wanna guess?(enter y to continue): ";
    cin >> interest;

a:
    int tries = 0;
    int secret = rand() % 1000 + 1;

    if (interest == "y" || interest == "Y")
    {
        do
        {

            cout << "Enter your guess: ";
            cin >> guess;
            tries++;
            if (guess > secret)
                cout << "Too large" << endl;
            else if (guess < secret)
                cout << "Too small" << endl;
            else
            {
                if (tries < 10)
                    cout << "You're a legend" << endl;
                else if (tries == 10)
                    cout << "You atleast got it." << endl;
                else
                    cout << "ahhh finally ypu got it, try smart next time!" << endl;
                cout << "NUmber of trial= " << tries << endl;
            }

        } while (secret != guess);
    }
    else
        cout << "you're afraid.";

    cout << "Do you wanna play again? ";
    cin >> playagain;

    if (playagain == "y" || playagain == "Y")
        goto a;
    else
        cout << "Ty atleast you tried!";
    return 0;
}