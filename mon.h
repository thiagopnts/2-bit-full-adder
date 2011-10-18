#include "systemc.h"
#include <iomanip>

using namespace std;

SC_MODULE(mon) {
    sc_in<bool> A1,A2,B1,B2,Cin, Sum1, Sum2, Cout, Clk;

    void monitor() {
        cout << setw(4) << "A1";
        cout << setw(3) << "A2";
        cout << setw(3) << "B1";
        cout << setw(3) << "B2";
        cout << setw(5) << "Cout";
        cout << setw(3) << "S1";
        cout << setw(3) << "S2";
        while(true) {
            cout << setw(3) << A1.read();
            cout << setw(3) << A2.read();
            cout << setw(3) << B1.read();
            cout << setw(3) << B2.read();
            cout << setw(5) << Cout.read();
            cout << setw(3) << Sum1.read(); 
            cout << setw(4) << Sum2.read() << endl;
            wait();
        }
    }

    SC_CTOR(mon) {
        SC_THREAD(monitor);
        sensitive << Clk.pos();
    }
};
