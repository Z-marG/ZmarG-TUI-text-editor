# ZmarG-TUI-text-editor
<p align='center'>
	<i>
		"minimal, is this text editor, not built for the user, but for its creator's sanity." <br> <br>
		-Sun Tzu (2025)
	</i>
</p>

---
# Features (or lack thereof)
- Built Different 🔥 Not for your Convenience 🔥
- Basic **file creation**, **preview** and **editing (inconveniently!!)** 🔥
- Saves file into the *same directory* as the **executable!!** what!?! 😲🔥
- I can't stop adding the **fire emoji!!** 🔥🔥 

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
[~]	*{^[}* <- (ESC Pressed, because i havent imported real time user input!! 🔥)

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

# Issues
- honestly there are too many to count
- but there are none major spotted for now
