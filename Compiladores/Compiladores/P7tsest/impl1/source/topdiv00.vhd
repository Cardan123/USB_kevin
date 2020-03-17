library ieee;
use ieee.std_logic_1164.all;
library lattice;
library machxo2;
use machxo2.all;
use packagediv00.all;

entity topdiv00 is
  port(
       --clk0: in std_logic;
	   cdiv0: in std_logic_vector(3 downto 0);
	   oscout0: inout std_logic;
       outdiv0: inout std_logic);
end topdiv00;

architecture topdiv0 of topdiv00 is
signal sclk0: std_logic;
begin
--sclk0 <= oscout0;
  OS00: osc00 port map(osc_int => oscout0);
  
  OS01: div00 port map(clkdiv => oscout0,
                       indiv => cdiv0,
                       outdiv => outdiv0);
  
  
end topdiv0;