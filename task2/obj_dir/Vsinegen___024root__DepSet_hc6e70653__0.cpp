// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen.h for the primary calling header

#include "verilated.h"

#include "Vsinegen___024root.h"

VL_INLINE_OPT void Vsinegen___024root___sequent__TOP__0(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->dout2 = vlSelf->sinegen__DOT__rom1__DOT__rom_array
        [vlSelf->sinegen__DOT__addr2];
    vlSelf->dout1 = vlSelf->sinegen__DOT__rom1__DOT__rom_array
        [vlSelf->sinegen__DOT__addr1];
}

VL_INLINE_OPT void Vsinegen___024root___sequent__TOP__1(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___sequent__TOP__1\n"); );
    // Init
    CData/*7:0*/ __Vdly__sinegen__DOT__addr1;
    CData/*7:0*/ __Vdly__sinegen__DOT__addr2;
    // Body
    __Vdly__sinegen__DOT__addr2 = vlSelf->sinegen__DOT__addr2;
    __Vdly__sinegen__DOT__addr1 = vlSelf->sinegen__DOT__addr1;
    if (vlSelf->rst) {
        __Vdly__sinegen__DOT__addr1 = 0U;
        __Vdly__sinegen__DOT__addr2 = 0U;
    } else {
        __Vdly__sinegen__DOT__addr1 = (0xffU & ((IData)(vlSelf->sinegen__DOT__addr1) 
                                                + (IData)(vlSelf->incr)));
        __Vdly__sinegen__DOT__addr2 = (0xffU & ((((IData)(vlSelf->sinegen__DOT__addr1) 
                                                  + (IData)(vlSelf->incr)) 
                                                 + (IData)(vlSelf->incr)) 
                                                + (IData)(vlSelf->offset)));
    }
    VL_WRITEF("%3#\n%3#\n",8,vlSelf->sinegen__DOT__addr1,
              8,(IData)(vlSelf->sinegen__DOT__addr2));
    vlSelf->sinegen__DOT__addr1 = __Vdly__sinegen__DOT__addr1;
    vlSelf->sinegen__DOT__addr2 = __Vdly__sinegen__DOT__addr2;
}

void Vsinegen___024root___eval(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vsinegen___024root___sequent__TOP__0(vlSelf);
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vsinegen___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vsinegen___024root___eval_debug_assertions(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
