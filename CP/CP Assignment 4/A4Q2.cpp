// Name    : Waseem Hassan Shahid
// Roll No : i12-0097
// Section : F

#include <iostream>

using namespace std;

class UniquelyIdentified {
    public:
        UniquelyIdentified();
        int GetUniqueID();
    private:
        int ID;
        static int Count;
};

UniquelyIdentified::UniquelyIdentified() {
    ID = Count;
    Count++;
}

int UniquelyIdentified::GetUniqueID() {
    return ID;
}

int UniquelyIdentified::Count = 1;

int main() {
    UniquelyIdentified u1, u2, u3;
    cout << u1.GetUniqueID() << endl;
    cout << u2.GetUniqueID() << endl;
    cout << u3.GetUniqueID() << endl;
    return 0;
}
