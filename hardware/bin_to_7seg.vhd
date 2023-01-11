library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity bin_to_7seg is
    Port ( B : in  STD_LOGIC_VECTOR (3 downto 0);
           S : out  STD_LOGIC_VECTOR (7 downto 0));
end bin_to_7seg;

architecture Behavioral of bin_to_7seg is
begin
    process(B)
    begin
        case B is
            when "0000" => S <= "01000000";
            when "0001" => S <= "01111001";
            when "0010" => S <= "00100100";
            when "0011" => S <= "00110000";
            when "0100" => S <= "00011001";
            when "0101" => S <= "00010010";
            when "0110" => S <= "00000010";
            when "0111" => S <= "01111000";
            when "1000" => S <= "00000000";
            when "1001" => S <= "00010000";
            when others => S <= "11111110";
        end case;
    end process;
end Behavioral;
