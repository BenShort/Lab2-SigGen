module counter #(
    parameter WIDTH = 8
)(
    //interface signals
    input logic              clk,
    input logic              rst,
    input logic              en,
    input logic [WIDTH-1:0]  incr,
    output logic [WIDTH-1:0] count
);

always_ff @(posedge clk, posedge rst)
    if(rst) count <= incr; //forms width bits of '0'
    else begin
        count <= count + {{WIDTH-1{1'b0}}, en}; //adds width-1 digits of binary 0's and then adds the enable
    end
endmodule
