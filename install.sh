#! /bin/bash

#compile main.c
gcc main.c -o tictactoe

#move compiled bin to /usr/bin
sudo mv tictactoe /usr/bin
