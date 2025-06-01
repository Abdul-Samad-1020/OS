# 💻 Operating Systems Lab Codes (C Language)

This repository contains C programs and examples covering key Operating System concepts, designed for lab exams, assignments, and interviews. Each program demonstrates real system-level features using Linux system calls, process management, threading, scheduling, synchronization, and memory management.

---

## 📁 Contents

### 1. System Calls (File Handling)
- `open()`, `read()`, `write()`, `close()`, `lseek()`
- `wait()` and `fork()` (process management)

### 2. Process and Thread Management
- Creating child processes using `fork()`
- Creating threads using `pthread_create()`
- Difference between process and thread behavior

### 3. Orphan and Zombie Processes
- Program to demonstrate orphan process
- Program to simulate zombie process

### 4. Synchronization
- Semaphore-based synchronization using `sem_t`
- Critical section protection with semaphores

### 5. CPU Scheduling Algorithms
- First-Come First-Served (FCFS)
- Round Robin (RR)
- Shortest Job First (SJF) [TODO]
- Priority Scheduling [TODO]

### 6. Paging Algorithms
- FIFO (First-In-First-Out) Page Replacement
- [LRU, Optimal Paging - Coming Soon]

---

## 🚀 Getting Started

### Prerequisites
- GCC compiler (`sudo apt install build-essential`)
- POSIX threads (`-lpthread`)
- Linux/Unix-based environment

### Compilation
Use `gcc` to compile individual files. Examples:

```bash
gcc file_handling.c -o file_handling
./file_handling

gcc fork_wait.c -o fork_wait
./fork_wait

gcc threading.c -o threading -lpthread
./threading
