<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->

- [CImSpinner](#cimspinner)
  - [Notice](#notice)
  - [Prerequisites](#prerequisites)
  - [Build and run demo](#build-and-run-demo)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## CImSpinner

![alt](https://github.com/dinau/cimspinner/actions/workflows/windows.yml/badge.svg)
![alt](https://github.com/dinau/cimspinner/actions/workflows/linux.yml/badge.svg) 

Amazing [ImSpinner](https://github.com/dalerank/imspinner) !  
CImSpinner is C language bindings for ImSpinner.

![alt](img/cimspinner.gif)

### Notice

---

Now highly work in progress.



### Prerequisites

---

- Windows10 or later  
[MSys2/MinGW](https://www.msys2.org/) command line tools (Unix tools), make, gcc, g++, cp, rm, git, ...etc
- Linux : Debian / Ubuntu family  

  ```sh
  $ sudo apt install gcc g++ make git 
  $ sudo apt install xorg-dev lib{opengl-dev,gl1-mesa-dev,glfw3,glfw3-dev,libsdl2-dev}
  ```

### Build and run demo

---

```sh
git clone --recursive https://github.com/dinau/cimspinner
```

- Run C language simple demo

   ```sh
   cd demo/c
   make run
   ```

- Run C++ language demo  
This is original [ImSpinner](https://github.com/dalerank/imspinner)  demo.

   ```sh
   cd demo/cpp
   make run
   ```
