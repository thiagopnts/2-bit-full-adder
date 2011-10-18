#include "systemc.h"
#include <iomanip>

using namespace std;

SC_MODULE(mon) {
    sc_in<bool> A1,A2,B1,B2,Cin, Sum1, Sum2, Cout, Clk;

    void monitor() {
        cout << setw(10) << "Time";
        cout << setw(4) << "A1";
        cout << setw(4) << "B1";
        cout << setw(5) << "Cout";
        cout << setw(3) << "Sum" << endl;

        while(true) {
            cout << setw(10) << sc_time_stamp();
            cout << setw(3) << A1.read() << A2.read();
            cout << setw(3) << B1.read() << B2.read();
            cout << setw(5) << Cout.read();
            cout << Sum1.read() << Sum2.read() << endl;
            wait();
        }
    }

    SC_CTOR(mon) {
        SC_THREAD(monitor);
        sensitive << Clk.pos();
    }
};
