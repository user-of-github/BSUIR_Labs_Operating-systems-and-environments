### _Just to run_  
_from this (`project root`) folder_  
_Ensure that necessary source text files are present_   
`make`  
`./text_converter`

### _To build dynamic (shared) lib and make it global in your Linux system:_  
#### _Demonstrated in `libs_combination` project (also in LR4)_
`cd lib`  
`chmod u+rx get_shared_library.sh`  _// just to make this script executable directly in linux; (Or you may run it via `bash get_shared_library.sh`)_   
`./get_shared_library.sh`


#### _Used:_  
* _C++ 17_  
* _Makefile_
* _CMake_
* _STL_