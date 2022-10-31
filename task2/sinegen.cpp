#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    //inint top verilog instance
    Vsinegen* top = new Vsinegen;
    //init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("sinegen.vcd");

    //init vbuddy
    if(vbdOpen()!=1) return (-1);
    vbdHeader("Lab2: Sinegen");

    //initialize sim input
    top->clk = 1;
    top->rst = 0;
    top->en = 1;
    top->incr = 4;
    top->offset = 0;
    vbdSetMode(1);

    //run sims for many clock cycles
    for (i = 0; i < 1000000; i++) {
        
        //dump vars into VCD and toggle clock
        for (clk = 0; clk<2; clk++){
            tfp->dump (2*i+clk); //unit in ps
            top->clk = !top->clk;
            top->eval ();
        }
        //send counter to vbuddy

        /**
        vbdHex(4, (int(top->count) >> 16) & 0xF);
        vbdHex(3, (int(top->count) >> 8) & 0xF);
        vbdHex(2, (int(top->count) >> 4) & 0xF);
        vbdHex(1, int(top->count) & 0xF);
        vbdCycle(i+1);
        //end output section
        **/

       top->offset = vbdValue();

        vbdPlot(int(top->dout1), 0, 255);
        vbdPlot(int(top->dout2), 0, 255);
        
        if (Verilated::gotFinish() || (vbdGetkey() == 'q')) exit(0);
        
    }
    //vbdClose();
    tfp->close();
    exit(0);
    
}