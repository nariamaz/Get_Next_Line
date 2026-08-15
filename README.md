# get_next_line

> A 42 School project — read a line from a file descriptor, one call at a time, no matter the buffer size.

## 📋 About

`get_next_line` implements a function that returns, on each call, the **next line** read from a given file descriptor — including the trailing `\n`, except on the last line of a file if it doesn't end with one.

The core constraint of the project: the underlying `read()` syscall doesn't know about lines — it just returns raw bytes in chunks of `BUFFER_SIZE`. This project's job is to buffer those chunks intelligently across multiple calls so a single line can be reconstructed even if it spans several `read()`s, while never reading more from the file than necessary.

This implementation includes the **bonus part**: a single `get_next_line` can correctly and independently handle **multiple file descriptors** interleaved in any order (e.g. reading a line from `fd_a`, then `fd_b`, then back to `fd_a`) without mixing or losing data between them.

## ⚙️ Function Prototype

```c
char *get_next_line(int fd);
```

| Parameter | Description |
|---|---|
| `fd` | File descriptor to read from |

**Return value:**
- The next line read, **including** the `\n` if present.
- `NULL` if there is nothing left to read, or an error occurred.

## 🔧 Compilation

The mandatory and bonus parts are compiled with different `BUFFER_SIZE` values to verify behavior at different chunk sizes. No `Makefile` is required by the subject, but here's how to compile manually:

```bash
# Mandatory part
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

# Bonus part (multiple file descriptors)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

`BUFFER_SIZE` is not hardcoded — it's passed via compiler flag (`-D BUFFER_SIZE=n`) and defaults to a fallback value in the header if not provided.

## 📁 File Structure

```
.
├── get_next_line.h
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line_bonus.c        (bonus)
├── get_next_line_utils_bonus.c  (bonus)
└── README.md
```

## 🧠 How It Works

1. **`get_next_line(fd)`** allocates a temporary read buffer (`buf_read`) and delegates to `ft_read_and_search`, passing a `static` cache slot dedicated to that `fd`.
2. **`ft_read_and_search`** loops on `read(fd, buf_read, BUFFER_SIZE)`, appending each chunk to the persistent per-fd cache (`ft_strjoin`) until either:
   - a `\n` is found (searched locally in the new chunk, then translated into a global index in the cache), or
   - `read()` returns `0` (EOF) — in which case any leftover content is flushed as a final line via `ft_flush_cache`, or
   - `read()` returns `< 0` (error) — the function returns `NULL` immediately.
3. **`ft_extract_line`** splits the cache in two using `ft_build_line` (the completed line, up to and including `\n`) and `ft_build_rest` (everything after, kept for the next call).
4. The cache persists **between calls** thanks to `static` storage, so a call to `get_next_line` picks up exactly where the previous one left off — even mid-buffer.

### Multi-fd support (bonus)

Instead of a single `static char *cache`, the bonus uses:

```c
static char *cache[MAX_FD];
```

Each file descriptor gets its own independent slot (`cache[fd]`), so reading from several file descriptors in any interleaved order never mixes their content. `MAX_FD` bounds the number of simultaneously trackable file descriptors and is checked before any array access.

## 🧪 Edge Cases Handled

- Empty files
- Files with no trailing `\n` on the last line
- `BUFFER_SIZE` of `1` (byte-by-byte reads)
- Very large `BUFFER_SIZE` (larger than the whole file)
- Invalid `fd` (negative, or closed mid-read)
- Multiple file descriptors read in interleaved order (bonus)
- Repeated calls after EOF (returns `NULL` without crashing or leaking)

## 🧹 Memory

Tested with Valgrind for both leaks and invalid access:

```bash
valgrind --leak-check=full --show-leak-kinds=all -s ./gnl
```

No memory is leaked across normal execution — the per-fd cache is only retained between calls as designed, and every `line` returned to the caller is expected to be `free()`'d by the caller once no longer needed.

## 📐 Norm

Written in strict compliance with the 42 **Norminette**: max 25 lines per function, max 4 parameters, no assignments in conditions, variables declared at the top of scope, no `for` loops, no ternaries.

## ✍️ Author

**[Your Name]** — [42 login] — [42 campus]
