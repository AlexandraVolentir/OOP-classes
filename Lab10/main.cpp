#include "Map.h"

int main()

{
    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    Map<int, const char*> m1;
    m1.SetValueToKey(20, "AM");
    m1.SetValueToKey(30, "PM");
    m1.SetValueToKey(40, "AbM");
    m1.print();
    const char* value;
    std::cout << m1.Get(20, value) << "\n";
    std::cout << value << "here\n";
    std::cout << m.Count() << "\n";
    m1.Delete(30);
    m1.print();
    m1[10] = "C++";
    m1[20] = "test";
    m1[30] = "Poo";
    std::cout << m.Includes(m1);

    m1.Clear();
    m1.print();
    return 0;
}