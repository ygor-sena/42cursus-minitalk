<p align="center">
    <img src="https://user-images.githubusercontent.com/102881479/215282296-839ce5e6-5982-41f6-ba56-7e408f6ca9f8.png">
</p>
<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-blue.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

## Introduction

The purpose of this project is to code a small data exchange program using UNIX signals. Therefore, the communication program between a `client` and a `server` has to be done using **only** UNIX signals. Thus, it was allowed to use only two signals: `SIGUSR1` and `SIGUSR2`.

The `server` should be able to receive strings from several clients in a row without needing to restart. For the bonus project, the `server` also acknowlegdes every message received by sending back a signal to the `client` and supports Unicode characters.

## How to compile and run the project

#### 1) Copy this repository to your local workstation

```html
git clone git@github.com:ygor-sena/42cursus-minitalk.git
```

#### 2) Compile the project with Makefile

```html
make
```

#### 3) Open two instances of the command terminal and, in one of them, launch the `server` program

```html
./server
```

It will print something to the standard output, such as:

```html
Server PID is: 1084.
```

If you want to run the program looking for memory leaks, just start it as follows:

```html
valgrind --leak-check=full --show-leak-kinds=all ./server
```

#### 4) In the other terminal, launch the `client` program

It must receive the following three arguments: the executable program, the server PID and the text to be sent. For example:

```html
./client 1024 "This is an amazing but not so long sentence, minitalk!"
```

#### 5) Usage example

After completing the four steps above, the `server` will receive and print the message from `client`. After the message has been fully printed, the `server` will send a message back to the `client` signaling that data has been successfully received. The `client` will then show the following information:

```html
1084 server PID: data received.
```

To send another message to the `server`, the `client` program must be executed once again.

## References

- About Unicode characters:

  - [The Absolute Minimum Every Software Developer Absolutely, Positively Must Know About Unicode and Character Sets (No Excuses!)](https://www.joelonsoftware.com/2003/10/08/the-absolute-minimum-every-software-developer-absolutely-positively-must-know-about-unicode-and-character-sets-no-excuses/) by Joel Spolsky.
  - [Unicode in C and C++: What You Can Do About It Today](https://www.cprogramming.com/tutorial/unicode.html) by Jeff Bezanson.
  - [Unicode character table](https://unicode-table.com/en/) searcher to easily get Unicode characters.

- About signals:

  - [Introduction To Unix Signals Programming](https://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html) by [Kent State University](https://www.kent.edu/cs).
  - [signal handler sa_sigaction arguments](https://stackoverflow.com/questions/12587621/signal-handler-sa-sigaction-arguments) by StackOverflow.
  - [How can I translate from Decimal to binary and send it with sigusr 1-2?](https://stackoverflow.com/c/42network/questions/1919/1920#1920) by 42 Network StackOverflow.

- About bit shift manipulation (**this video is amazing!**):
  - [Bit Manipulation](https://www.youtube.com/watch?v=7jkIUgLC29I) by [Make School](https://www.youtube.com/@MakeSchoolCS).

- BRYANT, Randal; O'HALLARON, David. _Computer Systems: a programmer's perspective_. 3rd edition, 2016. 
  - Source code of the book examples: https://csapp.cs.cmu.edu/3e/code.html
