,>,                 # Input two characters
>++++++             # Set memory cell 1 to 6 (used as a counter)
[
  >++++++++        # Loop: Set memory cell 2 to 8 (used as a counter for inner loop)
  <-
]
>
[
  -               # Outer Loop: Decrement memory cell 1
  <<-
  >>
]
<<
[
  -               # Inner Loop: Decrement memory cell 2
  <+
  >
]
<.                  # Output the character at the current memory cell

