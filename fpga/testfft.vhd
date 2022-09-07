LIBRARY ieee;
USE ieee.std_logic_1164.all;
use IEEE.numeric_std.all;

entity testfft is
	port (
		clk          : in  std_logic;
		sink_ready   : out std_logic;  
      source_valid : out std_logic;                                        -- source.source_valid
		source_error : out std_logic_vector(1 downto 0);                     --       .source_error
		source_sop   : out std_logic;                                        --       .source_sop
		source_eop   : out std_logic;                                        --       .source_eop
		source_real  : out std_logic_vector(31 downto 0);                    --       .source_real
		source_imag  : out std_logic_vector(31 downto 0);                    --       .source_imag
		fftpts_out   : out std_logic_vector(7 downto 0);
		sink_valid   : buffer  std_logic                     := '0'; 		--       .fftpts_out		
		sink_sop     : buffer  std_logic                     := '0'; 
		sink_eop     : buffer  std_logic                     := '0';             --       .sink_eop
		sink_real    : buffer  std_logic_vector(31 downto 0) := (others => '0'); --       .sink_real
		sink_imag    : buffer  std_logic_vector(31 downto 0) := (others => '0')
	
	
	
	);
end entity testfft;
architecture rtl of testfft is
component ram_re1 IS
	PORT
	(
		clock		: IN STD_LOGIC  := '1';
		data		: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		rdaddress		: IN STD_LOGIC_VECTOR (14 DOWNTO 0);
		wraddress		: IN STD_LOGIC_VECTOR (14 DOWNTO 0);
		wren		: IN STD_LOGIC  := '0';
		q		: OUT STD_LOGIC_VECTOR (31 DOWNTO 0)
	);
END component ram_re1;

component ram_im1 IS
	PORT
	(
		clock		: IN STD_LOGIC  := '1';
		data		: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		rdaddress		: IN STD_LOGIC_VECTOR (14 DOWNTO 0);
		wraddress		: IN STD_LOGIC_VECTOR (14 DOWNTO 0);
		wren		: IN STD_LOGIC  := '0';
		q		: OUT STD_LOGIC_VECTOR (31 DOWNTO 0)
	);
END component ram_im1;


component fft128 is
	port (
		clk          : in  std_logic                     := '0';             --    clk.clk
		reset_n      : in  std_logic                     := '0';             --    rst.reset_n
		sink_valid   : in  std_logic                     := '0';             --   sink.sink_valid
		sink_ready   : out std_logic;                                        --       .sink_ready
		sink_error   : in  std_logic_vector(1 downto 0)  := (others => '0'); --       .sink_error
		sink_sop     : in  std_logic                     := '0';             --       .sink_sop
		sink_eop     : in  std_logic                     := '0';             --       .sink_eop
		sink_real    : in  std_logic_vector(31 downto 0) := (others => '0'); --       .sink_real
		sink_imag    : in  std_logic_vector(31 downto 0) := (others => '0'); --       .sink_imag
		fftpts_in    : in  std_logic_vector(7 downto 0)  := (others => '0'); --       .fftpts_in
		source_valid : out std_logic;                                        -- source.source_valid
		source_ready : in  std_logic                     := '0';             --       .source_ready
		source_error : out std_logic_vector(1 downto 0);                     --       .source_error
		source_sop   : out std_logic;                                        --       .source_sop
		source_eop   : out std_logic;                                        --       .source_eop
		source_real  : out std_logic_vector(31 downto 0);                    --       .source_real
		source_imag  : out std_logic_vector(31 downto 0);                    --       .source_imag
		fftpts_out   : out std_logic_vector(7 downto 0)                      --       .fftpts_out
	);
end component fft128;

--signal sink_valid : std_logic:='0';
signal source_ready : std_logic:='1';
--signal sink_sop : std_logic:='0';
--signal sink_eop : std_logic:='0';
--signal sink_real    : std_logic_vector(31 downto 0) := (others => '0'); 
--signal sink_imag    : std_logic_vector(31 downto 0) := (others => '0');
signal sink_error :std_logic_vector(1 downto 0):="00";
signal fftpts_in    :  std_logic_vector(7 downto 0)  := "10000000";
signal counter    :  std_logic_vector(14 downto 0)  := "000000000000000";
signal q_re :  STD_LOGIC_VECTOR (31 DOWNTO 0):="00000000000000000000000000000000";
signal q_im:  STD_LOGIC_VECTOR (31 DOWNTO 0):="00000000000000000000000000000000";
signal count4 : integer :=-2;
signal countend : integer :=0;
signal beg :integer :=0;
signal reset_n:std_logic :='0';


begin

u0:component ram_re1
		port map (
		clock		 => clk,
		data		=>"00000000000000000000000000000000",
		rdaddress		=>counter,
		wraddress		=>"000000000000000",
		wren		=> '0',
		q		=> q_re
	);
u2:component ram_im1
		port map (
		clock		 => clk,
		data		=>"00000000000000000000000000000000",
		rdaddress		=>counter,
		wraddress		=>"000000000000000",
		wren		=> '0',
		q		=> q_im
	);
	
u1 : component fft128
		port map (
			clk          => clk,          --    clk.clk
			reset_n      => reset_n,      --    rst.reset_n
			sink_valid   => sink_valid,   --   sink.sink_valid
			sink_ready   => sink_ready,   --       .sink_ready
			sink_error   => sink_error,   --       .sink_error
			sink_sop     => sink_sop,     --       .sink_sop
			sink_eop     => sink_eop,     --       .sink_eop
			sink_real    => sink_real,    --       .sink_real
			sink_imag    => sink_imag,    --       .sink_imag
			fftpts_in    => fftpts_in,    --       .fftpts_in
			source_valid => source_valid, -- source.source_valid
			source_ready => source_ready, --       .source_ready
			source_error => source_error, --       .source_error
			source_sop   => source_sop,   --       .source_sop
			source_eop   => source_eop,   --       .source_eop
			source_real  => source_real,  --       .source_real
			source_imag  => source_imag,  --       .source_imag
			fftpts_out   => fftpts_out    --       .fftpts_out
		);

process (clk)

begin
if(rising_edge(clk)) then
	count4<= count4+1;
	if(count4=0) then
		sink_sop<='1';
		sink_eop<='0';
			if(beg =0) then
				sink_valid <= '1';
				beg<=1;
			end if;
	elsif(count4=127) then 
	  sink_eop<='1';
	  count4<=0;
	countend<=countend+1;
	else
	sink_eop<='0';
	sink_sop<='0';
   end if;
	
	if(countend=2) then
	  sink_valid<='0';
	end if;
	sink_real <= q_re;
	sink_imag <=q_im;
	
	counter<=std_logic_vector(unsigned(counter)+1);
elsif(falling_edge(clk)) then
	if(count4=-1) then
		if(beg =0) then
				reset_n<='1';
			end if;
	 end if;


end if;

end process;




end architecture rtl; 