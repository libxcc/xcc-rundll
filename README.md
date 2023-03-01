# xcc.rundll

[![996.icu](https://img.shields.io/badge/link-996.icu-red.svg)](https://996.icu)

*An application that emulates Rundll32.exe*


## Explain

On Linux and Darwin, there is no such program as Rundll32.exe, so this program tries to simulate some operations.

Currently only calls with full string parameters are implemented.


## Note

If you want to commit any changes, write the code in the following format.

set encoding=utf-8

set tabstop=8

set shiftwidth=8



## Comment format

```shell
/// <summary>
/// The description of the current function
/// </summary>
/// <param name="_ParameterName"> Parameter description </param>
/// <returns> Return value description</returns>
/// <examples> Examples </examples>
```


## Installation

### Ubuntu Linux

First install all required dependencies and build tools:
```shell
sudo apt install git
sudo apt install autoconf
sudo apt install automake
sudo apt install libtool-bin
sudo apt install cmake
```

Then clone the actual project Repository:
```shell
git clone https://github.com/libxcc/xcc-rundll.git
svn checkout https://github.com/libxcc/xcc-rundll/trunk
cd xcc-core
```

Now you can build and install it:
```shell
cmake .
make
sudo make install
```

## License

This library is licensed under the [GNU Lesser General Public License v2.1](https://www.gnu.org/licenses/lgpl-2.1.en.html),
also included in the repository in the `LICENSE` file.

README Updated on: 2023-03-01
