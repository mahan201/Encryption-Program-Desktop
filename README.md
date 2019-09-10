# Encryption-Program-Desktop
Windows Encryption program developed as part of my EPQ qualification. 


For my Extended Project Qualification (EPQ), I decided to explore security and encryption and build a program that can encrypt and decrypt
text files. The first part of my research was spent researching which programming languages would benefit me the most and any frameworks 
that were useful to my program. The second part of my research was exploring encryption methods and which method I could use to implement 
into my program.

_This program was developed using the **QT** framework built using C++._

# VERSION 3

Version 3 of my program was a big jump for which I decided to start with the Graphical User Interface, designing and coding a seamless 
interface that the user would navigate in with ease. I designed my own interface as shown below which adopts a black, grey and white colour
palette. The program has two “layers” which are the encryption and decryption page. On each “layer” the user has the choice of Real-Time 
Encryption or File Encryption. The user can access these two pages by using the buttons on the side which come with self-explanatory icons.

![alt text](https://raw.githubusercontent.com/mahan201/Encryption-Program-Desktop/Version-3/Images/Version%203_1.jpg)

The real-time encryption encrypts the input of the user as the user types it so there is no delay and if the user decides to change the 
key after they have typed their text, the program will update the cypher text based on the new key. File encryption allows the user to 
easily browse for a .txt text file from their computer, choose their encrypted file name and location and encrypt it using their desired 
key. The program has been optimised to minimise any loading while the program encrypts/decrypts and outputs the file.

![alt text](https://raw.githubusercontent.com/mahan201/Encryption-Program-Desktop/Version-3/Images/Version%203_2.jpg)

I was initially unhappy with the default toolbar that Windows provides. It did not fit the style of my program, therefore, I set out to 
program in my own toolbar. Adding a toolbar with the buttons was not a hard task however, replicating the ability to move the program 
window by clicking and dragging the toolbar was challenging. I learnt a new skill of working with vectors and locations to be able to 
create a function which allowed the window to be moved when clicked and dragged. The function calculates the difference between vector 
positions of the mouse before the movement and after the movement and applies that difference to the window, replicating movement alongside 
the mouse.

**Before:**
![alt text](https://raw.githubusercontent.com/mahan201/Encryption-Program-Desktop/Version-3/Images/Toolbar1.jpg)

**After:**
![alt text](https://raw.githubusercontent.com/mahan201/Encryption-Program-Desktop/Version-3/Images/Toolbar2.jpg)
