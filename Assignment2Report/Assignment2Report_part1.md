Name: Muhammad Awawdi
Student Number: 209319003
Name: Muhammad sarahni
Student Number: 207662958


##2A part 1:
In this part, we drew a rectangle around each face by finding the minimum and maximum x and y and z coordinates of the face's vertices. We then used these coordinates to draw four lines in a random color to create a bounding rectangle for each face. We do a checkbox that the User can show the bounding rectangle.

Here is a bounding rectangle for one face, with colored to make them easier to see:



![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2a_part1.png)


A bounding rectangle has been drawn around each face in the image, with the rectangles being displayed in randomly chosen colors.
Gif:

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2a_part11.gif)


PNG:

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2a_par111.png)



##2A part 2:

In this part, We implemented the edge walking approach to remove hidden surfaces from the image. We did this by using two nested for loops to iterate over every pixel in each bounding rectangle that we had drawn in the previous part. For each pixel, we checked whether it was also within the bounds of the corresponding triangle. If it was, we color the pixel, otherwise, we left it unchanged.


##2A part 3:

We used the same random color that we had chosen in the previous part to color all the pixels within each face. The resulting image is a collection of colored triangles, as shown in the screenshot below.

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2a_part3.png)


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/2a_part33.png)


##2A part 4:

In this part,  We implemented the z-buffer algorithm (hidden surfaces from the image). To do this, we created two arrays with the size of the viewport's width and height. The first array was used to store the color of each pixel, while the second array was used to store the z-value of each pixel, which was calculated using an equation from the Hidden Surface Removal lecture.

As the distance between a surface and the viewer increases, the color of the surface appears darker in the final image.


![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/pat4_1.png)




![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/part4_11.png)




![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/part4_111.png)



![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/part4_1111.png)





![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/part4_11111.png)



Here, We changed the translate_z local value of  Bunny

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/4_1.jpeg)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/4_2.jpeg)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/4_3.jpeg)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment2Report/4_4.jpeg)
