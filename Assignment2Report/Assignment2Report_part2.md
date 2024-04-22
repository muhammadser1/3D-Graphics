Name: Muhammad Awawdi
Student Number: 209319003
Name: Muhammad sarahni
Student Number: 207662958


#2B part 1:
To calculate the ambient light (Ia), we applied the formula Ia = Ka * La, where Ka represents the material color of the bunny. In the figure, the bunny appears rosy red (244, 108, 108) even when the light source is white (255, 255, 255) because the white light's color is translated to (1, 1, 1). However, when the light source color changes to blue, the bunny's color shifts to a royal purple due to the combination of blue and red.

The original color of the bunny on the right is red, but it transitions to purple when blue ambient light is added.


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2b_1%20merged.jpg)

#2B part 2:


The calculation of diffuse light (Id) was performed using the equation Id = Kd * (l . n) * Ld.

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2B_22.png)


#2B part 3:


We employed Gouraud shading, incorporating both ambient and diffuse light, in this section. The shading of the mesh model in the figure appears smoother than in Part 2.


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2B_3.png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2B_33.png)

#2B part 4:

The reflected ray was determined using the formula: r = I - 2 * dot(I, N) * N (with normalized vectors). The figure illustrates the direction of light (represented in red) and the reflected ray (shown in green) on a mesh model.

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2B_4.png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2b_444.png)

#2B part 5:

In this section, the specular light (Is) was computed using the equation: Is = Ks * (r . v)^alpha * Ls, where alpha signifies the brightness. Phong shading was then implemented.



![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2b_5.png)


#2B part 6:


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2_6.png)


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2_66.png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2_666.png)

