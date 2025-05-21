# File Handling and Graphics in C

## Syllabus
- Introduction to using files in C
- Declaration of file pointer
- Opening, closing, and flushing files
- Working with text files
- Character input and output
- End of File (EOF)
- Working with binary files
- Direct file input and output
- Sequential vs. random file access
- Files of records
- Working with files of records
- Random access to files of records
- Other file management functions (deleting and renaming files)
- Low-level I/O
- Creating header files in C
- Working with C graphics functions

## 1. Introduction to Files in C
A file is a collection of data stored in secondary memory (e.g., disk). Files store both data and programs, allowing persistence beyond program execution. To work with files in C, you need to understand file input and output operations—how to read from and write to files.

A **stream** is a logical interface to a file or device in C. There are two types of streams:
- **Text Stream**: A sequence of characters processed sequentially in the forward direction.
- **Binary Stream**: Stores data in binary format, often used for numerical or non-text data.

## 2. Using Files in C
To use a file, four essential actions are required:
1. Declare a file pointer variable.
2. Open the file using `fopen()`.
3. Process the file using appropriate functions.
4. Close the file using `fclose()` and optionally flush buffers with `fflush()`.

### 2.1 Declaration of File Pointer
A file pointer is a variable that points to a `FILE` structure, used for file operations. The programmer does not need to interact with the structure's members directly.

**Syntax:**
```c
FILE *file_pointer_name;
```
**Example:**
```c
FILE *fp;
```

### 2.2 Opening a File
The `fopen()` function opens a file and associates it with a stream.

**Syntax:**
```c
FILE *fopen(const char *fname, const char *mode);
```
- `fname`: The file path (e.g., `D:\\501\\example.txt` where `D:` is the drive, `501` is the directory, and `example.txt` is the file name).
- `mode`: Specifies the mode in which the file is opened (see table below).

**File Opening Modes:**
| Mode  | Description |
|-------|-------------|
| `r`   | Opens a text file for reading. |
| `w`   | Opens or creates a text file for writing (overwrites existing content). |
| `a`   | Opens a text file for appending (adds to the end). |
| `r+`  | Opens a text file for both reading and writing. |
| `w+`  | Opens or creates a text file for both reading and writing (overwrites existing content). |
| `a+`  | Opens a text file for reading and appending. |
| `rb`  | Opens a binary file for reading. |
| `wb`  | Opens or creates a binary file for writing (overwrites existing content). |
| `ab`  | Opens a binary file for appending. |
| `rb+` | Opens a binary file for both reading and writing. |
| `wb+` | Opens or creates a binary file for both reading and writing (overwrites existing content). |
| `ab+` | Opens a binary file for reading and appending. |

**Difference Between Write (`w`) and Append (`a`) Modes:**
- **Write (`w`)**: Overwrites the file if it exists; creates a new file if it doesn't.
- **Append (`a`)**: Adds data to the end of the file without overwriting existing content; creates a new file if it doesn't exist.

### 2.3 Closing and Flushing Files
- **Closing**: Use `fclose()` to close a file and release resources.
  **Prototype:**
  ```c
  int fclose(FILE *fp);
  ```
  - Returns `0` on success, `-1` on error.

- **Flushing**: Use `fflush()` to write the file's buffer to disk without closing it.
  **Prototypes:**
  ```c
  int fflush(FILE *fp);
  int flushall(void); // Flushes buffers of all open streams
  ```

**Example: Check if a File Exists**
```c
#include <stdio.h>
#include <conio.h>
void main() {
    FILE *fp;
    char x[100]; // Corrected: Increased buffer size for safety
    clrscr();
    printf("Enter the file name: ");
    gets(x); // Note: gets() is deprecated; consider fgets() in modern C
    fp = fopen(x, "r");
    if (fp == NULL) {
        printf("The file ---%s--- is not found in the present directory\n", x);
    } else {
        printf("The file ---%s--- is found in the present directory\n", x);
        fclose(fp);
    }
    getch();
}
```

**Correction**: Replaced `char *x` with `char x[100]` to allocate memory for the file name. Noted that `gets()` is deprecated and should be replaced with `fgets()` in modern C for safety.

## 3. Character Input/Output
Two functions, `getc()` and `putc()`, are used for character-level file operations.

**Prototypes:**
```c
int getc(FILE *file_pointer);
int putc(int c, FILE *file_pointer); // Corrected: putc takes an int, not const char
```

### 3.1 Detecting End of File (EOF)
EOF is a symbolic constant defined in `stdio.h` as `-1`, indicating the end of a file.

**Example Check for EOF:**
```c
while ((c = getc(fp)) != EOF) {
    // Process character
}
```

