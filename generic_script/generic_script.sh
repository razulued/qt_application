#!/bin/bash

if [ -e /home/pi/generic_script/run ]
then
    #File exists. Delete run_script
    rm /home/pi/generic_script/run

    #Run installer
    /home/pi/generic_script/file_installer.sh
fi
