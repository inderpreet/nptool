# CPP Template for OpenCV and getting started

This is my template for creating new projects using cmake

## Prerequisites

### On MacOS

```
sudo mkdir -p /usr/local/include /usr/local/sbin\n  
sudo chown -R $(whoami) /usr/local/include /usr/local/sbin
sudo mkdir /usr/local/Frameworks\nsudo chown $USER /usr/local/Frameworks

brew update 
brew upgrade
brew install opencv
```

## Installation/Building

create a folder build and cd into it run the command

cmake .. && make 

This should do everything. Changes to the binary version can be made via the cmake file

## Making Changes

## Sample Use cases 

## Troubleshooting and FAQ

## Contributing

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