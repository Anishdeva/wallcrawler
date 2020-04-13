#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <stdlib.h>

using namespace std;
void move(){

}
int main(int argc, char**argv){
    ros::init(argc, argv,"Lets move the robot");
    ros::NodeHandle nh;
    ros::Rate loop_rate(2);

    while(ros::ok())
    {
        int speed=0,distance=0;
        bool isForward=TRUE;

        //Receiving user input
        cout<<" Input the speed:";
        cin>> speed;
        cout<<"Type your distance(in meters):"
        cin>>distance;
        cout<<"Forward?:"
        cin>>isForward;

        //Checking if the movement is forward or backwards
        if(isForward){

        }
        else{

        }

        //Seting the current time for distance calculus

        //Loop to move the motors in a specified distance
        while (current_distance < distance){
        //Publish the velocity

        //Takes actual time to velocity calculus

        //calculate distancePoseStamped

        //After the loop, stop the robot

        //Force the robot to stop

        }
    }
    return;
}

