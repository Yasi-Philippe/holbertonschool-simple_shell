# holbertonschool-simple_shell

## Project Description

This project consists of creating a **simple UNIX command line interpreter also known as shell** as part of the Holberton School curriculum.

The shell implements the following features:
- Displays a prompt in interactive mode
- Reads and executes commands with arguments
- Searches for executables in the directories listed in the **PATH**
- Handles built-in commands: **exit** and **env**
- Works correctly in both **interactive** and **non-interactive** modes
- Exits the program with the **exit** command and **Ctrl + D**

## Requirements

- All files are compiled on **Ubuntu 20.04 LTS** using **gcc**, using the options **-Wall -Werror -Wextra -pedantic -std=gnu89**
- All files end with a new line
- A **README.md** file is present at the root of the folder of the project
- The code uses the **Betty style**
- The shell has no memory leaks (checked with Valgrind)
- There is no more than 5 functions per file
- All the header files are include-guarded
- Use system calls only when you need to

## How to use the program

###

## Compilation Command

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Source files


| File              | Function                                                                                                                        |
|-------------------|---------------------------------------------------------------------------------------------------------------------------------|
| arr_strtok.c      |Takes a string as input and returns an array of strings.                                                                         |
| ev_exec_cmd.c     |Shell Function. Evaluates commands and executes them.                                                                            |
| exit_shell.c      |Function that handles the exit command.                                                                                          |
| find_path.c       |Function that finds the full path of a command.                                                                                  |
| fork_shell.c      |Function that forks the main processus into a child and executes the program linked to the comand given in the child processus.  |
| free_args.c       |Function that frees a 2D array of strings.                                                                                       |
| main.h            |Library containing all the prototypes.                                                                                           |
| print_env.c       |Prints the environment.                                                                                                          |
| simple_shell.c    |Shell Function. Takes commands as input and execcute the programs                                                                |
| strtok_arr_len.c  |Takes a string as input and returns the array lenght.                                                                            |


## Usage Examples

### Interactive Mode

```bash
$ ./hsh
#cisfun$ ls -la
total 120
drwxrwxr-x  3 user user  4096 Jan  5 12:30 .
drwxrwxr-x 10 user user  4096 Jan  5 10:00 ..
-rwxrwxr-x  1 user user 35240 Jan  5 12:30 hsh
-rw-rw-r--  1 user user  1234 Jan  5 12:15 main.c
...
#cisfun$ /bin/pwd
/home/user/holbertonschool-simple_shell
#cisfun$ env
USER=user
HOME=/home/user
PATH=/usr/local/bin:/usr/bin:/bin:/usr/games
...
#cisfun$ exit
$
```

### Non-Interactive Mode

```bash
$ echo "/bin/ls" | ./hsh
hsh  main.c  arr_strtok.c  find_path.c  fork_shell.c  free_args.c  print_env.c  ...

$ cat test_script
/bin/ls
env
exit
$ cat test_script | ./hsh
hsh  main.c  arr_strtok.c  ...
USER=user
PATH=/usr/local/bin:/usr/bin:/bin
...
$
```

### Error Case

```bash
#cisfun$ qwerty
./hsh: No such file or directory
#cisfun$
```

## Man Page

To view the shell's man page:

```bash
man ./man_1_simple_shell
```

or

```bash
export MANPATH=$$ MANPATH: $$(pwd)
man hsh
```

## Testing

- Launch in interactive and non-interactive mode (with the examples given above)
- Test commands (/bin/ls), relative (./hsh), and PATH commands (ls)
- Test built-ins **exit** and **env**
- Test **Ctrl+D** and **exit** to exit cleanly
- Test empty lines or lines containing spaces only

### Memory Leak Check with Valgrind

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./hsh
```

Then type a few commands and exit. Expected result:

```text
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: ... allocs, ... frees, ... bytes allocated
==12345==
==12345== All heap blocks were freed -- no leaks are possible
```

**No memory leaks detected.**

## Flowchart

Here we see how the shell operation works thanks to the flowchart:

## Additional Information

- This simplified version of shell does not yet handle: redirections, pipes, custom environment variables, separators ;, &&, ||, or signals (Ctrl+C).
- This project was done in peer coding within 2 weeks to better our communication and group work skills
- The project was completed on January 2026
