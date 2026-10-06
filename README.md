# MK7-Memory

A collection of data structures for Mario Kart 7.

## Usage

The data structures are generated from template files located in the [template](template) folder. These files have a special syntax so that it's easier to add new members to the data structures while doing reverse engineering.

## AI Disclosure

LLMs are used to aid on research and documentation of the game (see [mk7-llm-research](mk7-llm-research/README.md)). This decision was taken after a quick discussion with the community, which concluded that usage of LLMs for this purpose is acceptable.

The tooling inside the the LLM workspace is fully AI generated, and its purpose is to aid agents on the research process instead of having to recreate scripts every time they are needed. Use at your own risk.

Due to the current legal uncertainties of AI generated content, everything that lies inside the LLM workspace is public domain, including tooling and documentation (see [mk7-llm-research LICENSE](mk7-llm-research/LICENSE)).

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

See [LICENSE](LICENSE), and each submodule's LICENSE files.
