# int open(const char *filename, int flags, mode_t mode);
[*filename]
	open("file.txt", ...)           // File in current directory
	open("/home/user/file.txt", ...)  // Absolute path
	open("../data/file.txt", ...)   // Relative path
[Flags]
	O_WRONLY | O_CREAT | O_TRUNC  (the | pipe means combine these options)
	: write-only AND create if missing AND empty if exists;
* first
	O_RDONLY  →  open for Read only   (can only read)
	O_WRONLY  →  open for Write only  (can only write)
	O_RDWR    →  open for Read+Write  (can read AND write)
* second
	O_CREAT  →  Create file if missing
* third
	O_TRUNC  →  Erase file contents (set size to 0)
[mode]
	XXXX
	||||
	||||_others'permission
	|||__groups'permission
	||___Owner'permission
	|____8 octal prefix(always 0)
	number meanings
	0 = --- (no permissions)
	1 = --x (execute)
	2 = -w- (write)
	3 = -wx (write + execute)
	4 = r-- (read)
	5 = r-x (read + execute)
	6 = rw- (read + write)
	7 = rwx (read + write + execute)
[[RETURN]]
	0 = STDIN  (Standard Input)   → Keyboard input
	1 = STDOUT (Standard Output)  → Screen output
	2 = STDERR (Standard Error)   → Error messages
	-1 if error

 # Tips:
 1. passing long int to a function expecting int will automatically convert it to int. So don't need to ft_putnbr_fd((int)(ln / 10), fd);

[strlcat] if the dest is defined by malloc, then it should be initialized (dest[0]='\0')

Type	    What it points to	 When to use
t_list *	a node	             just need to look at or walk through the list.
t_list **	a pointer to a node	 change the head pointer (e.g., add/remove at front, clear list)
