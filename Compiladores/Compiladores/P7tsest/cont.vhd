
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity contador is
	port (clk,clr: in std_logic;
		control: in std_logic_vector(1 downto 0);
		c: in std_logic_vector(9 downto 0);
		E: inout std_logic_vector(3 downto 0);		
		display: inout std_logic_vector(6 downto 0)
		);
end contador;

architecture A_deca of contador is

--Esta parte son todos los digitos 
--Para otro ejemplo de ponerlos de 8 bits en hexa seria xx "01" 
--para representar un numero en exa
constant dig0: std_logic_vector(6 downto 0):="0000001"; 
constant dig1: std_logic_vector(6 downto 0):="1001111";
constant dig2: std_logic_vector(6 downto 0):="0010010"; 
constant dig3: std_logic_vector(6 downto 0):="0000110"; 
constant dig4: std_logic_vector(6 downto 0):="1001100"; 
constant dig5: std_logic_vector(6 downto 0):="0100100"; 
constant dig6: std_logic_vector(6 downto 0):="0100000"; 
constant dig7: std_logic_vector(6 downto 0):="0001110";    
constant dig8: std_logic_vector(6 downto 0):="0000000"; 
constant dig9: std_logic_vector(6 downto 0):="0001100"; 
constant apa: std_logic_vector(6 downto 0):="1111111";
begin
	
	PROCESS(c,E)
	BEGIN
			IF(C=0)THEN
				E<="ZZZZ";
			ELSIF(C=1)THEN
				E<="0000";
			ELSIF(C<=3)THEN
				E<="0001";
			ELSIF(C<=7)THEN
				E<="0010";
			ELSIF(C<=15)THEN
				E<="0011";
			ELSIF(C<=31)THEN
				E<="0100";
			ELSIF(C<=63)THEN
				E<="0101";
			ELSIF(C<=127)THEN
				E<="0110";
			ELSIF(C<=255)THEN
				E<="0111";
			ELSIF(C<=511)THEN
				E<="1000";
			ELSIF(C<=1023)THEN
				E<="1001";
			end if;
	END PROCESS;

	
	process(clk,clr,control,display,e)
	begin
		if(clr = '0')then
		display <= dig0;
		elsif (clk'event and clk = '1')then
			case control is
			when "00" =>
				case display is 
				when dig0 => display <= dig1;
				when dig1 => display <= dig2;
				when dig2 => display <= dig3;
				when dig3 => display <= dig4;
				when dig4 => display <= dig5;
				when dig5 => display <= dig6;
				when dig6 => display <= dig7;
				when dig7 => display <= dig8;
				when dig8 => display <= dig9;
				when dig9 => display <= dig0;				
				end case;
			when "01" =>
				case display is 
				when dig9 => display <= dig8;
				when dig8 => display <= dig7;
				when dig7 => display <= dig6;
				when dig6 => display <= dig5;
				when dig5 => display <= dig4;
				when dig4 => display <= dig3;
				when dig3 => display <= dig2;
				when dig2 => display <= dig1;
				when dig1 => display <= dig0;
				when dig0 => display <= dig9;
				end case;
			when "10"=> display <= display;
			when others => 
				case E is			
				when "0000" => display <= dig0;
				when "0001" => display <= dig1;
				when "0010" => display <= dig2;
				when "0011" => display <= dig3;
				when "0100" => display <= dig4;
				when "0101" => display <= dig5;
				when "0110" => display <= dig6;
				when "0111" => display <= dig7;
				when "1000" => display <= dig8;
				when "1001" => display <= dig9;
				when others => display <= "0011010";
				end case;
			end case;
		end if;
	end process; 
end a_deca;