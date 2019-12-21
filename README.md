# New Project Tool

nptool is a simple CLI tool to create a new project based on predefined templates

## Prerequisites

## Description

`nptool` is a command line utility created for the sole purpose of creating new projects from existing templates. It comes with certain commands and features that allow for user(s) like me to quickly bootstrap a new project. Currently, the following types of projects are supported.

 - C++
 - C
 - Python
 - Docker

I will be adding support as per my needs.

Once invoked, the tool will:
1. Create a new folder for the new project with the desired name. It must check if the folder already exisits and exit with error if it does.
2. Create .gitignore file as well as README.md and License.txt file
3. Create required sub folders for the source etc.
4. Create necessary files for the beginner project.
5. Create a script to allow execution of the project or show commands that allow running the project.

and then exit.


### Commands

The tool currently supports the following commands:

#### Help

`nptool --help` brings up the help message which lists of available commands, supported project types as well as usage examples.

#### Interactive Tool

`nptool` execution without any arguments will start the interactive project generator which will ask for new project name, type as well as some other details.

#### New Project Creation

`nptool -n Project_Name -t CPP` for example would create a new project by the name of Project_Name and type CPP. 


## Installation/Building

create a folder `build` and cd into it run the command

`cmake .. && make` 

This should do everything. Changes to the binary version can be made via the cmake file

## Making Changes
@TODO

## Troubleshooting and FAQ
@TODO

## Contributing
@TODO

## Author and License

Designed by [Inderpreet Singh](https://inderpreet.github.io)

This software may be distributed and modified under the terms of the GNU
General Public License version 2 (GPL2) as published by the Free Software
Foundation and appearing in the file LICENSE.TXT included in the packaging of
this file. Please note that GPL2 Section 2[b] requires that all works based
on this software must also be made publicly available under the terms of
the GPL2 ("Copyleft").

We put a lot of time and effort into our project and hence this copyright 
notice ensures that people contribute as well as each contribution is 
acknowledged. Please retain this original notice and if you make changes
please document them below along with your details.

The latest copy of this project/library can be found at: 
https://github.com/inderpreet/
