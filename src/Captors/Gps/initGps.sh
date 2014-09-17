#!/bin/bash
echo 00 > /sys/kernel/debug/omap_mux/uart1_txd
echo 20 > /sys/kernel/debug/omap_mux/uart1_rxd
stty -F /dev/ttyO1 57600
echo -e '$PMTK220,200*2C\r\n' > /dev/ttyO1
echo -e '$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n' > /dev/ttyO1
echo -e '$PMTK251,38400*27\r\n' > /dev/ttyO1
stty -F /dev/ttyO1 38400
