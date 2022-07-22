# CPSC_380_Assignment_1
The  objective  of  this  code  consists  of  designing  a  C/C++  program  to  serve  as  a  shell  interface that accepts user commands and then executes each command in a separate process.

## Idendifying Information

* Name: Marco Mauricio
* StudentID: 2344979
* Email: mauricio@chapman.edu
* Course: CPSC 380
* Assignment: 1

## Source Files

* sshell.c
	
## References

* https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
* https://www.ibm.com/docs/en/i/7.4?topic=functions-fgets-read-string
* https://beginnersbook.com/2014/01/c-strings-string-functions/
* https://linux.die.net/man/2/waitpid 
	
## Known Errors

* "&" command not recognized (i.e "ls -l &" is seen as garbage option)

## Build Instructions

* <code> gcc sshell.c -o sshell </code>
	
## Execution Instructions

* <code> ./sshell </code>
