#include "systemc.h"
#include <iomanip>

using namespace std;

SC_MODULE(mon) {
    sc_in<bool> A1,A2,B1,B2,Cin, Sum1, Sum2, Cout, Clk;

    void monitor() {
        cout << setw(10) << "Time";
        cout << setw(3) << "A";
        cout << setw(4) << "B";
        cout << setw(5) << "Cin";
        cout << setw(5) << "Sum";
        cout << setw(6) << "Cout";
        cout << setw(7) << "Final" << endl;

        while(true) {
            cout << setw(10) << sc_time_stamp();
            cout << setw(3) << A1.read() << A2.read();
            cout << setw(3) << B1.read() << B2.read();
            cout << setw(3) << Cin.read();
            cout << setw(5) << Sum1.read() << Sum2.read();
            cout << setw(5) << Cout.read();
            cout << setw(5) << Cout.read() << Sum1.read() << Sum2.read() << endl;
            wait();
        }
    }

    SC_CTOR(mon) {
        SC_THREAD(monitor);
        sensitive << Clk.pos();
    }
};
