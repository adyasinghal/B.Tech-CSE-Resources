#include<stdio.h>
#include<math.h>

int main()
               {
                 float r;
                 float h;
                 float l;
                 float sur_area;
                 printf("Enter height of cylinder: ");
                 scanf("%f" , &h);
                 printf("Enter radius of cylinder: ");
                 scanf("%f" , &r);
                 l = sqrt(pow(r,2)+pow(h , 2));
                 sur_area = (22*(r*(r+l))/7);
                 printf("The surface area of the maximum size cone that can be inscribed in the cylinder is:  %f\n" ,  sur_area);

}

