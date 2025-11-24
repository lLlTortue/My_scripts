#!/bin/bash

# Count connected monitors
monitor_count=$(hyprctl monitors | grep "^Monitor" | wc -l)

# Lock if only one monitor (internal) is connected
if [ "$monitor_count" -eq 1 ]; then
    lockscreen.sh
fi

#bindl = , switch:on:Lid Switch, exec, locker.sh
