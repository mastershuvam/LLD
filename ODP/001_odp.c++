//observer design pattern

#include <iostream>

using namespace std;

/*


        +-------------------+
        |   <<interface>>   |
        |     IChannel      |
        +-------------------+
        | +subscribe()      |
        | +unsubscribe()    |
        | +notify()         |
        +-------------------+
                 ▲
                 |
                 |
        +-------------------------------+
        |           Channel             |
        +-------------------------------+
        | - name : string               |
        | - latestVideo : string        |
        | - subscribers : List<ISubscriber> |
        +-------------------------------+
        | +subscribe()                  |
        | +unsubscribe()                |
        | +notify()                     |
        | +uploadNewVideo(videoname)    |
        +-------------------------------+
                 |
                 | has-a
                 |
                 ▼
        +-------------------+
        | <<interface>>     |
        |   ISubscriber     |
        +-------------------+
        | +update(video)    |
        +-------------------+
                 ▲
                 |
                 |
        +-------------------+
        |   Subscriber      |
        +-------------------+
        | - name : string   |
        +-------------------+
        | +update(video)    |
        +-------------------+

*/

class ISubscriber{
public:
    virtual void update()=0;
};

class IChannel{
    public:
    virtual void subscribe(ISubscriber* subscriber)=0;
    virtual void unsubscribe(ISubscriber* subscriber)=0;
    virtual void notify()=0;
};

class channel: public IChannel{
    vector<ISubscriber*> subscribers;
    string name;
    string latestVideo;
    public:
    channel(string name){
        this->name=name;
    }
    void subscribe(ISubscriber* subscriber) override{
        if(find(subscribers.begin(),subscribers.end(),subscriber)==subscribers.end()){
            subscribers.push_back(subscriber);
        }
    }
    void unsubscribe(ISubscriber* subscriber) override{
        auto it = find(subscribers.begin(),subscribers.end(),subscriber);
        if(it!=subscribers.end()){
            subscribers.erase(it);
        }
    }

    void notify() override{
        for(auto subscriber: subscribers){
            subscriber->update();
        }
    }

    void uploadNewVideo(const string & title){
        latestVideo=title;
        cout << "\n[" << name << " uploaded \"" << title << "\"]\n";
        notify();
    }

    string getVideoData(){
        return "\nCheckout our new Video : " + latestVideo + "\n";
    }
};

class subscriber: public ISubscriber{
    string name;
    channel * ch;

    public:
    subscriber(string name, channel * ch){
        this->name=name;
        this->ch=ch;
    }

    void update() override{
        cout << "Hey " << name << ", " << ch->getVideoData();
    }
};


int main(){
    channel* techChannel = new channel("TechExplained");
    subscriber* alice = new subscriber("Alice", techChannel);
    subscriber* bob = new subscriber("Bob", techChannel);

    techChannel->subscribe(alice);
    techChannel->subscribe(bob);

    techChannel->uploadNewVideo("Understanding Design Patterns in C++");

    techChannel->unsubscribe(bob);

    techChannel->uploadNewVideo("Observer Pattern Explained");

    delete alice;
    delete bob;
    delete techChannel;

    return 0;
}