**Example: Write a String to a Text File**
```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
void main() {
    FILE *fp;
    char text[80];
    int i;
    clrscr();
    fp = fopen("Sample.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    printf("Enter the text: ");
    gets(text); // Note: Replace with fgets() in modern C
    for (i = 0; i < strlen(text); i++) {
        putc(text[i], fp);
    }
    printf("The string copied into a text file\n");
    fclose(fp);
    getch();
}
```

**Correction**: Added error checking for `fopen()` and a return statement for failure. Noted `gets()` deprecation.

## 4. Working with Text Files
C provides functions for reading and writing text files:
- Reading: `fscanf()`, `fgets()`, `fgetc()`, `fread()`
- Writing: `fprintf()`, `fputs()`, `fputc()`, `fwrite()`

**Prototypes:**
```c
int fscanf(FILE *stream, const char *format, ...);
int fgetc(FILE *stream);
char *fgets(char *str, int n, FILE *stream);
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
int fprintf(FILE *stream, const char *format, ...);
int fputc(int c, FILE *stream);
int fputs(const char *str, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
```

**Example: Write a String Using `fputs()`**
```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
void main() {
    FILE *fp;
    char text[80];
    clrscr();
    fp = fopen("Sample.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    printf("Enter the text: ");
    gets(text); // Note: Replace with fgets()
    fputs(text, fp);
    printf("The string copied into a text file\n");
    fclose(fp);
    getch();
}
```

**Example: Copy One File to Another**
```c
#include <stdio.h>
#include <conio.h>
void main() {
    FILE *fp, *fp1;
    int ch;
    clrscr();
    fp = fopen("ex_file4.c", "r");
    fp1 = fopen("ex_file2.c", "w");
    if (fp == NULL || fp1 == NULL) {
        printf("File is not available\n");
        return;
    }
    while ((ch = getc(fp)) != EOF) {
        putc(ch, fp1);
    }
    fclose(fp);
    fclose(fp1);
    getch();
}
```

**Correction**: Added error checking for both file pointers.

**Example: Display File Content**
```c
#include <stdio.h>
#include <conio.h>
void main() {
    FILE *fp;
    int ch;
    clrscr();
    fp = fopen("ex_file4.c", "r");
    if (fp == NULL) {
        printf("File is not available\n");
        return;
    }
    while ((ch = getc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
    getch();
}
```

**Example: Read/Write Using `fprintf()` and `fscanf()`**
```c
#include <stdio.h>
#include <conio.h>
void main() {
    FILE *fptr;
    char name[20];
    int age;
    float salary;
    clrscr();
    fptr = fopen("abc.txt", "w");
    if (fptr == NULL) {
        printf("File does not exist\n");
        return;
    }
    printf("Enter the name: ");
    scanf("%s", name);
    fprintf(fptr, "Name = %s\n", name);
    printf("Enter the age: ");
    scanf("%d", &age);
    fprintf(fptr, "Age = %d\n", age);
    printf("Enter the salary: ");
    scanf("%f", &salary);
    fprintf(fptr, "Salary = %f\n", salary);
    fclose(fptr);
    getch();
}
```

**Correction**: Fixed formatting (`\n` instead of `$\ln$`) and ensured proper error handling.

## 5. Working with Binary Files
Binary files store large numerical data and are opened in modes like `rb`, `wb`, or `ab`. The process to copy a binary file includes:
1. Open the source file in binary read mode (`rb`).
2. Open the destination file in binary write mode (`wb`).
3. Read a character from the source file.
4. Check for EOF using `feof()`.
5. Write the character to the destination file if not at EOF.
6. Repeat from step 3 until EOF is reached.
7. Close both files.

**Example: Copy a Binary File**
```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
void main() {
    FILE *fp, *fp1;
    char s[100], s1[100];
    int ch;
    clrscr();
    printf("Enter the source file: ");
    gets(s); // Note: Replace with fgets()
    printf("Enter the destination file: ");
    gets(s1);
    fp = fopen(s, "rb");
    fp1 = fopen(s1, "wb");
    if (fp == NULL || fp1 == NULL) {
        printf("Error opening files\n");
        return;
    }
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch, fp1);
    }
    fclose(fp);
    fclose(fp1);
    getch();
}
```

**Correction**: Added error checking for file opening and used `fgetc()` consistently.

## 6. Direct File Input and Output
Direct I/O involves reading/writing blocks of data to/from binary files using `fread()` and `fwrite()`.

**Example: Write to a Binary File**
```c
#include <stdio.h>
#include <string.h>
void main() {
    const char *mytext = "The quick brown fox jumps over the lazy dog";
    FILE *bfp = fopen("test.txt", "wb");
    if (bfp) {
        fwrite(mytext, sizeof(char), strlen(mytext), bfp);
        fclose(bfp);
    }
}
```

