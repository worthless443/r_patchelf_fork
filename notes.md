## How to read ELF binaries

There are standards

### The standard  
Even though the size of sections and the corrosponding data associated with each section and therefore the dynamic size of ELF header structs are variable, it is relative to some constants that is standard to the ELF framework, and is calucated based on those contansts (for example, the offsets that enclose chucks of meaningful data). 

While sections can be rearranged or relocated while retaining the same information format as before, it can not be scalarly reversed and be expected to retain meaningful format. 

Bytes can be calculated using the ELF headers
