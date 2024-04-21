// Where it may be applicable: Copyright (c) 2024 FinestandIllest. FinestandIllest grants to all, without discrimination of any sort, the inalienable and irrevocable rights to, for any purpose, for any reason, and in any manner, without limitation of any sort, use, copy, adapt, modify, display, perform, translate, distribute, and do anything to or with this work, in any and all of its forms, original, compiled, translated, printed, written, typed, displayed, performed, or otherwise. FinestandIllest cannot, under any circumstance, revoke these rights or otherwise cause anyone to not have these rights. These rights are granted by FinestandIllest under zero conditions. This work is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall FinestandIllest be liable for any claim, damages, or other liability, whether in an action of contract, tort or otherwise, arising from, out of, or in connection with this work or the use or other dealings in this work.
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <stdexcept>
int main() {
 bool minusculeAllowed = false;
 bool majusculeAllowed = false;
 bool digitsAllowed = false;
 bool symbolsAllowed = false;
 bool invalidSetting = false;
 std::string mn = "qwertyuiopasdfghjklzxcvbnm";
 std::string mj = "QWERTYUIOPASDFGHJKLZXCVBNM";
 std::string dg = "0123456789";
 std::string sm = "`~!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
 std::string c;
 std::string s;
 std::string fn;
 unsigned long long int n = 0;
 unsigned long long int ln = 0;
 std::cout << "Welcome to strgen, strings that're randomly generated easily, niftily!\n";
 if (!std::filesystem::exists("strgenset.txt")) {
  c = mn + mj + dg + sm;
  std::cout << "Could not find strgenset.txt. Characters that can be generated: " << c << "\n";
 } else {
  std::ifstream stg("strgenset.txt");
  if (stg.is_open()) {
   std::string li;
   std::getline(stg, li);
   if (li == "minusculeAllowed = true") {
    minusculeAllowed = true;
   } else if (li == "minusculeAllowed = false") {
    minusculeAllowed = false;
   } else {
    std::cout << "Invalid setting for `minusculeAllowed`. `minusculeAllowed` will be considered `true`.\n";
    minusculeAllowed = true;
    invalidSetting = true;
   }
   std::getline(stg, li);
   if (li == "majusculeAllowed = true") {
    majusculeAllowed = true;
   } else if (li == "majusculeAllowed = false") {
    majusculeAllowed = false;
   } else {
    std::cout << "Invalid setting for `majusculeAllowed`. `majusculeAllowed` will be considered `true`.\n";
    majusculeAllowed = true;
    invalidSetting = true;
   }
   std::getline(stg, li);
   if (li == "digitsAllowed = true") {
    digitsAllowed = true;
   } else if (li == "digitsAllowed = false") {
    digitsAllowed = false;
   } else {
    std::cout << "Invalid setting for `digitsAllowed`. `digitsAllowed` will be considered `true`.\n";
    digitsAllowed = true;
    invalidSetting = true;
   }
   std::getline(stg, li);
   if (li == "symbolsAllowed = true") {
    symbolsAllowed = true;
   } else if (li == "symbolsAllowed = false") {
    symbolsAllowed = false;
   } else {
    std::cout << "Invalid setting for `symbolsAllowed`. `symbolsAllowed` will be considered `true`.\n";
    symbolsAllowed = true;
    invalidSetting = true;
   }
  }
  stg.close();
  if (invalidSetting) {
   std::cout << "Ensure that your strgenset.txt file is written as:\n";
   std::cout << "```\n";
   std::cout << "minusculeAllowed = <bool>\n";
   std::cout << "majusculeAllowed = <bool>\n";
   std::cout << "digitsAllowed = <bool>\n";
   std::cout << "symbolsAllowed = <bool>\n";
   std::cout << "```\n";
   invalidSetting = false;
  }
  if (minusculeAllowed) {
   c += mn;
  }
  if (majusculeAllowed) {
   c += mj;
  }
  if (digitsAllowed) {
   c += dg;
  }
  if (symbolsAllowed) {
   c += sm;
  }
  if (c.empty()) {
   std::cout << "All settings are `false`. All characters will be allowed to be generated.\n";
   c = mn + mj + dg + sm;
  }
  std::cout << "Characters allowed to be generated: " << c << "\n";
 }
 std::random_device rd;
 std::mt19937 gen(rd());
 std::uniform_int_distribution<size_t> dis(0, c.size() - 1);
 while (true) {
  std::cout << "\nEnter an integer in the interval [1, 18446744073709551615] (larger numbers may cause the program to eventually crash) to generate a string of that length, 's' to save the most recently generated string to a text file, 'st' to view and refresh your settings or create a settings file, 'logo' to view the SVG code of the strgen logo or save it as a .svg file, c to view the strgen copyright information, readme to view or save the strgen readme information, or 'q' to quit the program.\n";
  std::string l;
  std::getline(std::cin, l);
  if (l == "s") {
   if (!std::filesystem::exists("gendstr.txt")) {
    fn = "gendstr.txt";
   } else {
    while (std::filesystem::exists("gendstr" + std::to_string(n) + ".txt")) {
     n++;
    }
    fn = "gendstr" + std::to_string(n) + ".txt";
   }
   std::ofstream f(fn);
   if (f.is_open()) {
    f << s;
    std::cout << "Saved text file as " << fn << ".\n";
   } else {
    std::cerr << "Failed to open file.\n";
   }
   f.close();
   fn.clear();
   n = 0;
  } else if (l == "st") {
   std::string o;
   if (!std::filesystem::exists("strgenset.txt")) {
    std::cout << "Failed to find strgenset.txt. Enter 'c' to create a strgenset.txt file, or enter anything else not to.\n";
    std::getline(std::cin, o);
    if (o == "c") {
     std::ofstream stg("strgenset.txt");
     if (stg.is_open()) {
      stg << "minusculeAllowed = true\n";
      stg << "majusculeAllowed = true\n";
      stg << "digitsAllowed = true\n";
      stg << "symbolsAllowed = true";
      std::cout << "Saved text file as strgenset.txt\n";
     } else {
      std::cerr << "Failed to open file.\n";
     }
     stg.close();
    }
   } else {
    std::cout << "Enter 'v' to view your settings, or 'r' to refresh your settings.\n";
    std::getline(std::cin, o);
    if (o == "v") {
     std::ifstream stg("strgenset.txt");
     if (stg.is_open()) {
      std::string li;
      while (std::getline(stg, li)) {
       std::cout << li << "\n";
      }
      std::cout << "Enter 'st' then 'r' to ensure the settings of the program are matched with the settings of strgenset.txt.\n";
     } else {
      std::cerr << "Failed to open strgenset.txt.\n";
     }
     stg.close();
    } else if (o == "r") {
     c.clear();
     std::ifstream stg("strgenset.txt");
     if (stg.is_open()) {
      std::string li;
      std::getline(stg, li);
      if (li == "minusculeAllowed = true") {
       minusculeAllowed = true;
      } else if (li == "minusculeAllowed = false") {
       minusculeAllowed = false;
      } else {
       std::cout << "Invalid setting for `minusculeAllowed`. `minusculeAllowed` will be considered `true`.\n";
       minusculeAllowed = true;
       invalidSetting = true;
      }
      std::getline(stg, li);
      if (li == "majusculeAllowed = true") {
       majusculeAllowed = true;
      } else if (li == "majusculeAllowed = false") {
       majusculeAllowed = false;
      } else {
       std::cout << "Invalid setting for `majusculeAllowed`. `majusculeAllowed` will be considered `true`.\n";
       majusculeAllowed = true;
       invalidSetting = true;
      }
      std::getline(stg, li);
      if (li == "digitsAllowed = true") {
       digitsAllowed = true;
      } else if (li == "digitsAllowed = false") {
       digitsAllowed = false;
      } else {
       std::cout << "Invalid setting for `digitsAllowed`. `digitsAllowed` will be considered `true`.\n";
       digitsAllowed = true;
       invalidSetting = true;
      }
      std::getline(stg, li);
      if (li == "symbolsAllowed = true") {
       symbolsAllowed = true;
      } else if (li == "symbolsAllowed = false") {
       symbolsAllowed = false;
      } else {
       std::cout << "Invalid setting for `symbolsAllowed`. `symbolsAllowed` will be considered `true`.\n";
       symbolsAllowed = true;
       invalidSetting = true;
      }
     }
     stg.close();
     if (invalidSetting) {
      std::cout << "Ensure that your strgenset.txt file is written as:\n";
      std::cout << "```\n";
      std::cout << "minusculeAllowed = <bool>\n";
      std::cout << "majusculeAllowed = <bool>\n";
      std::cout << "digitsAllowed = <bool>\n";
      std::cout << "symbolsAllowed = <bool>\n";
      std::cout << "```\n";
      invalidSetting = false;
     }
     if (minusculeAllowed) {
      c += mn;
     }
     if (majusculeAllowed) {
      c += mj;
     }
     if (digitsAllowed) {
      c += dg;
     }
     if (symbolsAllowed) {
      c += sm;
     }
     if (c.empty()) {
      std::cout << "All settings are `false`. All characters will be allowed to be generated.\n";
      c = mn + mj + dg + sm;
     }
     std::cout << "Characters allowed to be generated: " << c << "\n";
    }
   }
  } else if (l == "c") {
   std::cout << "Where it may be applicable: Copyright (c) 2024 FinestandIllest. FinestandIllest grants to all, without discrimination of any sort, the inalienable and irrevocable rights to, for any purpose, for any reason, and in any manner, without limitation of any sort, use, copy, adapt, modify, display, perform, translate, distribute, and do anything to or with this work, in any and all of its forms, original, compiled, translated, printed, written, typed, displayed, performed, or otherwise. FinestandIllest cannot, under any circumstance, revoke these rights or otherwise cause anyone to not have these rights. These rights are granted by FinestandIllest under zero conditions.\n";
   std::cout << "Enter 's' to save this copyright information as a .txt file, or enter anything else not to.\n";
   std::string o;
   std::getline(std::cin, o);
   if (o == "s") {
    if (!std::filesystem::exists("strgencopr.txt")) {
     fn = "strgencopr.txt";
    } else {
     while (std::filesystem::exists("strgencopr" + std::to_string(n) + ".txt")) {
      n++;
     }
     fn = "strgencopr" + std::to_string(n) + ".txt";
    }
    std::ofstream f(fn);
    if (f.is_open()) {
     f << "Where it may be applicable: Copyright (c) 2024 FinestandIllest. FinestandIllest grants to all, without discrimination of any sort, the inalienable and irrevocable rights to, for any purpose, for any reason, and in any manner, without limitation of any sort, use, copy, adapt, modify, display, perform, translate, distribute, and do anything to or with this work, in any and all of its forms, original, compiled, translated, printed, written, typed, displayed, performed, or otherwise. FinestandIllest cannot, under any circumstance, revoke these rights or otherwise cause anyone to not have these rights. These rights are granted by FinestandIllest under zero conditions.";
     std::cout << "Saved text file as " << fn << ".\n";
    } else {
     std::cerr << "Failed to open file.\n";
    }
    f.close();
    fn.clear();
    n = 0;
   }
  } else if (l == "readme") {
   std::cout << "[//]:# (Where it may be applicable: Copyright (c) 2024 FinestandIllest. FinestandIllest grants to all, without discrimination of any sort, the inalienable and irrevocable rights to, for any purpose, for any reason, and in any manner, without limitation of any sort, use, copy, adapt, modify, display, perform, translate, distribute, and do anything to or with this work, in any and all of its forms, original, compiled, translated, printed, written, typed, displayed, performed, or otherwise. FinestandIllest cannot, under any circumstance, revoke these rights or otherwise cause anyone to not have these rights. These rights are granted by FinestandIllest under zero conditions. This work is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall FinestandIllest be liable for any claim, damages, or other liability, whether in an action of contract, tort or otherwise, arising from, out of, or in connection with this work or the use or other dealings in this work.)\n\n# ![strgen](strgen.svg) strgen, Strings That're Randomly Generated Easily, Niftily\n\n## Brief Description of strgen\n\nstrgen (/stˈɜːd͡ʒən/, like *sturgeon*), short for *string generator* and a backronym for *strings that're randomly generated easily, niftily* is a command-line based tool that can be used to generate strings and save them as .txt files. It can generate strings with a length of any integer in the interval [1, 18446744073709551615].\n\n## How strgen Works\n\n### strgen Settings\n\nThere are four settings in strgen:\n\n- `minusculeAllowed` determines if characters in the string `qwertyuiopasdfghjklzxcvbnm` are allowed in generated strings.\n- `majusculeAllowed` determines if characters in the string `QWERTYUIOPASDFGHJKLZXCVBNM` are allowed in generated strings.\n- `digitsAllowed` determines if characters in the string `0123456789` are allowed in generated strings.\n- `symbolsAllowed` determines if characters in the string `` `0~!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`` are allowed in generated strings.\n\nThese settings can be modified in a .txt file called strgenset.txt. This file must be written as:\n\n```\nminusculeAllowed = <bool>\nmajusculeAllowed = <bool>\ndigitsAllowed = <bool>\nsymbolsAllowed = <bool>\n```\n\n`<bool>` must either be `true` or `false`. `minusculeAllowed` must be on the first line, `majusculeAllowed` on the second, `digitsAllowed` on the third, and `symbolsAllowed` on the fourth. strgen does not care about any line after the fourth.\n\nWhen the program starts, it will try to detect a strgenset.txt file. If it can find this file, it will use each valid setting. Invalid settings will be considered `true`, and if each setting is false in strgenset.txt, then the program will consider each setting to be `true`.\n\nWhen the program starts, it will try to find strgenset.txt. If strgenset.txt is found, it will check the first four lines to determine whether or not each setting is `true`, `false`, or invalid. If a setting is valid, the program will use that setting. If a setting is invalid, the program will consider that setting to be true. If each setting is false, or if strgenset.txt is not found, the program will consider each setting to be true.\n\n### strgen Program\n\n#### Generating Strings\n\nIf the user enters an integer in the interval [`1`, `18446744073709551615`], then the program will generate a string of the length given by the user.\n\n#### Saving Strings\n\nIf the user enters `s`, then the program will save the most recently generated string as a .txt file. The program will try to save the string as gendstr.txt. If gendstr.txt already exists, then the program will try to save the string as gendstr*n*.txt beginning at *n* = 0.\n\n#### Settings\n\nIf the user enters `st`, then the program will try to find strgenset.txt. If the program can find strgenset.txt, then it will prompt the user to enter `c`, `v`, or `r`. If the program cannot find strgenset.txt, then it will prompt the user to enter `c` to create a strgenset.txt file with each setting set to true, or anything else not to. The contents of the newly created strgenset.txt file will be:\n\n```\nminusculeAllowed = true\nmajusculeAllowed = true\ndigitsAllowed = true\nsymbolsAllowed = true\n```\n\n##### Creating strgenset.txt\n\nIf the user enters `c`, a strgenset.txt file will be create with each setting set to true (this will replace an existing strgenset.txt file). The contents of the newly created strgenset.txt file will be:\n\n```\nminusculeAllowed = true\nmajusculeAllowed = true\ndigitsAllowed = true\nsymbolsAllowed = true\n```\n\n##### Viewing strgenset.txt\n\nIf the user enters `v`, the program will say the contents of strgenset.txt.\n\n##### Refreshing strgenset.txt\n\nIf the user enters `r`, the program will check the first four lines to determine whether or not each setting is `true`, `false`, or invalid. If a setting is valid, the program will use that setting. If a setting is invalid, the program will consider that setting to be true. If each setting is false, or if strgenset.txt is not found, the program will consider each setting to be true.\n\n#### Viewing and Saving the Logo\n\nIf the user enters `logo`, the program will say the SVG code of the strgen logo:\n\n```\n<?xml version=\"1.0\" encoding=\"UTF-8\"?><svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 100 100\"><path style=\"stroke:#fff;stroke-width:10px;stroke-linejoin:round;fill:#000\" d=\"M 5 5 L 95 5 L 95 95 L 5 95 z\"/><text style=\"fill:#fff;font-size:7px;font-family:terminal\"><tspan x=\"14\" y=\"22\">57</tspan><tspan x=\"14\" y=\"32\">Generated string:</tspan><tspan x=\"14\" y=\"49\" font-size=\"20\">strgen</tspan><tspan x=\"14\" y=\"62\">strings_that're_r</tspan><tspan x=\"14\" y=\"72\">andomly_generated</tspan><tspan x=\"14\" y=\"82\">_easily,_niftily!</tspan></text></svg>\n```\n\nThe program will then prompt the user to enter `s` to save the logo as a .svg file, or enter anything else not to. If the user enters `s`, the program will try to save the logo as strgenlogo.svg. If strgenlogo.svg already exists, then the program will try to save the logo as strgenlogo*n*.svg beginning at *n* = 0.\n\n#### Viewing and Saving Copyright Information\n\nIf the user enters `c`, the program will say the copyright information of strgen code:\n\n```\nWhere it may be applicable: Copyright (c) 2024 FinestandIllest. FinestandIllest grants to all, without discrimination of any sort, the inalienable and irrevocable rights to, for any purpose, for any reason, and in any manner, without limitation of any sort, use, copy, adapt, modify, display, perform, translate, distribute, and do anything to or with this work, in any and all of its forms, original, compiled, translated, printed, written, typed, displayed, performed, or otherwise. FinestandIllest cannot, under any circumstance, revoke these rights or otherwise cause anyone to not have these rights. These rights are granted by FinestandIllest under zero conditions. This work is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall FinestandIllest be liable for any claim, damages, or other liability, whether in an action of contract, tort or otherwise, arising from, out of, or in connection with this work or the use or other dealings in this work.\n```\n\nThe program will then prompt the user to enter `s` to save the logo as a .svg file, or enter anything else not to. If the user enters `s`, the program will try to save the logo as strgencopr.svg. If strgencopr.svg already exists, then the program will try to save the logo as strgencopr*n*.svg beginning at *n* = 0.\n\n#### Viewing and Saving Readme File\n\nIf the user enters `readme`, the program will say the contents of this readme file.\n\nThe program will then prompt the user to enter `s` to save the contents of this readme file as a .txt file, or enter anything else not to. If the user enters `s`, the program will try to save the logo as readme.md. If readme.md already exists, then the program will try to save the logo as readme*n*.md beginning at *n* = 0.\n\n#### Quitting the Program\n\nIf the user enters `q`, then the program will quit.\n";
   std::cout << "Enter 's' to save this copyright information as a .md file, or enter anything else not to.\n";
   std::string o;
   std::getline(std::cin, o);
   if (o == "s") {
    if (!std::filesystem::exists("readme.md")) {
     fn = "readme.md";
    } else {
     while (std::filesystem::exists("readme" + std::to_string(n) + ".md")) {
      n++;
     }
     fn = "readme" + std::to_string(n) + ".md";
    }
    std::ofstream f(fn);
    if (f.is_open()) {
     f << "[//]:# (Where it may be applicable: Copyright (c) 2024 FinestandIllest. FinestandIllest grants to all, without discrimination of any sort, the inalienable and irrevocable rights to, for any purpose, for any reason, and in any manner, without limitation of any sort, use, copy, adapt, modify, display, perform, translate, distribute, and do anything to or with this work, in any and all of its forms, original, compiled, translated, printed, written, typed, displayed, performed, or otherwise. FinestandIllest cannot, under any circumstance, revoke these rights or otherwise cause anyone to not have these rights. These rights are granted by FinestandIllest under zero conditions. This work is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall FinestandIllest be liable for any claim, damages, or other liability, whether in an action of contract, tort or otherwise, arising from, out of, or in connection with this work or the use or other dealings in this work.)\n\n# ![strgen](strgen.svg) strgen, Strings That're Randomly Generated Easily, Niftily\n\n## Brief Description of strgen\n\nstrgen (/stˈɜːd͡ʒən/, like *sturgeon*), short for *string generator* and a backronym for *strings that're randomly generated easily, niftily* is a command-line based tool that can be used to generate strings and save them as .txt files. It can generate strings with a length of any integer in the interval [1, 18446744073709551615].\n\n## How strgen Works\n\n### strgen Settings\n\nThere are four settings in strgen:\n\n- `minusculeAllowed` determines if characters in the string `qwertyuiopasdfghjklzxcvbnm` are allowed in generated strings.\n- `majusculeAllowed` determines if characters in the string `QWERTYUIOPASDFGHJKLZXCVBNM` are allowed in generated strings.\n- `digitsAllowed` determines if characters in the string `0123456789` are allowed in generated strings.\n- `symbolsAllowed` determines if characters in the string `` `0~!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`` are allowed in generated strings.\n\nThese settings can be modified in a .txt file called strgenset.txt. This file must be written as:\n\n```\nminusculeAllowed = <bool>\nmajusculeAllowed = <bool>\ndigitsAllowed = <bool>\nsymbolsAllowed = <bool>\n```\n\n`<bool>` must either be `true` or `false`. `minusculeAllowed` must be on the first line, `majusculeAllowed` on the second, `digitsAllowed` on the third, and `symbolsAllowed` on the fourth. strgen does not care about any line after the fourth.\n\nWhen the program starts, it will try to detect a strgenset.txt file. If it can find this file, it will use each valid setting. Invalid settings will be considered `true`, and if each setting is false in strgenset.txt, then the program will consider each setting to be `true`.\n\nWhen the program starts, it will try to find strgenset.txt. If strgenset.txt is found, it will check the first four lines to determine whether or not each setting is `true`, `false`, or invalid. If a setting is valid, the program will use that setting. If a setting is invalid, the program will consider that setting to be true. If each setting is false, or if strgenset.txt is not found, the program will consider each setting to be true.\n\n### strgen Program\n\n#### Generating Strings\n\nIf the user enters an integer in the interval [`1`, `18446744073709551615`], then the program will generate a string of the length given by the user.\n\n#### Saving Strings\n\nIf the user enters `s`, then the program will save the most recently generated string as a .txt file. The program will try to save the string as gendstr.txt. If gendstr.txt already exists, then the program will try to save the string as gendstr*n*.txt beginning at *n* = 0.\n\n#### Settings\n\nIf the user enters `st`, then the program will try to find strgenset.txt. If the program can find strgenset.txt, then it will prompt the user to enter `c`, `v`, or `r`. If the program cannot find strgenset.txt, then it will prompt the user to enter `c` to create a strgenset.txt file with each setting set to true, or anything else not to. The contents of the newly created strgenset.txt file will be:\n\n```\nminusculeAllowed = true\nmajusculeAllowed = true\ndigitsAllowed = true\nsymbolsAllowed = true\n```\n\n##### Creating strgenset.txt\n\nIf the user enters `c`, a strgenset.txt file will be create with each setting set to true (this will replace an existing strgenset.txt file). The contents of the newly created strgenset.txt file will be:\n\n```\nminusculeAllowed = true\nmajusculeAllowed = true\ndigitsAllowed = true\nsymbolsAllowed = true\n```\n\n##### Viewing strgenset.txt\n\nIf the user enters `v`, the program will say the contents of strgenset.txt.\n\n##### Refreshing strgenset.txt\n\nIf the user enters `r`, the program will check the first four lines to determine whether or not each setting is `true`, `false`, or invalid. If a setting is valid, the program will use that setting. If a setting is invalid, the program will consider that setting to be true. If each setting is false, or if strgenset.txt is not found, the program will consider each setting to be true.\n\n#### Viewing and Saving the Logo\n\nIf the user enters `logo`, the program will say the SVG code of the strgen logo:\n\n```\n<?xml version=\"1.0\" encoding=\"UTF-8\"?><svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 100 100\"><path style=\"stroke:#fff;stroke-width:10px;stroke-linejoin:round;fill:#000\" d=\"M 5 5 L 95 5 L 95 95 L 5 95 z\"/><text style=\"fill:#fff;font-size:7px;font-family:terminal\"><tspan x=\"14\" y=\"22\">57</tspan><tspan x=\"14\" y=\"32\">Generated string:</tspan><tspan x=\"14\" y=\"49\" font-size=\"20\">strgen</tspan><tspan x=\"14\" y=\"62\">strings_that're_r</tspan><tspan x=\"14\" y=\"72\">andomly_generated</tspan><tspan x=\"14\" y=\"82\">_easily,_niftily!</tspan></text></svg>\n```\n\nThe program will then prompt the user to enter `s` to save the logo as a .svg file, or enter anything else not to. If the user enters `s`, the program will try to save the logo as strgenlogo.svg. If strgenlogo.svg already exists, then the program will try to save the logo as strgenlogo*n*.svg beginning at *n* = 0.\n\n#### Viewing and Saving Copyright Information\n\nIf the user enters `c`, the program will say the copyright information of strgen code:\n\n```\nWhere it may be applicable: Copyright (c) 2024 FinestandIllest. FinestandIllest grants to all, without discrimination of any sort, the inalienable and irrevocable rights to, for any purpose, for any reason, and in any manner, without limitation of any sort, use, copy, adapt, modify, display, perform, translate, distribute, and do anything to or with this work, in any and all of its forms, original, compiled, translated, printed, written, typed, displayed, performed, or otherwise. FinestandIllest cannot, under any circumstance, revoke these rights or otherwise cause anyone to not have these rights. These rights are granted by FinestandIllest under zero conditions. This work is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall FinestandIllest be liable for any claim, damages, or other liability, whether in an action of contract, tort or otherwise, arising from, out of, or in connection with this work or the use or other dealings in this work.\n```\n\nThe program will then prompt the user to enter `s` to save the logo as a .svg file, or enter anything else not to. If the user enters `s`, the program will try to save the logo as strgencopr.svg. If strgencopr.svg already exists, then the program will try to save the logo as strgencopr*n*.svg beginning at *n* = 0.\n\n#### Viewing and Saving Readme File\n\nIf the user enters `readme`, the program will say the contents of this readme file.\n\nThe program will then prompt the user to enter `s` to save the contents of this readme file as a .txt file, or enter anything else not to. If the user enters `s`, the program will try to save the logo as readme.md. If readme.md already exists, then the program will try to save the logo as readme*n*.md beginning at *n* = 0.\n\n#### Quitting the Program\n\nIf the user enters `q`, then the program will quit.";
     std::cout << "Saved text file as " << fn << ".\n";
    } else {
     std::cerr << "Failed to open file.\n";
    }
    f.close();
    fn.clear();
    n = 0;
   }
  }else if (l == "q") {
   std::cout << "Quitting strgen.\n";
   break;
  } else if (l == "logo") {
   std::cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?><svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 100 100\"><path style=\"stroke:#fff;stroke-width:10px;stroke-linejoin:round;fill:#000\" d=\"M 5 5 L 95 5 L 95 95 L 5 95 z\"/><text style=\"fill:#fff;font-size:7px;font-family:terminal\"><tspan x=\"14\" y=\"22\">57</tspan><tspan x=\"14\" y=\"32\">Generated string:</tspan><tspan x=\"14\" y=\"49\" font-size=\"20\">strgen</tspan><tspan x=\"14\" y=\"62\">strings_that're_r</tspan><tspan x=\"14\" y=\"72\">andomly_generated</tspan><tspan x=\"14\" y=\"82\">_easily,_niftily!</tspan></text></svg><!--Where it may be applicable: Copyright (c) 2024 FinestandIllest. FinestandIllest grants to all, without discrimination of any sort, the inalienable and irrevocable rights to, for any purpose, for any reason, and in any manner, without limitation of any sort, use, copy, adapt, modify, display, perform, translate, distribute, and do anything to or with this work, in any and all of its forms, original, compiled, translated, printed, written, typed, displayed, performed, or otherwise. FinestandIllest cannot, under any circumstance, revoke these rights or otherwise cause anyone to not have these rights. These rights are granted by FinestandIllest under zero conditions. This work is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall FinestandIllest be liable for any claim, damages, or other liability, whether in an action of contract, tort or otherwise, arising from, out of, or in connection with this work or the use or other dealings in this work.-->\n";
   std::cout << "Enter 's' to save the logo of strgen as a .svg file, or enter anything else not to.\n";
   std::string o;
   std::getline(std::cin, o);
   if (o == "s") {
    if (!std::filesystem::exists("strgenlogo.svg")) {
     fn = "strgenlogo.svg";
    } else {
     while (std::filesystem::exists("strgenlogo" + std::to_string(n) + ".svg")) {
      n++;
     }
     fn = "strgenlogo" + std::to_string(n) + ".svg";
    }
    std::ofstream f(fn);
    if (f.is_open()) {
     f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?><svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 100 100\"><path style=\"stroke:#fff;stroke-width:10px;stroke-linejoin:round;fill:#000\" d=\"M 5 5 L 95 5 L 95 95 L 5 95 z\"/><text style=\"fill:#fff;font-size:7px;font-family:terminal\"><tspan x=\"14\" y=\"22\">57</tspan><tspan x=\"14\" y=\"32\">Generated string:</tspan><tspan x=\"14\" y=\"49\" font-size=\"20\">strgen</tspan><tspan x=\"14\" y=\"62\">strings_that're_r</tspan><tspan x=\"14\" y=\"72\">andomly_generated</tspan><tspan x=\"14\" y=\"82\">_easily,_niftily!</tspan></text></svg><!--Where it may be applicable: Copyright (c) 2024 FinestandIllest. FinestandIllest grants to all, without discrimination of any sort, the inalienable and irrevocable rights to, for any purpose, for any reason, and in any manner, without limitation of any sort, use, copy, adapt, modify, display, perform, translate, distribute, and do anything to or with this work, in any and all of its forms, original, compiled, translated, printed, written, typed, displayed, performed, or otherwise. FinestandIllest cannot, under any circumstance, revoke these rights or otherwise cause anyone to not have these rights. These rights are granted by FinestandIllest under zero conditions. This work is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall FinestandIllest be liable for any claim, damages, or other liability, whether in an action of contract, tort or otherwise, arising from, out of, or in connection with this work or the use or other dealings in this work.-->";
     std::cout << "Saved text file as " << fn << ".\n";
    } else {
     std::cerr << "Failed to open file.\n";
    }
    f.close();
    fn.clear();
    n = 0;
   }
  } else {
   if (std::all_of(l.begin(), l.end(), ::isdigit)) {
    try {
     s.clear();
     ln = std::stoull(l);
     if (ln >= 1) {
      std::cout << "Generated string: ";
      for (unsigned long long int i = 0; i < ln; i++) {
       size_t x = dis(gen);
       s += c[x];
       std::cout << c[x];
      }
      std::cout << "\n";
      ln = 0;
     } else {
      std::cout << "Invalid input.\n";
     }
    } catch (const std::exception&) {
     std::cout << "Invalid input.\n";
    }
   } else {
    std::cout << "Invalid input.\n";
   }
  }
 }
 return 0;
}
