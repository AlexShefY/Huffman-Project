# Huffman-Project
Simple tool on C++ for encoding/decoding text using Huffman algorithm

**Build**

first, go to the hw-02_huffman directory

run cmake to build program

**Run**

Program hw-02_huffman performs compression and decompression with the two-pass Huffman algorithm. There are also some test for program, which is wrote using doctest. 

The program starts with the flags: 

```
./hw-02_huffman [flags]
```
Where flag:
* `-c`: compression,
* `-u`: decompression,
* `-f <path>`, `--file <path>`: name of the input file,
* `-o <path>`, `--output <путь>`: name of the output file.
Flags can be specified in any order.