### 6.1 Sequential vs. Random File Access
- **Sequential Access**: Processes data in order, suitable for tasks like counting words in a text file.
- **Random Access**: Accesses specific positions directly, useful for structured data (e.g., records). A hybrid approach may combine sequential and random access, similar to a File Allocation Table (FAT).

Every file has a **file position indicator**:
- New files: Starts at position 0.
- Existing files: Starts at 0 for most modes, or at the end for append mode.

## 7. Files of Records
Binary files can store fixed-length records using a `struct` data type. Records are written sequentially or accessed randomly.

### 7.1 Working with Files of Records
**Example: Append, Modify, and Display Records**
```c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct item {
    int itemcode;
    char name[30];
    double price;
};
void append();
void modify();
void dispall();
void dele();
int main() {
    int ch;
    struct item it;
    FILE *fp;
    fp = fopen("item.dat", "w");
    if (fp == NULL) {
        printf("Error in opening the file...\n");
        return 1;
    }
    printf("Enter the ITEM code: ");
    scanf("%d", &it.itemcode);
    printf("Enter the ITEM name: ");
    scanf("%s", it.name); // Corrected: Removed & as name is already a pointer
    printf("Enter the price: ");
    scanf("%lf", &it.price);
    fprintf(fp, "%d\t%s\t%lf\n", it.itemcode, it.name, it.price);
    fprintf(fp, "%d", 0); // Sentinel value
    fclose(fp);
    while (1) {
        printf("\n1. Append records...\n");
        printf("2. Display all the records...\n");
        printf("3. Edit the records...\n");
        printf("4. Delete the records...\n");
        printf("5. Exit...\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: append(); break;
            case 2: dispall(); break;
            case 3: modify(); break;
            case 4: dele(); break;
            case 5: exit(0);
        }
    }
}
void append() {
    FILE *fp;
    struct item it;
    fp = fopen("item.dat", "a"); // Corrected: Use append mode
    if (fp == NULL) {
        printf("Error in opening a file...\n");
        return;
    }
    printf("Enter the ITEM code: ");
    scanf("%d", &it.itemcode);
    printf("Enter the ITEM name: ");
    scanf("%s", it.name);
    printf("Enter the price: ");
    scanf("%lf", &it.price);
    fprintf(fp, "%d\t%s\t%lf\n", it.itemcode, it.name, it.price);
    fclose(fp);
}
void dispall() {
    FILE *fp;
    struct item it;
    fp = fopen("item.dat", "r");
    if (fp == NULL) {
        printf("Error in opening a file...\n");
        return;
    }
    while (fscanf(fp, "%d", &it.itemcode), it.itemcode != 0) {
        fscanf(fp, "%s%lf", it.name, &it.price);
        printf("%d\t%s\t%lf\n", it.itemcode, it.name, it.price);
    }
    fclose(fp);
}
void modify() {
    FILE *fp, *fptr;
    struct item it;
    int icd, found = 0;
    fp = fopen("item.dat", "r");
    fptr = fopen("temp.dat", "w");
    if (fp == NULL || fptr == NULL) {
        printf("Error in opening a file\n");
        return;
    }
    printf("Enter the Item code to edit: ");
    scanf("%d", &icd);
    while (fscanf(fp, "%d", &it.itemcode), it.itemcode != 0) {
        fscanf(fp, "%s%lf", it.name, &it.price);
        if (it.itemcode == icd) {
            found = 1;
            printf("Existing record is: %d\t%s\t%lf\n", it.itemcode, it.name, it.price);
            printf("Enter the new ITEM name: ");
            scanf("%s", it.name);
            printf("Enter the new item price: ");
            scanf("%lf", &it.price);
        }
        fprintf(fptr, "%d\t%s\t%lf\n", it.itemcode, it.name, it.price);
    }
    fprintf(fptr, "%d", 0);
    fclose(fptr);
    fclose(fp);
    remove("item.dat");
    rename("temp.dat", "item.dat");
    if (!found) printf("Item not found\n");
}
void dele() {
    FILE *fp, *fptr;
    struct item it;
    int icd, found = 0;
    fp = fopen("item.dat", "r");
    fptr = fopen("temp.dat", "w");
    if (fp == NULL || fptr == NULL) {
        printf("Error in opening a file\n");
        return;
    }
    printf("Enter the Item code to delete: ");
    scanf("%d", &icd);
    while (fscanf(fp, "%d", &it.itemcode), it.itemcode != 0) {
        fscanf(fp, "%s%lf", it.name, &it.price);
        if (it.itemcode != icd) {
            fprintf(fptr, "%d\t%s\t%lf\n", it.itemcode, it.name, it.price);
        } else {
            found = 1;
        }
    }
    fprintf(fptr, "%d", 0);
    fclose(fptr);
    fclose(fp);
    remove("item.dat");
    rename("temp.dat", "item.dat");
    if (!found) printf("Item not found\n");
}
```

