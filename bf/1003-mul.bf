,>++++++++[<------>-](read1)    # Read the first character and convert it to ASCII
,>++++++++[<------>-](read2)    # Read the second character and convert it to ASCII
<<[->(startclone)[>+>+<<-]>>[-<<+>>](endclone)<[->>+<<]<<(add)]    # Clone the values for addition
>>>>>++++++++++(start)    # Set up a loop to subtract 48 (ASCII for '0') from each value
[->-[>+>>]>[+[-<+>]>+>>]<<<<<]
>>>>++++++++[<++++++>-]<.#    # Print the result of the first addition
<[->>+<<]#    # Clone the values again for the second addition
>>>++++++++[<++++++>-]<.#    # Print the result of the second addition
>++++++++++.    # Print a newline character

