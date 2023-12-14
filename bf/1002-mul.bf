>,------------------------------------------------ # Read the first character into memory cell #1
>,------------------------------------------------ # Read the second character into memory cell #2

[                           # Start of loop: COPY BLOCK 1 INTO BLOCK 3 AND 0 THEN COPY BLOCK 3 BACK TO BLOCK 1
  <[>>+<<<+>-]               # Move to BLOCK 1 and copy to BLOCK 3 (Temporary storage)
  >>[<<+>>-]                 # Move back to BLOCK 1 and copy from BLOCK 3
<-]                          # End of loop, done with one iteration

# Move to BLOCK 2 and decrease (BLOCK 2 now contains the difference between ASCII values)
MOVE BLOCK TO BLOCK 2 AND DECREASE (DONE WITH ONE ITERATION)

# Move to BLOCK 0 and increase by ASCII '0' (DEC 48)
<<++++++++++++++++++++++++++++++++++++++++++++++++. # Print the result (BLOCK 0 now contains the result as ASCII)

