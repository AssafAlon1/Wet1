
#include "library1.h"
#include "SinglePlayer.h"
#include "PlayersManager.h"
#include "assert.h"

// Check AVL Tree is valid with ints
void PreProductionTest1()
{
    std::cout << "Running PreProductionTest1... ";
    
    // AVL Tree test with ints

    std:: cout << "[OK]";
}

// Check AVL Tree is valid with ints
void PreProductionTest2()
{
    std::cout << "Running PreProductionTest1... ";
    
    // AVL Tree test with ints

    std:: cout << "[OK]";
}

// Check AVL Tree is valid with ints
void PreProductionTest3()
{
    std::cout << "Running PreProductionTest1... ";
    
    // AVL Tree test with ints

    std:: cout << "[OK]";
}

// Check SinglePlayer order (by id)
void PreProductionTest4()
{
    std::cout << "Running PreProductionTest4... ";
    
    SinglePlayer sp1 = SinglePlayer(1, 0, false, nullptr);
    SinglePlayer sp2 = SinglePlayer(2, 0, false, nullptr);
    SinglePlayer sp3 = SinglePlayer(3, 0, false, nullptr);
    SinglePlayer sp4 = SinglePlayer(4, 0, false, nullptr);

    assert(sp2 > sp1);
    assert(sp3 > sp1);
    assert(sp4 > sp1);
    assert(sp3 > sp2);
    assert(sp4 > sp2);
    assert(sp4 > sp3);

    assert(!(sp1 > sp2));
    assert(!(sp1 > sp3));
    assert(!(sp1 > sp4));
    assert(!(sp2 > sp3));
    assert(!(sp2 > sp4));
    assert(!(sp3 > sp4));

    std:: cout << "[OK]";
}


// Check SinglePlayer order (by lvl - all same id)
void PreProductionTest5()
{
    std::cout << "Running PreProductionTest5... ";
    
    SinglePlayer sp1 = SinglePlayer(1, 0, true, nullptr);
    SinglePlayer sp2 = SinglePlayer(2, 0, true, nullptr);
    SinglePlayer sp3 = SinglePlayer(3, 0, true, nullptr);
    SinglePlayer sp4 = SinglePlayer(4, 0, true, nullptr);

    assert(sp2 > sp1);
    assert(sp3 > sp1);
    assert(sp4 > sp1);
    assert(sp3 > sp2);
    assert(sp4 > sp2);
    assert(sp4 > sp3);

    assert(!(sp1 > sp2));
    assert(!(sp1 > sp3));
    assert(!(sp1 > sp4));
    assert(!(sp2 > sp3));
    assert(!(sp2 > sp4));
    assert(!(sp3 > sp4));

    std:: cout << "[OK]";
}


// Check SinglePlayer order (by lvl)
void PreProductionTest6()
{
    std::cout << "Running PreProductionTest6... ";
    
    SinglePlayer sp1 = SinglePlayer(1, 6, true, nullptr);
    SinglePlayer sp2 = SinglePlayer(2, 2, true, nullptr);
    SinglePlayer sp3 = SinglePlayer(3, 3, true, nullptr);
    SinglePlayer sp4 = SinglePlayer(4, 2, true, nullptr);

    assert(sp1 > sp2);
    assert(sp1 > sp3);
    assert(sp1 > sp4);
    assert(sp3 > sp2);
    assert(sp2 > sp4);
    assert(sp3 > sp4);

    assert(!(sp2 > sp1));
    assert(!(sp3 > sp1));
    assert(!(sp4 > sp1));
    assert(!(sp3 > sp2));
    assert(!(sp4 > sp2));
    assert(!(sp4 > sp3));

    std:: cout << "[OK]";
}

// void BasicTest1()
// {
//     void* DS = Init();
// }


int main ()
{
    PreProductionTest1();
    PreProductionTest2();
    PreProductionTest3();
    PreProductionTest4();
    PreProductionTest5();
    PreProductionTest6();
}