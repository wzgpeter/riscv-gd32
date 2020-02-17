
How to debug this project:

1. run the command in the Terminal1:
		"sudo openocd -f openocd-ft2232-jtag.cfg"

2. run the command in the Terminal2:
		"ddd -debugger riscv32-unknown-elf-gdb build/test"
	the DDD debugger GUI will pop up.

3. in the command line of DDD, input command as below;
		"target remote localhost:3333"

4. the ELF file after compiling will be here: build/test
   load the ELF file into target board as below:
		"load build/test"
		"file build/test"

5. then you can use the DDD to start the debugging now.


