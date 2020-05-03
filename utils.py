#!/usr/bin/env python
import psutil
import serial
import time
#REPLACE #### WITH YOUR ARDUINO SERIAL PORT(ie:COM4)

ard= serial.Serial('####',baudrate=9600,timeout=1)

while(True):
    #total cpu usage percentage
    cpu=psutil.cpu_percent(percpu=False,interval=1)
    print(cpu)
    #flush the serial port
    ard.flush()

    #get object of ram total, usage, percentage, etc
    psutil.virtual_memory()
    data=dict(psutil.virtual_memory()._asdict())

    #ram in bytes
    ram_b=data["total"]/1024

    #ram in megabytes
    ram_mb=ram_b//1024
    #ram percentage
    ram_percent=data["percent"]
    print(ram_percent)
    rp=str(int(ram_percent))+","+str(int(cpu))
    print(rp)
    ard.write(rp.encode())
    time.sleep(1)