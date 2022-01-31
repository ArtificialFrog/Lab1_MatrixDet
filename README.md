# Лабораторная работа №1. Кондрашова Я.С.
## Терминал 1:
```
catkin_make
roscore
```
## Терминал 2:
```
source devel/setup.bash
rosrun client_server client_server
```
## Терминал 3:
```
source devel/setup.bash
rosservice call /count_det_server "{x11: 5, x12: -4, x13: 13, x21: 16, x22: 25, x23: -17, x31: 18, x32: -52, x33: -2}" 
```
## Терминал 4 (просмотр сообщения в топике):
```
source devel/setup.bash
rostopic echo topic_parity

```
