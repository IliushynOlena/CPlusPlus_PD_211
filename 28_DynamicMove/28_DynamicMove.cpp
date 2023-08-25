#include"Console.h"
#include<chrono>
enum Direction{LEFT, RIGHT, UP, DOWN};
class Hero
{
private:
    int hp;
    int h, w;
    COORD position;
    char symbol;
    string name;
    Direction dir;
    void Print(char filler)const
    {
        for (int y = 0; y < h; y++)
        {
            gotoxy(position.X, position.Y + y);
            for (int i = 0; i < w; i++)
            {
                cout << filler;
            }
            cout << endl;
        }
    }
public:
    Hero() :hp(100), h(1), w(1), position({ 0,0 }), symbol('#'), name("no name"),dir(RIGHT) {}
    Hero(string name, int h, int w, char s) :hp(100), position({ 0,0 }), 
        symbol(s), name(name), dir(RIGHT)
    {
        this->h = h >= 1 ? h : 1;
        this->w = w >= 1 ? w : 1;
    }
    void ShowInfo()
    {
        cout << "--------- Player [" << name << "] . HP : " << 
            hp << "--------------------" << endl;
    }
    void PrintHero()const
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::GREEN);
        Print(symbol);
    }
    void MarkHero()const
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::RED);
        Print(symbol);
    }
    void ClearHero()
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::BLACK);
        Print((char)219);
    }
    void SetPosition(int x, int y)
    {
        position.X = x >= 0 ? x : 0;
        position.Y = y >= 0 ? y : 0;
    }
    void Move()
    {
        bool isMoved = false;
        ClearHero();
        switch (dir)
        {
        case LEFT:isMoved = MoveLeft();break;
        case RIGHT:isMoved = MoveRight();break;
        case UP:isMoved = MoveUp(); break;
        case DOWN:isMoved = MoveDown(); break;
        }
        isMoved ? PrintHero() : MarkHero();
    }
    bool MoveRight()
    {
        if (IsValidPosition(position.X + 1, position.Y))
        {
            position.X++;
            return true;
        }
        return false;
    }
    bool MoveLeft()
    {
        if (IsValidPosition(position.X - 1, position.Y))
        {            
            position.X--; return true;
        }
        return false;
    }
    bool MoveUp()
    {
        if (IsValidPosition(position.X , position.Y - 1))
        {
            position.Y--; return true;
        }
        return false;
    }
    bool MoveDown()
    {
        if (IsValidPosition(position.X, position.Y + 1))
        {
            position.Y++; return true;
        }
        return false;
    }
    void ChangeDirection(Direction dir)
    {
        this->dir = dir;
    }
    bool IsValidPosition(int x, int y)const
    {
        return x >= 0 && y >= 0;
    }
};
int main()
{
    hidecursor();
    Hero hero("Petro", 4, 3, (char)219);
   /* hero.ShowInfo();
    hero.PrintHero();
    hero.Move(10, 10);
    hero.PrintHero();*/


    time_t interval = 500;
    time_t start = clock();

    while (true)
    {
        if (clock() >= start + 500)
        {
            hero.Move();
            start = clock();
        }
        if (_kbhit())
        {
            int key = _getch();
            //cout << key << endl;
            if (key == 224)
            {
                key = _getch();
                switch (key)
                {
                case 77: hero.ChangeDirection(RIGHT); break;
                case 80: hero.ChangeDirection(DOWN); break;
                case 72: hero.ChangeDirection(UP); break;
                case 75: hero.ChangeDirection(LEFT); break;
                }
            }
        }
    }     
}

