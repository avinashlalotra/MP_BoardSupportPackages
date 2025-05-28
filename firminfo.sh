#!/bin/bash

echo "Generated hex file successfully" > log
echo "FILE NAME : firmware.mem" >> log
echo "FILE TYPE : hexfile" >> log
echo "FILE SIZE : $(($(cat ./artifacts/firmware.mem | wc -l) * 4)) bytes" >> log
