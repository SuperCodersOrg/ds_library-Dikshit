#include <iostream>
#include "Linked_List.h"


int main()
{
    LinkedList<int> list;

    std::cout << " insertFront() \n";
    list.insertFront(20);
    list.insertFront(10);

    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";
    std::cout << "\n\n";


    std::cout << " insertBack() \n";
    list.insertBack(30);
    list.insertBack(40);


    
    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";
    std::cout << "\n\n";


    std::cout << " insert(index, value) \n";

    list.insert(2, 25);

    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";

    std::cout << "\n\n";


    std::cout << " insert at beginning \n";

    list.insert(0, 5);

    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";

    std::cout << "\n\n";


    std::cout << " insert at end \n";

    list.insert(list.size(), 50);

    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";

    std::cout << "\n\n";


    std::cout << " Invalid Index \n";

    try
    {
        list.insert(100, 99);
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}