/*Define a structure to represent a point in 2D space with x and y coordinates. Implement
functions to calculate the distance between two points and to check if a point lies within
a specific rectangular boundary.*/
#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); //distance formila :sqroot[(x2-x1)^2 - (y2-y1)^2]
    
    }
int isWithinBoundary(Point p, Point bottomLeft, Point topRight) {
    return (p.x>= bottomLeft.x &&p.x <= topRight.x&&p.y >= bottomLeft.y&&p.y<=topRight.y);
}

int main(void) {
    Point p1;
    printf("\nEnter point 1 for x: "); scanf("%lf",&p1.x);
    printf("\nEnter point 1 for y: "); scanf("%lf",&p1.y);
    Point p2;
    printf("\nEnter point 2 for x: "); scanf("%lf",&p2.x);
    printf("\nEnter point 2 for y: "); scanf("%lf",&p2.y);
    //distance between p1 p2
    double dist = distance(p1, p2);
    printf("Distance between points: %.2f\n", dist);
    Point bottomLeft = {1.0, 1.0};
    Point topRight = {6.0, 5.0};  //x is maximum 6 y is maximum 5 so
    if (isWithinBoundary(p1, bottomLeft, topRight)){
        printf("Point (%.2f, %.2f) is within the boundary.\n", p1.x, p1.y);} 
        else {
        printf("Point (%.2f, %.2f) is outside the boundary.\n", p1.x, p1.y);}
if (isWithinBoundary(p2, bottomLeft, topRight) ){
        printf("Point (%.2f, %.2f) is within the boundary.\n", p2.x, p2.y);
    } else {
        printf("Point (%.2f, %.2f) is outside the boundary.\n", p2.x, p2.y);
    
    }

    return 0;
}
