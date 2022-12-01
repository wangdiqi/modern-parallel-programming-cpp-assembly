# Apress Source Code

This repository accompanies [*Modern Parallel Programming with C++ and Assembly Language*](https://link.springer.com/book/10.1007/978-1-4842-7918-2) by Daniel Kusswurm (Apress, 2022).

[comment]: #cover
![Cover image](978-1-4842-7917-5.jpg)

Download the files as a zip using the green button, or clone the repository to your machine using Git.

## Releases

Release v1.0 corresponds to the code in the published book, without corrections or updates.

## Contributions

See the file Contributing.md for more information on how you can contribute to this repository.

## Convention

| File Name Suffix | Description                             |
|------------------|-----------------------------------------|
| .h               | Standard C++ header file                |
| .cpp             | Standard C++ source code file           |
| _fcpp.cpp        | C++ algorithm code (non-SIMD and SIMD)  |
| _misc.cpp        | Miscellaneous C++ functions             |
| _bm.cpp          | Benchmarking code                       |
| _fasm.asm        | Assembly language algorithm code (SIMD) |


| Function Name Suffix | Description                                               |
|----------------------|-----------------------------------------------------------|
| _Cpp (or no suffix)  | Function that uses standard C++ statements                |
| _Iavx                | Function that uses C++ AVX intrinsic functions            |
| _Iavx2               | Function that uses C++ AVX2 intrinsic functions           |
| _Iavx512             | Function that uses C++ AVX-512 intrinsic functions        |
| _Aavx                | Function that uses AVX assembly language instructions     |
| _Aavx2               | Function that uses AVX2 assembly language instructions    |
| _Avx512              | Function that uses AVX-512 assembly language instructions |


## FAQ

SignExtend16
ZeroExtend16
