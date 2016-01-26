#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;


class Box {
    private:
        int l, b, h;
    public:
        Box(int l, int b, int h) {
            this->l = l;
            this->b = b;
            this->h = h;
            BoxesCreated++;
        }
        Box() : Box(0,0,0) { }
        Box(const Box &box) : Box(box.l, box.b, box.h) {}
        ~Box() {
            BoxesDestroyed++;
        }

    int getLength() {return l;}
    int getBreadth () {return b;}
    int getHeight () {return h;}
    long long CalculateVolume() {return (long long)(l) * (long long)(b) * (long long)(h);}
    bool operator< (Box &box) {
        if ((l < box.l) ||
            ((l == box.l) && (b < box.b)) ||
            ((l == box.l) && (b == box.b) && (h < box.h)))
            return true;
        return false;
    }
};

ostream& operator<<(ostream& out, Box B) {
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}


//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);

// Destructor
// ~Box()
// {

// }

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box &b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box B)



void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
    {
    int type;
    cin>>type;
    if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
        }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}



