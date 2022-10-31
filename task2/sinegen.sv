module sinegen (
    input logic [7:0]   incr,
    input logic         rst,
    input logic         en,
    input logic         clk,
    input logic [7:0]   offset,

    output logic [7:0]  dout1,
    output logic [7:0]  dout2
);

logic [7:0] addr1;
logic [7:0] addr2;

counter counter1(
    .clk (clk),
    .rst (rst),
    .en (en),
    .incr (incr),
    .offset (offset),
    .count1 (addr1),
    .count2 (addr2)
);

rom rom1(
    .addr1 (addr1),
    .addr2 (addr2),
    .clk (clk),
    .dout1 (dout1),
    .dout2 (dout2)
);

endmodule
