/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Data Desk

Author  : Ryan Fleury
Updated : 5 December 2019
License : MIT, at end of file.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#define _Assert(c, crash) if(!(c)) { _AssertFailure(#c, __LINE__, __FILE__, crash); }
#define Assert(c) _Assert(c, 1)
#define SoftAssert(c) _Assert(c, 0)

static void
_AssertFailure(char *condition, int line, char *file, int crash)
{
    fprintf(stderr, "ASSERTION FAILURE: %s at %s:%i\n", condition, file, line);
    if(crash)
    {
        *(volatile int *)0 = 0;
    }
}

static int global_log_enabled = 0;
#define Log(...) if(global_log_enabled) { fprintf(stdout, __VA_ARGS__); fprintf(stdout, "\n"); }
#define LogError(...) do { fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n"); } while(0);

/*
Copyright 2019 Ryan Fleury

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/