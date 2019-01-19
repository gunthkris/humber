#include <iostream>
#include <windows.h> // To use system()
#include <conio.h> // To use getch()

// Decimal values (from the ASCII table) constant for key strokes
// Arrow keys actually produces extended ASCII codes followed by actual arrow key codes
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32

using namespace std;

// Clear screen function
void clearScreen()
{
    system("CLS");
}

class Robot
{
public:
    int xPos;
    int yPos;
    int speed;
    bool claw;

    // Constructor for default values
    Robot (int spd) // Asks for speed value to start with
    {
        xPos = 20; // X position
        yPos = 10; // Y position
        speed = spd; // Speed
        claw = false; // Claws open or closed
    }

    // Displays general information
    void printInfo()
    {
        cout << "\nSpeed: " << speed << "   Claw: " << (claw ? "Closed" : "Open\n");
    }

    // Function to move to a position based on xPos and yPos values
    void moving()
    {
        for (int i = 0; i <= yPos; i++) // Rows
        {
            for (int j = 0; j <= xPos; j++) // Columns
                cout << " "; // Blank spaces to fill
            cout << (i == yPos ? (claw ? "||" : "\\/") : "\n"); // prints claws based on boolean values
        }
    }

    void moveUp()
    {
        clearScreen();
        yPos -= speed; // Decreases rows by speed value
        moving();
    }

    void moveDown()
    {
        clearScreen();
        yPos += speed; // Increases rows by speed value
        moving();
    }

    void moveLeft()
    {
        clearScreen();
        xPos -= speed; // Decreases column by speed value
        moving();
    }

    void moveRight()
    {
        clearScreen();
        xPos += speed; // Increases column by speed value
        moving();
    }

    void toggleClaw()
    {
        claw = (claw == false ? true : false); // Toggler
        clearScreen();
        moving();
    }

    void speedChange(int spd)
    {
        speed = spd; // Change the speed to user input
        printInfo();
    }
};


int main()
{
    cout << "Welcome :: Arrow keys to move :: 1-9 keys to change speed :: q to exit :: Any other keys for information";
    Robot bot(1); // bot was born @ speed 1
    bot.printInfo(); // Display stats to start

    int c = 0, // used for the switch key input
        junk = 0;   // Junk absorber (mainly to absorb the first input from the arrow keys)
                    // Use W, A, S, D instead to simplify the controls, and remove junk variable
                    // I've also discovered that there is another way to get key presses without using getch
                    // called "events", perhaps we can cover that for one of our programming sessions?
    while(c != 113) // q to quit
    {
        c = 0; // Reset c
        junk = getch(); // Absorbs a junk character with arrow key input and filters
        // cout << junk << " "; // Debugging purposes
        if (junk >= 32 && junk <= 127) // Only printable characters
            c = junk; // Accepts printable character to go through (including space)
        else
        {
            c = getch(); // Get the arrow key value after it has been filtered by junk
            //cout << c; // Debugging purposes
        }

        // This should be self-explanatory
        switch(c)
        {
        case KEY_UP:
            bot.moveUp();
            break;
        case KEY_DOWN:
            bot.moveDown();
            break;
        case KEY_LEFT:
            bot.moveLeft();
            break;
        case KEY_RIGHT:
            bot.moveRight();
            break;
        case KEY_SPACE: // Space bar to toggle claw - open/close
            bot.toggleClaw();
            break;
        case 49: // Key 1
            bot.speedChange(1);
            break;
        case 50: // Key 2
            bot.speedChange(2);
            break;
        case 51: // Key 3
            bot.speedChange(3);
            break;
        case 52: // Key 4
            bot.speedChange(4);
            break;
        case 53: // Key 5
            bot.speedChange(5);
            break;
        case 54: // Key 6
            bot.speedChange(6);
            break;
        case 55: // Key 7
            bot.speedChange(7);
            break;
        case 56: // Key 8
            bot.speedChange(8);
            break;
        case 57: // Key 9
            bot.speedChange(9);
            break;
        case 113: // Do nothing on exit
            break;
        default: // Any other keys will display the Robot info
            bot.printInfo();
            break;
        }
    }

    cout << "\nIEEE Club @ Humber Programming Session";
    Sleep(3000); // 3 second delay for no reason
    return 0;
}
