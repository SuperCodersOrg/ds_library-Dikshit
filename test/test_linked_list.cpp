#include <iostream>
#include "Linked_List.h"

int main()
{
    LinkedList<int> list;

    // Create list: 10 20 30 40 50
    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);
    list.insertBack(40);
    list.insertBack(50);

    std::cout << "Initial List: ";
    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";
    std::cout << "\n\n";


    // deleteFront
    std::cout << " deleteFront() \n";
    list.deleteFront();

    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";
    std::cout << "\n\n";


    // deleteBack
    std::cout << " deleteBack() \n";
    list.deleteBack();

    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";
    std::cout << "\n\n";


    // remove middle
    std::cout << " remove(1) \n";
    list.remove(1);

    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";
    std::cout << "\n\n";


    // remove first
    std::cout << " remove(0) \n";
    list.remove(0);

    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";
    std::cout << "\n\n";


    // remove last remaining element
    std::cout << " remove(last) \n";
    list.remove(0);

    std::cout << "Size : " << list.size() << '\n';
    std::cout << "Empty: " << std::boolalpha << list.empty() << "\n\n";


    // delete from empty list
    std::cout << " deleteFront() on Empty List \n";
    try
    {
        list.deleteFront();
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\n";


    // invalid remove
    std::cout << " remove() Invalid Index \n";
    try
    {
        list.remove(5);
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}