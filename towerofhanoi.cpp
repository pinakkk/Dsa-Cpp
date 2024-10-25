#include <iostream>
using namespace std;

int moveCount = 0;
void moveDisk(int disks, int from, int to, int aux){
    if(disks == 1){
        moveCount++;
        return;
    }

    // from, aux, to
    // aux, to, from

    moveDisk(disks - 1, from, aux, to);
    moveCount++;
    moveDisk(disks -1, aux, to, from);

}
int main(){
    int disks;
    cin >> disks;
    moveDisk(disks, 1, 2, 3);

    cout << moveCount;
    return 0;
}