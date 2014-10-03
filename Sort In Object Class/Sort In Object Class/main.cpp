//
//  main.cpp
//  Sort In Object Class
//
//  Created by Shuai Wang on 10/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Person {

public:
    int height;
    int weight;
    
    Person (int h, int w) : height(h), weight(w) {};
    

};


// sort way 1:
//class myCompare {
//
//public:
//    bool operator() (const Person &p1, const Person &p2) {
//        return p1.height > p2.height;
//    
//    }
//
//};


// sort way 2:
//bool myCompare (const Person &p1, const Person &p2) {
//    return p1.height > p2.height;
//    
//}

// priority_queue way 1:
class myCompare {
public:
      bool operator() (const Person &p1, const Person &p2) {
          return p1.height > p2.height;
      }

};



int main(int argc, const char * argv[])
{

//    vector<Person> persons;
    Person p1(10,10);
    Person p2(100,120);
    Person p3(30,60);
    Person p4(20,40);
    Person p5(50,30);
    Person p6(90,30);
    Person p7(20,70);
    Person p8(60,40);
    Person p9(10,30);
    

    
    priority_queue <Person, vector<Person>, myCompare> q;
    
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    q.push(p5);
    q.push(p6);
    
    
//    persons.push_back(p1);
//    persons.push_back(p2);
//    persons.push_back(p3);
//    persons.push_back(p4);
//    persons.push_back(p5);
//    persons.push_back(p6);
//    persons.push_back(p7);
//    persons.push_back(p8);
//    persons.push_back(p9);
//    
//    sort(persons.begin(), persons.end(), myCompare);
//    
//    for (int i = 0; i < persons.size(); i++) {
//        cout << "The " << i + 1<< " Person " << "with " << "height " << persons[i].height << " weight " << persons[i].weight << ". ";
//        cout << endl;
//    }
//
    
    cout << q.top().height << endl;
    
    return 0;
}

