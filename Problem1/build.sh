#!/bin/bash

config-pin p8.16 gpio_pu
config-pin p9.12 gpio
#config-pin -q p8.16
#config-pin -q p9.12

echo "compiling the programs"
g++ lightSwitch.cpp -o lightSwitch
echo "finished!"

