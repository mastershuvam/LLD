//Strategy Design Pattern

#include<iostream>
using namespace std;

class WalkableRobot{
    public:
    virtual void walk() = 0;
    virtual ~WalkableRobot(){}
};

class NormalWalkRobot : public WalkableRobot{
    public:
    void walk() override{
        cout<<"I am walking normally."<<endl;
    }
};

class NonWalkRobot : public WalkableRobot{
    public:
    void walk() override{
        cout<<"I cannot walk."<<endl;
    }
};

class TalkingRobot{
    public:
    virtual void talk() = 0;
    virtual ~TalkingRobot(){}
};

class NormalTalkRobot : public TalkingRobot{
    public:
    void talk() override{
        cout<<"I am talking normally."<<endl;
    }
};

class NonTalkRobot : public TalkingRobot{
    public:
    void talk() override{
        cout<<"I cannot talk."<<endl;
    }
};

class FlyableRobot{
    public:
    virtual void fly() = 0;
    virtual ~FlyableRobot(){}
};

class NormalFlyRobot : public FlyableRobot{
    public:
    void fly() override{
        cout<<"I am flying normally."<<endl;
    }
};

class NonFlyRobot : public FlyableRobot{
    public:
    void fly() override{
        cout<<"I cannot fly."<<endl;
    }
};

class Projection{
    public:
    virtual void project(){
        cout<<"I am projecting normally."<<endl;
    }
};


class Robot{
    private:
    WalkableRobot* walkBehavior;
    TalkingRobot* talkBehavior;
    FlyableRobot* flyBehavior;
    Projection* projectBehavior;

    public:
    Robot(WalkableRobot* w, TalkingRobot* t, FlyableRobot* f, Projection* p){
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
        this->projectBehavior = p;
    }

    void walk(){
        walkBehavior->walk();
    }

    void talk(){
        talkBehavior->talk();
    }

    void fly(){
        flyBehavior->fly();
    }

    void project(){
        projectBehavior->project();
    }

};

class AdvancedRobot : public Robot{
    public:
    AdvancedRobot(WalkableRobot*w, TalkingRobot*t, FlyableRobot*f, Projection*p) : Robot(w, t, f, p){}
};

class BasicRobot : public Robot{
    public:
    BasicRobot(WalkableRobot*w, TalkingRobot*t, FlyableRobot*f, Projection*p) : Robot(w, t, f, p){}
};


int main(){
    Robot* robot1 = new AdvancedRobot(new NormalWalkRobot(), new NormalTalkRobot(), new NormalFlyRobot(), new Projection());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->project(); 
    
    cout<< "---------------" << endl;
    Robot* robot2 = new BasicRobot(new NormalWalkRobot(), new NormalTalkRobot(), new NonFlyRobot(), new Projection());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->project();

    return 0;
}