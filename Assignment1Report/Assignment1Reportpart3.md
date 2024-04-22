# Assignement 1_c
 
 Student1 : Muhammad  sarahni - 207662958	
 
Student2 :Muhammad  Awawdi  - 209319003 

Q1:


 #Implement a camera with a orthographic projection:
 
 At First, We removed a centering trick (hw_1_part2) and then we added the camera in the main.cpp and then we added a orthgraphic function with Getters and Setters parameters, and then we Added in main Gui than have six Float sliders. (buttom,up,far,near,left,right).we multplied the matrix with the matrices of Meshmodel.
 
 ![enter image description here](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/3part1%20(online-video-cutter.com).gif)






 Q2:
 #transformation matrices:
 
 in This part we added LookAt Matrix (with Getters, Setters and calculate the matrix by glm::lookat()),
 We alse added a local and world transformation of Camera, We can change the parameters by changing the values of Sliders in the main.
 the matrices are implemented as same as in the previous assignment.
 
 There is no need for scaling matrix of Camera

 ![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/2.png)
  
  
 ![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/%D7%9E.png)



Q3:
#shwoing A meshmodel after changing the size of the viewer (hight and width)

in main We call Set function that change the width and hight of the render.
and in the renderer we Get the new values of width and hight 

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(134).png)


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(135).png)


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(136).png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(137).png)


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(138).png)


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(139).png)



Q4:
#Implement a feature in the renderer that draws axes of the model and the world frame:

we defined center of the model and world frame and then we define the length of axes
( pos and neg) and then we drew 3 lined for each axis by specifing start and end point.
and then we calculated the start and end point by multplied them with model's transformation matrix for the model frame, and by the identity matrix for the world frame.

The axis in the model frame stay fixe because we dont multplied them with the transformation matrices.
however in the local frame we do. so the axis trasnform with the model.

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(84).png)

Q5:

#T1 in model frame and T2 in world frame :


T1:
 - Translate x 260
 - translate y 150
 - Rotate x 24
 - Rotate y 107
 - Rotate z 20

T2:

 - Rotate x 154
 - Rotate y 160
 - Rotate z 30

This is two models that show the diff between T1 in model frame and T2 in world frame and T2 in model frame and T1 in world frame:

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(126).png)



Q6:

Firstly, we found the max and min of vertices value before multiplied them by the matrices of camera and model transformation. and then we multiplyed them with the matrices.

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(133).png)

Q7:
 Face normals and vertex normals:
 
 Vertex normal:
 Firstly we Found the vertex normal and then we calculated the new vertex of the model:
 vertex >>> vertex+ vertex_normal
 
 Face normal:
 
 Firstly, we found the center by calculate the avg of 3 vertex of the face and then we 
 lines from the center to (face+face_normal)
 
 
![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(128).png)


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(127).png)


Q8:
As Shown in this images, when we change the tranzlate in z in perspective frame, the camera doing zoom.

however, their is no change in orthpgrafic matrix.


translate Z=50 (perppective)
![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/z_50.png)

translate Z=-50 (perppective)
![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/minos50.png)

translate Z=20 (perppective)
![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/z_20.png)

translate Z(orthpgrafic)
There is no effect.

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/orthzdoesntchange.png)

Q9:

After Zoom:

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(90).png)

Before Zoom:


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(89).png)


Q10:

Set Camera To (-5,-5,-5):


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(91).png)


Q11:

After dolly zoom.
its changes fovy value and axis Z
![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(112).png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(113).png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(111).png)


Q12:

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(101).png)


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(100).png)




Q13:
![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(99).png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(98).png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(97).png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(96).png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(95).png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(94).png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(93).png)


Q14:
The User can  set and enter the number of the values of Slider in the input text,


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment1Report/Screenshot%20(92).png)
