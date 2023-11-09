# Gregorian calendar (static) HTML (page) generator

An exercise for a coding interview.

## Building

To build the code, just:

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

And the executable will be under `/bin`, with the name `gchg_app`.

If you configure CMake with `-DGCHG_DEVELOPER_MODE=ON`, tests will also be
generated.

You can create a `zip`/`tgz` with the executable using CPack, just like so:

```sh
cpack
```

## Executing

You can run the app with either positional arguments or named arguments.

```txt
>.\gchg_app.exe

Usage:
  gchg [OPTION...] <file-name> <year>

  -f, --file-name arg  File name of the output, including extension.
  -y, --year arg       Year (+-1) to generate the calendar for.
  -h, --help           Print usage
```

So, for example, if you want to output to `output.html` for the years 2020,
2021, and 2022, you should run:

```sh
./gchg_app output.html 2021
```

## Notes

### Dependencies

The requirements were explicit: no time/calendar libraries.
I took that to include `std::chrono`, so I did not use it.
I used `doctest` for unit testing, and `cxxopts` for the CLI arguments.
The CMake code tries to `find_package` them (useful, for example, if you use
Conan), and downloads them with FetchContent in case it fails.

### CMake

The project requires CMake 3.23 or newer.
This is a relatively new version, but it is the first one that supports
`FIND_PACKAGE_ARGS` in `find_package`, and the `FILE_SET` feature, which I much
like and use in this project.
I have tried CMake 3.21 and it does not work, but I have not tried any other
version.

### Unit testing

I added unit tests that test the calendar bits of the code.
The HTML bits aren't so easily "testeable" so those had to be visually debugged.
These tests helped catch many, many bugs.

### Performance

I did not take many performance considerations into account.
In particular, the code to generate the HTML is full of string concatenations,
and I did not worry too much about the memory allocations.
This was a deliberate choice, as I wanted to focus on the algorithmic part of
the problem.

### Platform

I developed this on Windows 10 x64, using the toolchain from Visual Studio 2022
as compiler.
I did not test it on other platforms, but the code is standard C++17, so it
should work on any platform with a C++17 compiler.
