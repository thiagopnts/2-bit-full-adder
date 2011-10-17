#include "systemc.h"
#include "stim.h"
#include "adder2.h"
#include "mon.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool>A1Sig, A2Sig, B1Sig, B2Sig, CinSig, S1Sig, S2Sig, CoSig;
    sc_clock TestClk("TestClock", 10, SC_NS, 0.5);
    stim Stim1("Stimulus");
    Stim1.A1(A1Sig);
    Stim1.A2(A2Sig);
    Stim1.B1(B1Sig);
    Stim1.B2(B2Sig);
    Stim1.Cin(CinSig);
    Stim1.Clk(TestClk);

    adder2 DUT("adder2");
    DUT.A1(A1Sig);
    DUT.A2(A2Sig);
    DUT.B1(B1Sig);
    DUT.B2(B2Sig);
    DUT.Cin(CinSig);
    DUT.Sum1(S1Sig);
    DUT.Sum2(S2Sig);
    DUT.Cout(CoSig);

    mon Monitor1("Monitor");

    Monitor1.A1(A1Sig);
    Monitor1.A2(A2Sig);
    Monitor1.B1(B1Sig);
    Monitor1.B2(B2Sig);
    Monitor1.Cin(CinSig);
    Monitor1.Sum1(S1Sig);
    Monitor1.Sum2(S2Sig);
    Monitor1.Cout(CoSig);
    Monitor1.Clk(TestClk);

    sc_start();
    return 0;
}
