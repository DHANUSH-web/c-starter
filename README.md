# C Starter

This repository contains starter code and resources for C programming. It is designed to help beginners get started with writing and understanding C programs.

## Features

- Basic C program structure
- Examples of common C programming concepts
- Instructions for compiling and running C programs

## Getting Started
1. Clone the repository:
    ```bash
    git clone https://github.com/DHANUSH-web/c-starter.git
    ```
2. Navigate to the project directory:
    ```bash
    cd c-starter
    ```
3. Build the project using the provided script:
    ```bash
    # For only building
    ./build build           # builds in debug by default [RECOMMENDED]
    ./build build --debug   # builds in debug preset
    ./build build --release # builds in release preset
    ./build build --all     # builds both debug and release preset
    # For build and run
    ./build run             # runs in debug by default [RECOMMENDED]
    ./build run --debug     # runs in debug preset
    ./build run --release   # runs in release preset
    ```
   This will:
   - Create a build directory
   - Configure CMake with the default preset
   - Build the project
   - Runs the executable
4. Clean the project
    ```bash
    ./build clean           # cleans the entire build [RECOMMENDED]
    ./build clean --debug   # cleans only debug build
    ./build clean --release # cleans only release build
    ```

Note: You can also use specific CMake presets:
```bash
cmake --preset debug    # For debug build
cmake --preset release  # For release build
```

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests to improve this repository.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.