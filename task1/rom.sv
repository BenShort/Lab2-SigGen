module rom #(
    parameter   ADDRESS_WIDTH = 8,
                DATA_WIDTH = 8
)(
    input logic [7:0]   addr,
    input logic         clk,
    output logic [7:0]  dout
);

logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

initial begin
    $display("Loading rom.");
    $readmemh("sinerom.mem", rom_array);
end

always_ff @(posedge clk) begin
    //output is synchronous
    dout <= rom_array[addr];
    $display(addr);

end

endmodule
