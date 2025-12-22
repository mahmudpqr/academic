#include <iostream>
using namespace std;

void time(int s) {
    int m = s / 60;
    int h = m / 60;
    
    s = s - m * 60;
    m = m - h * 60;
    
    cout << h << " " << m << " " << s << "\n";
}

int main() {
    time(86836);
    return 0;
}