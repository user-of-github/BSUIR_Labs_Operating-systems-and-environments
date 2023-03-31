### _It is an additional task, given me by teacher_

_Previously in this (4th) Lab I've implemented 2 variants (`censorship-filter` and `errors-checker`).   
So here the purpose is to
create __static library__ from one of these variants and create __shared (dynamic) library__ from another one.
And then __link (combine)__ them here and use in this project_

____

### _To combine libs in this app:_

_**1.** You firstly need to build static (`.a`) lib of `errors-checker` project and copy it
 for example (as I did)  to  `./external_libs/static` [folder](./external_libs/static)._  
_**2.** Also copy all necessary headers of `errors-checker` lib from that project to here (for example, as I did,
to [./external_libs/static/include](./external_libs/static/include))_  
_**3.** Build shared library of `replace_words` (it is `censorship-filter`) project and make it globally available_  
_**4.** Copy headers from `replace_words` (`censorship-filter`) project to here (for example, as I did,
to [./external_libs/shared_include](./external_libs/shared_include))_  
_**5.** Write some code using functionality from static and shared libs in `main.cpp`. Of course include necessary
headers from `./external_libs/static/include` and `./external_libs/shared_include)`_    
_**6.** __Ensure that necessary source text files are present___  
_**7.** Run from this (root) folder `make` (and fix paths in [./Makefile](./Makefile), if you copied static lib and header not to folders from description above)_  
_**8.** Launch the compiled app `./program`_  

&nbsp;  
____

###### Copyright © 2023 March | All rights reserved