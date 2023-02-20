## Recitation 6 Algorithm - Vowel Counter
### AddVowel Function
1. Use a switch structure to determine which vowel counter to add to
1.1 Case A/a, add to A counter.
1.2 Case E/e, add to E counter.
1.3 Case I/i, add to I counter.
1.4 Case O/o, add to O counter.
1.5 Case U/u, add to U counter.
1.6 Default add to other counter.

### Main Function
1. Declare variables for current character, and character counters.
2. Open the paragraph file
3. Do a EOF controlled while loop reading in one character at a time.
3.1 Call The AddVowel function on the current character.
4. Close input file.
5. Print the character counts.