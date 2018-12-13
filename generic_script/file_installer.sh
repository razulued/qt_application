#!/bin/bash

#Move files from one location to other
SOURCE_DIR="/home/pi/generic_script/files_to_install/*"
TARGET_DIR="/home/pi/"

sudo mv $SOURCE_DIR $TARGET_DIR