**Corrections**:
- Changed `scanf("%s", &it.name)` to `scanf("%s", it.name)` as `name` is already an array.
- Used append mode (`"a"`) in `append()` function.
- Added error handling and file renaming in `modify()` and `dele()`.
- Simplified `fscanf` in loops to avoid syntax errors.

## 8. Random Access to Files of Records
Functions for random access:
1. **fseek()**: Sets the file position indicator.
   **Prototype:**
   ```c
   int fseek(FILE *fp, long offset, int origin);
   ```
   - Origins: `SEEK_SET` (start), `SEEK_CUR` (current position), `SEEK_END` (end).
2. **ftell()**: Returns the current file position.
   **Prototype:**
   ```c
   long ftell(FILE *fp);
   ```
3. **rewind()**: Sets the file position to the beginning.
   **Prototype:**
   ```c
   void rewind(FILE *fp);
   ```

**Example: Copy File Using `fseek()`**
```c
#include <stdio.h>
#include <conio.h>
void main() {
    FILE *fp1, *fp2;
    char ch;
    long pos;
    clrscr();
    fp1 = fopen("File_1.txt", "r");
    if (fp1 == NULL) {
        printf("File cannot be opened\n");
        return;
    }
    fp2 = fopen("File_2.txt", "w");
    if (fp2 == NULL) {
        printf("Error opening destination file\n");
        fclose(fp1);
        return;
    }
    fseek(fp1, 0L, SEEK_END);
    pos = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET);
    while (pos--) {
        ch = fgetc(fp1);
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    getch();
}
```

**Correction**: Fixed incomplete code and ensured proper file closing.

## 9. Other File Management Functions
### 9.1 Deleting a File
**Prototype:**
```c
int remove(const char *filename);
```

**Example:**
```c
#include <stdio.h>
#include <conio.h>
int main() {
    char file[80];
    printf("File to delete: ");
    gets(file); // Note: Replace with fgets()
    if (remove(file) == 0) {
        printf("Removed %s\n", file);
    } else {
        printf("File cannot be removed\n");
    }
    getch();
    return 0;
}
```

### 9.2 Renaming a File
**Prototype:**
```c
int rename(const char *oldname, const char *newname);
```

## 10. Low-Level I/O
Low-level I/O is unbuffered, accessing the disk directly. It uses file handles (integers) instead of file pointers.

**Functions:**
```c
int open(const char *filename, int flag, int perms);
int creat(const char *filename, int perms);
int close(int handle);
```

## 11. Creating Header Files in C
Steps to create a header file:
1. Define functions with a header and body.
2. Save the file with a `.h` extension (e.g., `myhead.h`).
3. Include the header in the main program using `#include "myhead.h"`.

**Example Header File (`myhead.h`):**
```c
int add(int a, int b) {
    return a + b;
}
```

**Example Main Program:**
```c
#include <stdio.h>
#include "myhead.h"
void main() {
    int num1 = 10, num2 = 20, num3;
    num3 = add(num1, num2);
    printf("Sum of two numbers is: %d\n", num3);
}
```

**Note**: The header file and program must be in the same directory.

## 12. Working with C Graphics
Graphics in C are supported via the `graphics.h` library, primarily for 16-bit MS-DOS environments with a 640x480 VGA monitor.

### 12.1 Graphics Mode Initialization
Use `initgraph()` to initialize graphics mode.

**Prototype:**
```c
void initgraph(int *graphdriver, int *graphmode, char *pathtodriver);
```
- `graphdriver`: Specifies the driver (e.g., `DETECT` for auto-detection).
- `graphmode`: Specifies the graphics mode (e.g., highest resolution for the driver).
- `pathtodriver`: Path to `.BGI` driver files (e.g., `C:\\TC\\BGI`).

**Example: Draw Shapes and Text**
```c
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int main() {
    int gd = DETECT, gm;
    int left = 100, top = 100, right = 200, bottom = 200;
    int x = 300, y = 150, radius = 50;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    rectangle(left, top, right, bottom);
    circle(x, y, radius);
    bar(left + 300, top, right + 300, bottom);
    line(left - 10, top + 150, left + 410, top + 150);
    ellipse(x, y + 200, 0, 360, 100, 50);
    outtextxy(left + 100, top + 325, "My First C Graphics Program");
    getch();
    closegraph();
    return 0;
}
```

**Correction**: Changed `main()` to `int main()` and added `return 0` for standard compliance.
