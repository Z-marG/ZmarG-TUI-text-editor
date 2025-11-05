# ZmarG-TUI-text-editor
A text editor purely made for fun in C and the stdio.h library only, ~~complete~~ with file creation, file content preview and editing.

this was built not because it is simple to use let alone be useful, this was *simply* made for my purposive learning of file handling in C and string buffers.
might add dynamically allocated memory using stdlib.h if i feel like it

---
# Compile & Install
```bash
git clone https://github.com/Z-marG/ZmarG-TUI-text-editor.git
cd ZmarG-TUI-text-editor/
gcc main.c -o ./text-editor
```

# Usage 
text surrounded by \*{}* are user input
```
$ ./text-editor

Welcome to Zmar-G's crappy text editor


Initializing Buffers...

File name buffer... [ready!]
Text data buffer... [ready!]

What is your file name?
	~> *{example.txt}*

Opening File...

File Doesn't Exist!

Would you like to create it?
[y/n]	~> *{y}* 

[Creating file...]

[File Created!]

Would You Like to Edit it?
[y/n]	~> *{y}* 

New Contents: [Press ESC in a line after your last and press ENTER to save and exit]
[1]	*{Hello!}*
[2]	*{World!}*
[3]	
[~]	*{^[}*

--------------------------------

Saving file...

File saved!

File Contents:

	Hello!
	World!

--------------------------------
Line Count: [2]
Character Count: [12]


Would You Like to Edit it?
[y/n]	~> *{n}*
```
it saves in the same folder of the compiled executable
