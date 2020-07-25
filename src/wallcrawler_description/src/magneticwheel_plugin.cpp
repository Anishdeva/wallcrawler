#include<functional>
#include<gazebo/gazebo.hh>
#include<gazebo/physics/physics.hh>
#include<gazebo/common/common.hh>
#include<ignition/math/Vector3.hh>
#include <gazebo/common/Plugin.hh>
#include<ros/ros.h>

namespace gazebo
{
    class MagneticWheel : public ModelPlugin
    {
    public: void Load(physics::ModelPtr _model, sdf::ElementPtr /*_sdf*/)
    {
        //Store the pointer to the model
        math::Vector3 force(0,0,-10);

        _model->GetLink("center_right_wheel")->AddRelativeForce(force);
        this->model->GetLink("center_left_wheel")->AddRelativeForce(force);
        this->model->GetLink("front_right_wheel")->AddRelativeForce(force);
        this->model->GetLink("front_left_wheel")->AddRelativeForce(force);
        this->model->GetLink("back_right_wheel")->AddRelativeForce(force);
        this->model->GetLink("back_left_wheel")->AddRelativeForce(force);
        

        //Listens to the update event. This event broadcasts every simulation iteration
       // this->updateConnection =event::Events::ConnectWorldUpdateBegin(std::bind(&MagneticWheel::OnUpdate,this));
    }

    //Called by the world update start event
    // public:void OnUpdate()
    // {
    //     //Apply a small linear velocity to the model
    //     //this->model->SetLinearVel(ignition::math::Vector3d(0.3,0,0));

    //     //Apply force normal to the surface in contact

    // }

    //Pointer to the model
    private: physics::ModelPtr model;

    //Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
    };

GZ_REGISTER_MODEL_PLUGIN(MagneticWheel)
}