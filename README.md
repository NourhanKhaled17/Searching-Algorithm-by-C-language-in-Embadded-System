# Searching-Algorithm-by-C-language-in-Embadded-System
this algorithm for searching for a specific number and
returning its position/s.
• The user will enter a list of numbers through the keypad, which will be
displayed on the LCD.
• After pressing the confirmation button (+) one number is stored in array 
, After (=) the end of entering numbers, the user will enter the number he wants to search for.
• After pressing the confirmation button (-) the position will be displayed
on the seven segment. Also, the binary representation of the position
will be displayed on the LEDs.
• Ex: if the user enters: 1, 1, 2,1 and he wants to search on 1
• We should first see 0 in the seven segment and 0000 on the LEDs. After
1 sec, we should see 1 in the seven segments and 0001 on the LEDs.
After another 1 sec, we should see 3 on the seven segment and 0011
on the LEDs where 0,1, and 3 are the positions of 1.
• In the binary representations of the LEDs, 0 means the LED is off and 1
means the LED is on.
• If the number is repeated, all positions will be printed.
• The maximum length of the list is 16.
