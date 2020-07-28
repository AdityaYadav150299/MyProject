#include <iostream>
using namespace std;
#define INFINITY 10000 
  
struct Point 
{ 
    int x; 
    int y; 
};
int Check_on_line(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
        return 1; 
    return 0; 
} 
int orientation(Point p, Point q, Point r) 
{ 
	int value;
    value = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 

	if(value == 0)
	    	return 0;   
     if(value>0)
     {
     	return 1;
     }
     else
     {
     	return 2;
     } 
} 
int Check_Intersect(Point p1, Point q1,Point p2, Point q2)
{
	int ori_1,ori_2,ori_3,ori_4;
	
     	ori_1 = orientation(p1, q1, p2); 
     	ori_2 = orientation(p1, q1, q2);
     	ori_3 = orientation(p2, q2, p1);
     	ori_4 = orientation(p2, q2, q1); 
  
    if (ori_1 != ori_2 && ori_3 != ori_4) 
        return 1; 
    if (ori_1 == 0 && Check_on_line(p1, p2, q1)) 
    	return 1; 
    if (ori_2 == 0 && Check_on_line(p1, q2, q1)) 
    	return 1; 
    if (ori_3 == 0 && Check_on_line(p2, p1, q2)) 
    	return 1; 
    if (ori_4 == 0 && Check_on_line(p2, q1, q2)) 
    	return 1; 
  
    return 0;
} 
int Check_Point(Point polygon[], int no_pt, Point p) 
{  
    if(no_pt < 3)  
 	return 0; 
   
    Point end_point = {INFINITY, p.y}; 
    int count = 0, i = 0; 
    
    do
    { 
        int next_pt = (i+1)%no_pt; 
   
        if (Check_Intersect(polygon[i], polygon[next_pt], p, end_point)) 
        {  
            if (orientation(polygon[i], p, polygon[next_pt]) == 0) 
               return Check_on_line(polygon[i], p, polygon[next_pt]); 

            count++; 
        } 
       i = next_pt; 
    } while (i != 0);
    
    count=count%2;	   
    return(count);  
} 

int main() 
{ 
    Point polygonA[] = {{1, 0}, {8, 3}, {8, 8}, {1, 5}};
    int flag=0; 
    int n = sizeof(polygonA)/sizeof(polygonA[0]); 
    cout<<"Case 1 ans:";
    Point p1 = {3, 5}; 
    flag=Check_Point(polygonA, n, p1); 
   	if(flag==0)
   	{
   		cout<<"False \n";
   	}
   	else
   	{
   		cout<<"True \n";
   	}
  	
  	 cout<<"Case 2 ans:";
    Point polygonB[] = {{-3,2}, {-2,-0.8}, {0,1.2} , {2.2,0} , {2,4.5}}; 
    Point p2 = {0, 0}; 
    n = sizeof(polygonB)/sizeof(polygonB[0]); 
    flag=Check_Point(polygonB, n, p2); 
   	if(flag==0)
   	{
   		cout<<"False \n";
   	}
   	else
   	{
   		cout<<"True \n";
   	}
    return 0; 
    
}    
