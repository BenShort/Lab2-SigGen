module sigdelay
(
    input logic                     clk,
    input logic                     rst,
    input logic                     en,
    input logic                     wr,
    input logic                     rd,
    input logic [8:0]               offset,
    input logic [7:0]               mic_signal,

    output logic [7:0]   delayed_signal
);

logic [8:0] count1;
logic [8:0] count2;

counter count(
    .clk (clk),
    .rst (rst),
    .en  (en),
    .offset (offset),
    .count1 (count1),
    .count2 (count2)
);

dual_port_ram ram(
    .clk (clk),
    .wr_en (wr),
    .rd_en (rd),
    .wr_addr (count1),
    .rd_addr (count2),
    .din (mic_signal),
    .dout (delayed_signal)
);

endmodule
