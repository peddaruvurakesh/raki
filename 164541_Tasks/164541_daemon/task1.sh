#!/bin/bash

# Simple background task that writes to a log file every 10 seconds
while true; do
    echo "Daemon running: $(date)" >>/home/rakesh/daemon/daemon.log
    sleep 10
done &  # Run the loop in the background

