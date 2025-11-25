# GA-TUI-text-editor
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
- Takes in file names as the only argument 🔥🔥🔥
- Saves file into the *same directory* as the **executable!!** what!?! 😲🔥
- I can't stop adding the **fire emoji!!** 🔥🔥 

# Compile & Install
```bash
git clone https://github.com/GA-barely-pushes/GA-TUI-text-editor.git
cd GA-TUI-text-editor/
gcc main.c -o ./text-editor
```

# Usage
text surrounded by \*{  }* are user input
```
$ *{ ./text-editor example.txt }*

Welcome to GA's Crappy text editor


File Doesn't Exist!

Would you like to create it?
[y/n]	~> *{ y }*

Would You Like to Edit it?
[y/n]	~> *{ y }*

New Contents: [Press ESC in a new line and ENTER to save and exit]
[1]	*{ Hello! }*
[2]	*{ World! }*
[3]	
[~]	*{ ^[ }* <- (When ESC is pressed)

--------------------------------

--------------------------------

File Contents:

	Hello!
	World!

--------------------------------
Line Count: [2]
Character Count: [12]


Would You Like to Edit it?
[y/n]	~> *{ n }*
```
it saves in the same folder of the compiled executable

# Issues
- Too many to count 🔥
- Maybe adding real time input processing next time 🔥
