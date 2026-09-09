*This project has been created as part of the 42 curriculum by maridos-.*

# Get Next Line

> Reading a line from a file descriptor is way too tedious.

## Table of Contents
- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [Algorithm: Explanation & Justification](#algorithm-explanation--justification)
- [Bonus](#bonus)
- [Norm & Constraints Recap](#norm--constraints-recap)

## Description

`get_next_line` (GNL) is a 42 School project whose goal is to write a C function
that reads and returns, **one call at a time**, a single line from a file
descriptor — whether that descriptor points to a regular file, a pipe, or
standard input.

```c
char *get_next_line(int fd);
```

Repeated calls on the same `fd` progressively return the next line of the
underlying file, until there is nothing left to read, at which point the
function returns `NULL`.

Beyond producing an useful utility function, the project's real
purpose is to understand **static variables** in C: how to preserve state
between successive calls of a function without relying on global variables,
and how to manage the memory and read-buffer that this state requires.

Key constraints imposed by the subject:
- Only `read`, `malloc`, and `free` may be used.
- `lseek` and global variables are forbidden.
- `libft` may not be used in this project.
- The read buffer size is configurable at compile time via `-D BUFFER_SIZE=n`,
  and the function must behave correctly for any value of `n` (including `1`,
  `9999`, or `10000000`).
- The returned line includes the trailing `\n`, except when EOF is reached
  before a `\n` is found.

## Instructions

### Files

**Mandatory**

| File | Role |
|---|---|
| `get_next_line.h` | Header — function prototype and includes |
| `get_next_line.c` | Core logic of `get_next_line` |
| `get_next_line_utils.c` | Helper functions (string handling, memory helpers, etc.) |

**Bonus**

| File | Role |
|---|---|
| `get_next_line_bonus.h` | Header for the bonus (multiple fd) version |
| `get_next_line_bonus.c` | Core logic handling several file descriptors at once |
| `get_next_line_utils_bonus.c` | Helper functions for the bonus version |

### Compilation

No `Makefile` is required for this project — the subject compiles it
directly with `cc`, and that's how it's built here as well.

The project must compile with a `BUFFER_SIZE` value passed at compile time,
and must also compile fine *without* that flag (a default value is defined
in the header for that case).

```bash
# Mandatory part
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

# Bonus part (multiple file descriptors)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Usage example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int   fd;
    char  *line;

    fd = open("example.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Compile it together with the GNL sources, choosing any `BUFFER_SIZE`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=32 main.c get_next_line.c get_next_line_utils.c -o gnl_test
./gnl_test
```

## Resources

### Documentation & references

- `man 2 read`, `man 3 malloc`, `man 3 free`, `man 2 open`
- Static variables and storage duration — any standard C reference (e.g.
  K&R, *The C Programming Language*)
- The 42 Norm documentation (mandatory and bonus files are both norm-checked)

### AI usage disclosure

AI assistance was used only to help draft and format this `README.md`
according to the structure required by the subject. It was not used to
write, or generate the logic inside `get_next_line.c`,
`get_next_line_utils.c`, or the bonus files — that reasoning and code were
worked out independently.

## Algorithm: Explanation & Justification

The implementation follows the classic **"static leftover buffer"**
strategy, which satisfies the subject's requirement to read as little as
possible on each call, rather than reading the whole file upfront:

1. **Persistent state.** A `static char *buffer` (or, for the bonus, one
   stash per file descriptor) keeps whatever was already read from `fd` but
   not yet returned to the caller, across successive calls.

2. **Reading loop.** On each call, the function first checks whether the
   stash already contains a `\n`. If not, it repeatedly calls
   `read(fd, buffer, BUFFER_SIZE)`, appending each chunk to the stash, until
   either a `\n` is found, or `read` returns `0` (EOF) or `-1` (error).

3. **Extracting the line.** Once a `\n` is present (or EOF has been
   reached), the stash is split in two: the line to return (up to and
   including the `\n`, if present) and the remainder, which becomes the new
   stash for the next call.

4. **Termination.** When `read` returns `0` and the stash is empty, any
   remaining allocation is freed, the static variable is reset, and the
   function returns `NULL`.

5. **Multiple file descriptors (bonus).** A single static array (indexed by
   `fd`) or a static linked list keyed by `fd` lets several descriptors be
   read from in an interleaved fashion, without mixing up their respective
   states.

This approach was chosen because it:
- Minimises `read` syscalls — data already consumed is never re-read.
- Works correctly regardless of `BUFFER_SIZE`, since the stash simply grows
  or shrinks as needed.
- Never needs `lseek`: the file position only ever advances via `read`.
- Keeps the state footprint to a single static variable (or a single static
  structure for the bonus), which is what the norm and the bonus
  requirement demand.

## Bonus

This project includes the bonus implementation. The bonus version:
- Manages **multiple file descriptors at once** (e.g. fd 3, 4, 5), reading
  from a different one on each call without losing or mixing the reading
  state of any of them.
- Relies on **a single static variable** overall.

Build it with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

> Per the subject, the bonus is only assessed once the mandatory part is
> fully functional.

## Norm & Constraints Recap

- Written in C, Norm-compliant (mandatory and bonus files alike).
- No crashes (segfault, bus error, double free) outside of explicitly
  documented undefined behavior.
- No memory leaks.
- Allowed functions only: `read`, `malloc`, `free`.
- Forbidden: `lseek`, global variables, `libft`.
- Compiles both with and without the `-D BUFFER_SIZE=n` flag.
