# Backdoor
> :warning: **Please note that this document is intended for educational purposes only. I do not endorse nor condone the use of this information for illegal activities, and I will not be held responsible for any such actions.s**

## Files
**attacker.c:** 
 
The attacker's program connects to the server through a TCP socket and waits for user input. The user input is sent to the server, which then executes the command and sends the output back to the client. The victim then prints the output to the console. 

**server.c:**

The server program listens for incoming connections from the client on a specified port. Once a connection is established, the server waits for commands from the client. When it receives a command, it executes the command and sends the output back to the client. 

## Usage

Change victim's ip in **attacker.c**:
```c
...
const char *IP = "";
...
```
Compile and run **victim.c** in victim's computer then compile and run **attacker.c** in attacker's computer.

**Please use these programs responsibly and do not use them for malicious purposes.*
