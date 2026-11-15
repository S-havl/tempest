# TEMPEST

![100% Human Code](https://img.shields.io/badge/Code-100%25_Human-9D4EDD?style=flat-square&labelColor=000000)
![Zero Vibe Coding](https://img.shields.io/badge/Vibe_Coding-Zero-9D4EDD?style=flat-square&labelColor=000000)
![100% Human Code](https://img.shields.io/badge/Engineering-Deliberate-9D4EDD?style=flat-square&labelColor=000000)
![Zero Vibe Coding](https://img.shields.io/badge/AI_Assistance-None-9D4EDD?style=flat-square&labelColor=000000)

TEMPEST is a framework for covert physical exfiltration and microarchitectural side-channel attacks on air-gapped computers (Under development).

The core focus of this project is the research and comprehension of computer microarchitecture, exploring how it can be leveraged and manipulated to meet custom requirements—essentially forcing the hardware to perform tasks for which it was never originally designed.

The primary objective of this development is to achieve data exfiltration through the coordinated use of RAM and CPU microarchitecture, transmitting signals toward a radio or external receiving device capable of decoding them.

>[!WARNING]
> This project is built purely for research and understanding of the employed techniques; improper use could cause severe damage and is strictly illegal. It is planned to evolve into a utilitarian tool in the future, removing the exclusive "research-only project" label.

## Output Example
```
CPU affinity activation successful: core 7
Hello World
========== Timer Results ==========
Previous time calculation: 12975442465854

Subsequent time calculation:
Counter value = 12975442486248
TSC AUX Value = 7

Result diference = 20394
=================================================================================================
========== Cache Bypass Results  ==========
Cache bypass completed successfully. Value read from RAM: 50
```

## Key Features
- CPU affinity binding to lock the process to a single core, optimizing calculation precision.
- Implementation of key microarchitectural instructions to drive the research and execute the technique.
- Capability to test algorithms oriented toward optimization, performance analysis, and profiling.
- Clear, ergonomic data output designed for post-processing and analysis.

## Project Architecture
```
.
├── arch/               # Architecture-specific source code
├── include/            # Implementation of all auxiliary functions
├── src/                # Project source code and calculation benchmarks
├── LICENSE             # Project license
├── Makefile            # Project build automation
└── README.md           # Project documentation
```

## Prerequisites & Dependencies
- Linux-based computer (Windows is not supported)
- gcc
- make

## Build & Run
```
git clone https://github.com/S-havl/tempest.git
cd tempest
make clean && make
make run
```

>[!IMPORTANT]
> The project requires prior execution of the microarchitectural test routines; upon running, the program output will reflect the results of these tests.

# License

GNU General Public License v3.0
