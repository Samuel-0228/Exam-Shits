#include <iostream>
using namespace std;

void printTheatre(int **rows, int rowCount)
{
    int totalSeats = 0;

    cout << "\nCurrent theatre layout:\n";
    for (int i = 0; i < rowCount; ++i)
    {
        int seatsInRow = rows[i][0];
        cout << "Row " << i + 1 << ": " << seatsInRow << " seats\n";
        totalSeats += seatsInRow;
    }
    cout << "Total seats in theatre: " << totalSeats << "\n\n";
}

int main()
{
    int rowCount;

    cout << "Enter number of rows: ";
    cin >> rowCount;

    int **rows = new int *[rowCount];

    for (int i = 0; i < rowCount; ++i)
    {
        int seats;
        cout << "Enter number of seats in row " << i + 1 << ": ";
        cin >> seats;

        rows[i] = new int[seats + 1];
        rows[i][0] = seats;
    }

    bool running = true;
    while (running)
    {
        printTheatre(rows, rowCount);

        cout << "Choose an action:\n";
        cout << "1 - Change number of seats in a row\n";
        cout << "2 - Remove a row\n";
        cout << "3 - Add a new row\n";
        cout << "4 - Quit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            int r;
            cout << "Enter row index to modify (0 to " << rowCount - 1 << "): ";
            cin >> r;

            if (r < 0 || r >= rowCount)
            {
                cout << "Invalid row index.\n";
                break;
            }

            int newSeats;
            cout << "Enter new number of seats for row " << r + 1 << ": ";
            cin >> newSeats;

            delete[] rows[r];

            rows[r] = new int[newSeats + 1];
            rows[r][0] = newSeats;
            cout << "Row " << r + 1 << " updated.\n";
            break;
        }

        case 2:
        {

            if (rowCount == 0)
            {
                cout << "No rows to remove.\n";
                break;
            }

            int r;
            cout << "Enter row index to remove (0 to " << rowCount - 1 << "): ";
            cin >> r;

            if (r < 0 || r >= rowCount)
            {
                cout << "Invalid row index.\n";
                break;
            }

            delete[] rows[r];

            int **newRows = new int *[rowCount - 1];

            int newIndex = 0;
            for (int i = 0; i < rowCount; ++i)
            {
                if (i == r)
                    continue;
                newRows[newIndex++] = rows[i];
            }

            delete[] rows;
            rows = newRows;
            rowCount--;

            cout << "Row " << r + 1 << " removed.\n";
            break;
        }

        case 3:
        {

            int newSeats;
            cout << "Enter number of seats for new row: ";
            cin >> newSeats;

            // Create new array of row pointers with one extra row
            int **newRows = new int *[rowCount + 1];

            // Copy existing row pointers
            for (int i = 0; i < rowCount; ++i)
            {
                newRows[i] = rows[i];
            }

            // Allocate new row and set its length
            newRows[rowCount] = new int[newSeats + 1];
            newRows[rowCount][0] = newSeats;

            // Delete old pointer array and replace
            delete[] rows;
            rows = newRows;
            rowCount++;

            cout << "New row added at index " << rowCount - 1 << ".\n";
            break;
        }

        case 4:
            // Quit program
            running = false;
            break;

        default:
            cout << "Invalid choice.\n";
        }
    }

    // Clean up all dynamically allocated memory before exiting
    for (int i = 0; i < rowCount; ++i)
    {
        delete[] rows[i]; // delete each row array
    }
    delete[] rows; // delete array of row pointers

    cout << "Program ended. Memory cleaned up.\n";
    return 0;
}
