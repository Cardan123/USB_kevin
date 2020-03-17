library ieee;
use ieee.std_logic_1164.all;
library lattice;
library machxo2;
use machxo2.all;

package packageContador is

  component topdiv00
       port(
		   cdiv0: in std_logic_vector(3 downto 0);
		   oscout0: inout std_logic;
		   outdiv0: inout std_logic);
  end component;
  
   component contador
		port(
		clk,clr: in std_logic;
		control: in std_logic_vector(1 downto 0);
		E: inout std_logic_vector(3 downto 0);
		c: inout std_logic_vector(9 downto 0);
		display: inout std_logic_vector(6 downto 0)
			);
  end component;
  
 end packageContador;