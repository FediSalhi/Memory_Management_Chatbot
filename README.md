# Memory Management Chatbot

This is a wxWidgets based Chatbot that provides information related to C++ memory management topics. The ChatBot creates a dialogue where users can ask questions about some aspects of memory management in C++. After the knowledge base of the chatbot has been loaded from a text file, a knowledge graph representation is created in computer memory, where chatbot answers represent the graph nodes and user queries represent the graph edges. After a user query has been sent to the chatbot, the Levenshtein distance is used to identify the most probable answer.

The project was built for the Udacity C++ Nano Degree program third course as an application of modern C++ memory management techniques, such as:
- Resource Acquisition Is Initialization pattern
- Move semantics
- Smart pointers ...


<img src="images/chatbot_demo.gif"/>

## Dependencies (Linux)
1. Cmake and GCC:
```
    sudo apt update
    sudo apt install build-essential
    sudo apt install cmake
```

2. wxWidgets >= 3.0 Library
```
sudo apt-get install libwxgtk3.0-gtk3-dev libwxgtk3.0-gtk3-0v5
```
If you are facing unmet dependency issues, refer to the [official page](https://wiki.codelite.org/pmwiki.php/Main/WxWidgets30Binaries#toc2) for installing the unmet dependencies.


## Compiling
To compile the project, first, create a `build` directory and change to that directory:
```
    mkdir build && cd build
```
From within the `build` directory, run `cmake` and `make` as follows:
```
    cmake ..
    make
```

## Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
    ./membot
```

## Test
Run the Gtest unit tests using:
```
    ./TestRunner
```

## Authors

* **Fedi Salhi** [FediSalhi](https://www.linkedin.com/in/fedisalhi/)