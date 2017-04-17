FILE(REMOVE_RECURSE
  "CMakeFiles/manta_generate_messages_py"
  "/home/pi/my_catkin_ws/devel/lib/python2.7/dist-packages/manta/msg/_CmdMotors.py"
  "/home/pi/my_catkin_ws/devel/lib/python2.7/dist-packages/manta/msg/_Radio.py"
  "/home/pi/my_catkin_ws/devel/lib/python2.7/dist-packages/manta/msg/_NavSatFix.py"
  "/home/pi/my_catkin_ws/devel/lib/python2.7/dist-packages/manta/msg/_Imu.py"
  "/home/pi/my_catkin_ws/devel/lib/python2.7/dist-packages/manta/msg/_Echo.py"
  "/home/pi/my_catkin_ws/devel/lib/python2.7/dist-packages/manta/msg/__init__.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/manta_generate_messages_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
