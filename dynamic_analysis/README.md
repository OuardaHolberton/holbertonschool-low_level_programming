# 0. GDB Fundamentals
Objective
Use GDB from the command line to control execution and extract specific runtime values from a running C program.

This task validates your ability to:

*stop execution at precise moments,
*inspect runtime state,
*and extract correct values from a program while it is executing.
*Warm-up (required)
Before working on the provided code, complete the following tutorial end-to-end:

https://www.geeksforgeeks.org/c/gdb-step-by-step-introduction/
This tutorial is practice only. Do not include tutorial output in your submission.

Program Provided
You will receive a file named:

sample.c
You must not modify this file in any way.

Program Input (fixed)
Run the program using the following input exactly:

123456
(The newline produced by pressing Enter is expected.)

What you must submit
File name (exact)
You must submit a single file named:

gdb_fundamentals.txt
Output format (strict)
Your file must contain exactly 3 lines, in this order:

Each line must be a 32-bit unsigned value
Format must be:
0x followed by 8 uppercase hexadecimal digits
No labels
No comments
No extra whitespace
No extra lines
Example format (illustrative only):

0x1234ABCD
0x00000001
0xDEADBEEF
Values to extract (what and when)
You must run the program under GDB and extract the following values at the specified execution moments.

You are not told which GDB commands to use. Determining how to reach these states is part of the task.

Line 1 — TAG_ACC (32-bit)
Where / when:

Inside the function derive_key(...)
Immediately after the loop that iterates over the decoded tag finishes
Before the code combines the accumulator with user_pin and g_state
What to record:

The value of the local variable:

x

Write it as 0x????????.

Line 2 — KEY (32-bit)
Where / when:

Still inside derive_key(...)
Immediately before the function returns
What to record:

The value that will be returned by derive_key(...)

The local variable holding that value:

x

Write it as 0x????????.

Line 3 — ACC_AFTER_I0 (32-bit)
Where / when:

Inside the function compute_target(...)

During the loop

At the end of the iteration where:

i == 0

After the accumulator has been fully updated for that iteration

What to record:

The value of the local variable:

acc

Write it as 0x????????.

Constraints
You must not:

modify sample.c

add print statements or logging

hardcode values into the output file

All values must be obtained through runtime inspection.

The output must be reproducible by repeating your debugging steps.

