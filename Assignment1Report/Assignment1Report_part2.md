
Name: Muhammad Awawdi Student Number: 209319003 Name: Muhammad sarahni Student Number: 207662958


Part 1:
In order to print all the faces and vertices, we add a loop in order to print them in utils.cpp in 
Load MeshModel Function. Below is a screenshot of the result of printing Demo Model:


![hw1_2_part1](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/hw1_2_part1.png)


Part 2: 
Firstly, we added a scale variable and multiply the coordinates 
Secondly, we added 2 variables to coordinates x and y. (700 to x and 300 to y). 
Due to that, the model appeared in the middle.


![hw1_2_part2](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/hw1_2_part2.png)


part3:
 “Bunny Model”:
In the Renderer Function, we added  new function “DRAWMESH” which drew a mesh .
We calculated new coordinators (after scaling and translating from part 2 ) and then drew a mesh by taking each face and its vertices and drew 3 lines for each face


![hw1_2_part3](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/hw1_2_part3.png)


Part 4:  
In the main we added a GUI window which included local and world transformation. For each model, there are translating, rotating and scaling matrices. We can switch between local model and world model by checking the checkbox of the model that we want. We can change the transformation value by changing the value of the sliders. Each model has unique local matrices and world transformation matrices.
In main, the value of each slider is sent to Set_matrices_function and in Renderer we get all the matrices and multiply them in the following order: 
World rotate * world scale* world translate* local rotate * local scale* local translate.

![hw1_2_part4_1](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/hw1_2_part4_1.png)

![hw1_2_part4_2](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/hw1_2_part4_2.png)


Part 5:
We multiplied all the scaling, rotating and translating matrices for local and world model. And then we multiplied the result in each vector (x,y,z,1). We could see the model transforming as we changed the values of each slider.
Below is a screenshot of world’s translation and then local‘s rotation.

![hw1_2_part5_1](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/hw1_2_part5_1.png)

Below is a screenshot of local‘s translating and then world’s rotation.

![hw1_2_part5_2](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/hw1_2_part5_2.png)


Part 6:
We can add more models to the Scene. We can switch between each model by choosing num model in the GUI.
The first model that we loaded got the num  0
The second model that we loaded got the num  1
The third model that we loaded got the num  2
….
That means that we had control over all the models.

![hw1_2_part6_1](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/hw1_2_part6_1.png)

![hw1_2_part6_2](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/hw1_2_part6_2.png)

![hw1_2_part6_3](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/hw1_2_part6_3.png)


Part 7:
We added an extra option for doing transformations by using the mouse and keyboard.
The mouse is responsible for scaling the model (increasing and decreasing the size of the model).
w/a/s/d mean respectively: up, left, down, right.
1 and 2            rotate in x
3 and 4 	           rotate in y
5 and 6            rotate in z

There is no screenshot 😊 we added a Video instead … 😊


![vedio_hm1_part2_](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/vedio_hm1_part2_.mp4)
