,>,                 # Input two characters
>++++++             # Set memory cell 1 to 6 (used as a counter for the outer loop)
[
	>++++++++        # Loop: Set memory cell 2 to 8 (used as a counter for the inner loop)
	<-
]
>>++++++            # Set memory cell 3 to 6 (used as a counter for the second outer loop)
[
	>++++++++        # Loop: Set memory cell 4 to 8 (used as a counter for the second inner loop)
	<-
]
>
[
	-               # Outer Loop: Decrement memory cell 1
	<<<<-           # Move to memory cell 2
	<-
	>>>>>           # Move to memory cell 3
]
<<<<<
[
	>               # Inner Loop: Move to memory cell 4
	[
		>+          # Increment value at memory cell 4
		>>+         # Increment value at memory cell 5
		<<<-        # Move back to memory cell 3
	]
	>>>             # Move back to memory cell 1
	[
		-           # Decrement value at memory cell 1
		<<<+        # Move back to memory cell 4 and increment
		>>>         # Move back to memory cell 1
	]
	<<<<-           # Move back to memory cell 3
]
>>
[
	-               # Second Outer Loop: Decrement memory cell 3
	>+              # Increment value at memory cell 4
	<               # Move back to memory cell 3
]
>.                  # Output the character at the current memory cell

