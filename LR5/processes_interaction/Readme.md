## _Processes interaction with shared memory via semaphores_

### Description:

_One program [Process 1] (`main`) creates some semaphore and shared memory block. Writes some data to this shared memory
block. Then
blocks "permission" with semaphore and launches the second
program [Process 2] (`compute_data_from_shared_memory`). [Process 2] is waiting until the permissions in semaphore is
unlocked. Then reads data from shared memory (reads string) and transforms it in some way and finished
executing. [Process 1] waits till the [Process 2] finished executing and then reads transformed data from shared memory_
____

### _To run:_

`make run`  
or  
`make`  + `./make_app`  
&nbsp;  
_// pay attention that in [./shared/shared.hpp](./shared/shared.hpp) there are keys for semaphore and shared memory. So
for shared memory id there must be a file with the same name near compiled executable file. For example, I have
id `shared-memory-file-id` - so I need to have `shared-memory-file-id` file (with no extension, just empty file)_
___
##### _One of useful links to theory that helps to implement such type of lab:_  
[https://www.sensi.org/~alec/x/x-1-7-3-3.html](https://www.sensi.org/~alec/x/x-1-7-3-3.html)  
___

###### Copyright © 2023 April | All rights reserved