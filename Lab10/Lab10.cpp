#include <iostream>
#include <string>

using namespace std;


class List 
{
public:
    List();
    ~List();

    void push_back(int day, int month, int year, int hour, int minutes, int hour1, int minutes1, string airport, bool breakfast);
    int GetSize() { return Size; }
    void Get_data(const int number);
    int Get_Day(const int number);
    int Get_Month(const int number);
    int Get_Year(const int number);
    int Get_Hour(const int number);
    int Get_Minutes(const int number);
    int Get_Hour1(const int number);
    int Get_Minutes1(const int number);
    string Get_Airport(const int number);
    bool Get_Breakfast(const int number);
    void pop_front();
    void clear();
    

private:

    class Node
    {
    public:
        Node *pNext;

        int day, month, year; // Дата вылета
        int hour, minutes; // Время вылета
        int hour1, minutes1; // Время полета
        string airport; // название аэропорта
        bool breakfast; // наличие завтрака, если полет больше 4 часов
        Node(int day=0, int month = 0, int year = 0, int hour = 0, int minutes = 0, 
            int hour1 = 0, int minutes1 = 0, string airport = " ", bool breakfast = 0, Node* pNext = nullptr)
        {
            this->hour = hour;
            this->minutes = minutes;
            this->hour1 = hour1;
            this->minutes1 = minutes1;
            this->day = day;
            this->month = month;
            this->year = year;
            this->airport = airport;
            this->breakfast = breakfast;
            this->pNext = pNext;
        }
    };

    int Size;
    Node *head;

};

List::List()
{
    Size = 0;
    head = nullptr;
};

List::~List()
{
    clear();
}
void List::push_back(int day, int month, int year, int hour, int minutes, int hour1, int minutes1, string airport, bool breakfast)
{
    if (head == nullptr)
    {
        head = new Node(day, month,  year,  hour,  minutes,  hour1,  minutes1,  airport,  breakfast);
    }
    else 
    {
        Node* current = this->head;

        while (current->pNext != nullptr) 
        {
            current = current->pNext;
        }
        current->pNext = new Node(day, month, year, hour, minutes, hour1, minutes1, airport, breakfast);
    }
    Size++;
}
//int& List::operator[](const int index)
//{
//    int counter = 0;
//    Node* current = this->head;
//    while (current != nullptr)
//    {
//        if (counter == index)
//        {
//            return current->day;
//            return current->month;
//            return current->year;
//            return current->hour;
//            return current->minutes;
//            return current->hour1;
//            return current->minutes1;
//        }
//        current = current->pNext;
//        counter++;
//    }
//};

int List::Get_Day(const int number)
{
    int i = 0;
    Node* current = head;
    while (current != nullptr)
    {
        if (i == number)
        {
            return current->day;
        }
        current = current->pNext;
        i++;
    }
}
int List::Get_Month(const int number)
{
    int i = 0;
    Node* current = head;
    while (current != nullptr)
    {
        if (i == number)
        {
            return current->month;
        }
        current = current->pNext;
        i++;
    }
}
int List::Get_Year(const int number)
{
    int i = 0;
    Node* current = head;
    while (current != nullptr)
    {
        if (i == number)
        {
            return current->year;
        }
        current = current->pNext;
        i++;
    }
}

int List::Get_Hour(const int number)
{
    int i = 0;
    Node* current = head;
    while (current != nullptr)
    {
        if (i == number)
        {
            return current->hour;
        }
        current = current->pNext;
        i++;
    }
}
int List::Get_Minutes(const int number)
{
    int i = 0;
    Node* current = head;
    while (current != nullptr)
    {
        if (i == number)
        {
            return current->minutes;
        }
        current = current->pNext;
        i++;
    }
}
int List::Get_Hour1(const int number)
{
    int i = 0;
    Node* current = head;
    while (current != nullptr)
    {
        if (i == number)
        {
            return current->hour1;
        }
        current = current->pNext;
        i++;
    }
}
int List::Get_Minutes1(const int number)
{
    int i = 0;
    Node* current = head;
    while (current != nullptr)
    {
        if (i == number)
        {
            return current->minutes1;
        }
        current = current->pNext;
        i++;
    }
}
string List::Get_Airport(const int number)
{
    int i = 0;
    Node* current = head;
    while (current != nullptr)
    {
        if (i == number)
        {
            return current->airport;
        }
        current = current->pNext;
        i++;
    }
}
bool List::Get_Breakfast(const int number)
{
    int i = 0;
    Node* current = head;
    while (current != nullptr)
    {
        if (i == number)
        {
            return current->breakfast;
        }
        current = current->pNext;
        i++;
    }
}
void List::Get_data(const int number)
{
    int i = 0;
    Node* current = head;
    while (current != nullptr)
    {
        if (i == number)
        {
            cout << current->day << "          " << current->month << "          " << current->year << "          " 
                << current->hour << "          " << current->minutes << "          "  << current->hour1 << "          " << current->minutes1 << "          " <<
                current->airport << "          " << current->breakfast << endl;
        }
        current = current->pNext;
        i++;
    }
}

void List::pop_front() // удаление с начала
{
    Node *temp = head;
    head = head->pNext;
    
    delete temp;
    Size--;
}

void List::clear()
{
    while (Size)
    {
        pop_front();
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    List list;
    list.push_back(12, 02, 2001, 12, 56, 04, 20, "Красноярск", 1);
    list.push_back(13, 02, 2001, 12, 56, 04, 20, "Москва", 1);
    list.push_back(14, 02, 2001, 12, 56, 04, 20, "Абакан", 1);

    //cout << list.GetSize();
    /*cout << list[2];
    cout << list[3];*/

    for (int i=0;i<list.GetSize();i++) 
    {
        cout << list.Get_Airport(i) << endl;
    }

    

    return 0;
}
