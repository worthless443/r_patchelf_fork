## How to read ELF binaries

There are standards

### The standard  
Even though the size of sections and the corrosponding data associated with each section and therefore the dynamic size of ELF header structs are variable, it is relative to some constants that is standard to the ELF framework, and is calucated based on those contansts (for example, the offsets that enclose chucks of meaningful data).
[Citing](https://linker.iecc.com/code.html): 
> interesting segments are .text, .data, and .bss. In the output file, text starts at hex 1000, data starts at the next multiple of 1000 after the text, and bss starts on a 4 byte boundary after the data

The meaningful contents which are raw bytes are found always aligned to each specific size according to the machine specification. And the alignment presists even after linkage and relocation.

While sections can be rearranged or relocated while retaining the same information format as before, it can not be scalarly reversed and be expected to retain meaningful format. 

Bytes can be calculated using the ELF headers

For more details, consult the ELF manual.
