library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.components.all;
library machxo2;
use machxo2.all;
use packageContador.all;

entity topContador is
	port(
		indiv0: in std_logic_vector(3 downto 0);
	   oscraw0: inout std_logic;
       oscdiv0: inout std_logic;
		clk0,clr0: in std_logic;
		control0: in std_logic_vector(1 downto 0);
		c0 : inout std_logic_vector(9 downto 0);
		E0 : inout std_logic_vector(3 downto 0);
		display0: inout std_logic_vector(6 downto 0)
		); 
end topContador;

architecture a_topContador of topContador is 
begin 
	  OS00: topdiv00 port map(
		cdiv0 => indiv0,
		oscout0 => oscraw0,
		outdiv0 => oscdiv0);
		
	REG00: contador port map(
			 clk => oscdiv0,
			  clr => clr0,
			  c=> c0,
			  control => control0,
			  E => E0,
			  display => display0 );
end a_topContador;