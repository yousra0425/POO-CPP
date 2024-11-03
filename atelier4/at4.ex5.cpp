#include <iostream>
using namespace std;
class Test {
private:
    static int count;

public:
    void call() {
        ++count;
        cout << "La fonction call() a été appelée " << count << " fois." << endl;
    }

    static int getCount() {
        return count;
    }
};

int Test::count = 0;

int main() {
    Test t1, t2;

    t1.call(); 
    t2.call(); 
    t1.call(); 

   cout << "La fonction call() a été appelée un total de " << Test::getCount() << " fois." << endl;

    return 0;
}
