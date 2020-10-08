# ICG---HW2
Project Details
This purpose of this project is to use the GLUT/freeglut library for OpenGL code to create images on a screen. In particular two images were created, one with teapots in a circle and rotated by their position in the circle and another image of a pyramid of teapot objects. Lastly there is another image that recreates a hand using primitives to complete the last part of the project.

IDE (Environment)
Visual Studio 2019 was used to edit the cpp file and to run and build the project on a Windows 10 machine.

Algorithms
Every single problem includes using glPushMatrix(), glTranslatef(), glRotatef(), glutSolidTeapot(), and glPopMatrix() to create each image of the teapot in different positions and rotations on the screen. For loops are also used in every problem to repeat the process of getting the teapots on the screen.
For problem 1 Sin and Cos was used to get the positions of the teapots around the circle, cos((angle*pi)/180) and sin((angle*pi)/180, where angle = 0 initially where teapots = 10 and then after each teapot is printed angle += 360/teapots.
Problem 2 and 3 are simple algorithms where we are just increasing the positions x and y by static values to change the position of the objects.

Result
The results of the porject can be found in this Repository in each of the three screenshots uploaded.
