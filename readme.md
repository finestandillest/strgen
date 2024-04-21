[//]:# (Where it may be applicable: Copyright (c) 2024 FinestandIllest. FinestandIllest grants to all, without discrimination of any sort, the inalienable and irrevocable rights to, for any purpose, for any reason, and in any manner, without limitation of any sort, use, copy, adapt, modify, display, perform, translate, distribute, and do anything to or with this work, in any and all of its forms, original, compiled, translated, printed, written, typed, displayed, performed, or otherwise. FinestandIllest cannot, under any circumstance, revoke these rights or otherwise cause anyone to not have these rights. These rights are granted by FinestandIllest under zero conditions. This work is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall FinestandIllest be liable for any claim, damages, or other liability, whether in an action of contract, tort or otherwise, arising from, out of, or in connection with this work or the use or other dealings in this work.)

# ![strgen](strgen.svg) strgen, Strings That're Randomly Generated Easily, Niftily

## Brief Description of strgen

strgen (/stˈɜːd͡ʒən/, like *sturgeon*), short for *string generator* and a backronym for *strings that're randomly generated easily, niftily* is a command-line based tool that can be used to generate strings and save them as .txt files. It can generate strings with a length of any integer in the interval [1, 18446744073709551615].

## How strgen Works

### strgen Settings

There are four settings in strgen:

- `minusculeAllowed` determines if characters in the string `qwertyuiopasdfghjklzxcvbnm` are allowed in generated strings.
- `majusculeAllowed` determines if characters in the string `QWERTYUIOPASDFGHJKLZXCVBNM` are allowed in generated strings.
- `digitsAllowed` determines if characters in the string `0123456789` are allowed in generated strings.
- `symbolsAllowed` determines if characters in the string `` `0~!@#$%^&*()-_=+[{]}\|;:'",<.>/?`` are allowed in generated strings.

These settings can be modified in a .txt file called strgenset.txt. This file must be written as:

```
minusculeAllowed = <bool>
majusculeAllowed = <bool>
digitsAllowed = <bool>
symbolsAllowed = <bool>
```

`<bool>` must either be `true` or `false`. `minusculeAllowed` must be on the first line, `majusculeAllowed` on the second, `digitsAllowed` on the third, and `symbolsAllowed` on the fourth. strgen does not care about any line after the fourth.

When the program starts, it will try to detect a strgenset.txt file. If it can find this file, it will use each valid setting. Invalid settings will be considered `true`, and if each setting is false in strgenset.txt, then the program will consider each setting to be `true`.

When the program starts, it will try to find strgenset.txt. If strgenset.txt is found, it will check the first four lines to determine whether or not each setting is `true`, `false`, or invalid. If a setting is valid, the program will use that setting. If a setting is invalid, the program will consider that setting to be true. If each setting is false, or if strgenset.txt is not found, the program will consider each setting to be true.

### strgen Program

#### Generating Strings

If the user enters an integer in the interval [`1`, `18446744073709551615`], then the program will generate a string of the length given by the user.

#### Saving Strings

If the user enters `s`, then the program will save the most recently generated string as a .txt file. The program will try to save the string as gendstr.txt. If gendstr.txt already exists, then the program will try to save the string as gendstr*n*.txt beginning at *n* = 0.

#### Settings

If the user enters `st`, then the program will try to find strgenset.txt. If the program can find strgenset.txt, then it will prompt the user to enter `c`, `v`, or `r`. If the program cannot find strgenset.txt, then it will prompt the user to enter `c` to create a strgenset.txt file with each setting set to true, or anything else not to. The contents of the newly created strgenset.txt file will be:

```
minusculeAllowed = true
majusculeAllowed = true
digitsAllowed = true
symbolsAllowed = true
```

##### Creating strgenset.txt

If the user enters `c`, a strgenset.txt file will be create with each setting set to true (this will replace an existing strgenset.txt file). The contents of the newly created strgenset.txt file will be:

```
minusculeAllowed = true
majusculeAllowed = true
digitsAllowed = true
symbolsAllowed = true
```

##### Viewing strgenset.txt

If the user enters `v`, the program will say the contents of strgenset.txt.

##### Refreshing strgenset.txt

If the user enters `r`, the program will check the first four lines to determine whether or not each setting is `true`, `false`, or invalid. If a setting is valid, the program will use that setting. If a setting is invalid, the program will consider that setting to be true. If each setting is false, or if strgenset.txt is not found, the program will consider each setting to be true.

#### Viewing and Saving the Logo

If the user enters `logo`, the program will say the SVG code of the strgen logo:

```
<?xml version="1.0" encoding="UTF-8"?><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100"><path style="stroke:#fff;stroke-width:10px;stroke-linejoin:round;fill:#000" d="M 5 5 L 95 5 L 95 95 L 5 95 z"/><text style="fill:#fff;font-size:7px;font-family:terminal"><tspan x="14" y="22">57</tspan><tspan x="14" y="32">Generated string:</tspan><tspan x="14" y="49" font-size="20">strgen</tspan><tspan x="14" y="62">strings_that're_r</tspan><tspan x="14" y="72">andomly_generated</tspan><tspan x="14" y="82">_easily,_niftily!</tspan></text></svg>
```

The program will then prompt the user to enter `s` to save the logo as a .svg file, or enter anything else not to. If the user enters `s`, the program will try to save the logo as strgenlogo.svg. If strgenlogo.svg already exists, then the program will try to save the logo as strgenlogo*n*.svg beginning at *n* = 0.

#### Viewing and Saving Copyright Information

If the user enters `c`, the program will say the copyright information of strgen code:

```
<?xml version="1.0" encoding="UTF-8"?><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100"><path style="stroke:#fff;stroke-width:10px;stroke-linejoin:round;fill:#000" d="M 5 5 L 95 5 L 95 95 L 5 95 z"/><text style="fill:#fff;font-size:7px;font-family:terminal"><tspan x="14" y="22">57</tspan><tspan x="14" y="32">Generated string:</tspan><tspan x="14" y="49" font-size="20">strgen</tspan><tspan x="14" y="62">strings_that're_r</tspan><tspan x="14" y="72">andomly_generated</tspan><tspan x="14" y="82">_easily,_niftily!</tspan></text></svg><!--Where it may be applicable: Copyright (c) 2024 FinestandIllest. FinestandIllest grants to all, without discrimination of any sort, the inalienable and irrevocable rights to, for any purpose, for any reason, and in any manner, without limitation of any sort, use, copy, adapt, modify, display, perform, translate, distribute, and do anything to or with this work, in any and all of its forms, original, compiled, translated, printed, written, typed, displayed, performed, or otherwise. FinestandIllest cannot, under any circumstance, revoke these rights or otherwise cause anyone to not have these rights. These rights are granted by FinestandIllest under zero conditions. This work is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall FinestandIllest be liable for any claim, damages, or other liability, whether in an action of contract, tort or otherwise, arising from, out of, or in connection with this work or the use or other dealings in this work.-->
```

The program will then prompt the user to enter `s` to save the logo as a .svg file, or enter anything else not to. If the user enters `s`, the program will try to save the logo as strgencopr.svg. If strgencopr.svg already exists, then the program will try to save the logo as strgencopr*n*.svg beginning at *n* = 0.

#### Viewing and Saving Readme File

If the user enters `readme`, the program will say the contents of this readme file.

The program will then prompt the user to enter `s` to save the contents of this readme file as a .txt file, or enter anything else not to. If the user enters `s`, the program will try to save the logo as readme.md. If readme.md already exists, then the program will try to save the logo as readme*n*.md beginning at *n* = 0.

#### Quitting the Program

If the user enters `q`, then the program will quit.