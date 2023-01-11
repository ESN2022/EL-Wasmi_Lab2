library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Lab_Two is
	port (
		clk                         : in  std_logic;             --                        clk.clk
		leds_7: out std_logic_vector(7 downto 0);--   leds_external_connection.export
			reset                  : in  std_logic                    := 'X'  -- reset_n
			);
	
end entity Lab_Two;  
	 
	 architecture rtl of Lab_Two is
   component Lab2_sys is
        port (
            clk_clk                         : in  std_logic                    := 'X'; -- clk
            leds_external_connection_export : out std_logic_vector(3 downto 0) ;        -- export
				 reset_reset_n                  : in  std_logic                    := 'X'  -- reset_n
        );
    end component Lab2_sys;
	 
	 component bin_to_7seg is
    Port ( 
		B : in  STD_LOGIC_VECTOR (3 downto 0);
           S : out  STD_LOGIC_VECTOR (7 downto 0)
			                   --                    
			  );
end component bin_to_7seg;
signal leds: std_logic_vector(3 downto 0);

begin
    u0 : component Lab2_sys
        port map (
            clk_clk                         => clk,                         --                      clk.clk
            leds_external_connection_export => leds,  -- leds_external_connection.export
        reset_reset_n                   => reset           
		  );

		  u1 : component bin_to_7seg
        port map (
            B                         => leds,                         --                      clk.clk
             S  => leds_7  -- leds_external_connection.export
        );

		  end architecture rtl;