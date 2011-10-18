#include "systemc.h"

SC_MODULE(stim) {
    sc_out<bool> A1, A2, B1, B2, Cin;
    sc_in<bool> Clk;

    void StimGen() {
        A1.write(false); A2.write(false); B1.write(false); B2.write(false); Cin.write(false);
        wait();
        A1.write(false); A2.write(false); B1.write(false); B2.write(true); Cin.write(false);
        wait();
        A1.write(false); A2.write(false); B1.write(true); B2.write(false); Cin.write(false);
        wait();
        A1.write(false); A2.write(false); B1.write(true); B2.write(true); Cin.write(false);
        wait();
        A1.write(false); A2.write(true); B1.write(false); B2.write(false); Cin.write(false);
        wait();
        A1.write(false); A2.write(true); B1.write(false); B2.write(true); Cin.write(false);
        wait();
        A1.write(false); A2.write(true); B1.write(true); B2.write(false); Cin.write(false);
        wait();
        A1.write(false); A2.write(true); B1.write(true); B2.write(true); Cin.write(false);
        wait();
        A1.write(true); A2.write(false); B1.write(false); B2.write(false); Cin.write(false);
        wait();
        A1.write(true); A2.write(false); B1.write(false); B2.write(true); Cin.write(false);
        wait();
        A1.write(true); A2.write(false); B1.write(true); B2.write(false); Cin.write(false);
        wait();
        A1.write(true); A2.write(false); B1.write(true); B2.write(true); Cin.write(false);
        wait();
        A1.write(true); A2.write(true); B1.write(false); B2.write(false); Cin.write(false);
        wait();
        A1.write(true); A2.write(true); B1.write(false); B2.write(true); Cin.write(false);
        wait();
        A1.write(true); A2.write(true); B1.write(true); B2.write(false); Cin.write(false);
        wait();
        A1.write(true); A2.write(true); B1.write(true); B2.write(true); Cin.write(false);
        wait();
        sc_stop();
    }

    SC_CTOR(stim) {
        SC_THREAD(StimGen);
        sensitive << Clk.pos();
    }
};
