#include "ICurve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

bool isCircle(ICurve* p) {
	if (Circle* a = dynamic_cast<Circle*>(p))
    {
        (void)a;
		return true;
    }
    return false;
}

void printICurve(std::shared_ptr<ICurve> src) {
    ICurve *p = dynamic_cast<ICurve*>(src.get());
    if (Circle* a = dynamic_cast<Circle*>(p))
        {
            std::cout << *a;
		    return ;
        }
    if (Ellipse* a = dynamic_cast<Ellipse*>(p))
        {
            std::cout << *a;
		    return ;
        }
    if (Helix* a = dynamic_cast<Helix*>(p))
        {
            std::cout << *a;
		    return ;
        }
    return ;
}


std::shared_ptr<ICurve> randomICurve(int i) {
	std::srand(time(0) + i);
    switch(rand()%3)
    {
        case 0: 
            return std::shared_ptr<Circle>(new Circle(rand()%20));
        case 1: 
		    return std::shared_ptr<Ellipse>( new Ellipse(rand()%20,rand()%20));
        case 2: 
            return std::shared_ptr<Helix>(new Helix(rand()%20,rand()%20));
        }
    return std::shared_ptr<Circle>(new Circle(rand()%20));
}

struct comp {
    bool operator() (Circle* a, Circle* b) const {
        return a->GetRadius() < b->GetRadius();
    }
};


int main(int argc, char** argv) {
    std::vector<std::shared_ptr<ICurve> > ICurves;
	std::vector<Circle*> circle;
    int count;

	if (argc == 2)
	{
		count = atoi(argv[1]);
	} else
    {
        count = 10;
    }
    

	for (int i = 0; i < count; i++)
	{
        try
        {
            auto c = randomICurve(i);
            ICurves.push_back(c);
        }
        catch(const std::exception& e) {}
        
	}

	for (size_t i = 0; i < ICurves.size(); i++)
	{
        printICurve(ICurves[i]);
        std::cout << "\n\tcoordinates of point at t=PI/4 " << ICurves[i]->Coordinat(M_PI_2) << 
                "\n\tderivativesa at t=PI/4 " << ICurves[i]->Derivative(M_PI_2) << std::endl;
        if (isCircle(dynamic_cast<ICurve*>(ICurves[i].get()))) {
            circle.push_back(dynamic_cast<Circle*>(dynamic_cast<ICurve*>(ICurves[i].get())));
        }
	}

    std::sort(circle.begin(), circle.end(), comp());

    float sumRadius = 0;
    std::cout << "\nsorted circle container\n";
    for (std::vector<Circle*>::iterator it = circle.begin(); it < circle.end(); it++)
    {
        sumRadius += (*it)->GetRadius();
        std::cout << "   " << *(*it) <<std::endl;
    }
	std::cout << "Total sum of radius of all circle = " << sumRadius << std::endl;

	return (0);
}