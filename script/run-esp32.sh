#!/usr/bin/env bash
cd build
export dev=/dev/ttyACM0
python $IDF_PATH/components/esptool_py/esptool/esptool.py -p $dev write_flash @flash_project_args
python $IDF_PATH/tools/idf_monitor.py -p $dev espMagic.elf
