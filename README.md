# MK7-Memory

A collection of data structures for Mario Kart 7.

## Usage

The data structures are generated from template files located in the [template](template) folder. These files have a special syntax so that it's easier to add new members to the data structures while doing reverse engineering.

## Build

- [git](https://git-scm.com/downloads)
- [python3](https://www.python.org/downloads)
- [devkitPro](https://devkitpro.org/wiki/Getting_Started)

1. Clone the repository locally by running `git clone <repo url> --depth=1 --recurse-submodules --shallow-submodules`.
2. Run `make` in the repository root directory to generate the header files in the `include` folder.
3. Include the needed header files in your project and build it using C++23.

## Credits

- [Nintendo](https://github.com/nintendo)
- [OpenEAD](https://github.com/open-ead): [sead](https://github.com/open-ead/sead), [nnheaders](https://github.com/open-ead/nnheaders)
- [3DS Decompilation](https://github.com/3dsdecomp): [LibMessageStudio](https://github.com/3dsdecomp/LibMessageStudio)
- [Anto726](https://github.com/Anto726): game research
- [PabloMK7](https://github.com/PabloMK7): game research
- [B_squo](https://github.com/Bsquo): game research
- [Marioiscool246](https://github.com/Marioiscool246): `Kart::NetData` research
- _tZ: `System::RootSystem`, its nested classes, and much more

## License

See [LICENSE](LICENSE).
