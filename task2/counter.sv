module counter #(
    parameter WIDTH = 8
)(
    //interface signals
    input logic              clk,
    input logic              rst,
    input logic              en,
    input logic [WIDTH-1:0]  incr,
    input logic [WIDTH-1:0]  offset,
    output logic [WIDTH-1:0] count1,
    output logic [WIDTH-1:0] count2
);

always_ff @(posedge clk, posedge rst) begin
    if(rst) begin
        count1 <= 0; //forms width bits of '0'
        count2 <= 0;
    end
    else begin
        count1 <= count1 + incr;
        count2 <= count1 + incr +incr + offset; 
    end

    //count2 <= count2 + offset;
    $display(count1);
    $display(count2);

end
endmodule
