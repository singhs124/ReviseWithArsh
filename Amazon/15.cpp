class Solution {
public:
double r , x_center,y_center ;
    Solution(double radius, double x_center, double y_center) {
        srand(time(0)) ;
        this->r = radius;
        this->x_center = x_center ;
        this->y_center = y_center ;
    }
    double random(){
        return (double)rand()/ RAND_MAX ;
    }
    
    vector<double> randPoint() {

        double len = sqrt(random())*r ;
        double deg = 2*M_PI* random() ;
        return {x_center + len* cos(deg) , y_center + len* sin(deg)} ;

    }
};
