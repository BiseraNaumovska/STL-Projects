//  Asocijativni kontejneri
/*
•	set – Содржи единствен клуч за било кој тип. Обезбедува брзо пребарување и тестирање на постоење на клучеви.
•	multiset - multiset исто така содржи клуч за било кој тип, но тие не мора да бидат единствени.
•	map – контејнерот map е hash кој содржи пресликување еден-на-еден. Складира парови клуч/вредност од призволен тип.
•	 multimap – содржи пресликување еден-на-многу. Обезбедува складирање базирано на клучеви кои може да бидат и дуплирани.
Следува едноставен пример кој користи класа set. Повторно, објаснувањето на некои делови од кодот ќе следи во продолжение.
•	Постапката за креирање на множество е едноставна. Во примерот се креира множество од стрингови.
•	Додавањето на елементи е едноставно
•	За пребарување се користи функцијата find. Таа е функција членка на  set.

*/
#include <set>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main( )
{
    // Kreira prazno mnozestvo
    set <int> celi;
    // Dodava elementi vo mnozestvoto
    celi.insert(1);
    celi.insert(2);
    celi.insert(3);
    celi.insert(4);
    celi.insert(5);
    // find vrakja iterator na pronajden element.
    set <int>::iterator iter = celi.find(7);
    if (iter != celi.end()) { //ako iteratorot doshol do krajot na mnozestvoto, znachi deka ne uspeal da go najde elementot
        cout << "Ima" << endl;
    }
    else {
        cout << "Nema." << endl;
    }
    return 0;
}
