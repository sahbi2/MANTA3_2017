#!/bin/bash
clear
sudo chown root:root ~/my_catkin_ws/devel/lib/manta/GPS_talker # change ownship to root
sudo chmod a+rx ~/my_catkin_ws/devel/lib/manta/GPS_talker      # set as executable by all
sudo chmod u+s ~/my_catkin_ws/devel/lib/manta/GPS_talker  # set the setuid bit
echo "GPS_node permissions changed"
