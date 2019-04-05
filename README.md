# [42] ft_ls

The first project in the Unix branch at 42. Minimum requirements are to recode the functionality of "ls" with 5 flags: -l -a -r -t -R. I handle a few extra flags, as well as small QoL additions, including color and ACL management. Column management is handled by finding the longest file name, and using that as the base width for all files.

### Possible Optimization

The official ls on macs, at the time of this writing, utilizes 38 flags. Adding more flags for a more complete recreation would be the next step.

## Final Score

119/100 (Why is the max bonus score not 125 like every other project?? :<)

## Usage

### Compilation

Compiler:

```
clang-6.0
```

Dependencies:

```
libft
```

### Execution

How to run:

```
./ft_ls [flags] [files]
```

Flags:

```
-1: Displays each file output in a separate line
-R: Recursively executes ls in every subdirectory in the given directories
-a: Displays hidden files and folders
-f: Does not sort the output, and enables -a
-g: Displays detailed view without user
-l: Displays detailed view
-r: Reverses the order of the output
-t: Sorts the output by modification time
-u: Sorts the output by access time, displays access time instead of modification time with -l present
```

## Example

```
./ft_ls -l
total 4
-rwxrwxrwx 1 jo jo    8 Apr  4 17:04 author
drwxrwxrwx 1 jo jo  512 Apr  4 17:04 inc
drwxrwxrwx 1 jo jo  512 Apr  4 17:05 libft
-rwxrwxrwx 1 jo jo 1658 Apr  4 17:04 Makefile
drwxrwxrwx 1 jo jo  512 Apr  4 17:04 src
```

## Norme

This project is coded in accordance with the school's norms. A full copy of the norm can be found [here](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf).
