>, >, <<            # Input three characters
+++++ +             # Set memory cell 1 to 5
[
 >----- ---         # Loop: Decrement memory cell 1 to 0
 >----- ---         # Reset memory cell 2 and 3
 <<-                 # Move back to the beginning of the loop
]
>[
 >[>+>+<<-]          # Copy value at memory cell 1 to memory cell 4 and 5
 >[<+>-]             # Add the values at memory cell 4 and 5 and store the result in memory cell 1
 <<-                 # Move back to the beginning of the loop
]
>[-]>+              # Clear memory cell 2 and 3, increment memory cell 1
 >+++++ +++++<       # Set memory cell 2 to 70 (ASCII for 'F')
[
 - >-               # Loop: Decrement memory cell 3, move to memory cell 4
 [>>>]+++++ +++++<<+  # Loop: Move to memory cell 5, set to 100 (ASCII for 'd'), move back to memory cell 4
 [<<<]>>>>           # Move back to memory cell 3
]
<-                   # Move back to memory cell 1
<+++++ +++++>>>[-<<<->>>]<<<  # Move to memory cell 6 and clear, move back to memory cell 1
<+++++ +             # Set memory cell 2 to 5
[
 >+++++ +++>         # Loop: Increment memory cell 3 to 10
 [+++++ +++>]        # Loop: Increment memory cell 2 to 50 (ASCII for '2'), move back to memory cell 3
 <[<]>-              # Loop: Move back to memory cell 2, decrement to 49 (ASCII for '1'), move back to memory cell 3
]
>>[.<<]<[<<]>>.      # Output '1' and '2'
>>>>>>>>>>>>>>>>>>>>>>>++++++
                      # Move to memory cell 7 and set to 30 (ASCII for 'RS')

