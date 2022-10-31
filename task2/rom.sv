module rom #(
    parameter   ADDRESS_WIDTH = 8,
                DATA_WIDTH = 8
)(
    input logic [7:0]   addr1,
    input logic [7:0]   addr2,
    input logic         clk,
    output logic [7:0]  dout1,
    output logic [7:0]  dout2
);

logic [DATA_WIDTH-1:0] rom_array1 [2**ADDRESS_WIDTH-1:0];
logic [DATA_WIDTH-1:0] rom_array2 [2**ADDRESS_WIDTH-1:0];

initial begin
    $display("Loading rom 1.");
    $readmemh("sinerom.mem", rom_array1);

    $display("Loading rom 2.");
    $readmemh("sinerom.mem", rom_array2);
end

always_ff @(posedge clk) begin
    //output is synchronous
    dout1 <= rom_array2[addr1];
    dout2 <= rom_array2[addr2];
end

endmodule
